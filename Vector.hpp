/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:00:52 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/09 20:32:25 by lmartin          ###   ########.fr       */
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
			this->array = alloc.allocate(1);
			this->array[0] = NULL;
			this->length = 0;
			this->real_length = 0;
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
			this->alloc = vector.alloc;
			this->real_length = vector.real_length;
			this->array = alloc.allocate(this->real_length + 1);
			this->array[0] = NULL;
			this->length = 0;
			Vector::iterator it;
			
			it = vector.begin();
			while (it != vector.end())
			{
				this->push_back(*it);
				it++;
			}
			return (*this);
		}

		/* Non-Default Constructor */
		explicit Vector(size_type n, const value_type &val = value_type(),
const allocator_type &alloc = allocator_type())
		{
			this->alloc = alloc;
			this->array = alloc.allocate(1);
			this->array[0] = NULL;
			this->length = 0;
			this->real_length = 0;
			assign(static_cast<size_type>(n), static_cast<value_type>(val));
		}

		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->array = alloc.allocate(1);
			this->array[0] = NULL;
			this->length = 0;
			this->real_length = 0;
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
			return (this->real_length);
		}

		bool					empty(void) const
		{
			return (!this->length);
		}

		void					reserve(size_type n)
		{
			if (n > this->max_size())
				throw(std::length_error());
			if (n > this->real_length)
			{
				size_type				tmp;
				value_type				*new_array;

				new_array = this->alloc.allocate(n + 1);
				tmp = this->real_length;
				this->real_length = n;
				while (n)
				{
					n--;
					if (n < this->length)
						this->new_array[n] = this->array[n];
				}
				this->new_array[this->length] = NULL;
				this->alloc.deallocate(this->array, tmp + 1);
				this->array = this->new_array;
			}
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
			if (n >= this->length)
				throw(std::out_of_range());
			return (this->array[n]);
		}

		const_reference			at(size_type n) const
		{
			if (n >= this->length)
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
			return (this->array[this->length - 1]);
		}

		const_reference			back(void) const
		{
			return (this->array[this->length - 1]);
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
			array[this->length++] = val;
			array[this->length] = NULL;
		}

		void					pop_back(void)
		{
			delete(array[--this->length]);
			array[this->length] = NULL;
		}

		iterator				insert(iterator position, const value_type &val)
		{
			size_t				i;
			reverse_iterator 	end;

			if ((this->length + 1) > this->capacity())
				reserve(this->length + 1);
			i = this->length++;
			array[this->length] = NULL;
			end = this->rend();
			while (end++ != position)
			{
				array[i] = array[i - 1];
				i--;
			}
			array[i] = val;
		}

		void					insert(iterator position, size_type n, const value_type &val)
		{
			while (n--)
				insert(position, val);
		}

		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *first);
				first++;
			}
		}

		iterator				erase(iterator position)
		{
			size_t				i;
			reverse_iterator	end;
			value_type			val;

			delete(val);
			i = this->length - 1;
			end = this->rend();
			while (end++ != position)
			{
				array[i] = array[i + 1];
				i--;
			}
			this->length--;
		}

		iterator				erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
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
