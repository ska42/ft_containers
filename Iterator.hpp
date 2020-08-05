/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 09:21:08 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/05 21:15:46 by lmartin          ###   ########.fr       */
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

	template <class Key, class T>
	struct BinaryTreeMap
	{
		BinaryTreeMap		*parent;
		BinaryTreeMap		*left;
		BinaryTreeMap		*right;
		Key					key;
		T					value;
		size_t				left_height;
		size_t				right_height;
	};

	template <class T>
	struct DoublyLinkedList
	{
		DoublyLinkedList	*prev;
		DoublyLinkedList	*next;
		T					element;
	};

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag: input_iterator_tag {};
	struct bidirectional_iterator_tag: forward_iterator_tag {};
	struct random_access_iterator_tag: bidirectional_iterator_tag {};

	template <class T, class Category = bidirectional_iterator_tag>
	class IteratorList
	{
	
	private:
		/* Lock to compile error on use */
		IteratorList				operator+(const IteratorList &rhs) const;
		IteratorList				operator+(int n) const;
		IteratorList				operator-(const IteratorList &rhs) const;
		IteratorList				operator-(int n) const;
		bool						operator<(const IteratorList &rhs) const;
		bool						operator>(const IteratorList &rhs) const;
		bool						operator<=(const IteratorList &rhs) const;
		bool						operator>=(const IteratorList &rhs) const;
		IteratorList				&operator+=(int n) const;
		IteratorList				&operator-=(int n) const;
		T							&operator[](int n) const;

	protected:
		DoublyLinkedList<T>			*ptr;

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
		IteratorList(void) {}

		~IteratorList(void) {}

		IteratorList(const IteratorList &it)
		{
			*this = it;
		}

		IteratorList				&operator=(const IteratorList &rhs)
		{
			this->ptr = rhs.ptr;
			return (*this);
		}

		
		IteratorList(DoublyLinkedList<T> *list)
		{
			this->ptr = list;
		}

		IteratorList				&operator++(void)
		{
			if (this->ptr && this->ptr->next)
				this->ptr = this->ptr->next;
			return (*this);
		}

		IteratorList				operator++(int)
		{
			IteratorList tmp(*this);
			this->operator++();	
			return (tmp);
		}

		IteratorList				&operator--(void)
		{
			if (this->ptr && this->ptr->prev)
				this->ptr = this->ptr->prev;	
			return (*this);
		}

		IteratorList				operator--(int)
		{
			IteratorList tmp(*this);
			this->operator--();
			return (tmp);
		}

  		bool						operator==(const IteratorList &rhs) const
		{
			return (this->ptr == rhs.ptr);			
		}

  		bool						operator!=(const IteratorList &rhs) const
		{
			return (this->ptr != rhs.ptr);
		}

		T							&operator*(void) // dereferenced lvalue
		{
			return (this->ptr->element);	
		}

		T							*operator->(void) // dereferenced rvalue
		{ 
			return (&this->ptr->element);	
		}
		
		DoublyLinkedList<T>			*getPtr(void)
		{
			return (this->ptr);
		}	

	};

	template <class T>
	class ReverseIteratorList : public IteratorList<T>
	{

	private:

	public:
		ReverseIteratorList(void) {}
		~ReverseIteratorList(void) {}

		ReverseIteratorList(DoublyLinkedList<T> *list)
		{
			this->ptr = list;
		}

		ReverseIteratorList(const ReverseIteratorList &it)
		{
			*this = it;
		}

		ReverseIteratorList			&operator=(const ReverseIteratorList &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		ReverseIteratorList			&operator++(void)
		{
			if (this->ptr && this->ptr->prev)
				this->ptr = this->ptr->prev;
			return (*this);
		}

		ReverseIteratorList			operator++(int)
		{
			ReverseIteratorList tmp(*this);
			this->operator++();
			return (tmp);
		}

		ReverseIteratorList			&operator--(void)
		{
			if (this->ptr && this->ptr->next)
				this->ptr = this->ptr->next;
			return (*this);
		}

		ReverseIteratorList			operator--(int)
		{
			ReverseIteratorList tmp(*this);
			this->operator--();
			return (tmp);
		}
	};

	template <class T, class Category = random_access_iterator_tag>
	class IteratorVector: public IteratorList<T>
	{
	private:
		
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
		IteratorVector(void) {}

		~IteratorVector(void) {}

		IteratorVector(const IteratorVector &it)
		{
			*this = it;
		}

		IteratorVector				&operator=(const IteratorVector &rhs)
		{
			this->ptr = rhs.ptr;
			return (*this);
		}

		
		IteratorVector(DoublyLinkedList<T> *list)
		{
			this->ptr = list;
		}

		IteratorVector				operator+(int n) const
		{
			IteratorVector		iv(*this);

			iv += n;
			return (iv);	
		}

		IteratorVector				operator-(int n) const
		{
			IteratorVector		iv(*this);

			iv -= n;
			return (iv);
		}

		bool						operator<(const IteratorVector &rhs) const
		{
			return (this->ptr->element < rhs.ptr->element);
		}

		bool						operator>(const IteratorVector &rhs) const
		{
			return (this->ptr->element > rhs.ptr->element);
		}

		bool						operator<=(const IteratorVector &rhs) const
		{
			return (this->ptr->element <= rhs.ptr->element);
		}

		bool						operator>=(const IteratorVector &rhs) const
		{
			return (this->ptr->element >= rhs.ptr->element);
		}

		IteratorVector				&operator+=(int n) const
		{
			while (n > 0)	
			{
				n--;
				this++;
			}
			while (n < 0)
			{
				n++;
				this--;
			}
			return (*this);
		}

		IteratorVector				&operator-=(int n) const
		{
			while (n > 0)	
			{
				n--;
				this--;
			}
			while (n < 0)
			{
				n++;
				this++;
			}
			return (*this);
		}

		T							&operator[](int n) const
		{
			return (*(*this + n));
		}

	};

	template <class T>
	class ReverseIteratorVector : public ReverseIteratorList<T>, public IteratorVector<T>
	{

	private:

	public:
		ReverseIteratorVector(void) {}
		~ReverseIteratorVector(void) {}

		ReverseIteratorVector(DoublyLinkedList<T> *list)
		{
			this->ptr = list;
		}

		ReverseIteratorVector(const ReverseIteratorVector &it)
		{
			*this = it;
		}

		ReverseIteratorVector			&operator=(const ReverseIteratorVector &it)
		{
			this->ptr = it.ptr;
			return (*this);
		}

		ReverseIteratorVector			&operator+=(int n) const
		{
			while (n > 0)	
			{
				n--;
				this--;
			}
			while (n < 0)
			{
				n++;
				this++;
			}
			return (*this);
		}

		ReverseIteratorVector			&operator-=(int n) const
		{
			while (n > 0)	
			{
				n--;
				this++;
			}
			while (n < 0)
			{
				n++;
				this--;
			}
			return (*this);
		}

		T								&operator[](int n) const
		{
			return (*(*this + n));
		}

	};
	
	template <class Key, class T, class Category = bidirectional_iterator_tag>
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
			if (this->ptr && this->ptr->right)
				this->ptr = this->ptr->right;
			else if (this->ptr)
			{
				BinaryTreeMap<Key, T> *tmp = this->ptr;
				BinaryTreeMap<Key, T> *prev = this->ptr;
				this->ptr = this->ptr->parent;
				while (this->ptr && prev == this->ptr->right)
				{
					prev = this->ptr;
					this->ptr = this->ptr->parent;
				}
				if (!this->ptr)
					this->ptr = tmp;
			}
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
			if (this->ptr && this->ptr->left)
				this-ptr = this->ptr->left;
			else if (this->ptr)
			{
				BinaryTreeMap<Key, T> tmp = this->ptr;
				BinaryTreeMap<Key, T> prev = this->ptr;
				this->ptr = this->ptr->parent;
				while (this->ptr && prev == this->ptr->left)
				{
					prev = this->ptr;
					this->ptr = this->ptr->parent;
				}
				if (!this->ptr)
					this->ptr = tmp;
			}
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

		T							&operator*(void) // dereferenced lvalue
		{
			return (this->ptr->value);	
		}

		T							*operator->(void) // dereferenced rvalue
		{ 
			return (&this->ptr->value);	
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
			if (this->ptr && this->ptr->left)
				this->ptr = this->ptr->left;
			else if (this->ptr)
			{
				BinaryTreeMap<Key, T> tmp = this->ptr;
				BinaryTreeMap<Key, T> prev = this->ptr;
				this->ptr = this->ptr->parent;
				while (this->ptr && prev == this->ptr->left)
				{
					prev = this->ptr;
					this->ptr = this->ptr->parent;
				}
				if (!this->ptr)
					this->ptr = tmp;
			}
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
			if (this->ptr && this->ptr->right)
				this->ptr = this->ptr->right;
			else if (this->ptr)
			{
				BinaryTreeMap<Key, T> tmp = this->ptr;
				BinaryTreeMap<Key, T> prev = this->ptr;
				this->ptr = this->ptr->parent;
				while (this->ptr && prev == this->ptr->right)
				{
					prev = this->ptr;
					this->ptr = this->ptr->parent;
				}
				if (!this->ptr)
					this->ptr = tmp;
			}
			return (*this);

		}

		ReverseIteratorMap			operator--(int)
		{
			ReverseIteratorMap tmp(*this);
			this->operator--();
			return (tmp);
		}
	};

};

#endif
