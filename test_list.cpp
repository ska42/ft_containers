/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 04:32:26 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/26 23:59:25 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include <list>
# include "Iterator.hpp"
# include "List.hpp"
# include "colors.h"

template <class T>
void	printMyList(ft::List<T> list)
{
	int								d;
	typename ft::IteratorList<T> 	i;
	
	i = list.begin();
	d = 0;
	std::cout << _YELLOW << "---------------------- " << "[" << _GREEN;
	while (i != list.end())
	{
		std::cout << _GREEN << *i << ", ";
		i++;
		d++;
	}
	if (d)
		std::cout << *i << _YELLOW << "]" << _END << std::endl;
	else
		std::cout << _YELLOW << "]" << _END << std::endl;
	std::cout << std::endl;
}

template <class T>
void	printList(std::list<T> list)
{
	int								d;
	typename std::list<T>::iterator	i;
	
	i = list.begin();
	d = 0;
	std::cout << _YELLOW << "---------------------- " << "[" << _GREEN;
	while (i != list.end())
	{
		std::cout << _GREEN << *i << ", ";
		i++;
		d++;
	}
	if (d)
		std::cout << *i << _YELLOW << "]" << _END << std::endl;
	else
		std::cout << _YELLOW << "]" << _END << std::endl;
	std::cout << std::endl;
}

template <class T>
void	error_diff(ft::List<T> mylist, std::list<T> list)
{
	std::cout << _RED << "ERROR - DIFF" << _END << std::endl;
	std::cout << std::setw(30) << "mylist.empty(): " << mylist.empty() << std::endl;
	std::cout << std::setw(30) << "list.empty(): " << list.empty() << std::endl;
	std::cout << std::setw(30) << "mylist.size(): " << mylist.size() << std::endl;
	std::cout << std::setw(30) << "list.size(): " << list.size() << std::endl;
	std::cout << std::setw(30) << "mylist : ";
	printMyList(mylist);
	std::cout << std::setw(30) << "list : ";
	printList(list);
}

template <class T>
void	compareList(std::string function, ft::List<T> mylist, std::list<T> list)
{
	std::cout << std::setw(20) << function << ": ";
	if (mylist.empty() != list.empty())
		error_diff(mylist, list);
	else if (mylist.size() != list.size())
		error_diff(mylist, list);
	else
	{
		typename ft::List<T>::iterator my_it;
		typename std::list<T>::iterator	i;
		my_it = mylist.begin();
		i = list.begin();
		while (my_it != mylist.end())
		{
			if (*i != *my_it)
			{
				error_diff(mylist, list);
				return ;
			}
			i++;
			my_it++;
		}
		std::cout << _GREEN << "OK " << _END;
		printMyList(mylist);
	}
}

int		main(void)
{
	/* ********************************************************************** */
	/*                          BASIC TESTS                                   */
	/* ********************************************************************** */
	ft::List<int> mylist = ft::List<int>();
	std::list<int> list = std::list<int>();

	std::cout << "ft::List<int> mylist = ft::List<int>();" << std::endl;
	std::cout << "std::list<int> list = std::list<int>();" << std::endl;

	compareList("list.empty()", mylist, list);
	compareList("list.size()", mylist, list);

	//list.pop_back(); --> if empty std::list segfault
	mylist.pop_back();
	compareList("list.pop_back()", mylist, list);
	//list.pop_front(); --> if empty std::list segfault
	mylist.pop_front();
	compareList("list.pop_front()", mylist, list);

	for(int i = 0; i < 5; i++)
	{
		list.push_back(i);
		mylist.push_back(i);
		std::string thing = "list.push_back(" + std::to_string(i) + ")";
		compareList(thing, mylist, list);
	}
	
	compareList("list.empty()", mylist, list);
	compareList("list.size()", mylist, list);

	list.push_front(-1);
	mylist.push_front(-1);
	compareList("list.push_front(-1)", mylist, list);

	list.pop_back();
	mylist.pop_back();
	compareList("list.pop_back()", mylist, list);

	list.pop_back();
	mylist.pop_back();
	list.pop_back();
	mylist.pop_back();
	list.pop_back();
	mylist.pop_back();
	list.pop_back();
	mylist.pop_back();
	list.pop_back();
	mylist.pop_back();
	compareList("list.pop_back() x5", mylist, list);

	//list.pop_back(); --> if empty std::list segfault
	mylist.pop_back();
	compareList("list.pop_back()", mylist, list);

	list.assign((size_t)10, 6);
	mylist.assign((size_t)10, 6);
	compareList("list.assign(10, 6)", mylist, list);

	list.pop_front();
	mylist.pop_front();
	compareList("list.pop_front()", mylist, list);
	
	list.clear();
	mylist.clear();
	compareList("list.clear()", mylist, list);

	/* ********************************************************************** */
	/*                           ADVANCED TESTS                               */
	/* ********************************************************************** */
	int n;

	srand(time(NULL));
	for(int i = 0; i < 5; i++)
	{
		n = rand();
		list.push_back(n);
		mylist.push_back(n);
		std::string thing = "list.push_back(" + std::to_string(n) + ")";
		compareList(thing, mylist, list);
	}
	list.sort();
	mylist.sort();
	compareList("list.sort()", mylist, list);
	return (0);
}
