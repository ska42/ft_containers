/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorMap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:49:20 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/11 22:51:14 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORMAP_HPP
# define ITERATORMAP_HPP

# include "Iterator.hpp"

namespace ft
{
	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/references/iterator                          */
	/* https://www.cplusplus.com/references/iterator/iterator                 */
	/* https://www.cplusplus.com/reference/iterator/iterator_traits/          */
	/* ********************************************************************** */

	template <class Key, class T>
	struct BinaryTreeMap
	{
		BinaryTreeMap		*parent;
		BinaryTreeMap		*left;
		BinaryTreeMap		*right;
		std::pair<Key,T>	pair;
		size_t				left_height;
		size_t				right_height;
	};

	template <class Key, class T, class Category = ft::bidirectional_iterator_tag>
	class IteratorMap
	{
	
	private:
		/* Lock to compile error on use */
		IteratorMap					operator+(const IteratorMap &rhs) const;
		IteratorMap					operator+(int n) const;
		IteratorMap					operator-(const IteratorMap &rhs) const;
		IteratorMap					operator-(int n) const;
		bool						operator<(const IteratorMap &rhs) const;
		bool						operator>(const IteratorMap &rhs) const;
		bool						operator<=(const IteratorMap &rhs) const;
		bool						operator>=(const IteratorMap &rhs) const;
		IteratorMap					&operator+=(int n) const;
		IteratorMap					&operator-=(int n) const;
		T							&operator[](int n) const;

	protected:
		BinaryTreeMap<Key, T>			*ptr;

	public:
		
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */

		typedef T								value_type;
		typedef T								&reference;
		typedef T								*pointer;
		typedef Category						category;
		typedef std::ptrdiff_t					difference_type;

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */

		/* Coplien Form */
		IteratorMap(void) {}

		~IteratorMap(void) {}

		IteratorMap(const IteratorMap &it)
		{
			*this = it;
		}

		IteratorMap				&operator=(const IteratorMap &rhs)
		{
			this->ptr = rhs.ptr;
			return (*this);
		}

		
		IteratorMap(BinaryTreeMap<Key, T> *map)
		{
			this->ptr = map;
		}

		IteratorMap				&operator++(void)
		{
			BinaryTreeMap<Key, T> *next;

			if (!this->ptr)
				return (*this);
			if (!this->ptr->right)
			{
				next = this->ptr;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = this->ptr->right;
				while (next->left)
					next = next->left;
			}
			this->ptr = next;
			return (*this);
		}

		IteratorMap				operator++(int)
		{
			IteratorMap tmp(*this);
			this->operator++();	
			return (tmp);
		}

		IteratorMap				&operator--(void)
		{
			BinaryTreeMap<Key, T> *next;

			if (!this->ptr->left)
			{
				next = this->ptr;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = this->ptr->left;
				while (next->right)
					next = next->right;
			}
			this->ptr = next;
			return (*this);
		}

		IteratorMap				operator--(int)
		{
			IteratorMap tmp(*this);
			this->operator--();
			return (tmp);
		}

  		bool						operator==(const IteratorMap &rhs) const
		{
			return (this->ptr == rhs.ptr);			
		}

  		bool						operator!=(const IteratorMap &rhs) const
		{
			return (this->ptr != rhs.ptr);
		}

		std::pair<Key, T>			&operator*(void) // dereferenced lvalue
		{
			return (this->ptr->pair);
		}

		std::pair<Key, T>			*operator->(void) // dereferenced rvalue
		{ 
			return (&this->ptr->pair);
		}
		
		BinaryTreeMap<Key, T>			*getPtr(void)
		{
			return (this->ptr);
		}	

	};


	template <class Key, class T>
	class ReverseIteratorMap : public IteratorMap<Key, T>
	{

	private:

	public:
		ReverseIteratorMap(void) {}
		~ReverseIteratorMap(void) {}

		ReverseIteratorMap(BinaryTreeMap<Key, T> *map)
		{
			this->ptr = map;
		}

		ReverseIteratorMap(const ReverseIteratorMap &it)
		{
			*this = it;
		}

		ReverseIteratorMap			&operator=(const ReverseIteratorMap &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		ReverseIteratorMap			&operator++(void)
		{
			BinaryTreeMap<Key, T> *next;

			if (!this->ptr->left)
			{
				next = this->ptr;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = this->ptr->left;
				while (next->right)
					next = next->right;
			}
			this->ptr = next;
			return (*this);
		}

		ReverseIteratorMap			operator++(int)
		{
			ReverseIteratorMap tmp(*this);
			this->operator++();
			return (tmp);
		}

		ReverseIteratorMap			&operator--(void)
		{
			BinaryTreeMap<Key, T> *next;

			if (!this->ptr->right)
			{
				next = this->ptr;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = this->ptr->right;
				while (next->left)
					next = next->left;
			}
			this->ptr = next;
			return (*this);
		}

		ReverseIteratorMap			operator--(int)
		{
			ReverseIteratorMap tmp(*this);
			this->operator--();
			return (tmp);
		}
	};

	template <class Key, class T>
	class ConstIteratorMap : public IteratorMap<Key, T>
	{
	public:
		ConstIteratorMap(void) {}
		~ConstIteratorMap(void) {}

		ConstIteratorMap(BinaryTreeMap<Key, T> *map)
		{
			this->ptr = map;
		}

		ConstIteratorMap(const ConstIteratorMap &it)
		{
			*this = it;
		}

		ConstIteratorMap			&operator=(const ConstIteratorMap &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const std::pair<Key, T>		&operator*(void) // dereferenced lvalue
		{
			return (*this->ptr->pair);
		}
	};

	template <class Key, class T>
	class ConstReverseIteratorMap : public ReverseIteratorMap<Key, T>
	{
	public:
		ConstReverseIteratorMap(void) {}
		~ConstReverseIteratorMap(void) {}

		ConstReverseIteratorMap(BinaryTreeMap<Key, T> *map)
		{
			this->ptr = map;
		}

		ConstReverseIteratorMap(const ConstReverseIteratorMap &it)
		{
			*this = it;
		}

		ConstReverseIteratorMap			&operator=(const ConstReverseIteratorMap &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		const std::pair<Key, T>		&operator*(void) // dereferenced lvalue
		{
			return (*this->ptr->pair);
		}
	};
};

#endif
