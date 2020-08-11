/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:27:20 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/11 22:41:59 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>

# include <algorithm>
# include <functional>
# include "Iterator.hpp"

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/map/map                            */
	/* ********************************************************************** */

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class Map
	{
	
	public:
	
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef std::pair<const key_type, mapped_type>			value_type;
		typedef std::less<key_type>								key_compare;
		typedef Alloc											allocator_type;
		typedef T												&reference;
		typedef const T											&const_reference;
		typedef	T												*pointer;
		typedef	const T											*const_pointer;
		typedef ft::IteratorMap<Key, T>							iterator;
		typedef ft::ConstIteratorMap<Key, T>					const_iterator;
		typedef ft::ReverseIteratorMap<Key, T>					reverse_iterator;
		typedef ft::ConstReverseIteratorMap<Key, T>				const_reverse_iterator;
		typedef typename ft::IteratorMap<Key, T>::difference_type	difference_type;
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
	};

	private:
		/* TEST PURPOSE */
		void	print_binary_tree(BinaryTreeMap<Key, T> *x, int n = 0)
		{
			int i;

			i = n;
			if (x->left)
				print_binary_tree(x->left, n + 1);
			while (i--)
				std::cout << "   ";
			if (x == this->_end)
				std::cout << "E";
			else if (x == this->_start)
				std::cout << "S";
			else
				std::cout << x->pair.first;
			std::cout << std::endl;
			if (x->right)
				print_binary_tree(x->right, n + 1);
		}

	   /* ******************************************************************* */
	   /* references:                                                         */
	   /* https://www.programiz.com/dsa/avl-tree                              */
	   /* ******************************************************************* */

		/*
		**      p                p
		**      |                |
		**      x                y
		**     / \      =>      / \
		**    a   y            x   c
		**       / \          / \
		**      b   c        a   b
		*/
		void	left_rotate(BinaryTreeMap<Key, T> *x, BinaryTreeMap<Key, T> *y)
		{
			if (!x->parent)
				this->root = y;
			else if (x->parent->left == x)
				x->parent->left = y;
			else if (x->parent->right == x)
				x->parent->right = y;
			y->parent = x->parent;
			x->parent = y;
			if (y->left)
				y->left->parent = x;
			x->right = y->left;
			y->left = x;
			if (!x->right)
			{
				x->right_height = 0;
				calcul_height(x);
			}
			else
				calcul_height(x->right);
		}

		/*
		**          p           p
		**          |           |
		**          y           x
		**         / \    =>   / \
		**        x   c       a   y
		**       / \             / \
		**      a   b           b   c
		*/
		void	right_rotate(BinaryTreeMap<Key, T> *x, BinaryTreeMap<Key, T> *y)
		{
			if (!y->parent)
				this->root = x;
			else if (y->parent->left == y)
				y->parent->left = x;
			else if (y->parent->right == y)
				y->parent->right = x;
			x->parent = y->parent;
			y->parent = x;
			if (x->right)
				x->right->parent = y;
			y->left = x->right;
			x->right = y;
			if (!y->left)
			{
				y->left_height = 0;
				calcul_height(y);
			}
			else
				calcul_height(y->left);
		}

		void	left_right_rotate(BinaryTreeMap<Key, T> *x, BinaryTreeMap<Key, T> *y, BinaryTreeMap<Key, T> *z)
		{
			left_rotate(y, x);
			right_rotate(x, z);
		}

		void	right_left_rotate(BinaryTreeMap<Key, T> *x, BinaryTreeMap<Key, T> *y, BinaryTreeMap<Key, T> *z)
		{
			right_rotate(x, y);
			left_rotate(z, x);
		}

		void	calcul_height(BinaryTreeMap<Key, T> *branch)
		{
			BinaryTreeMap<Key, T>	*root;

			root = (branch) ? branch->parent : NULL;
			while (root)
			{
				if (root->left == branch)
					root->left_height = std::max<int>(branch->left_height, branch->right_height) + 1;
				else if (root->right == branch)
					root->right_height = std::max<int>(branch->left_height, branch->right_height) + 1;
				branch = root;
				root = branch->parent;
			}
		}

		void	balance(BinaryTreeMap<Key, T> *branch, int type)
		{
			BinaryTreeMap<Key, T>	*start;
			int						balance_factor;
			BinaryTreeMap<Key, T>	*grand_child;
			BinaryTreeMap<Key, T>	*root;

			start = branch;
			calcul_height(branch);
			grand_child = branch;
			root = (branch && branch->parent) ? branch->parent : branch;
			while (root)
			{
				balance_factor = static_cast<int>(root->left_height - root->right_height);
				if (balance_factor > 1 || balance_factor < -1)
				{
					rebalance(balance_factor, grand_child, type);
					balance(branch, type);
				}
				grand_child = branch;
				branch = root;
				root = branch->parent;
			}
			calcul_height(start);
			balance_factor = static_cast<int>(this->root->left_height - this->root->right_height);
			if (balance_factor > 1 || balance_factor < -1)
				balance(start, type);
		}

		void	rebalance(int balance_factor, BinaryTreeMap<Key, T> *branch, int type)
		{
			if (type == 0) // INSERTION
			{
				if (balance_factor > 1)
				{
					if (branch == branch->parent->left)
						right_rotate(branch, branch->parent);
					else if (branch == branch->parent->right)
						left_right_rotate(branch, branch->parent, branch->parent->parent);
				}
				else if (balance_factor < 1)
				{
					if (branch == branch->parent->right)	
						left_rotate(branch->parent, branch);
					else if (branch == branch->parent->left)
						right_left_rotate(branch, branch->parent, branch->parent->parent);
				}
			}
			else if (type == 1) // DELETION
			{
				int		balance_factor2;

				if (balance_factor > 1)
				{
					balance_factor2 = static_cast<int>(branch->left->left_height - branch->left->right_height);
					if (balance_factor2 >= 0)
						right_rotate(branch->left, branch);
					else
						left_right_rotate(branch->left, branch, branch->parent);
				}
				else if (balance_factor < -1)
				{
					balance_factor2 = static_cast<int>(branch->right->left_height - branch->right->right_height);
					if (balance_factor2 <= 0)
						left_rotate(branch, branch->right);
					else 
						right_left_rotate(branch->right, branch, branch->parent);
				}
			}
		}

		/* ****************************************************************** */
		/* references:                                                        */
		/* https://www.youtube.com/watch?v=cySVml6e_Fc                        */
		/* ****************************************************************** */

		void	remove_node(BinaryTreeMap<Key, T> *node)
		{
			BinaryTreeMap<Key, T>	*child;
			BinaryTreeMap<Key, T>	*to_balance;

			if ((!node->left || node->left == this->_start) && (!node->right || node->right == this->_end))
			{
				// 0 CHILD
				if (node->parent && node->parent->left == node)
				{
					if (node->left == this->_start)
						node->parent->left = this->_start;
					else
						node->parent->left = NULL;
				}
				else if (node->parent && node->parent->right == node)
				{
					if (node->right == this->_end)
						node->parent->right = this->_end;
					else
						node->parent->right = NULL;
				}
				else
				{
					this->root = this->_end;
					this->root->left = this->_start;
					this->_start->parent = this->root;
				}
				to_balance = node->parent;
				delete (node);
			}
			else if (node->left && node->left != this->_start && node->right && node->right != this->_end)
			{
				// 2 CHILD
				BinaryTreeMap<Key, T>	*tmp;

				to_balance = NULL;
				child = node->left;
				while (child->right && child->right != this->_end)
					child = child->right;
				tmp = new BinaryTreeMap<Key, T>();
				tmp->parent = node->parent;
				tmp->left = node->left;
				tmp->right = node->right;
				tmp->left_height = node->left_height;
				tmp->right_height = node->right_height;
				node->parent = child->parent;
				node->left = child->left;
				node->right = child->right;
				node->left_height = child->left_height;
				node->right_height = child->right_height;
				if (node->left)
					node->left->parent = node;
				if (node->right)
					node->right->parent = node;
				if (node->parent == node)
				{
					node->parent = child;
					node->parent->left = node;
				}
				else if (node->parent->left == child)
					node->parent->left = node;
				else if (node->parent->right == child)
					node->parent->right = node;
				child->parent = tmp->parent;
				if (!child->parent)
					this->root = child;
				else if (child->parent->left == node)
					child->parent->left = child;
				else if (child->parent->right == node)
					child->parent->right = child;
				child->left = tmp->left;
				child->right = tmp->right;
				child->left_height = tmp->left_height;
				child->right_height = tmp->right_height;
				if (child->left == child)
					child->left = node;
				else if (child->right == child)
					child->right = node;
				if (child->left)
					child->left->parent = child;
				if (child->right)
					child->right->parent = child;
				delete(tmp);
				remove_node(node);
			}
			else
			{
				// 1 CHILD
				child = (node->left && node->left != this->_start) ? node->left : node->right;
				child->parent = node->parent;
				if (!child->parent)
					this->root = child;
				else if (child->parent->left == node)
					child->parent->left = child;
				else if (child->parent->right == node)
					child->parent->right = child;
				to_balance = (child->parent) ? child->parent : child;
				calcul_height(child);
				if (node->left == this->_start)
					child->left = this->_start;
				delete(node);
			}
			if (to_balance)
				balance(to_balance, 1);
		}

		allocator_type				alloc;
		key_compare					comp;
		BinaryTreeMap<Key, T>		*root;
		BinaryTreeMap<Key, T>		*_start;
		BinaryTreeMap<Key, T>		*_end;
		size_type					length;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */
		explicit Map(const key_compare &comp = key_compare(),
const allocator_type &alloc = allocator_type())
		{
			this->comp = comp;
			this->alloc = alloc;
			this->_start = new BinaryTreeMap<Key, T>();
			this->_start->left = NULL;
			this->_start->right = NULL;
			this->_end = new BinaryTreeMap<Key, T>();
			this->_end->left = this->_start;
			this->_start->parent = this->_end;
			this->_end->right = NULL;
			this->_end->parent = NULL;
			this->root = this->_end;
			this->length = 0;
			return ;
		}

		~Map(void)
		{
			this->clear();
			delete(this->_end);
			delete(this->_start);
			return ;
		}

		Map(const Map &map)
		{
			*this = map;
			return ;
		}

		Map						&operator=(const Map &map)
		{
			this->comp = map.comp;
			this->alloc = map.alloc;
			this->_start = new BinaryTreeMap<Key, T>();
			this->_start->left = NULL;
			this->_start->right = NULL;
			this->_end = new BinaryTreeMap<Key, T>();
			this->_end->left = this->_start;
			this->_start->parent = this->_end;
			this->_end->right = NULL;
			this->_end->parent = NULL;
			this->root = this->_end;
			this->length = 0;
			this->insert(map.begin(), map.end());
			return (*this);
		}

		/* Non-Default Constructor */
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			this->comp = comp;
			this->alloc = alloc;
			this->_start = new BinaryTreeMap<Key, T>();
			this->_start->left = NULL;
			this->_start->right = NULL;
			this->_end = new BinaryTreeMap<Key, T>();
			this->_end->left = this->_start;
			this->_start->parent = this->_end;
			this->_end->right = NULL;
			this->_end->parent = NULL;
			this->root = this->_end;
			this->length = 0;
			this->insert(first, last);
		}

		/* Iterators */
		iterator				begin(void)
		{
			BinaryTreeMap<Key, T>		*node;

			node = this->root;
			while (node->left && node->left != this->_start)
				node = node->left;
			return (iterator(node));
		}

		const_iterator			begin(void) const
		{
			BinaryTreeMap<Key, T>		*node;

			node = this->root;
			while (node->left && node->left != this->_start)
				node = node->left;
			return (iterator(node));
		}

     	iterator				end(void)
		{
			return (iterator(this->_end));
		}

		const_iterator			end(void) const
		{
			return (iterator(this->_end));
		}

		reverse_iterator		rbegin(void)
		{
			BinaryTreeMap<Key, T>		*node;

			node = this->root;
			while (node->right && node->right != this->_end)
				node = node->right;
			return (reverse_iterator(node));
		}

		const_reverse_iterator	rbegin(void) const
		{
			BinaryTreeMap<Key, T>		*node;

			node = this->root;
			while (node->right && node->right != this->_end)
				node = node->right;
			return (reverse_iterator(node));
		}

		reverse_iterator		rend(void)
		{
			return (reverse_iterator(this->_start));
		}

		const_reverse_iterator	rend(void) const
		{
			return (reverse_iterator(this->_start));
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
			// TO COMPLETE
		}

		/* Element access */
		mapped_type				&operator[](const key_type &k)
		{
			BinaryTreeMap<Key, T>	*node;

			node = this->root;
			while (node && node != this->_end && node != this->_start)
			{
				if (k == node->pair.first)
					return (node->pair.second);
				if (this->comp(k, node->pair.first))
				{
					if (node->left)
						node = node->left;
					else
						insert(iterator(node), value_type(k, 0));
				}
				else
				{
					if (node->right)
						node = node->right;	
					else
						insert(iterator(node), value_type(k, 0));
				}
			}
			insert(value_type(k, 0));
			return (this->root->pair.second);
		}

		/* Modifiers */
		std::pair<iterator, bool>	insert(const value_type &val)
		{
			BinaryTreeMap<Key, T>	*node;
			BinaryTreeMap<Key, T>	*new_node;

			new_node = new BinaryTreeMap<Key, T>();
			new_node->parent = NULL;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->pair = val;
			new_node->left_height = 0;
			new_node->right_height = 0;
			if (this->root != this->_end)
			{
				node = this->root;
				while (!new_node->parent)
				{
					if (new_node->pair.first == node->pair.first)
					{
						node->pair.second = new_node->pair.second;
						delete(new_node);
						return (std::pair<iterator, bool>(iterator(node), false));
					}
					if (this->comp(new_node->pair.first, node->pair.first))
					{
						if (node->left && node->left != this->_start)
							node = node->left;
						else
						{
							if (node->left == this->_start)
								this->_start->parent = new_node;
							node->left = new_node;
							new_node->parent = node;
							if (this->_start->parent == new_node)
								new_node->left = this->_start;
						}
					}
					else
					{
						if (node->right && node->right != this->_end)
							node = node->right;	
						else
						{
							if (node->right == this->_end)
								this->_end->parent = new_node;
							node->right = new_node;
							new_node->parent = node;
							if (this->_end->parent == new_node)
								new_node->right = this->_end;
						}
					}
				}
			}
			else
			{
				this->root = new_node;
				this->root->right = this->_end;
				this->root->left = this->_start;
				this->_end->parent = this->root;
				this->_end->left = NULL;
				this->_end->right = NULL;
				this->_start->parent = this->root;
			}
			this->balance(new_node, 0);
			this->length++;
			return (std::pair<iterator, bool>(iterator(new_node), true));
		}

		iterator				insert(iterator position, const value_type &val)
		{
			BinaryTreeMap<Key, T>	*node;
			BinaryTreeMap<Key, T>	*new_node;

			new_node = new BinaryTreeMap<Key, T>();
			new_node->parent = NULL;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->pair = val;
			new_node->left_height = 0;
			new_node->right_height = 0;
			if (this->root != this->_end)
			{
				node = position.getPtr();
				while (!new_node->parent)
				{
					if (new_node->pair.first == node->pair.first)
					{
						node->pair.second = new_node->pair.second;
						delete(new_node);
						return (iterator(node));
					}
					if (this->comp(new_node->pair.first, node->pair.second))
					{
						if (node->left && node->left != this->_start)
							node = node->left;
						else
						{
							if (node->left == this->_start)
								this->_start->parent = new_node;
							node->left = new_node;
							new_node->parent = node;
							if (this->_start->parent == new_node)
								new_node->left = this->_start;
						}
					}
					else
					{
						if (node->right && node->right != this->_end)
							node = node->right;	
						else
						{
							if (node->right == this->_end)
								this->_end->parent = new_node;
							node->right = new_node;
							new_node->parent = node;
							if (this->_end->parent == new_node)
								new_node->right = this->_end;
						}
					}
				}
			}
			else
			{
				this->root = new_node;
				this->root->right = this->_end;
				this->root->left = this->_start;
				this->_end->parent = this->root;
				this->_end->left = NULL;
				this->_end->right = NULL;
				this->_start->parent = this->root;
			}
			this->balance(new_node, 0);
			this->length++;
			return (iterator(new_node));
		}

		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		void					erase(iterator position)
		{
			remove_node(position.getPtr());
			this->length--;
		}

		size_type				erase(const key_type &k)
		{
			BinaryTreeMap<Key, T>	*node;

			node = this->root;
			while (node && node != this->_end && node != this->_start)
			{
				if (k == node->pair.first)
				{
					erase(iterator(node));
					return (1);
				}
				if (this->comp(k, node->pair.first))
					node = node->left;
				else
					node = node->right;	
			}
			return (0);
		}

		void					erase(iterator first, iterator last)
		{
			iterator next;

			while (first != last)
			{
				next = first;
				next++;
				erase(first);
				first = next;
			}
		}

		void					swap(Map &x)
		{
			BinaryTreeMap <Key, T>	*tmp;
			size_type				length;

			tmp = this->root;
			this->root = x.root;
			x.root = tmp;
			tmp = this->_end;
			this->_end = x._end;
			x._end = tmp;
			tmp = this->_start;
			this->_start = x._start;
			x._start = tmp;
			length = this->length;
			this->length = x.length;
			x.length = length;
		}

		void					clear(void)
		{
			erase(this->begin(), this->end());
		}

		/* Observers */
		key_compare				key_comp(void) const
		{
			return (this->comp);
		}

		value_compare			value_comp(void) const
		{
			return (this->value_compare);
		}

		/* Operations */
		iterator				find(const key_type &k)
		{
			BinaryTreeMap <Key, T>	*node;

			node = this->root;
			while (node && node != this->_end && node != this->_start)
			{
				if (k == node->pair.first)
					return (iterator(node));
				if (this->comp(k, node->pair.first))
					node = node->left;
				else
					node = node->right;
			}
			return (this->end());
		}

		const_iterator			find(const key_type &k) const
		{			
			BinaryTreeMap <Key, T>	*node;

			node = this->root;
			while (node && node != this->_end && node != this->_start)
			{
				if (k == node->pair.first)
					return (const_iterator(node));
				if (this->comp(k, node->pair.first))
					node = node->left;
				else
					node = node->right;
			}
			return (this->end());
		}

		size_type				count(const key_type &k) const
		{
			return ((find(k) == this->end()));
		}

		iterator				lower_bound(const key_type &k)
		{
			iterator it = this->begin();
			iterator it2 = this->end();

			while (it != it2) {
				if (!this->key_comp()(*it.first, k))
					return (iterator(it));
				++it;
			}
			return (this->end());
		}

		const_iterator			lower_bound(const key_type &k) const
		{
			const_iterator it = this->begin();
			const_iterator it2 = this->end();

			while (it != it2) {
				if (!this->key_comp()(*it.first, k))
					return (const_iterator(it));
				++it;
			}
			return (this->end());
		}

		iterator				upper_bound(const key_type &k)
		{
			iterator it = this->begin();
			iterator it2 = this->end();

			while (it != it2) {
				if (this->key_comp()(*it.first, k))
					return (iterator(it));
				++it;
			}
			return (this->end());
		}

		const_iterator			upper_bound(const key_type &k) const
		{
			const_iterator it = this->begin();
			const_iterator it2 = this->end();

			while (it != it2) {
				if (this->key_comp()(*it.first, k))
					return (const_iterator(it));
				++it;
			}
			return (this->end());
		}

		std::pair<const_iterator,const_iterator>		equal_range(const key_type &k) const
		{
			return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		}

		std::pair<iterator,iterator>					equal_range(const key_type &k)
		{
			return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		}

	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

	/* Function overloads */
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		typename Map<Key, T, Compare, Alloc>::const_iterator	it = lhs.begin();
		size_t				i;

		if (lhs.size() != rhs.size())
			return (false);
		i = 0;
		while (i < lhs.size())
		{
			typename Map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.find(it->first);
			if (it2 == rhs.end())
				return (false);
			if (it2->first != it->first && it2->second != it->second)
				return (false);
			it++;
			i++;
		}
		return (true);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{	
		typename Map<Key, T, Compare, Alloc>::const_iterator	it = rhs.begin();
		size_t				n;
		size_t				i;

		if (lhs.size() > rhs.size())
			n = rhs.size();
		else
		{
			it = lhs.begin();
			n = lhs.size();
		}
		i = 0;
		while (i < n)
		{
			if (lhs.size() > rhs.size())
			{
				typename Map<Key, T, Compare, Alloc>::const_iterator it2 = lhs.find(it->first);
				if (it2 == lhs.end())
					return (true);
				if (it->first != it2->first)
					return (it2->first < it->first);
				if (it->second != it2->second)
					return (it2->second < it->second);
			}
			else
			{
				typename Map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.find(it->first);
				if (it2 == rhs.end())
					return (false);
				if (it->first != it2->first)
					return (it->first < it2->first);
				if (it->second != it2->second)
					return (it->second < it2->second);
			}
			it++;
			i++;
		}
		return (lhs.size() < rhs.size());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{	
		return (!(lhs < rhs) && !(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::Map<Key, T, Compare, Alloc> &lhs, const ft::Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::Map<Key, T, Compare, Alloc> &x, ft::Map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	}

};

#endif
