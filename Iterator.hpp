/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 09:21:08 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/18 10:27:25 by lmartin          ###   ########.fr       */
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
		pointer								*ptr;

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef T							*pointer;
		typedef T							&reference;
		typedef random_access_iterator_tag	iterator_category;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
	
		/* Coplien form */
		~Iterator(void);
		Iterator(const Iterator &it);
		Iterator							&operator=(const Iterator &it);

		Iterator(pointer ptr);
		virtual Iterator					&operator++(void);
		virtual Iterator					operator++(int n);
		virtual bool						operator==(const Iterator &rhs);
		virtual bool						operator!=(const Iterator &rhs);
		virtual bool						operator!=(const Iterator &rhs);
		reference							operator*(void);

	};

};

#endif
