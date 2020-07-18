/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 04:01:16 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/18 04:40:25 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

namespace ft
{
	/* ********************************************* */
	/* references:                                   */
	/* https://www.cplusplus.com/reference/list/list */
	/* ********************************************* */
	template <class T, class Alloc = allocator<T>>
	class List
	{

	private:
		

	public:
		/* Coplien form */
		List(void);
		~List(void);
		List(const List &list);
		List					&operator=(const List &list);

		/* Iterators */
		iterator				begin(void);
		const_iterator			begin(void) const;	
		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;

		/* Capacity */
		bool					empty(void) const;
		size_type				size(void) const;
		size_type				max_size(void) const;

		/* Element access */
		reference				front(void);
		const_reference			front(void) const;
		reference				back(void);
		const_reference			back(void) const;

		/* Modifiers */
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const value_type& val);
		void					push_front(const value_type &val);
		void					pop_front(void);
		void					push_back(const value_type &val);
		void					pop_back(void);
		iterator				insert(iterator position, const value_type &val);
		void					insert(iterator position, size_type n, const value_type &val);
		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(list &x);
		void					resize(size_type n, value_type val = value_type());
		void					clear(void);

		/* Operations */
		void					splice(iterator position, list &x);
		void					splice(iterator position, list &x, iterator i);
		void					splice(iterator position, list &x, iterator first, iterator last);
		void					remove(const value_type &val);
		template <class Predicate>
		void					remove_if(Predicate pred);
		void					unique(void);
		template <class BinaryPredicate>
		void					unique(BinaryPredicate binary_pred);
		void					merge(list &x);
		template <class Compare>
		void					merge(list &x, Compare comp);
		void					sort(void);
		template <class Compare>
		void					sort(Compare comp);
		void					reverse(void);

		/* Observers */
		allocator_type			get_allocator const;
		
	};

	/* Function overloads */
	template <class T, class Alloc>
	bool						operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool						operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs);
	template <class T, class Alloc>
	void						swap(list<T, Alloc> &x, list <T, Alloc> &y);
}

#endif
