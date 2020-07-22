/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 04:32:26 by lmartin           #+#    #+#             */
/*   Updated: 2020/07/22 04:34:40 by lmartin          ###   ########.fr       */
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
	std::cout << "---------------------- " << _GREEN << "[";
	while (i != list.end())
	{
		std::cout << *i << ", ";
		i++;
		d++;
	}
	if (d)
		std::cout << *i << "]" << _END << std::endl;
	else
		std::cout << "]" << _END << std::endl;
	std::cout << std::endl;
}

int		main(void)
{
	ft::List<int> list = ft::List<int>();
	
	std::srand(std::time(nullptr));
	std::cout << "ft::List<int> list = ft::List<int>();" << std::endl;
	printList<int>(list);
	for(int i = 0; i < 5; i++)
	{
		std::cout << "list.push_back(" << i << ");" << std::endl;
		list.push_back(i);
	}
	printList<int>(list);

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

	std::cout << "list.pop_front();" << std::endl;
	list.pop_front();
	printList<int>(list);

	std::cout << "list.clear();" << std::endl;
	list.clear();
	printList<int>(list);
	return (0);
}
