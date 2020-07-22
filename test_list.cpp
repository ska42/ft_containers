/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 04:32:26 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/22 12:38:28 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Iterator.hpp"
# include "List.hpp"
# include "colors.h"

template <class T>
void	printList(ft::List<int> list)
{
	int					d;
	ft::IteratorList<T> i;
	
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

int		main(void)
{
	ft::List<int> list = ft::List<int>();

	std::cout << "ft::List<int> list = ft::List<int>();" << std::endl;
	printList<int>(list);

	std::cout << "list.empty();" << std::endl;
	std::cout << list.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "list.size();" << std::endl;
	std::cout << list.size() << std::endl;
	std::cout << std::endl;

	for(int i = 0; i < 5; i++)
	{
		std::cout << "list.push_back(" << i << ");" << std::endl;
		list.push_back(i);
	}
	printList<int>(list);

	std::cout << "list.empty();" << std::endl;
	std::cout << list.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "list.size();" << std::endl;
	std::cout << list.size() << std::endl;
	std::cout << std::endl;

	std::cout << "list.push_front(" << -1 << ");" << std::endl;
	list.push_front(-1);
	printList<int>(list);

	std::cout << "list.pop_back();" << std::endl;
	list.pop_back();
	printList<int>(list);

	std::cout << "list.pop_back();" << std::endl;
	list.pop_back();
	std::cout << "list.pop_back();" << std::endl;
	list.pop_back();
	std::cout << "list.pop_back();" << std::endl;
	list.pop_back();
	std::cout << "list.pop_back();" << std::endl;
	list.pop_back();
	std::cout << "list.pop_back();" << std::endl;
	list.pop_back();
	printList<int>(list);

	std::cout << "list.pop_back();" << std::endl;
	list.pop_back();
	printList<int>(list);

	std::cout << "list.assign(10, 6);" << std::endl;
	list.assign((size_t)10, 6);
	printList<int>(list);

	std::cout << "list.pop_front();" << std::endl;
	list.pop_front();
	printList<int>(list);

	std::cout << "list.clear();" << std::endl;
	list.clear();
	printList<int>(list);
	return (0);
}
