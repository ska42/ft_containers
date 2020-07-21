/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 04:01:16 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/21 14:50:28 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <iterator>
# include "Iterator.hpp"

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/list/list                          */
	/* ********************************************************************** */

	template <class T, class Alloc = std::allocator<T> >
	class List
	{
	
	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef T												&reference;
		typedef const T											&const_reference;
		typedef	T												*pointer;
		typedef	const T											*const_pointer;
		typedef ft::IteratorList<T>								iterator;
		typedef ft::IteratorList<const T>						const_iterator;
		typedef ft::ReverseIteratorList<T>						reverse_iterator;
		typedef ft::ReverseIteratorList<const T>				const_reverse_iterator;
		typedef typename ft::IteratorList<T>::difference_type	difference_type;
		typedef size_t											size_type;

	private:
		DoublyLinkedList<T>			*head;
		DoublyLinkedList<T>			*tail;
		size_type					length;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */
		explicit List (const allocator_type& alloc = allocator_type())
		{
			(void)alloc;
			this->head = NULL;
			this->tail = NULL;
			this->length = 0;
		}

		~List(void)
		{
			// free ALL with iterator
			delete(head);
			delete(tail);
			return ;				
		}

		List(const List &list)
		{
			*this = list;
			return ;	
		}

		List					&operator=(const List &list)
		{
			// NON --- FAIRE UNE COPIE DE TOUT
			this->head = list.head;
			this->tail = list.tail;
			this->length = list.length;
			return (*this);
		}

		/* Non-Default Constructor */

		explicit List (size_type n, const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type())
		{
		}
		
		template <class InputIterator>
  		List (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type())
		{
		}

		/* Iterators */
		iterator				begin(void)
		{
			return (iterator(this->head));
		}

		const_iterator			begin(void) const
		{
			return (iterator(this->head));
		}

		iterator				end(void)
		{
			return (iterator(this->tail));
		}

		const_iterator			end(void) const
		{
			return (iterator(this->tail));
		}

		reverse_iterator		rbegin(void)
		{
			return (reverse_iterator(this->head));
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (reverse_iterator(this->head));
		}

		reverse_iterator		rend(void)
		{
			return (reverse_iterator(this->tail));
		}

		const_reverse_iterator	rend(void) const
		{
			return (reverse_iterator(this->tail));
		}

		/* Capacity */
		bool					empty(void) const
		{
			return (!this->length);
		}

		size_type				size(void) const
		{
			return (this->length);
		}

		size_type				max_size(void) const
		{
			return (SIZE_MAX/sizeof(value_type));
		}

		/* Element access */
		reference				front(void)
		{
			return (this->head->element);
		}

		const_reference			front(void) const
		{
			return (this->head->element);
		}

		reference				back(void)
		{
			return (this->tail->element);
		}

		const_reference			back(void) const
		{
			return (this->tail->element);
		}

		/* Modifiers */
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const value_type& val);

		void					push_front(const value_type &val)
		{
			DoublyLinkedList <T>	*ptr = new DoublyLinkedList<T>();

			ptr->element = val;
			if (!this->length)
				this->tail = this->head = ptr;
			else
				this->tail = this->tail->next = ptr;	
			this->length++;
		}

		void					pop_front(void)
		{
			if (this->length)
			{
				if (this->length == 1)
				{
					delete(this->head);
					this->tail = this->head = NULL;
				}
				else
				{
					this->head = this->head->next;
					delete(this->head->prev);
					this->head->prev = NULL;
				}
				this->length--;
			}
		}

		void					push_back(const value_type &val)
		{
			DoublyLinkedList <T>	*ptr = new DoublyLinkedList<T>();

			ptr->element = val;
			if (!this->length)
				this->head = this->tail = ptr;
			else
				this->tail = this->tail->next = ptr;	
			this->length++;
		}

		void					pop_back(void)
		{
			if (this->length)
			{
				if (this->length == 1)
				{
					delete(this->tail);
					this->head = this->tail = NULL;
				}
				else
				{
					this->tail = this->tail->prev;
					delete(this->tail->next);
					this->tail->next = NULL;
				}
				this->length--;		
			}
		}

		iterator				insert(iterator position, const value_type &val);
		void					insert(iterator position, size_type n, const value_type &val);
		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(List &x);
		void					resize(size_type n, value_type val = value_type());
		void					clear(void);

		/* Operations */
		void					splice(iterator position, List &x);
		void					splice(iterator position, List &x, iterator i);
		void					splice(iterator position, List &x, iterator first, iterator last);
		void					remove(const value_type &val);
		template <class Predicate>
		void					remove_if(Predicate pred);
		void					unique(void);
		template <class BinaryPredicate>
		void					unique(BinaryPredicate binary_pred);
		void					merge(List &x);
		template <class Compare>
		void					merge(List &x, Compare comp);
		void					sort(void);
		template <class Compare>
		void					sort(Compare comp);
		void					reverse(void);
		
	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

	/* Function overloads */
	template <class T, class Alloc>
	bool						operator==(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator!=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator<(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator<=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator>(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator>=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs);
	template <class T, class Alloc>
	void						swap(List<T, Alloc> &x, List <T, Alloc> &y);
}

#endif
