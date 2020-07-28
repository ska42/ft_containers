/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 03:38:54 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/28 17:58:30 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/stack/stack                        */
	/* ********************************************************************** */

	template <class T, class C>
	class Stack
	{

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T				value_type;
		typedef C				container_type;
		typedef size_t			syze_type;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
		
		explicit Stack (const container_type &ctnr = container_type())
		{
			return ;
		}

		~Stack(void)
		{
			return ;
		}

		Stack(const Stack &stack)
		{
			return ;
		}

		Stack					&operator=(const Stack &stack)
		{
			return ;
		}

		bool empty(void) const
		{
		}

		void push (const value_type &val)
		{
		}

		size_type				size(void) const
		{
		}

		value_type				&top(void)
		{
		}

		const value_type		&top(void) const
		{
		}
	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

template <class T, class C>
bool	operator==(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
{
}

template <class T, class C>
bool	operator!=(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
{
}

template <class T, class C>
bool	operator<(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
{
}

template <class T, class C>
bool	operator<=(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
{
}

template <class T, class C>
bool	operator>(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
{
}

template <class T, class C>
bool	operator>=(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
{
}

};

#endif
