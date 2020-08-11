/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:58:37 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/12 01:45:57 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <map>
#include "colors.h"
#include "Iterator.hpp"
#include "Map.hpp"

template <class Container>
void	printMap(Container c)
{
	int								n;
	typename Container::iterator	i;
	
	i = c.begin();
	n = 0;
	std::cout << _YELLOW << "---------------------- " << "[" << _GREEN;
	while (i != c.end())
	{
		if (n != 0)
			std::cout << ", ";
		std::cout << _GREEN << i->first << _END << ":" << _GREEN << i->second << _END;
		i++;
		n++;
	}
	std::cout << _YELLOW << "]" << _END << std::endl;
	std::cout << std::endl;
}

template <class Key, class T>
void	error_diff(ft::Map<Key, T> mymap, std::map<Key, T> map)
{
	std::cout << _RED << "ERROR - DIFF" << _END << std::endl;
	std::cout << std::setw(30) << "mymap.empty(): " << mymap.empty() << std::endl;
	std::cout << std::setw(30) << "map.empty(): " << map.empty() << std::endl;
	std::cout << std::setw(30) << "mymap.size(): " << mymap.size() << std::endl;
	std::cout << std::setw(30) << "map.size(): " << map.size() << std::endl;
	std::cout << std::setw(30) << "mymap : ";
	printMap(mymap);
	std::cout << std::setw(30) << "map : ";
	printMap(map);
}

template <class Key, class T>
void	compareMap(std::string function, ft::Map<Key, T> mymap, std::map<Key, T> map)
{
	std::cout << std::setw(30) << function << ": ";
	if (mymap.empty() != map.empty())
		error_diff(mymap, map);
	else if (mymap.size() != map.size())
		error_diff(mymap, map);
	else
	{
		typename std::map<Key, T>::iterator	it = map.begin();
		size_t				i;

		i = 0;
		while (i < map.size())
		{
			typename ft::Map<Key, T>::iterator it2 = mymap.find(it->first);
			if (it2 == mymap.end())
				error_diff(mymap, map);
			if (it2->first != it->first || it2->second != it->second)
				error_diff(mymap, map);
			it++;
			i++;
		}
		std::cout << _GREEN << "OK " << _END;
		printMap(mymap);
	}
}

int					main(void)
{

	std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	std::cout << "/* ********************************************************************** */" << _END << std::endl;
	std::cout << std::endl;


	ft::Map<std::string, int> mymap;
	std::map<std::string, int> map;


	std::cout << "ft::Map<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END << "> mymap;" << std::endl;
	std::cout << "std::map<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> map;" << std::endl;

	std::cout << std::endl;
	std::cout << "mymap.max_size(): " << mymap.max_size() << std::endl;
	std::cout << "map.max_size(): " << map.max_size() << std::endl;
	std::cout << std::endl;

	compareMap("map.empty()", mymap, map);
	compareMap("map.size()", mymap, map);

	mymap.insert(std::pair<std::string, int>("ft", 42));
	map.insert(std::pair<std::string, int>("ft", 42));
	compareMap("map.insert(\"ft\", 42)", mymap, map);

	mymap.insert(std::pair<std::string, int>("one", 1));
	map.insert(std::pair<std::string, int>("one", 1));
	compareMap("map.insert(\"one\", 1)", mymap, map);

	ft::Map<std::string, int>::iterator mit;
	std::map<std::string, int>::iterator it;
	mit = mymap.lower_bound("aaa");
	it = map.lower_bound("aaa");
	std::cout << "mymap.lower_bound(\"aaa\"): " << mit->first << ":" << mit->second << std::endl;;
	std::cout << "map.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;

	/*
	map.insert(ft::Map<int, int>::value_type(1, 1));
	map.insert(ft::Map<int, int>::value_type(4, 1));
	map.insert(ft::Map<int, int>::value_type(3, 1));
	map.insert(ft::Map<int, int>::value_type(5, 1));
	map.insert(ft::Map<int, int>::value_type(9, 1));
	map.insert(ft::Map<int, int>::value_type(2, 1));
	map.insert(ft::Map<int, int>::value_type(8, 199));
	map.insert(ft::Map<int, int>::value_type(7, 1));
	map.insert(ft::Map<int, int>::value_type(6, 1));
	map.insert(ft::Map<int, int>::value_type(6, 1));
	map.insert(ft::Map<int, int>::value_type(0, 1));
	std::cout << map[8] << std::endl;
	try
	{
		std::cout << map[100] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	map.erase(6);
	map.erase(7);
	map.erase(7);
	map.erase(3);
	map.erase(2);
	map.erase(8);
	map.erase(1);
	map.erase(5);
	map.clear();
	try
	{
		std::cout << map[100] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	*/
	return (0);
}
