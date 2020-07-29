/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:00:52 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/29 06:22:31 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "Iterator.hpp"

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/vector/vector                      */
	/* ********************************************************************** */

	template <class T, class Alloc = allocator<T> >
	class Vector
	{

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef T															&reference;
		typedef const T														&const_reference;
		typedef	T															*pointer;
		typedef	const T														*const_pointer;
		typedef ft::IteratorVector<T>										iterator;
		typedef ft::IteratorVector<const T>									const_iterator;
		typedef ft::ReverseIteratorVector<T>								reverse_iterator;
		typedef ft::ReverseIteratorVector<const T>							const_reverse_iterator;
		typedef typename ft::ReverseIteratorVector<T>::difference_type		difference_type;
		typedef size_t														size_type;

	private:
		DoublyLinkedList<T>		*head;
		size_type				length;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */

		explicit Vector(const allocator_type& alloc = allocator_type())
		{
			(void)alloc;
			this->head = NULL;
			this->length = 0;
			return ;
		}

		~Vector(void)
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

		Vector(const Vector &vector)
		{
			*this = vector;
			return ;
		}

		Vector				&operator=(const Vector &vector)
		{
			DoublyLinkedList<T>		*tmp;

			this->head = NULL;
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
		explicit Vector(size_type n, const value_type &val = value_type(),
const allocator_type &alloc = allocator_type())
		{
			(void) alloc;
			this->head = NULL;
			this->length = 0;
			assign(static_cast<size_type>(n), static_cast<value_type>(val));
		}

		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
const allocator_type& alloc = allocator_type())
		{
			(void) alloc;
			this->head = NULL;
			this->length = 0;
			assign(static_cast<InputIterator>(first), static_cast<InputIterator>(last));
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
			return (iterator(this->tail) + this->length);
		}

		const_iterator			end(void) const
		{
			return (iterator(this->tail) + this->length);
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
			return (reverse_iterator(this->tail) - this->length);
		}

		const_reverse_iterator	rend(void) const
		{
			return (reverse_iterator(this->tail) - this->length);
		}

		/* Capacity */
		size_type				size(void) const
		{
			return (this->length);
		}

		size_type				max_size(void) const
		{
			// A FAIRE
		}

		void					resize(size_type n, value_type val = value_type())
		{
			while (this->length > n)
				this->pop_back();
			while (this->length < n)
				this->push_back(val);
		}

		size_type				capacity(void) const
		{
			// A FAIRE
		}

		bool					empty(void) const
		{
			return (!this->length);
		}

		void					reserve(size_type n)
		{
			// A FAIRE
		}

		/* Element access */
		reference				operator[](size_type n)
		{
			return (iterator(this->head)[n]);
		}

		const_reference			operator[](size_type n) const
		{
			return (iterator(this->head)[n]);
		}

		reference				at(size_type n)
		{
			return (iterator(this->head)[n]);
		}

		const_reference			at(size_type n) const
		{
			return (iterator(this->head)[n]);
		}

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
			if (!this->head)
				throw(std::exception());
			return (iterator(this->head)[this->length]);
		}

		const_reference			back(void) const
		{
			if (!this->head)
				throw(std::exception());
			return (iterator(this->head)[this->length]);
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

		void					push_back(const value_type &val)
		{
			DoublyLinkedList <T>	*tail;
			DoublyLinkedList <T>	*ptr = new DoublyLinkedList<T>();

			ptr->next = NULL;
			ptr->prev = NULL;
			ptr->element = val;
			if (!this->length)
				this->head = ptr;
			else
			{
				tail = this->head;
				while (tail->next)
					tail = tail->next;
				tail->next = ptr;
				ptr->prev = tail;
			}
			this->length++;
		}

		void					pop_back(void)
		{
			DoublyLinkedList <T>	*tail;

			if (this->length)
			{
				tail = this->head;
				while (tail->next)
					tail = tail->next;
				if (this->length == 1)
				{
					delete(tail);
					this->head = NULL;
				}
				else
				{
					tail = tail->prev;
					delete(tail->next);
					tail->next = NULL;
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
			if (!ptr->prev)
				this->head = add;
			add->prev = ptr->prev;
			if (ptr->prev)
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
			{
				this->head = ptr->next;
				if (this->head)
					this->head->prev = NULL;
			}
			else
				ptr->prev->next = ptr->next;
			if (!ptr->next)
			{
				if (ptr->prev)
					ptr->prev->next = NULL;
			}
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

		void					swap(Vector &x)
		{
			DoublyLinkedList<T>	*tmp;
			size_type			tmp_length;
			
			tmp = x.head;
			x.head = this->head;
			this->head = tmp;
			tmp_length = x.length;
			x.length = this->length;
			this->length = tmp_length;
		}

		void					clear(void)
		{
			while (this->length)
				this->pop_back();
		}

	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

	/* Function overloads */
	template <class T, class Alloc>
	bool						operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (lhs == rhs);
	}

	template <class T, class Alloc>
	bool						operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (lhs != rhs);
	}

	template <class T, class Alloc>
	bool						operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (lhs < rhs);
	}

	template <class T, class Alloc>
	bool						operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (lhs <= rhs);
	}

	template <class T, class Alloc>
	bool						operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (lhs > rhs);
	}

	template <class T, class Alloc>
	bool						operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (lhs >= rhs);
	}

	template <class T, class Alloc>
	void						swap(vector<T,Alloc> &x, vector<T,Alloc> &y)
	{
		x.swap(y);
	}

};


#endif
