/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:00:52 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/28 22:04:44 by lmartin          ###   ########.fr       */
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
		explicit Vector (const allocator_type& alloc = allocator_type())
		{
		}

	};
};


#endif
