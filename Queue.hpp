/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:32:17 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/10 13:15:13 by lmartin          ###   ########.fr       */
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

	template <class T, class C = std::deque<T>>
	class Queue
	{

	public:
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T					value_type;
		typedef C					container_type;
		typedef size_t				syze_type;

	private:
		container_type<T>			container;
	
	public:
	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
		
		explicit Queue (const container_type& ctnr = container_type())
		{
			this->container = ctnr;
			return ;
		}

		~Queue(void)
		{
			~this->container();
			return ;
		}

		Queue(const Queue &queue)
		{
			*this = queue;
			return ;
		}

		Queue				&operator=(const Queue &queue)
		{
			this->container = queue.container;
			return ;
		}
		
		value_type			&back(void)
		{
			return (this->container.back());
		}

		const value_type	&back(void) const
		{
			return (this->container.back());
		}

		bool				empty(void) const
		{
			return (this->container.empty());
		}

		value_type			&front(void)
		{
			return (this->container.front());
		}

		const value_type	&front(void) const
		{
			return (this->container.front());
		}

		void				pop(void)
		{
			return (this->container.pop_front());
		}

		void				push(const value_type &val)
		{
			return (this->container.push_back(val));
		}

		size_type size(void) const
		{
			return (this->container.size());
		}
	};

/* ************************************************************************** */
/*   Non-member functions                                                     */
/* ************************************************************************** */

template <class T, class C>
bool		operator==(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
{
	return (lhs == rhs);
}

template <class T, class C>
bool		operator!=(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
{
	return (lhs != rhs);
}

template <class T, class C>
bool		operator<(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
{
	return (lhs < rhs);
}

template <class T, class C>
bool		operator<=(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
{
	return (lhs <= rhs);
}

template <class T, class C>
bool		operator>(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
{
	return (lhs > rhs);
}

template <class T, class C>
bool		operator>=(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
{
	return (lhs >= rhs);
};

#endif
