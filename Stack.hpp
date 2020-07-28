/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 03:38:54 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/28 04:43:53 by lmartin          ###   ########.fr       */
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

	template <class T, class Container = deque<T> >
	class Stack
	{

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t			syze_type;

	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
		
		explicit Stack (const container_type& ctnr = container_type())
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

		size_type size(void) const
		{
		}

		value_type& top(void)
		{
		}

		const value_type& top(void) const
		{
		}
	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

template <class T, class Container>
bool	operator==(const Stack<T,Container> &lhs, const Stack<T,Container> &rhs)
{
}

template <class T, class Container>
bool	operator!=(const Stack<T,Container> &lhs, const Stack<T,Container> &rhs)
{
}

template <class T, class Container>
bool	operator<(const Stack<T,Container> &lhs, const Stack<T,Container> &rhs)
{
}

template <class T, class Container>
bool	operator<=(const Stack<T,Container> &lhs, const Stack<T,Container> &rhs)
{
}

template <class T, class Container>
bool	operator>(const Stack<T,Container> &lhs, const Stack<T,Container> &rhs)
{
}

template <class T, class Container>
bool	operator>=(const Stack<T,Container> &lhs, const Stack<T,Container> &rhs)
{
}

};

#endif
