/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:39:11 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/10 01:52:30 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"
#include "colors.h"

template <class container>
void	printVector(container vector)
{
	int								n;
	typename container::iterator	i;
	
	i = vector.begin();
	n = 0;
	std::cout << _YELLOW << "---------------------- " << "[" << _GREEN;
	while (i != vector.end())
	{
		if (n != 0)
			std::cout << ", ";
		std::cout << _GREEN << *i << _END;
		i++;
		n++;
	}
	std::cout << _YELLOW << "]" << _END << std::endl;
	std::cout << std::endl;
}

int			main(void)
{
	ft::Vector<int>	v;

	v.push_back(4);
	printVector(v);
	v.push_back(-19);
	printVector(v);
	v.pop_back();
	printVector(v);
	v.assign((size_t)10, (int)8);
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	return (0);
}
