/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:00:52 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/29 05:34:32 by lmartin          ###   ########.fr       */
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
		}

		/* Element access */
		reference				operator[](size_type n)
		{
		}

		const_reference			operator[](size_type n) const
		{
		}

		reference				at(size_type n)
		{
		}

		const_reference			at(size_type n) const
		{
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
		}

		void					assign(size_type n, const value_type &val)
		{
		}

		void					push_back(const value_type &val)
		{
		}

		void					pop_back(void)
		{
		}

		iterator				insert(iterator position, const value_type &val)
		{
		}

		void					insert(iterator position, size_type n, const value_type &val)
		{
		}

		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last)
		{
		}

		iterator				erase(iterator position)
		{
		}

		iterator				erase(iterator first, iterator last)
		{
		}

		void					swap(vector &x)
		{
		}

		void					clear(void)
		{
		}

	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

	/* Function overloads */
	template <class T, class Alloc>
	bool						operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
	}

	template <class T, class Alloc>
	bool						operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
	}

	template <class T, class Alloc>
	bool						operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
	}

	template <class T, class Alloc>
	bool						operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
	}

	template <class T, class Alloc>
	bool						operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
	}

	template <class T, class Alloc>
	bool						operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
	}

	template <class T, class Alloc>
	void						swap(vector<T,Alloc> &x, vector<T,Alloc> &y)
	{
	}

};


#endif
