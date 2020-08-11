/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:53:13 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/11 22:54:13 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORVECTOR_HPP
# define ITERATORVECTOR_HPP

# include "Iterator.hpp"

namespace ft
{

	template <class T, class Category = random_access_iterator_tag>
	class IteratorVector
	{
	public:
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef T								value_type;
		typedef T								&reference;
		typedef T								*pointer;
		typedef Category						category;
		typedef std::ptrdiff_t					difference_type;

	protected:
		pointer									ptr;
		
	public:
	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien Form */
		IteratorVector(void) {}

		~IteratorVector(void) {}

		IteratorVector(const IteratorVector &it)
		{
			*this = it;
		}

		IteratorVector				&operator=(const IteratorVector &rhs)
		{
			this->ptr = rhs.ptr;
			return (*this);
		}

		
		IteratorVector(pointer ptr)
		{
			this->ptr = ptr;
		}

		IteratorVector				&operator++(void)
		{
			this->ptr++;
			return (*this);
		}

		IteratorVector				operator++(int)
		{
			IteratorVector tmp(*this);
			this->operator++();	
			return (tmp);
		}

		IteratorVector				&operator--(void)
		{
			this->ptr--;
			return (*this);
		}

		IteratorVector				operator--(int)
		{
			IteratorVector tmp(*this);
			this->operator--();
			return (tmp);
		}

  		bool						operator==(const IteratorVector &rhs) const
		{
			return (this->ptr == rhs.ptr);
		}

  		bool						operator!=(const IteratorVector &rhs) const
		{
			return (this->ptr != rhs.ptr);
		}

		T							&operator*(void) // dereferenced lvalue
		{
			return (*this->ptr);
		}

		T							*operator->(void) // dereferenced rvalue
		{ 
			return (this->ptr);
		}

		IteratorVector				operator+(int n) const
		{
			IteratorVector		iv(*this);

			iv += n;
			return (iv);
		}

		IteratorVector				operator-(int n) const
		{
			IteratorVector		iv(*this);

			iv -= n;
			return (iv);
		}

		bool						operator<(const IteratorVector &rhs) const
		{
			return (this->ptr < rhs.ptr);
		}

		bool						operator>(const IteratorVector &rhs) const
		{
			return (this->ptr > rhs.ptr);
		}

		bool						operator<=(const IteratorVector &rhs) const
		{
			return (this->ptr <= rhs.ptr);
		}

		bool						operator>=(const IteratorVector &rhs) const
		{
			return (this->ptr >= rhs.ptr);
		}

		IteratorVector				&operator+=(int n)
		{
			while (n > 0)	
			{
				n--;
				this->operator++();
			}
			while (n < 0)
			{
				n++;
				this->operator--();
			}
			return (*this);
		}

		IteratorVector				&operator-=(int n)
		{
			while (n > 0)
			{
				n--;
				this->operator--();
			}
			while (n < 0)
			{
				n++;
				this->operator++();
			}
			return (*this);
		}

		T							&operator[](int n) const
		{
			return (*(*this + n));
		}

		pointer						getPtr(void) const
		{
			return (this->ptr);
		}

	};

	template <class T, class Category = random_access_iterator_tag>
	class ReverseIteratorVector : public IteratorVector<T>
	{

	public:
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef T								value_type;
		typedef T								&reference;
		typedef T								*pointer;
		typedef Category						category;
		typedef std::ptrdiff_t					difference_type;

	private:

	public:
		ReverseIteratorVector(void) {}
		~ReverseIteratorVector(void) {}

		ReverseIteratorVector(const ReverseIteratorVector &it)
		{
			*this = it;
		}

		ReverseIteratorVector(pointer ptr)
		{
			this->ptr = ptr;
		}

		ReverseIteratorVector			&operator=(const ReverseIteratorVector &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		ReverseIteratorVector			&operator++(void)
		{
			this->ptr--;
			return (*this);
		}

		ReverseIteratorVector			operator++(int)
		{
			ReverseIteratorVector tmp(*this);
			this->operator++();
			return (tmp);
		}

		ReverseIteratorVector			&operator--(void)
		{
			this->ptr++;
			return (*this);
		}

		ReverseIteratorVector			operator--(int)
		{
			ReverseIteratorVector tmp(*this);
			this->operator--();
			return (tmp);
		}

		ReverseIteratorVector			&operator+=(int n) const
		{
			while (n > 0)	
			{
				n--;
				this--;
			}
			while (n < 0)
			{
				n++;
				this++;
			}
			return (*this);
		}

		ReverseIteratorVector			&operator-=(int n) const
		{
			while (n > 0)	
			{
				n--;
				this++;
			}
			while (n < 0)
			{
				n++;
				this--;
			}
			return (*this);
		}

		T								&operator[](int n) const
		{
			return (*(*this - n));
		}

	};
	
	template <class T>
	class ConstIteratorVector : public IteratorVector<T>
	{
	public:
		ConstIteratorVector(void) {}
		~ConstIteratorVector(void) {}

		ConstIteratorVector(T *ptr)
		{
			this->ptr = ptr;
		}

		ConstIteratorVector(const ConstIteratorVector &it)
		{
			*this = it;
		}

		ConstIteratorVector			&operator=(const ConstIteratorVector &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const T						&operator*(void) // dereferenced lvalue
		{
			return (*this->ptr);
		}
	};

	template <class T>
	class ConstReverseIteratorVector : public ReverseIteratorVector<T>
	{
	public:
		ConstReverseIteratorVector(void) {}
		~ConstReverseIteratorVector(void) {}

		ConstReverseIteratorVector(T *ptr)
		{
			this->ptr = ptr;
		}

		ConstReverseIteratorVector(const ConstReverseIteratorVector &it)
		{
			*this = it;
		}

		ConstReverseIteratorVector			&operator=(const ConstReverseIteratorVector &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const T						&operator*(void) // dereferenced lvalue
		{
			return (*this->ptr);
		}
	};
};

#endif
