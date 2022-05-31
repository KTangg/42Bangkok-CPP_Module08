/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:27:39 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/31 10:13:32 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

# include <iostream>
# include <algorithm>

class MemberNotFound : public std::exception
{
	public:
		virtual const char	*what(void) const throw()
		{
			return "Error: Member not found";
		}
};

template <typename T>
typename T::iterator	easyfind(T &container, int const i)
{
	typename T::iterator	it = find(container.begin(), container.end(), i);
	if (it == container.end())
	{
		throw MemberNotFound();
	}
	return it;
}

#endif
