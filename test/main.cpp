/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:31:12 by skybt             #+#    #+#             */
/*   Updated: 2020/08/11 13:44:29 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"

int main()
{
	std::cout << ":: Vector ::" << std::endl;
	test_vector();
	std::cout << ":: List ::" << std::endl;
	test_list();
	std::cout << ":: Stack ::" << std::endl;
	test_stack();
	std::cout << ":: Queue ::" << std::endl;
	test_queue();
	std::cout << ":: Map ::" << std::endl;
	test_map();
	std::cout << ":: Everything is ok! ::" << std::endl;
	return 0;
}
