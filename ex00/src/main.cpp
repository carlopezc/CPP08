/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:11:49 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/02/24 11:47:42 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

int main (void)
{
    std::vector<int> v;
    std::vector<int>::iterator i;

    v.push_back(1);
    v.push_back(2);
    v.push_back(9);
    v.push_back(100);
    
    std::cout << "--- PRUEBA 1: Buscar un numero que SI existe ---" << std::endl;
    try {
        i = easyfind(v, 9);
        std::cout << "¡Éxito! Encontrado: " << *i << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 2: Buscar un numero que NO existe ---" << std::endl;
    try {
        i = easyfind(v, 99);
        std::cout << "¡Éxito! Encontrado: " << *i << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl; 
    }
    return 0;
}