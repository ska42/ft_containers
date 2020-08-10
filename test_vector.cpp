/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:39:11 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/10 03:15:18 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "utils.hpp"
#include "colors.h"
#include "Vector.hpp"

int			main(void)
{
	ft::Vector<int>	v;

	v.push_back(4);
	printContainer(v);
	v.push_back(-19);
	printContainer(v);
	v.pop_back();
	printContainer(v);
	v.assign((size_t)10, (int)8);
	printContainer(v);
	v.erase(v.begin());
	printContainer(v);
	std::cout << v[5] << std::endl;
	std::cout << v.front() << std::endl;
	v.push_back(20);
	std::cout << v.back() << std::endl;
	ft::Vector<int> v2;
	v2.clear();
	return (0);
}
