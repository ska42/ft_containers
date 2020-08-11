/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:00:52 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/11 22:54:58 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

# include <memory>
# include <stdexcept>
# include "IteratorVector.hpp"

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/vector/vector                      */
	/* ********************************************************************** */

	template <class T, class Alloc = std::allocator<T> >
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
		typedef ft::ConstIteratorVector<T>									const_iterator;
		typedef ft::ReverseIteratorVector<T>								reverse_iterator;
		typedef ft::ConstReverseIteratorVector<T>							const_reverse_iterator;
		typedef typename ft::ReverseIteratorVector<T>::difference_type		difference_type;
		typedef size_t														size_type;

	private:
		allocator_type			alloc;
		value_type				*array;
		size_type				length;
		size_type				real_length;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */

		explicit Vector(const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->array = this->alloc.allocate(2);
			this->length = 0;
			this->real_length = 0;
			return ;
		}

		~Vector(void)
		{
			this->clear();
			this->alloc.deallocate(this->array, this->real_length + 2);
			return ;
		}

		Vector(const Vector &vector)
		{
			*this = vector;
			return ;
		}

		Vector				&operator=(const Vector &vector)
		{
			int		n;

			this->alloc = vector.alloc;
			this->real_length = vector.real_length;
			this->array = this->alloc.allocate(this->real_length + 2);
			this->length = vector.length;
			n = vector.length + 1;
			while (n--)
				this->array[n] = vector.array[n];
			return (*this);
		}

		/* Non-Default Constructor */
		explicit Vector(size_type n, const value_type &val = value_type(),
const allocator_type &alloc = allocator_type())
		{
			this->alloc = alloc;
			this->array = this->alloc.allocate(2);
			this->length = 0;
			this->real_length = 0;
			assign(static_cast<size_type>(n), static_cast<value_type>(val));
		}

		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->array = this->alloc.allocate(2);
			this->length = 0;
			this->real_length = 0;
			assign(static_cast<InputIterator>(first), static_cast<InputIterator>(last));
		}

		/* Iterators */
		iterator				begin(void)
		{
			return (iterator(&(this->array[0 + 1])));
		}

		const_iterator			begin(void) const
		{
			return (const_iterator(&(this->array[0 + 1])));
		}

		iterator				end(void)
		{
			return (iterator(&(this->array[this->length + 1])));
		}

		const_iterator			end(void) const
		{
			return (const_iterator(&(this->array[this->length + 1])));
		}

		reverse_iterator		rbegin(void)
		{
			return (reverse_iterator(&(this->array[this->length])));
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(&(this->array[this->length])));
		}

		reverse_iterator		rend(void)
		{
			return (reverse_iterator(&(this->array[0])));
		}

		const_reverse_iterator	rend(void) const
		{
			return (const_reverse_iterator(&(this->array[0])));
		}

		/* Capacity */
		size_type				size(void) const
		{
			return (this->length);
		}

		size_type				max_size(void) const
		{
			// A FAIRE
			return (std::numeric_limits<size_type>::max()/sizeof(value_type));
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
			return (this->real_length);
		}

		bool					empty(void) const
		{
			return (!this->length);
		}

		void					reserve(size_type n)
		{
			if (n > this->max_size())
				throw(std::length_error("max_size reached"));
			if (n > this->real_length)
			{
				size_type				tmp;
				value_type				*new_array;

				new_array = this->alloc.allocate(n + 2);
				tmp = this->real_length;
				this->real_length = n;
				while (n)
				{
					if (n <= this->length + 1)
						new_array[n] = this->array[n];
					n--;
				}
				this->alloc.deallocate(this->array, tmp + 2);
				this->array = new_array;
			}
		}

		/* Element access */
		reference				operator[](size_type n)
		{
			return (this->array[n + 1]);
		}

		const_reference			operator[](size_type n) const
		{
			return (this->array[n + 1]);
		}

		reference				at(size_type n)
		{
			if (n >= this->length)
				throw(std::out_of_range("n is outside the array"));
			return (this->array[n + 1]);
		}

		const_reference			at(size_type n) const
		{
			if (n >= this->length)
				throw(std::out_of_range("n is outside the array"));
			return (this->array[n + 1]);
		}

		reference				front(void)
		{
			return (this->array[0 + 1]);
		}

		const_reference			front(void) const
		{
			return (this->array[0 + 1]);
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
			this->clear();
			this->insert(this->begin(), first, last);
		}

		void					assign(size_type n, const value_type &val)
		{
			this->clear();
			this->insert(this->begin(), n, val);
		}

		void					push_back(const value_type &val)
		{
			if ((this->length + 1) > this->capacity())
				reserve(this->length + 1);
			array[this->length++ + 1] = val;
		}

		void					pop_back(void)
		{
			this->length--;
		}

		iterator				insert(iterator position, const value_type &val)
		{
			iterator			end;
			size_t				i;

			i = this->length + 1;
			end = this->end();
			while (position++ != end)
			{
				this->array[i] = this->array[i - 1];
				i--;
			}
			array[i] = val;
			if ((this->length + 1) > this->capacity())
				reserve(this->length + 1);
			this->length++;
			return (iterator(&this->array[i]));
		}

		void					insert(iterator position, size_type n, const value_type &val)
		{
			while (n--)
				position = this->insert(position, val);
		}

		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				position = this->insert(position, *first++);
				position++;
			}
		}

		iterator				erase(iterator position)
		{
			iterator			tmp;
			iterator			next;

			tmp = position;
			while (tmp != this->end())
			{
				next = tmp;
				next++;	
				*tmp = *next;
				tmp++;
			}
			this->length--;
			return (position);
		}

		iterator				erase(iterator first, iterator last)
		{
			iterator			tmp2;
			iterator			tmp;

			tmp2 = last;
			tmp = first;
			while (last != this->end())
			{
				*tmp = *last;
				tmp++;
				last++;
			}
			last = tmp2;
			tmp = first;
			while (tmp != last)
			{
				tmp++;
				this->length--;
			}
			return (first);
		}

		void					swap(Vector &x)
		{
			value_type		*array_tmp;
			size_t			tmp;
			
			array_tmp = x.array;
			x.array = this->array;
			this->array = array_tmp;
			tmp = x.length;
			x.length = this->length;
			this->length = tmp;
			tmp = x.real_length;
			x.real_length = this->real_length;
			this->real_length = tmp;
		}

		void					clear(void)
		{
			erase(this->begin(), this->end());
		}

	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

	/* Function overloads */
	template <class T, class Alloc>
	bool						operator==(const Vector<T,Alloc> &lhs, const Vector<T,Alloc> &rhs)
	{
		size_t			i;

		if (lhs.size() != rhs.size())
			return (false);
		i = 0;
		while (i < lhs.size())
		{
			if (lhs.at(i) != rhs.at(i))
				return (false);
			i++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool						operator!=(const Vector<T,Alloc> &lhs, const Vector<T,Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool						operator<(const Vector<T,Alloc> &lhs, const Vector<T,Alloc> &rhs)
	{
		size_t		i;
		size_t		n;

		if (lhs.size() > rhs.size())
			n = rhs.size();
		else
			n = lhs.size();
		i = 0;
		while (i < n)
		{
			if (lhs.at(i) != rhs.at(i))
				return (lhs.at(i) < rhs.at(i));
			i++;
		}
		return (lhs.size() < rhs.size());
	}

	template <class T, class Alloc>
	bool						operator<=(const Vector<T,Alloc> &lhs, const Vector<T,Alloc> &rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	bool						operator>(const Vector<T,Alloc> &lhs, const Vector<T,Alloc> &rhs)
	{
		return (!(lhs < rhs) && !(lhs == rhs));
	}

	template <class T, class Alloc>
	bool						operator>=(const Vector<T,Alloc> &lhs, const Vector<T,Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void						swap(Vector<T,Alloc> &x, Vector<T,Alloc> &y)
	{
		x.swap(y);
	}

};


#endif
