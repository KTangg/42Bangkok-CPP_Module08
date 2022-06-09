/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:17:14 by spoolpra          #+#    #+#             */
/*   Updated: 2022/06/09 11:42:50 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void) {return ;}
		MutantStack<T>(MutantStack<T> const &rhs) : std::stack<T>(rhs) {*this = rhs;}
		virtual ~MutantStack<T>(void) {return ;}

		MutantStack<T>	&operator=(MutantStack<T> const &rhs)
		{
			this->c = rhs.c;
			return *this;
		}

		// iterator type is in "c" container std::stack<T>::container_type::iterator
		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin(void) {return this->c.begin();}
		iterator	end(void) {return this->c.end();}
};

#endif
