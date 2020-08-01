/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:58:37 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/02 00:13:01 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iterator.hpp"
#include "Map.hpp"

int					main(void)
{
	ft::Map<int, int> map;
	map.insert(ft::Map<int, int>::value_type(1, 1));
	map.insert(ft::Map<int, int>::value_type(4, 1));
	map.insert(ft::Map<int, int>::value_type(3, 1));
	//map.insert(ft::Map<int, int>::value_type(5, 1));
	//map.insert(ft::Map<int, int>::value_type(9, 1));
	//map.insert(ft::Map<int, int>::value_type(2, 1));
	//map.insert(ft::Map<int, int>::value_type(8, 1));
	return (0);
}
