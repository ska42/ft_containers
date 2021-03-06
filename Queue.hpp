/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:32:17 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/12 04:31:51 by lmartin          ###   ########.fr       */
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

	template <class T, class C = std::deque<T> >
	class Queue
	{

	public:
	/* ********************************************************************** */
	/*   Member types                                                         */
	/* ********************************************************************** */
	
		typedef T					value_type;
		typedef C					container_type;
		typedef size_t				size_type;

	private:
		container_type				container;
	
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
			return (*this);
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

		size_type			size(void) const
		{
			return (this->container.size());
		}

	private:
		/* Make friends to grant access of sub-container to compare */
		template <class U, class V>
		friend bool	operator==(const Queue<U,V> &lhs, const Queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator!=(const Queue<U,V> &lhs, const Queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator<(const Queue<U,V> &lhs, const Queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator<=(const Queue<U,V> &lhs, const Queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator>(const Queue<U,V> &lhs, const Queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator>=(const Queue<U,V> &lhs, const Queue<U,V> &rhs);
	};

	/* ************************************************************************** */
	/*   Non-member functions                                                     */
	/* ************************************************************************** */

	template <class T, class C>
	bool		operator==(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
	{
		return (lhs.container == rhs.container);
	}

	template <class T, class C>
	bool		operator!=(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
	{
		return (lhs.container != rhs.container);
	}

	template <class T, class C>
	bool		operator<(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
	{
		return (lhs.container < rhs.container);
	}

	template <class T, class C>
	bool		operator<=(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
	{
		return (lhs.container <= rhs.container);
	}

	template <class T, class C>
	bool		operator>(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
	{
		return (lhs.container > rhs.container);
	}

	template <class T, class C>
	bool		operator>=(const Queue<T,C> &lhs, const Queue<T,C> &rhs)
	{
		return (lhs.container >= rhs.container);
	}

};

#endif
