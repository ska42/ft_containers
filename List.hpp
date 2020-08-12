/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 04:01:16 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/12 05:01:06 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include <memory>
# include "IteratorList.hpp"

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/list/list                          */
	/* ********************************************************************** */

	template <class T, class Alloc = std::allocator<T> >
	class List
	{
	
	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef T												&reference;
		typedef const T											&const_reference;
		typedef	T												*pointer;
		typedef	const T											*const_pointer;
		typedef ft::IteratorList<T>								iterator;
		typedef ft::ConstIteratorList<T>						const_iterator;
		typedef ft::ReverseIteratorList<T>						reverse_iterator;
		typedef ft::ConstReverseIteratorList<T>					const_reverse_iterator;
		typedef typename ft::IteratorList<T>::difference_type	difference_type;
		typedef size_t											size_type;

	private:
		DoublyLinkedList<T>			*head;
		DoublyLinkedList<T>			*tail;
		DoublyLinkedList<T>			*_start;
		DoublyLinkedList<T>			*_end;
		allocator_type				alloc;
		size_type					length;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */
		explicit List (const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->_start = new DoublyLinkedList<T>();
			this->_start->prev = NULL;
			this->_end = new DoublyLinkedList<T>();
			this->_end->next = NULL;
			this->_start->next = _end;
			this->_end->prev = _start;
			this->head = this->_end;
			this->tail = this->_end;
			this->length = 0;
			return ;
		}

		~List(void)
		{
			this->clear();
			delete(this->_start);
			delete(this->_end);
			return ;
		}

		List(const List &list)
		{
			this->_start = new DoublyLinkedList<T>();
			this->_end = new DoublyLinkedList<T>();
			this->_end->next = NULL;
			this->_start->prev = NULL;
			this->_start->next = _end;
			this->_end->prev = _start;
			this->head = this->_end;
			this->tail = this->_end;
			this->length = 0;
			*this = list;
			return ;
		}

		List					&operator=(const List &list)
		{
			DoublyLinkedList<T>		*tmp;

			this->clear();
			this->alloc = list.alloc;
			this->length = 0;
			if (list.length)
			{
				tmp = list.head;
				while (tmp != list._end)
				{
					this->push_back(*tmp->element);
					tmp = tmp->next;
				}
			}
			return (*this);
		}

		/* Non-Default Constructor */
		explicit List (size_type n, const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type())
		{
			this->alloc = alloc;
			this->_start = new DoublyLinkedList<T>();
			this->_start->prev = NULL;
			this->_end = new DoublyLinkedList<T>();
			this->_end->next = NULL;
			this->_start->next = _end;
			this->_end->prev = _start;
			this->head = this->_end;
			this->tail = this->_end;
			this->length = 0;
			assign(n, val);
		}
		
		template <class InputIterator>
  		List (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->_start = new DoublyLinkedList<T>();
			this->_start->prev = NULL;
			this->_end = new DoublyLinkedList<T>();
			this->_end->next = NULL;
			this->_start->next = _end;
			this->_end->prev = _start;
			this->head = this->_end;
			this->tail = this->_end;
			this->length = 0;
			assign(static_cast<InputIterator>(first), static_cast<InputIterator>(last));
		}

		/* Iterators */
		iterator				begin(void)
		{
			return (iterator(this->head));
		}

		const_iterator			begin(void) const
		{
			return (const_iterator((this->head)));
		}

		iterator				end(void)
		{
			return (iterator(this->_end));
		}

		const_iterator			end(void) const
		{
			return (const_iterator(this->_end));
		}

		reverse_iterator		rbegin(void)
		{
			return (reverse_iterator(this->tail));
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(this->tail));
		}

		reverse_iterator		rend(void)
		{
			return (reverse_iterator(this->_start));
		}

		const_reverse_iterator	rend(void) const
		{
			return (const_reverse_iterator(this->_start));
		}

		/* Capacity */
		bool					empty(void) const
		{
			return (!this->length);
		}

		size_type				size(void) const
		{
			return (this->length);
		}

		size_type				max_size(void) const
		{
			return (std::numeric_limits<size_type>::max()/sizeof(this->head));
		}

		/* Element access */
		reference				front(void)
		{
			return (*this->head->element);
		}

		const_reference			front(void) const
		{
			return (*this->head->element);
		}

		reference				back(void)
		{
			return (*this->tail->element);
		}

		const_reference			back(void) const
		{
			return (*this->tail->element);
		}

		/* Modifiers */
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last)
		{
			this->clear();
			while (first != last)
			{
				this->push_back(*first);
				first++;
			}
		}

		void					assign(size_type n, const value_type &val)
		{
			this->clear();	
			while (n--)
				this->push_back(val);
		}

		void					push_front(const value_type &val)
		{
			DoublyLinkedList <T>	*ptr = new DoublyLinkedList<T>;

			ptr->next = NULL;
			this->_start->next = ptr;
			ptr->prev = this->_start;
			ptr->element = this->alloc.allocate(1);
			this->alloc.construct(ptr->element, val);
			if (!this->length)
			{
				this->tail = this->head = ptr;
				this->_end->prev = this->tail;
				this->tail->next = this->_end;
			}
			else
			{
				this->head->prev = ptr;
				ptr->next = this->head;
				this->head = ptr;
			}
			this->length++;
		}

		void					pop_front(void)
		{
			if (this->length)
			{
				if (this->length == 1)
				{
					this->alloc.destroy(this->head->element);
					this->alloc.deallocate(this->head->element, 1);
					delete(this->head);
					this->_end->prev = this->_start;
					this->_start->next = this->_end;
					this->tail = this->head = this->_end;
				}
				else
				{
					this->head = this->head->next;
					this->alloc.destroy(this->head->prev->element);
					this->alloc.deallocate(this->head->prev->element, 1);
					delete(this->head->prev);
					this->head->prev = this->_start;
					this->_start->next = this->head;
				}
				this->length--;
			}
		}

		void					push_back(const value_type &val)
		{
			DoublyLinkedList <T>	*ptr = new DoublyLinkedList<T>;

			ptr->next = this->_end;
			this->_end->prev = ptr;
			ptr->prev = NULL;
			ptr->element = this->alloc.allocate(1);
			this->alloc.construct(ptr->element, val);
			if (!this->length)
			{
				this->head = this->tail = ptr;
				this->_start->next = this->head;
				this->head->prev = this->_start;
			}
			else
			{
				this->tail->next = ptr;
				ptr->prev = this->tail;
				this->tail = this->tail->next;
			}
			this->length++;
		}

		void					pop_back(void)
		{
			if (this->length)
			{
				if (this->length == 1)
				{
					this->alloc.destroy(this->tail->element);
					this->alloc.deallocate(this->tail->element, 1);
					delete(this->tail);
					this->_end->prev = this->_start;
					this->_start->next = this->_end;
					this->head = this->tail = this->_end;
				}
				else
				{
					this->tail = this->tail->prev;
					this->alloc.destroy(this->tail->next->element);
					this->alloc.deallocate(this->tail->next->element, 1);
					delete(this->tail->next);
					this->tail->next = this->_end;
					this->_end->prev = this->tail;
				}
				this->length--;
			}
		}

		iterator				insert(iterator position, const value_type &val)
		{
			DoublyLinkedList<T>		*add;
			DoublyLinkedList<T>		*ptr;
			
			add = new DoublyLinkedList<T>;
			add->next = NULL;
			add->prev = NULL;
			add->element = this->alloc.allocate(1);
			this->alloc.construct(add->element, val);	
			ptr = position.getPtr();
			if (ptr->prev == this->_start)
			{
				add->prev = this->_start;
				this->_start->next = add;
				if (!this->length)
				{
					this->tail = this->head = add;
					add->next = this->_end;
					this->_end->prev = add;
				}
				else
				{
					this->head->prev = add;
					add->next = this->head;
					this->head = add;
				}
			}
			else if (!ptr->next)
			{
				add->next = this->_end;
				this->_end->prev = add;
				if (!this->length)
				{
					this->head = this->tail = add;
					add->prev = this->_start;
					this->_start->next = add;
				}
				else
				{
					this->tail->next = add;
					add->prev = this->tail;
					this->tail = this->tail->next;
				}
			}
			else
			{
				add->prev = ptr->prev;
				if (ptr->prev)
					ptr->prev->next = add;
				add->next = ptr;
				ptr->prev = add;
			}
			this->length++;
			return (iterator(add));
		}

		void					insert(iterator position, size_type n, const value_type &val)
		{
			while (n--)
				this->insert(position, val);
		}

		template <class InputIterator>
		void					insert(iterator position, InputIterator first, InputIterator last)
		{
			for (InputIterator it = first; it != last; it++)
				this->insert(position, *it);
		}

		iterator				erase(iterator position)
		{
			DoublyLinkedList<T>		*next;
			DoublyLinkedList<T>		*ptr;

			if (position == this->end())
				return (this->end());
			ptr = position.getPtr();
			if (ptr == this->_start)
				return (iterator(this->_start));
			if (ptr->prev == this->_start)
			{
				this->head = ptr->next;
				this->head->prev = this->_start;
				this->_start->next = this->head;
			}
			else
				ptr->prev->next = ptr->next;
			if (ptr->next == this->_end)
			{
				if (ptr->prev != this->_start)
				{
					this->tail = ptr->prev;
					this->tail->next = this->_end;
					this->_end->prev = this->tail;
				}
				else
					this->tail = this->_end;
			}
			else
				ptr->next->prev = ptr->prev;
			next = ptr->next;
			this->alloc.destroy(ptr->element);
			this->alloc.deallocate(ptr->element, 1);
			delete(ptr);
			this->length--;
			return (iterator(next));
		}

		iterator				erase(iterator first, iterator last)
		{
			iterator tmp;
		
			while (first != last)
			{
				tmp = first;
				first++;
				this->erase(tmp);
			}
			return (iterator(this->head));
		}

		void					swap(List &x)
		{
			DoublyLinkedList<T>	*tmp;
			size_type			tmp_length;
			
			tmp = x.head;
			x.head = this->head;
			this->head = tmp;
			tmp = x.tail;
			x.tail = this->tail;
			this->tail = tmp;
			tmp = x._end;
			x._end = this->_end;
			this->_end = tmp;
			tmp_length = x.length;
			x.length = this->length;
			this->length = tmp_length;
		}

		void					resize(size_type n, value_type val = value_type())
		{
			while (this->length > n)
				this->pop_back();
			while (this->length < n)
				this->push_back(val);
		}

		void					clear(void)
		{
			while (this->length)
				this->pop_back();
		}

		/* Operations */
		void					splice(iterator position, List &x)
		{
			this->insert(position, x.begin(), x.end());
			x.clear();
		}

		void					splice(iterator position, List &x, iterator i)
		{
			this->insert(position, *i);
			x.erase(i);
		}

		void					splice(iterator position, List &x, iterator first, iterator last)
		{
			this->insert(position, first, last);
			x.erase(first, last);
		}

		void					remove(const value_type &val)
		{
			iterator	it;
			iterator	tmp;
			
			if (this->length)
			{
				it = this->begin();
				while (it != this->end())
				{
					tmp = it;
					it++;
					if (*tmp == val)
						this->erase(tmp);
				}
			}
		}

		template <class Predicate>
		void					remove_if(Predicate pred)
		{
			iterator	it;
			iterator	tmp;
			
			if (this->length)
			{
				it = this->begin();
				while (it != this->end())
				{
					tmp = it;
					it++;
					if (pred(*tmp))
						this->erase(tmp);
				}
			}
		}

		void					unique(void)
		{
			iterator 	it;
			iterator	it2;
			iterator 	tmp;

			it = this->begin();	
			while (it != this->end())
			{
				it2 = it;
				tmp = it2;
				it2++;
				while (it2 != this->end())
				{
					if (*it2 == *it)
					{
						this->erase(it2);
						it2 = tmp;
					}
					tmp = it2;
					it2++;
				}
				it++;
			}
		}

		template <class BinaryPredicate>
		void					unique(BinaryPredicate binary_pred)
		{
			iterator 	it;
			iterator	it2;
			iterator 	tmp;

			it = iterator(this->head);	
			while (it != this->end())
			{
				it2 = it;
				tmp = it2;
				it2++;
				while (it2 != this->end())
				{
					if (binary_pred(*it2, *it))
					{
						this->erase(it2);
						it2 = tmp;
					}
					tmp = it2;
					it2++;
				}
				it++;
			}
		}

		void					merge(List &x)
		{
			size_type	size;
			iterator	it;
			iterator	itx;
			iterator	next;

			size = this->length;
			if (size)
				it = this->begin();
			if (x.length)
				itx = x.begin();
			while (x.length)
			{
				while (size && (it != this->end()) && !(*itx < *it))
					it++;
				next = itx;
				if (x.length != 1)
					next++;
				if (size && it != this->end())
					splice(it, x, itx);
				else
				{
					this->push_back(*itx);
					x.erase(itx);
				}
				itx = next;
			}
		}

		template <class Compare>
		void					merge(List &x, Compare comp)
		{
			size_type	size;
			iterator	it;
			iterator	itx;
			iterator	next;

			size = this->length;
			if (size)
				it = this->begin();
			if (x.length)
				itx = x.begin();
			while (x.length)
			{
				while (size && (it != this->end()) && comp(*itx, *it))
					it++;
				next = itx;
				if (x.length != 1)
					next++;
				if (size && it != this->end())
					splice(it, x, itx);
				else
				{
					this->push_back(*itx);
					x.erase(itx);
				}
				itx = next;
			}
		}

		void					sort(void)
		{
			size_type	size;
			iterator 	it;
			iterator 	it2;

			size = this->length;
			while (size--)
			{
				it = this->begin();
				it2 = it;
				it2++;
				while (it2 != this->end())
				{
					if (*it2 < *it)
						this->splice(it, *this, it2);
					else
						it++;
					it2 = it;
					it2++;
				}
			}
		}

		template <class Compare>
		void					sort(Compare comp)
		{
			size_type	size;
			iterator 	it;
			iterator 	it2;

			size = this->length;
			while (size--)
			{
				it = this->begin();
				it2 = it;
				it2++;
				while (it2 != this->end())
				{
					if (comp(*it2, *it))
						this->splice(it, *this, it2);
					else
						it++;
					it2 = it;
					it2++;
				}
			}
		}

		void					reverse(void)
		{
			size_type	n;
			iterator	it;

			if (this->length)
			{
				n = this->length - 1;
				it = this->begin();
				while (n--)
					this->splice(it, *this, iterator(this->tail));
			}
		}
		
	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

	/* Function overloads */
	template <class T, class Alloc>
	bool						operator==(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		typename List<T, Alloc>::const_iterator		it = lhs.begin();
		typename List<T, Alloc>::const_iterator		it2 = rhs.begin();
		size_t				i;

		if (lhs.size() != rhs.size())
			return (false);
		i = 0;
		while (i < lhs.size())
		{
			if (*it != *it2)
				return (false);
			it++;
			it2++;
			i++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool						operator!=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool						operator<(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		typename List<T, Alloc>::const_iterator		it = lhs.begin();
		typename List<T, Alloc>::const_iterator		it2 = rhs.begin();
		size_t				n;
		size_t				i;

		if (lhs.size() > rhs.size())
			n = rhs.size();
		else
			n = lhs.size();
		i = 0;
		while (i < n)
		{
			if (*it != *it2)
				return (*it < *it2);
			it++;
			it2++;
			i++;
		}
		return (lhs.size() < rhs.size());
	}

	template <class T, class Alloc>
	bool						operator<=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	bool						operator>(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (!(lhs < rhs) && !(lhs == rhs));
	}

	template <class T, class Alloc>
	bool						operator>=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void						swap(List<T, Alloc> &x, List <T, Alloc> &y)
	{
		x.swap(y);
	}
}

#endif
