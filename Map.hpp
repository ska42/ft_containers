/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:27:20 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/04 23:21:00 by lmartin          ###   ########.fr       */
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
		typedef std::pair<const key_type,mapped_type>			value_type;
		typedef std::less<key_type>								key_compare;
		typedef Alloc											allocator_type;
		typedef T												&reference;
		typedef const T											&const_reference;
		typedef	T												*pointer;
		typedef	const T											*const_pointer;
		typedef ft::IteratorMap<Key, T>							iterator;
		typedef ft::IteratorMap<Key, const T>					const_iterator;
		typedef ft::ReverseIteratorMap<Key, T>					reverse_iterator;
		typedef ft::ReverseIteratorMap<Key, const T>			const_reverse_iterator;
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
		Compare						comp;
		BinaryTreeMap<Key, T>		*root;
		size_type					length;

		/* TEST PURPOSE */
		void	print_binary_tree(BinaryTreeMap<Key, T> *x, int n = 0)
		{
			int i;

			i = n;
			if (x->left)
				print_binary_tree(x->left, n + 1);
			while (i--)
				std::cout << "   ";
			std::cout << x->key;
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

		void	balance(BinaryTreeMap<Key, T> *branch)
		{
			BinaryTreeMap<Key, T>	*start;
			int						balance_factor;
			BinaryTreeMap<Key, T>	*grand_child;
			BinaryTreeMap<Key, T>	*root;

			start = branch;
			calcul_height(branch);
			grand_child = branch;
			root = (branch) ? branch->parent : NULL;
			while (root)
			{
				balance_factor = static_cast<int>(root->left_height - root->right_height);
				if (balance_factor > 1 || balance_factor < -1)
				{
					rebalance(balance_factor, grand_child);
					balance(branch);
				}
				grand_child = branch;
				branch = root;
				root = branch->parent;
			}
			calcul_height(start);
			balance_factor = static_cast<int>(this->root->left_height - this->root->right_height);
			if (balance_factor > 1 || balance_factor < -1)
				balance(start);
		}

		void	rebalance(int balance_factor, BinaryTreeMap<Key, T> *branch)
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

		void	remove_node(BinaryTreeMap<Key, T> *node)
		{
			BinaryTreeMap<Key, T>	*child;
			BinaryTreeMap<Key, T>	*to_balance;

			if (!node->left && !node->right)
			{
				// 0 CHILD
				if (node->parent && node->parent->left == node)
					node->parent->left = NULL;
				else if (node->parent && node->parent->right == node)
					node->parent->right = NULL;
				else
					this->root = NULL;
				to_balance = node->parent;
				delete (node);
			}
			else if (node->left && node->right)
			{
				BinaryTreeMap<Key, T>	*tmp;

				// 2 CHILD
				child = node->left;
				while (child->right)
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
				if (node->parent && node->parent->left == child)
					node->parent->left = node;
				else if (node->parent && node->parent->right == child)
					node->parent->right = node;
				else if (node->parent && node->parent == node)
				{
					node->parent = child;
					node->parent->left = node;
				}
				child->parent = tmp->parent;
				if (!child->parent)
					this->root = child;
				delete(tmp);
				remove_node(node);
			}
			else
			{
				// 1 CHILD
				child = (node->left) ? node->left : node->right;
				child->parent = node->parent;
				if (child->parent && child->parent->left == node)
					child->parent->left = child;
				else if (child->parent && child->parent->right == node)
					child->parent->right = child;
				else
					this->root = child;
				to_balance = child;
				delete(node);
			}
			if (to_balance)
				balance(to_balance);
		}

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien form */
		explicit Map (const key_compare &comp = key_compare(),
const allocator_type &alloc = allocator_type())
		{
			this->comp = comp;
			(void) alloc;
			this->root = NULL;
			this->length = 0;
			return ;
		}

		~Map(void)
		{
			// TO COMPLETE
		}

		Map(const Map &map)
		{
			*this = map;
			return ;
		}

		Map						&operator=(const Map &map)
		{
			//TO COMPLETE
			(void) map;
			return (*this);
		}

		/* Non-Default Constructor */
		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			this->comp = comp;
			(void) first;
			(void) last;
			(void) alloc;
		}

		/* Iterators */
		iterator				begin(void)
		{
			BinaryTreeMap<Key, T>		*node;

			node = root;
			while (node->left)
				node = node->left;
			return (iterator(node));
		}

		const_iterator			begin(void) const
		{
			BinaryTreeMap<Key, T>		*node;

			node = root;
			while (node->left)
				node = node->left;
			return (iterator(node));
		}

     	iterator				end(void)
		{
			BinaryTreeMap<Key, T>		*node;

			node = root;
			while (node->right)
				node = node->right;
			return (iterator(node));
		}

		const_iterator			end(void) const
		{
			BinaryTreeMap<Key, T>		*node;

			node = root;
			while (node->right)
				node = node->right;
			return (iterator(node));
		}

		reverse_iterator		rbegin(void)
		{
			BinaryTreeMap<Key, T>		*node;

			node = root;
			while (node->left)
				node = node->left;
			return (reverse_iterator(node));
		}

		const_reverse_iterator	rbegin(void) const
		{
			BinaryTreeMap<Key, T>		*node;

			node = root;
			while (node->left)
				node = node->left;
			return (reverse_iterator(node));
		}

		reverse_iterator		rend(void)
		{
			BinaryTreeMap<Key, T>		*node;

			node = root;
			while (node->right)
				node = node->right;
			return (reverse_iterator(node));
		}

		const_reverse_iterator	rend(void) const
		{
			BinaryTreeMap<Key, T>		*node;

			node = root;
			while (node->right)
				node = node->right;
			return (reverse_iterator(node));
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
			(void) k;	
		}

		/* Modifiers */
		std::pair<iterator, bool>	insert(const value_type &val)
		{
			BinaryTreeMap<Key, T>	*node;
			BinaryTreeMap<Key, T>	*new_node;

			std::cout << "INSERTING " << val.first << std::endl;
			new_node = new BinaryTreeMap<Key, T>();
			new_node->parent = NULL;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->key = val.first;
			new_node->value = val.second;
			new_node->left_height = 0;
			new_node->right_height = 0;
			if (this->root)
			{
				node = this->root;
				while (!new_node->parent)
				{
					if (new_node->key == node->key)
					{
						node->value = new_node->value;
						delete(new_node);
						return (std::pair<iterator, bool>(iterator(node), false));
					}
					if (this->comp(new_node->key, node->key))
					{
						if (node->left)
							node = node->left;
						else
						{
							node->left = new_node;
							new_node->parent = node;
						}
					}
					else
					{
						if (node->right)
							node = node->right;	
						else
						{
							node->right = new_node;
							new_node->parent = node;
						}
					}
				}
			}
			else
				this->root = new_node;
			std::cout << "BEFORE BALANCE " << std::endl;
			print_binary_tree(this->root);
			std::cout << "==============================" << std::endl;
			this->balance(new_node);
			std::cout << "AFTER BALANCE " << std::endl;
			print_binary_tree(this->root);
			std::cout << "==============================" << std::endl;
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
			new_node->key = val.first;
			new_node->value = val.second;
			new_node->left_height = 0;
			new_node->right_height = 0;
			if (this->root)
			{
				node = position.getPtr();
				while (!new_node->parent)
				{
					if (new_node->key == node->key)
					{
						node->value = new_node->value;
						delete(new_node);
						return (std::pair<iterator, bool>(iterator(node), false));
					}
					if (this->comp(new_node->key, node->key))
					{
						if (node->left)
							node = node->left;
						else
						{
							node->left = new_node;
							new_node->parent = node;
						}
					}
					else
					{
						if (node->right)
							node = node->right;	
						else
						{
							node->right = new_node;
							new_node->parent = node;
						}
					}
				}
			}
			else
				this->root = new_node;
			this->balance(new_node);
			this->length++;
			return (std::pair<iterator, bool>(iterator(new_node), true));
		}

		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(value_type(first.getPtr()->key, first.getPtr()->value));
				first++;
			}
		}

		void					erase(iterator position)
		{
			std::cout << "DELETE " << position.getPtr()->key << std::endl;
			remove_node(position.getPtr());
			this->length--;
			print_binary_tree(this->root);
		}

		size_type				erase(const key_type &k)
		{
			BinaryTreeMap<Key, T>	*node;

			if (this->root)
			{
				node = this->root;
				while (node)
				{
					if (k == node->key)
					{
						erase(iterator(node));
						return (1);
					}
					if (this->comp(k, node->key))
					{
						if (node->left)
							node = node->left;
						else
							return (0);
					}
					else
					{
						if (node->right)
							node = node->right;	
						else
							return (0);
					}
				}
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
			(void) x;
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
			(void) k;
		}

		const_iterator			find(const key_type &k) const
		{
			(void) k;
		}

		size_type				count(const key_type &k) const
		{
			(void) k;
		}

		iterator				lower_bound(const key_type &k)
		{
			(void) k;
		}

		const_iterator			lower_bound(const key_type &k) const
		{
			(void) k;
		}

		iterator				upper_bound(const key_type &k)
		{
			(void) k;
		}

		const_iterator			upper_bound(const key_type &k) const
		{
			(void) k;
		}

		std::pair<const_iterator,const_iterator>		equal_range(const key_type &k) const
		{
			(void) k;
		}

		std::pair<iterator,iterator>					equal_range(const key_type &k)
		{
			(void) k;
		}

	};

};

#endif
