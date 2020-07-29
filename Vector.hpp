/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:00:52 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/29 02:50:25 by lmartin          ###   ########.fr       */
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

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */

		explicit Vector(const allocator_type& alloc = allocator_type())
		{
		}

		~Vector(void)
		{
		}

		Vector(const Vector &vector)
		{
		}

		Vector				&operator=(const Vector &vector)
		{
		}

		/* Non-Default Constructor */
		explicit Vector(size_type n, const value_type &val = value_type(),
const allocator_type &alloc = allocator_type())
		{
		}

		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
const allocator_type& alloc = allocator_type())
		{
		}
		
		Vector(const Vector &x)
		{
		}

		/* Iterators */
		iterator				begin(void)
		{
		}

		const_iterator			begin(void) const
		{
		}

		iterator				end(void)
		{
		}

		const_iterator			end(void) const
		{
		}

		reverse_iterator		rbegin(void)
		{
		}

		const_reverse_iterator	rbegin(void) const
		{
		}

		reverse_iterator		rend(void)
		{
		}

		const_reverse_iterator	rend(void) const
		{
		}

		/* Capacity */
		size_type				size(void) const
		{
		}

		size_type				max_size(void) const
		{
		}

		void					resize(size_type n, value_type val = value_type())
		{
		}

		size_type				capacity(void) const
		{
		}

		bool					empty(void) const
		{
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
		}

		const_reference			front(void) const
		{
		}

		reference				back(void)
		{
		}

		const_reference			back(void) const
		{
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
