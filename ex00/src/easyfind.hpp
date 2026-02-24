/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:21:11 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/02/24 11:37:25 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
    public :

        NotFoundException() throw() {}
        NotFoundException(const NotFoundException&) throw() {}
        NotFoundException& operator=(const NotFoundException&) throw() { return *this; }
        virtual ~NotFoundException() throw() {}

        virtual const char * what() const throw() {
            return ("Error: Número no encontrado en el contenedor");
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