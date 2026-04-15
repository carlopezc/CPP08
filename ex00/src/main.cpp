/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:11:49 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/04/15 12:53:30 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>

int main (void)
{
    std::vector<int> v;
    std::vector<int>::iterator i;

    v.push_back(1);
    v.push_back(2);
    v.push_back(9);
    v.push_back(100);
    
    std::cout << "--- PRUEBA 1 VECTOR: Buscar un numero que SI existe ---" << std::endl;
    try {
        i = easyfind(v, 9);
        std::cout << "¡Éxito! Encontrado: " << *i << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 2 VECTOR: Buscar un numero que NO existe ---" << std::endl;
    try {
        i = easyfind(v, 99);
        std::cout << "¡Éxito! Encontrado: " << *i << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl; 
    }

    std::list<int> l;
    std::list<int>::iterator it_list;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    std::cout << "\n--- PRUEBA 3 LISTA: Buscar en una lista---" << std::endl;
    try {
        it_list = easyfind(l, 20);
        std::cout << "¡Éxito! Encontrado: " << *it_list << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 4 LISTA: Buscar un numero que NO existe ---" << std::endl;
    try {
        it_list = easyfind(l, 99);
        std::cout << "¡Éxito! Encontrado: " << *it_list << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl; 
    }
    return 0;
}