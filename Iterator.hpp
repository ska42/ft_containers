/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 09:21:08 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/19 08:39:01 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef> // type ptrdiff_t

namespace ft
{
	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/references/iterator                          */
	/* https://www.cplusplus.com/references/iterator/iterator                 */
	/* https://www.cplusplus.com/reference/iterator/iterator_traits/          */
	/* ********************************************************************** */

	template <class T>
	struct DoublyLinkedList
	{
		DoublyLinkedList	*prev;	
		DoublyLinkedList	*next;
		T					element;
	};

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag: input_iterator_tag {};
	struct bidirectional_iterator_tag: forward_iterator_tag {};
	struct random_access_iterator_tag: bidirectional_iterator_tag {};

	template <class T, class Category = bidirectional_iterator_tag>
	class IteratorList
	{
	
	private:
		/* Lock to compile error on use */
		IteratorList				operator+(const IteratorList &rhs) const;
		IteratorList				operator+(int n) const;
		IteratorList				operator-(const IteratorList &rhs) const;
		IteratorList				operator-(int n) const;
		IteratorList				operator<(const IteratorList &rhs) const;
		IteratorList				operator>(const IteratorList &rhs) const;
		IteratorList				operator<=(const IteratorList &rhs) const;
		IteratorList				operator>=(const IteratorList &rhs) const;
		IteratorList				operator+=(int n) const;
		IteratorList				operator-=(int n) const;
		IteratorList				&operator[](int n) const;

	protected:
		DoublyLinkedList<T>			list;

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
		IteratorList(void);
		~IteratorList(void);
		IteratorList(const IteratorList &it);
		IteratorList				&operator=(const IteratorList &it);

		IteratorList				&operator++(void);
		IteratorList				operator++(int n);
  		bool						operator==(const IteratorList &rhs) const;
  		bool						operator!=(const IteratorList &rhs) const;
		IteratorList				&operator*(void); // dereferenced lvalue
		IteratorList				*operator->(void); // dereferenced rvalue
		IteratorList				&&operator*(void); // dereferenced rvalue
		IteratorList				&operator--(void);
		IteratorList				operator--(int n);
	};

	template <class T>
	class ReverseIteratorList : public IteratorList<T>
	{

	private:

	public:
		ReverseIteratorList(void);
		~ReverseIteratorList(void);
		ReverseIteratorList(const ReverseIteratorList &it);
		ReverseIteratorList			&operator=(const ReverseIteratorList &it);

		ReverseIteratorList			&operator++(void);
		ReverseIteratorList			operator++(int n);
		ReverseIteratorList			&operator--(void);
		ReverseIteratorList			operator--(int n);
	};
};

#endif
