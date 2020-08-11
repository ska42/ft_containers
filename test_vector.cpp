/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:39:11 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/11 22:13:58 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "utils.hpp"
#include "colors.h"
#include "Vector.hpp"

int			main(void)
{

	std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	std::cout << "/* ********************************************************************** */" << _END << std::endl;
	std::cout << std::endl;

	ft::Vector<int>	myv;
	std::vector<int> v;

	std::cout << "ft::Vector<" << _PURPLE << "int" << _END << "> myv;" << std::endl;
	std::cout << "std::vector<" << _PURPLE << "int" << _END << "> v;" << std::endl;

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
	v2.swap(v);
	printContainer(v);
	printContainer(v2);
	return (0);
}
