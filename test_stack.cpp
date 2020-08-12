/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 04:08:02 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/12 04:27:03 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include <stack>
#include "colors.h"
#include "utils.hpp"
#include "Iterator.hpp"
#include "List.hpp"
#include "Stack.hpp"

int			main(void)
{
	ft::Stack<int> mystack;

	std::cout << "ft::Stack<" << _PURPLE << "int" << _END << "> mystack" << std::endl;
	std::cout << std::endl;


	std::cout << _WHITE << "# empty" << _END << std::endl;
	std::cout << "mystack.empty(): " <<  mystack.empty() << std::endl;
	std::cout << "mystack.size(): " << mystack.size() << std::endl;
	std::cout << _WHITE << "# one element" << _END << std::endl;
	mystack.push(42);
	std::cout << "mystack.push(42)" << std::endl;
	std::cout << "mystack.empty(): " <<  mystack.empty() << std::endl;
	std::cout << "mystack.size(): " << mystack.size() << std::endl;
	std::cout << "mystack.top(): " << mystack.top() << std::endl;
	std::cout << _WHITE << "# two element" << _END << std::endl;
	mystack.push(2);
	std::cout << "mystack.push(2)" << std::endl;
	std::cout << "mystack.size(): " << mystack.size() << std::endl;
	std::cout << "mystack.top(): " << mystack.top() << std::endl;
	std::cout << _WHITE << "# pop element" << _END << std::endl;
	mystack.pop();
	std::cout << "mystack.pop()" << std::endl;
	std::cout << "mystack.size(): " << mystack.size() << std::endl;
	std::cout << "mystack.top(): " << mystack.top() << std::endl;
	std::cout << std::endl;

	ft::Stack<int, ft::List<int> > mystack2;

	std::cout << "ft::Stack<" << _PURPLE << "int" << _END << ", " << _PURPLE << "ft::List" << _END << "> mystack2" << std::endl;
	std::cout << std::endl;


	std::cout << _WHITE << "# empty" << _END << std::endl;
	std::cout << "mystack2.empty(): " <<  mystack2.empty() << std::endl;
	std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	std::cout << _WHITE << "# one element" << _END << std::endl;
	mystack2.push(42);
	std::cout << "mystack2.push(42)" << std::endl;
	std::cout << "mystack2.empty(): " <<  mystack2.empty() << std::endl;
	std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	std::cout << _WHITE << "# two element" << _END << std::endl;
	mystack2.push(2);
	std::cout << "mystack2.push(2)" << std::endl;
	std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	std::cout << _WHITE << "# pop element" << _END << std::endl;
	mystack2.pop();
	std::cout << "mystack2.pop()" << std::endl;
	std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	std::cout << std::endl;

	std::cout << _WHITE << "# test cpy and equality" << _END << std::endl;
	ft::Stack<int>	cpystack = mystack;
	std::cout << "ft::Stack<" << _PURPLE << "int" << _END << "> cpystack = mystack" << std::endl;
	std::cout << std::endl;

	std::cout << "cpystack == mystack:" << (cpystack == mystack) << std::endl;
	cpystack.push(7);
	std::cout << "cpystack.push(7)" << std::endl;
	std::cout << "cpystack == mystack:" << (cpystack == mystack) << std::endl;
	return (0);
}
