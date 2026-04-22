/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:21:11 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/04/22 18:07:34 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
    public :
        virtual const char * what() const throw() {
            return ("Error: Number not found");
        }
};

template <typename T>

typename T::iterator easyfind(T& cont, int value)
{
    typename T::iterator i;

    i = std::find(cont.begin(), cont.end(), value);
    if (i != cont.end())
        return (i);
    else
        throw NotFoundException();
        
}

#endif