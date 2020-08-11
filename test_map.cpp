/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:58:37 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/11 18:35:55 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "Iterator.hpp"
#include "Map.hpp"

int					main(void)
{
	ft::Map<int, int> map;
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
	return (0);
}
