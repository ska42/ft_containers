/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:27:20 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/30 02:51:01 by lmartin          ###   ########.fr       */
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
		typedef std::pair<const key_type,mapped_type>			value_type;
		typedef less<key_type>									key_compare;
		typedef Alloc											allocator_type;
		typedef T												&reference;
		typedef const T											&const_reference;
		typedef	T												*pointer;
		typedef	const T											*const_pointer;
		typedef ft::IteratorMap<T>								iterator;
		typedef ft::IteratorMap<const T>						const_iterator;
		typedef ft::ReverseIteratorMap<T>						reverse_iterator;
		typedef ft::ReverseIteratorMap<const T>					const_reverse_iterator;
		typedef typename ft::IteratorMap<T>::difference_type	difference_type;
		typedef size_t											size_type;


	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/map/map/value_comp                 */
	/* ********************************************************************** */

	class value_compare
	{

	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
  	friend class map;

	protected:
  		Compare comp;
  		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object

	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;

		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	}
	
	private:
		BinaryTreeMap<T>		*head;
		size_type				length;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */
		explicit Map (const key_compare &comp = key_compare(),
const allocator_type &alloc = allocator_type())
		{
			this->head = NULL;
			this->length = 0;
			return ;
		}

		~Map(void)
		{
			while (this->length)
				this->erase(iterator(this->head));
		}

		Map(const Map &map)
		{
			*this = map;
			return ;
		}

		Map						&operator=(const Map &map)
		{
			//TO COMPLETE
		}

		/* Non-Default Constructor */
		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
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
		bool					empty(void) const
		{
		}

		size_type				size(void) const
		{
		}

		size_type				max_size(void) const
		{
			// TO COMPLETE
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
