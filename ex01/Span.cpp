/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:57:44 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/31 16:08:25 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
}

Span::Span(unsigned int n) : _max_size(n), _vector()
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span(void)
{
}

Span	&Span::operator=(Span const &rhs)
{
	_max_size = rhs._max_size;
	_vector = rhs._vector;
	return (*this);
}

size_t	Span::size(void) const
{
	return _vector.size();
}

void	Span::addNumber(int i)
{
	if (_vector.size() < _max_size)
	{
		_vector.push_back(i);
	}
	else
	{
		throw NoSlotLeftError();
	}
}

void	Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	for (std::vector<int>::iterator it = first; it != last; it++)
	{
		try
		{
			addNumber(*it);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			break ;
		}
	}
}

int	Span::shortestSpan(void)
{
	if (_vector.size() <= 1)
	{
		throw TooFewIntegerError();
	}
	int	min = INT_MAX;
	for (std::vector<int>::iterator it = _vector.begin(); it < _vector.end() - 1; it++)
	{
		int	diff = *it - *(it + 1);
		if (abs(diff) < min)
		{
			min = abs(diff);
		}
	}
	return min;
}

int	Span::longestSpan(void)
{
	if (_vector.size() <= 1)
	{
		throw TooFewIntegerError();
	}
	int	max = INT_MIN;
	for (std::vector<int>::iterator it = _vector.begin(); it < _vector.end() - 1; it++)
	{
		int	diff = *it - *(it + 1);
		if (abs(diff) > max)
		{
			max = abs(diff);
		}
	}
	return max;
}
