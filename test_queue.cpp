/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 04:28:01 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/12 04:50:11 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <queue>
#include "colors.h"
#include "utils.hpp"
#include "Iterator.hpp"
#include "List.hpp"
#include "Queue.hpp"

void		test_queue(void)
{
	std::cout << _WHITE << "# test_queue" << _END << std::endl;
	std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	std::cout << "/* ********************************************************************** */" << _END << std::endl;
	ft::Queue<int> myqueue;

	std::cout << "ft::Queue<" << _PURPLE << "int" << _END << "> myqueue" << std::endl;
	std::cout << std::endl;


	std::cout << _WHITE << "# empty" << _END << std::endl;
	std::cout << "myqueue.empty(): " <<  myqueue.empty() << std::endl;
	std::cout << "myqueue.size(): " << myqueue.size() << std::endl;
	std::cout << _WHITE << "# one element" << _END << std::endl;
	myqueue.push(42);
	std::cout << "myqueue.push(42)" << std::endl;
	std::cout << "myqueue.empty(): " <<  myqueue.empty() << std::endl;
	std::cout << "myqueue.size(): " << myqueue.size() << std::endl;
	std::cout << "myqueue.back(): " << myqueue.back() << std::endl;
	std::cout << "myqueue.front(): " << myqueue.front() << std::endl;
	std::cout << _WHITE << "# two element" << _END << std::endl;
	myqueue.push(2);
	std::cout << "myqueue.push(2)" << std::endl;
	std::cout << "myqueue.size(): " << myqueue.size() << std::endl;
	std::cout << "myqueue.back(): " << myqueue.back() << std::endl;
	std::cout << "myqueue.front(): " << myqueue.front() << std::endl;
	std::cout << _WHITE << "# pop element" << _END << std::endl;
	myqueue.pop();
	std::cout << "myqueue.pop()" << std::endl;
	std::cout << "myqueue.size(): " << myqueue.size() << std::endl;
	std::cout << "myqueue.back(): " << myqueue.back() << std::endl;
	std::cout << "myqueue.front(): " << myqueue.front() << std::endl;
	std::cout << std::endl;

	ft::Queue<int, ft::List<int> > myqueue2;

	std::cout << "ft::Queue<" << _PURPLE << "int" << _END << ", " << _PURPLE << "ft::List" << _END << "> myqueue2" << std::endl;
	std::cout << std::endl;


	std::cout << _WHITE << "# empty" << _END << std::endl;
	std::cout << "myqueue2.empty(): " <<  myqueue2.empty() << std::endl;
	std::cout << "myqueue2.size(): " << myqueue2.size() << std::endl;
	std::cout << _WHITE << "# one element" << _END << std::endl;
	myqueue2.push(42);
	std::cout << "myqueue2.push(42)" << std::endl;
	std::cout << "myqueue2.empty(): " <<  myqueue2.empty() << std::endl;
	std::cout << "myqueue2.size(): " << myqueue2.size() << std::endl;
	std::cout << "myqueue.back(): " << myqueue.back() << std::endl;
	std::cout << "myqueue2.front(): " << myqueue2.front() << std::endl;
	std::cout << _WHITE << "# two element" << _END << std::endl;
	myqueue2.push(2);
	std::cout << "myqueue2.push(2)" << std::endl;
	std::cout << "myqueue2.size(): " << myqueue2.size() << std::endl;
	std::cout << "myqueue.back(): " << myqueue.back() << std::endl;
	std::cout << "myqueue2.front(): " << myqueue2.front() << std::endl;
	std::cout << _WHITE << "# pop element" << _END << std::endl;
	myqueue2.pop();
	std::cout << "myqueue2.pop()" << std::endl;
	std::cout << "myqueue2.size(): " << myqueue2.size() << std::endl;
	std::cout << "myqueue.back(): " << myqueue.back() << std::endl;
	std::cout << "myqueue2.front(): " << myqueue2.front() << std::endl;
	std::cout << std::endl;

	std::cout << _WHITE << "# test cpy and equality" << _END << std::endl;
	ft::Queue<int>	cpyqueue = myqueue;
	std::cout << "ft::queue<" << _PURPLE << "int" << _END << "> cpyqueue = myqueue" << std::endl;
	std::cout << std::endl;

	std::cout << "cpyqueue == myqueue:" << (cpyqueue == myqueue) << std::endl;
	cpyqueue.push(7);
	std::cout << "cpyqueue.push(7)" << std::endl;
	std::cout << "cpyqueue == myqueue:" << (cpyqueue == myqueue) << std::endl;
}
