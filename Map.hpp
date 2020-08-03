/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:27:20 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/03 22:34:50 by lmartin          ###   ########.fr       */
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
					rebalance(balance_factor, grand_child);
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
			return (std::pair<iterator, bool>(iterator(new_node), true));
		}

		iterator				insert(iterator position, const value_type &val)
		{
			(void) position;
			(void) val;
		}

		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last)
		{
			(void) first;
			(void) last;
		}

		void					erase(iterator position)
		{
			(void) position;
		}

		size_type				erase(const key_type &k)
		{
			(void) k;
		}

		void					erase(iterator first, iterator last)
		{
			(void) first;
			(void) last;
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
