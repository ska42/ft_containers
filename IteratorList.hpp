/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:55:19 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/11 22:56:21 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORLIST_HPP
# define ITERATORLIST_HPP

# include "Iterator.hpp"

namespace ft
{

	template <class T>
	struct DoublyLinkedList
	{
		DoublyLinkedList	*prev;
		DoublyLinkedList	*next;
		T					*element;
	};

	template <class T, class Category = bidirectional_iterator_tag>
	class IteratorList
	{
	
	private:
		/* Lock to compile error on use */
		IteratorList				operator+(const IteratorList &rhs) const;
		IteratorList				operator+(int n) const;
		IteratorList				operator-(const IteratorList &rhs) const;
		IteratorList				operator-(int n) const;
		bool						operator<(const IteratorList &rhs) const;
		bool						operator>(const IteratorList &rhs) const;
		bool						operator<=(const IteratorList &rhs) const;
		bool						operator>=(const IteratorList &rhs) const;
		IteratorList				&operator+=(int n) const;
		IteratorList				&operator-=(int n) const;
		T							&operator[](int n) const;

	protected:
		DoublyLinkedList<T>			*ptr;

	public:
		
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef T								value_type;
		typedef T								&reference;
		typedef T								*pointer;
		typedef Category						category;
		typedef std::ptrdiff_t					difference_type;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien Form */
		IteratorList(void) {}

		~IteratorList(void) {}

		IteratorList(const IteratorList &it)
		{
			*this = it;
		}

		IteratorList				&operator=(const IteratorList &rhs)
		{
			this->ptr = rhs.ptr;
			return (*this);
		}

		
		IteratorList(DoublyLinkedList<T> *list)
		{
			this->ptr = list;
		}

		IteratorList				&operator++(void)
		{
			if (this->ptr && this->ptr->next)
				this->ptr = this->ptr->next;
			return (*this);
		}

		IteratorList				operator++(int)
		{
			IteratorList tmp(*this);
			this->operator++();	
			return (tmp);
		}

		IteratorList				&operator--(void)
		{
			if (this->ptr && this->ptr->prev)
				this->ptr = this->ptr->prev;	
			return (*this);
		}

		IteratorList				operator--(int)
		{
			IteratorList tmp(*this);
			this->operator--();
			return (tmp);
		}

  		bool						operator==(const IteratorList &rhs) const
		{
			return (this->ptr == rhs.ptr);			
		}

  		bool						operator!=(const IteratorList &rhs) const
		{
			return (this->ptr != rhs.ptr);
		}

		T							&operator*(void) // dereferenced lvalue
		{
			return (*this->ptr->element);
		}

		T							*operator->(void) // dereferenced rvalue
		{ 
			return (this->ptr->element);	
		}
		
		DoublyLinkedList<T>			*getPtr(void)
		{
			return (this->ptr);
		}	

	};

	template <class T>
	class ReverseIteratorList : public IteratorList<T>
	{

	private:

	public:
		ReverseIteratorList(void) {}
		~ReverseIteratorList(void) {}

		ReverseIteratorList(DoublyLinkedList<T> *list)
		{
			this->ptr = list;
		}

		ReverseIteratorList(const ReverseIteratorList &it)
		{
			*this = it;
		}

		ReverseIteratorList			&operator=(const ReverseIteratorList &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		ReverseIteratorList			&operator++(void)
		{
			if (this->ptr && this->ptr->prev)
				this->ptr = this->ptr->prev;
			return (*this);
		}

		ReverseIteratorList			operator++(int)
		{
			ReverseIteratorList tmp(*this);
			this->operator++();
			return (tmp);
		}

		ReverseIteratorList			&operator--(void)
		{
			if (this->ptr && this->ptr->next)
				this->ptr = this->ptr->next;
			return (*this);
		}

		ReverseIteratorList			operator--(int)
		{
			ReverseIteratorList tmp(*this);
			this->operator--();
			return (tmp);
		}
	};

	template <class T>
	class ConstIteratorList : public IteratorList<T>
	{
	public:
		ConstIteratorList(void) {}
		~ConstIteratorList(void) {}

		ConstIteratorList(DoublyLinkedList<T> *list)
		{
			this->ptr = list;
		}

		ConstIteratorList(const ConstIteratorList &it)
		{
			*this = it;
		}

		ConstIteratorList			&operator=(const ConstIteratorList &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const T						&operator*(void) // dereferenced lvalue
		{
			return (*this->ptr->element);
		}
	};

	template <class T>
	class ConstReverseIteratorList : public ReverseIteratorList<T>
	{
	public:
		ConstReverseIteratorList(void) {}
		~ConstReverseIteratorList(void) {}

		ConstReverseIteratorList(DoublyLinkedList<T> *list)
		{
			this->ptr = list;
		}

		ConstReverseIteratorList(const ConstReverseIteratorList &it)
		{
			*this = it;
		}

		ConstReverseIteratorList			&operator=(const ConstReverseIteratorList &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const T						&operator*(void) // dereferenced lvalue
		{
			return (*this->ptr->element);
		}
	};
};

#endif
