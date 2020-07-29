/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:27:20 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/29 07:18:33 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/map/map                            */
	/* ********************************************************************** */


	template <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> > >
	class Map
	{
	
	public:
	
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef pair<const key_type,mapped_type>				value_type;
		typedef less<key_type>									key_compare;
		typedef ???												value_compare;
value_compare	Nested function class to compare elements	see value_comp`
		typedef Alloc											allocator_type;
		typedef T												&reference;
		typedef const T											&const_reference;
		typedef	T												*pointer;
		typedef	const T											*const_pointer;
		typedef ft::IteratorList<T>								iterator;
		typedef ft::IteratorList<const T>						const_iterator;
		typedef ft::ReverseIteratorList<T>						reverse_iterator;
		typedef ft::ReverseIteratorList<const T>				const_reverse_iterator;
		typedef typename ft::IteratorList<T>::difference_type	difference_type;
		typedef size_t											size_type;
	
	private:


	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */
		explicit Map (const key_compare &comp = key_compare(),
const allocator_type &alloc = allocator_type())
		{
		}

		~Map(void)
		{
		}

		Map(const Map &map)
		{
		}

		Map						&operator=(const Map &map)
		{
		}

		/* Non-Default Constructor */
		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
		}

		Map (const Map &x)
		{
		}

		/* Iterators */
		iterator				begin(void)
		{
		}

		const_iterato			begin(void) const
		{
		}

     	iterato					end(void)
		{
		}

		const_iterato			end(void) const
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
		bool					empty(void) const
		{
		}

		size_type				size(void) const
		{
		}

		size_type				max_size(void) const
		{
		}

		/* Element access */
		mapped_type				&operator[](const key_type &k)
		{
		}

		/* Modifiers */
		pair<iterator, bool>	insert(const value_type &val)
		{
		}

		iterator				insert(iterator position, const value_type &val)
		{
		}

		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last)
		{
		}

		void					erase(iterator position)
		{
		}

		size_type				erase(const key_type &k)
		{
		}

		void					erase(iterator first, iterator last)
		{
		}

		void					swap(Map &x)
		{
		}

		void					clear(void)
		{
		}

		/* Observers */
		key_compare				key_comp(void) const
		{
		}

		value_compare			value_comp(void) const
		{
		}

		/* Operations */
		iterator				find(const key_type &k)
		{
		}

		const_iterator			find(const key_type &k) const
		{
		}

		size_type				count(const key_type &k) const
		{
		}

		iterator				lower_bound(const key_type &k)
		{
		}

		const_iterator			lower_bound(const key_type &k) const
		{
		}

		iterator				upper_bound(const key_type &k)
		{
		}

		const_iterator			upper_bound(const key_type &k) const
		{
		}

		pair<const_iterator,const_iterator>		equal_range(const key_type &k) const
		{
		}

		pair<iterator,iterator>					equal_range(const key_type &k)
		{
		}

	};

};

#endif
