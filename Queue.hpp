/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:32:17 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/28 04:44:34 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

namespace ft
{

	/* ********************************************************************** */
	/* references:                                                            */
	/* https://www.cplusplus.com/reference/queue/queue                        */
	/* ********************************************************************** */

	template <class T, class Container = deque<T> >
	class Queue
	{

	public:

	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T					value_type;
		typedef Container			container_type;
		typedef size_t				syze_type;

	
	public:

	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
		
		explicit Queue (const container_type& ctnr = container_type())
		{
		}

		~Queue(void)
		{
		}

		Queue(const Queue &queue)
		{
		}

		Queue				&operator=(const Queue &queue)
		{
		}
		
		value_type			&back(void)
		{
		}

		const value_type	&back(void) const
		{
		}

		bool				empty(void) const
		{
		}

		value_type			&front(void)
		{
		}

		const value_type	&front(void) const
		{
		}

		void				pop(void)
		{
		}

		void				push(const value_type &val)
		{
		}

		size_type size(void) const
		{
		}
	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

template <class T, class Container>
bool		operator==(const Queue<T,Container> &lhs, const Queue<T,Container> &rhs)
{
}

template <class T, class Container>
bool		operator!=(const Queue<T,Container> &lhs, const Queue<T,Container> &rhs)
{
}

template <class T, class Container>
bool		operator<(const Queue<T,Container> &lhs, const Queue<T,Container> &rhs)
{
}

template <class T, class Container>
bool		operator<=(const Queue<T,Container> &lhs, const Queue<T,Container> &rhs)
{
}

template <class T, class Container>
bool		operator>(const Queue<T,Container> &lhs, const Queue<T,Container> &rhs)
{
}

template <class T, class Container>
bool		operator>=(const Queue<T,Container> &lhs, const Queue<T,Container> &rhs)
{
}

};

#endif
