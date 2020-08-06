/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:00:52 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/06 03:45:47 by lmartin          ###   ########.fr       */
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
		allocator_type			alloc;
		pointer					array;
		size_type				length;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */

		explicit Vector(const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->array = new value_type[1];
			this->array[0] = NULL;
			this->length = 0;
			return ;
		}

		~Vector(void)
		{
			this->clear();
			return ;
		}

		Vector(const Vector &vector)
		{
			*this = vector;
			return ;
		}

		Vector				&operator=(const Vector &vector)
		{
			// TO COMPLETE
			return (*this);
		}

		/* Non-Default Constructor */
		explicit Vector(size_type n, const value_type &val = value_type(),
const allocator_type &alloc = allocator_type())
		{
			this->alloc = alloc;
			this->array = new value_type[1];
			this->array[0] = NULL;
			this->length = 0;
			assign(static_cast<size_type>(n), static_cast<value_type>(val));
		}

		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->array = new value_type[1];
			this->array[0] = NULL;
			this->length = 0;
			this->length = 0;
			assign(static_cast<InputIterator>(first), static_cast<InputIterator>(last));
		}

		/* Iterators */
		iterator				begin(void)
		{
			return (iterator(&this->array[0]));
		}

		const_iterator			begin(void) const
		{
			return (const_iterator(&this->array[0]));
		}

		iterator				end(void)
		{
			return (iterator(&this->array[this->length]));
		}

		const_iterator			end(void) const
		{
			return (const_iterator(&this->array[this->length]));
		}

		reverse_iterator		rbegin(void)
		{
			return (reverse_iterator(&this->array[0]));
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(&this->array[0]));
		}

		reverse_iterator		rend(void)
		{
			return (reverse_iterator(&this->array[this->length]));
		}

		const_reverse_iterator	rend(void) const
		{
			return (const_reverse_iterator(&this->array[this->length]));
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
			return (this->array[n]);
		}

		const_reference			operator[](size_type n) const
		{
			return (this->array[n]);
		}

		reference				at(size_type n)
		{
			if (n > this->length)
				throw(std::out_of_range());
			return (this->array[n]);
		}

		const_reference			at(size_type n) const
		{
			if (n > this->length)
				throw(std::out_of_range());
			return (this->array[n]);
		}

		reference				front(void)
		{
			return (this->array[0]);
		}

		const_reference			front(void) const
		{
			return (this->array[0]);
		}

		reference				back(void)
		{
			return (this->array[this->length]);
		}

		const_reference			back(void) const
		{
			return (this->array[this->length]);
		}

		/* Modifiers */
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last)
		{
			// TO COMPLETE
		}

		void					assign(size_type n, const value_type &val)
		{
			this->clear();	
			while (n--)
				this->push_back(val);
		}

		void					push_back(const value_type &val)
		{
			// TO COMPLETE
		}

		void					pop_back(void)
		{
			// TO COMPLETE
		}

		iterator				insert(iterator position, const value_type &val)
		{
			// TO COMPLETE
		}

		void					insert(iterator position, size_type n, const value_type &val)
		{
			
			// TO COMPLETE

		}

		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last)
		{
			
			// TO COMPLETE

		}

		iterator				erase(iterator position)
		{

			// TO COMPLETE

		}

		iterator				erase(iterator first, iterator last)
		{

			// TO COMPLETE

		}

		void					swap(Vector &x)
		{

			// TO COMPLETE

		}

		void					clear(void)
		{

			// TO COMPLETE

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
