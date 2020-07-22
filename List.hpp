/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 04:01:16 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/22 12:37:33 by lmartin          ###   ########.fr       */
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
			DoublyLinkedList<T>		*tmp;

			while(this->head)
			{
				tmp = this->head->next;
				delete(this->head);
				this->head = this->head->next;
			}
			return ;
		}

		List(const List &list)
		{
			*this = list;
			return ;	
		}

		List					&operator=(const List &list)
		{
			DoublyLinkedList<T>		*tmp;

			this->head = NULL;
			this->tail = NULL;
			this->length = 0;
			tmp = list.head;
			while (tmp)
			{
				this->push_back(tmp->element);
				tmp = tmp->next;
			}
			return (*this);
		}

		/* Non-Default Constructor */

		explicit List (size_type n, const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type())
		{
			(void) alloc;
			this->head = NULL;
			this->tail = NULL;
			this->length = 0;
			assign(n, val);
		}
		
		template <class InputIterator>
  		List (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type())
		{
			(void) alloc;
			this->head = NULL;
			this->tail = NULL;
			this->length = 0;
			assign(first, last);
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
			if (!this->head)
				throw(std::exception());
			return (this->head->element);
		}

		const_reference			front(void) const
		{
			if (!this->head)
				throw(std::exception());
			return (this->head->element);
		}

		reference				back(void)
		{
			if (!this->tail)
				throw(std::exception());
			return (this->tail->element);
		}

		const_reference			back(void) const
		{
			if (!this->tail)
				throw(std::exception());
			return (this->tail->element);
		}

		/* Modifiers */
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last)
		{
			this->clear();
			while (first != last)
			{
				this->push_back(*first);
				first++;
			}
			this->push_back(*last);
		}

		void					assign(size_type n, const value_type &val)
		{
			this->clear();	
			while (n--)
				this->push_back(val);
		}

		void					push_front(const value_type &val)
		{
			DoublyLinkedList <T>	*ptr = new DoublyLinkedList<T>();

			ptr->next = NULL;
			ptr->prev = NULL;
			ptr->element = val;
			if (!this->length)
				this->tail = this->head = ptr;
			else
			{
				this->head->prev = ptr;
				ptr->next = this->head;
				this->head = ptr;
			}
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

			ptr->next = NULL;
			ptr->prev = NULL;
			ptr->element = val;
			if (!this->length)
				this->head = this->tail = ptr;
			else
			{
				this->tail->next = ptr;
				ptr->prev = this->tail;
				this->tail = this->tail->next;
			}
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

		iterator				insert(iterator position, const value_type &val)
		{
			DoublyLinkedList<T>		*add;
			DoublyLinkedList<T>		*ptr;
			
			add = new DoublyLinkedList<T>();
			add->next = NULL;
			add->prev = NULL;
			add->element = val;
			ptr = position.getPtr();
			add->prev = ptr->prev;
			ptr->prev->next = add;
			add->next = ptr;
			ptr->prev = add;
			this->length++;
			return (iterator(add));
		}

		void					insert(iterator position, size_type n, const value_type &val)
		{
			while (n--)
				this->insert(position, val);
		}

		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last)
		{
			for (InputIterator it = first; it != last; it++)
				this->insert(position, first);
		}

		iterator				erase(iterator position)
		{
			DoublyLinkedList<T>		*ptr;

			ptr = position.getPtr();
			if (!ptr->prev)
				this->head = ptr->next;
			else
				ptr->prev->next = ptr->next;
			if (!ptr->next)
				this->tail = ptr->prev;
			else
				ptr->next->prev = ptr->prev;
			delete(ptr);
			this->length--;
			return (iterator(this->head));
		}

		iterator				erase(iterator first, iterator last)
		{
			iterator tmp;
		
			while (first != last)
			{
				tmp = first;
				first++;
				this->erase(tmp);
			}
			this->erase(last);
			return (iterator(this->head));
		}

		void					swap(List &x)
		{
			DoublyLinkedList<T>	*tmp;
			size_type			tmp_length;
			
			tmp = x.head;
			x.head = this->head;
			this->head = tmp;
			tmp = x.tail;
			x.tail = this->tail;
			this->tail = tmp;
			tmp_length = x.length;
			x.length = this->length;
			this->length = tmp_length;
		}

		void					resize(size_type n, value_type val = value_type())
		{
			while (this->length > n)
				this->pop_back();
			while (this->length < n)
				this->push_back(val);
		}

		void					clear(void)
		{
			while (this->length)
				this->pop_back();
		}

		/* Operations */
		void					splice(iterator position, List &x)
		{
			this->insert(position, x.begin(), x.end());
			x.clear();
		}

		void					splice(iterator position, List &x, iterator i)
		{
			this->insert(position, *i);
			x.erase(i);			
		}

		void					splice(iterator position, List &x, iterator first, iterator last)
		{
			this->insert(position, first, last);
			x.erase(first, last);
		}

		void					remove(const value_type &val)
		{
			iterator	it;
			iterator	tmp;
			iterator	end;
			
			it = iterator(this->head);
			end = iterator(this->tail);
			while (it != end)
			{
				tmp = it;
				it++;
				if (*tmp == val)
					this->erase(tmp);
			}
			if (*tmp == val)
					this->erase(tmp);
		}

		template <class Predicate>
		void					remove_if(Predicate pred)
		{
			iterator	it;
			iterator	tmp;
			iterator	end;
			
			it = iterator(this->head);
			end = iterator(this->tail);
			while (it != end)
			{
				tmp = it;
				it++;
				if (pred(*tmp))
					this->erase(tmp);
			}
			if (pred(*tmp))
				this->erase(tmp);		
		}

		void					unique(void)
		{
			iterator it;
			iterator tmp;
			iterator tmp2;
			iterator end;

			it = iterator(this->head);	
			end = iterator(this->tail);
			while (it != end)
			{
				tmp = it;	
				while (it != end)
				{
					tmp2 = it;
					it++;
					if (*it == *tmp)
						this->erase(it);
					it = tmp2;
					it++;
				}
				if (*it == *tmp)
					this->erase(it);
				end = iterator(this->tail);
				it = tmp;
				it++;
			}
		}

		template <class BinaryPredicate>
		void					unique(BinaryPredicate binary_pred)
		{
			iterator it;
			iterator tmp;
			iterator tmp2;
			iterator end;

			it = iterator(this->head);	
			end = iterator(this->tail);
			while (it != end)
			{
				tmp = it;	
				while (it != end)
				{
					tmp2 = it;
					it++;
					if (binary_pred(*it, *tmp))
						this->erase(it);
					it = tmp2;
					it++;
				}
				if (binary_pred(*it, *tmp))
					this->erase(it);
				end = iterator(this->tail);
				it = tmp;
				it++;
			}
		}

		void					merge(List &x)
		{
			iterator it;
			iterator itx;
			iterator next;

			it = this->begin();
			itx = x.begin();
			while (itx != x.end())
			{
				while (it != this->end() && !(*itx < *it))
					it++;
				next = it;
				next++;
				splice(it, x, itx);
				itx = next;
			}
		}

		template <class Compare>
		void					merge(List &x, Compare comp)
		{
			iterator it;
			iterator itx;
			iterator next;

			it = this->begin();
			itx = x.begin();
			while (itx != x.end())
			{
				while (it != this->end() && comp(*itx, *it))
					it++;
				next = it;
				next++;
				splice(it, x, itx);
				itx = next;
			}
		}

		void					sort(void)
		{
			iterator it;
			iterator tmp;
			iterator tmp2;
			iterator end;

			it = iterator(this->head);	
			end = iterator(this->tail);
			while (it != end)
			{
				tmp = it;	
				while (it != end)
				{
					tmp2 = it;
					it++;
					if (*it < *tmp)
						this->splice(tmp, *this, it);
					it = tmp2;
					it++;
				}
				if (*it < *tmp)
					this->splice(tmp, *this, it);
				end = iterator(this->tail);
				it = tmp; it++;
			}
		}

		template <class Compare>
		void					sort(Compare comp)
		{
			iterator it;
			iterator tmp;
			iterator tmp2;
			iterator end;

			it = iterator(this->head);	
			end = iterator(this->tail);
			while (it != end)
			{
				tmp = it;	
				while (it != end)
				{
					tmp2 = it;
					it++;
					if (comp(*it, *tmp))
						this->splice(tmp, *this, it);
					it = tmp2;
					it++;
				}
				if (comp(*it, *tmp))
					this->splice(tmp, *this, it);
				end = iterator(this->tail);
				it = tmp;
				it++;
			}		
		}

		void					reverse(void)
		{
			iterator	start;
			iterator	tmp;
			iterator	it;
			size_type	n;

			start = iterator(this->head);
			it = iterator(this->head);
			n = this->length - 1;
			while (n--)
			{
				tmp = it;
				tmp++;
				this->splice(start, *this, it);
				start = iterator(this->head);
				it = tmp;
			}
		}
		
	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

	/* Function overloads */
	template <class T, class Alloc>
	bool						operator==(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (lhs == rhs);
	}

	template <class T, class Alloc>
	bool						operator!=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (lhs != rhs);
	}

	template <class T, class Alloc>
	bool						operator<(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (lhs < rhs);
	}

	template <class T, class Alloc>
	bool						operator<=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (lhs <= rhs);
	}

	template <class T, class Alloc>
	bool						operator>(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (lhs > rhs);
	}

	template <class T, class Alloc>
	bool						operator>=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (lhs >= rhs);
	}

	template <class T, class Alloc>
	void						swap(List<T, Alloc> &x, List <T, Alloc> &y)
	{
		x.swap(y);
	}
}

#endif
