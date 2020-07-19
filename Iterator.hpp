/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 09:21:08 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/19 06:55:36 by lmartin          ###   ########.fr       */
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

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag: input_iterator_tag {};
	struct bidirectional_iterator_tag: forward_iterator_tag {};
	struct random_access_iterator_tag: bidirectional_iterator_tag {};

	template <class T>
	class Iterator
	{
	
	private:
		Iterator(void);

	protected:

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef T							*pointer;
		typedef T							&reference;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
	
		/* Coplien form */
		~Iterator(void);
		Iterator(const Iterator &it);
		Iterator							&operator=(const Iterator &it);

		virtual Iterator					&operator++(void);
		virtual Iterator					operator++(int n);
		reference							operator*(void);

	};

	template <class T>
	class InputIterator: public Iterator
	{

	private:
	/* All invalid expression to get compilation error on trying to use them */
		InputIterator(void);

		InputIterator						&operator*(void); // dereferenced lvalue
		InputIterator						&operator--(void);
		InputIterator						operator--(int n);
		InputIterator						operator+(const InputIterator &rhs) const;
		InputIterator						operator+(int n) const;
		InputIterator						operator-(const InputIterator &rhs) const;
		InputIterator						operator-(int n) const;
		InputIterator						operator<(const InputIterator &rhs) const;
		InputIterator						operator>(const InputIterator &rhs) const;
		InputIterator						operator<=(const InputIterator &rhs) const;
		InputIterator						operator>=(const InputIterator &rhs) const;
		InputIterator						operator+=(int n) const;
		InputIterator						operator-=(int n) const;
		InputIterator						&operator[](int n) const;

	protected:

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef input_iterator_tag			iterator_category;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
	
		/* Coplien form */
		~InputIterator(void);
		InputIterator(const InputIterator &it);
		InputIterator						&operator=(const InputIterator &it);

		Iterator							&operator++(void);
		Iterator							operator++(int n);
  		bool								operator==(const InputIterator &rhs) const;
  		bool								operator!=(const InputIterator &rhs) const;
		InputIterator						*operator->(void); // dereferenced rvalue
		InputIterator						&&operator*(void); // dereferenced rvalue

	};	

	template <class T>
	class OutputIterator: public Iterator
	{

	private:
	/* All invalid expression to get compilation error on trying to use them */
		OutputIterator(void);

  		bool								operator==(const OutputIterator &rhs) const;
  		bool								operator!=(const OutputIterator &rhs) const;
		OutputIterator						*operator->(void); // dereferenced rvalue
		OutputIterator						&&operator*(void); // dereferenced rvalue
		OutputIterator						&operator--(void);
		OutputIterator						operator--(int n);
		OutputIterator						operator+(const OutputIterator &rhs) const;
		OutputIterator						operator+(int n) const;
		OutputIterator						operator-(const OutputIterator &rhs) const;
		OutputIterator						operator-(int n) const;
		OutputIterator						operator<(const OutputIterator &rhs) const;
		OutputIterator						operator>(const OutputIterator &rhs) const;
		OutputIterator						operator<=(const OutputIterator &rhs) const;
		OutputIterator						operator>=(const OutputIterator &rhs) const;
		OutputIterator						operator+=(int n) const;
		OutputIterator						operator-=(int n) const;
		OutputIterator						&operator[](int n) const;

	protected:

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef output_iterator_tag			iterator_category;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
	
		/* Coplien form */
		~OutputIterator(void);
		OutputIterator(const OutputIterator &it);
		OutputIterator						&operator=(const OutputIterator &it);

		Iterator							&operator++(void);
		Iterator							operator++(int n);
		OutputIterator						&operator*(void); // dereferenced lvalue
	};	

	template <class T>
	class ForwardIterator: public Iterator
	{

	private:
		ForwardIterator						&operator--(void);
		ForwardIterator						operator--(int n);
		ForwardIterator						operator+(const ForwardIterator &rhs) const;
		ForwardIterator						operator+(int n) const;
		ForwardIterator						operator-(const ForwardIterator &rhs) const;
		ForwardIterator						operator-(int n) const;
		ForwardIterator						operator<(const ForwardIterator &rhs) const;
		ForwardIterator						operator>(const ForwardIterator &rhs) const;
		ForwardIterator						operator<=(const ForwardIterator &rhs) const;
		ForwardIterator						operator>=(const ForwardIterator &rhs) const;
		ForwardIterator						operator+=(int n) const;
		ForwardIterator						operator-=(int n) const;
		ForwardIterator						&operator[](int n) const;

	protected:

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef forward_iterator_tag			iterator_category;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
	
		/* Coplien form */
		ForwardIterator(void); // Forward, Bidirectionnal and RandomAccess are default constructible
		~ForwardIterator(void);
		ForwardIterator(const ForwardIterator &it);
		ForwardIterator						&operator=(const ForwardIterator &it);

		Iterator							&operator++(void);
		Iterator							operator++(int n);
  		bool								operator==(const ForwardIterator &rhs) const;
  		bool								operator!=(const ForwardIterator &rhs) const;
		ForwardIterator						&operator*(void); // dereferenced lvalue
		ForwardIterator						*operator->(void); // dereferenced rvalue
		ForwardIterator						&&operator*(void); // dereferenced rvalue
	};	

	template <class T>
	class BidirectionalIterator: public Iterator
	{

	private:
		pointer								left;
		pointer								right;

		BidirectionalIterator				operator+(const BidirectionalIterator &rhs) const;
		BidirectionalIterator				operator+(int n) const;
		BidirectionalIterator				operator-(const BidirectionalIterator &rhs) const;
		BidirectionalIterator				operator-(int n) const;
		BidirectionalIterator				operator<(const BidirectionalIterator &rhs) const;
		BidirectionalIterator				operator>(const BidirectionalIterator &rhs) const;
		BidirectionalIterator				operator<=(const BidirectionalIterator &rhs) const;
		BidirectionalIterator				operator>=(const BidirectionalIterator &rhs) const;
		BidirectionalIterator				operator+=(int n) const;
		BidirectionalIterator				operator-=(int n) const;
		BidirectionalIterator				&operator[](int n) const;

	protected:

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef bidirectional_iterator_tag	iterator_category;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
	
		/* Coplien form */
		BidirectionalIterator(void); // Forward, Bidirectionnal and RandomAccess are default constructible
		~BidirectionalIterator(void);
		BidirectionalIterator(const BidirectionalIterator &it);
		BidirectionalIterator				&operator=(const BidirectionalIterator &it);

		Iterator							&operator++(void);
		Iterator							operator++(int n);
  		bool								operator==(const BidirectionalIterator &rhs) const;
  		bool								operator!=(const BidirectionalIterator &rhs) const;
		BidirectionalIterator				&operator*(void); // dereferenced lvalue
		BidirectionalIterator				*operator->(void); // dereferenced rvalue
		BidirectionalIterator				&&operator*(void); // dereferenced rvalue
		BidirectionalIterator				&operator--(void);
		BidirectionalIterator				operator--(int n);
	};	

	template <class T>
	class RandomAccessIterator: public Iterator
	{

	private:

	protected:

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef random_access_iterator_tag	iterator_category;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
	
		/* Coplien form */
		RandomAccessIterator(void); // Forward, Bidirectionnal and RandomAccess are default constructible
		~RandomAccessIterator(void);
		RandomAccessIterator(const RandomAccessIterator &it);
		RandomAccessIterator				&operator=(const RandomAccessIterator &it);

		Iterator							&operator++(void);
		Iterator							operator++(int n);
  		bool								operator==(const RandomAccessIterator &rhs) const;
  		bool								operator!=(const RandomAccessIterator &rhs) const;
		RandomAccessIterator				&operator*(void); // dereferenced lvalue
		RandomAccessIterator				*operator->(void); // dereferenced rvalue
		RandomAccessIterator				&&operator*(void); // dereferenced rvalue
		RandomAccessIterator				&operator--(void);
		RandomAccessIterator				operator--(int n);
		RandomAccessIterator				operator+(const RandomAccessIterator &rhs) const;
		RandomAccessIterator				operator+(int n) const;
		RandomAccessIterator				operator-(const RandomAccessIterator &rhs) const;
		RandomAccessIterator				operator-(int n) const;
		RandomAccessIterator				operator<(const RandomAccessIterator &rhs) const;
		RandomAccessIterator				operator>(const RandomAccessIterator &rhs) const;
		RandomAccessIterator				operator<=(const RandomAccessIterator &rhs) const;
		RandomAccessIterator				operator>=(const RandomAccessIterator &rhs) const;
		RandomAccessIterator				operator+=(int n) const;
		RandomAccessIterator				operator-=(int n) const;
		RandomAccessIterator				&operator[](int n) const;
	};

};

#endif
