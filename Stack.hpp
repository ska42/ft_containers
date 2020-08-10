/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 03:38:54 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/10 15:06:18 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <deque>

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/stack/stack                        */
	/* ********************************************************************** */

	template <class T, class C = std::deque<T> >
	class Stack
	{

	public:
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T				value_type;
		typedef C				container_type;
		typedef size_t			size_type;

	private:
		container_type			container;

	public:
	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
		
		explicit Stack (const container_type &ctnr = container_type())
		{
			this->container = ctnr;
			return ;
		}

		~Stack(void)
		{
			return ;
		}

		Stack(const Stack &stack)
		{
			*this = stack;
			return ;
		}

		Stack					&operator=(const Stack &stack)
		{
			this->container = stack.container;
			return (*this);
		}

		bool empty(void) const
		{
			return (container.empty());
		}

		void					push (const value_type &val)
		{
			container.push_back(val);
		}
		
		void					pop (void)
		{
			container.pop_back();
		}

		size_type				size(void) const
		{
			return (container.size());
		}

		value_type				&top(void)
		{
			return (container.back());
		}

		const value_type		&top(void) const
		{
			return (container.back());
		}
	};

	/* ********************************************************************** */
	/*   Non-member functions                                                 */
	/* ********************************************************************** */

	template <class T, class C>
	bool	operator==(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
	{
		return (lhs == rhs);
	}

	template <class T, class C>
	bool	operator!=(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
	{
		return (lhs != rhs);
	}

	template <class T, class C>
	bool	operator<(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
	{
		return (lhs < rhs);
	}

	template <class T, class C>
	bool	operator<=(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
	{
		return (lhs <= rhs);
	}

	template <class T, class C>
	bool	operator>(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
	{
		return (lhs > rhs);
	}

	template <class T, class C>
	bool	operator>=(const Stack<T,C> &lhs, const Stack<T,C> &rhs)
	{
		return (lhs >= rhs);
	}

};

#endif
