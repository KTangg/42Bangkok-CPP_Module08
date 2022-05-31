/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:47:53 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/31 10:22:12 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

int	main(void)
{
	// Test vector
	std::cout << "Test Vector container" << std::endl;
	std::vector<int> vec(20, 42);

	try
	{
		std::vector<int>::iterator it = easyfind<std::vector<int> > (vec, 41);
		std::cout << *it << " found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator it = easyfind<std::vector<int> > (vec, 42);
		std::cout << *it << " found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test list
	std::cout << "Test List container" << std::endl;
	std::list<int>	intList;

	intList.push_back(42);
	intList.push_back(0);
	intList.push_front(123);
	intList.push_front(2147483647);

	try
	{
		std::list<int>::iterator it = easyfind<std::list<int> > (intList, 41);
		std::cout << *it << " found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator it = easyfind<std::list<int> > (intList, 123);
		std::cout << *it << " found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator it = easyfind<std::list<int> > (intList, 0);
		std::cout << *it << " found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
