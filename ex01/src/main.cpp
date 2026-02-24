/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:11:49 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/02/24 12:53:06 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "--- Test 1: Prueba basica del Subject ---" << std::endl;
    try 
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span (esperado 2): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (esperado 14): " << sp.longestSpan() << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Rendimiento con 10.000 numeros ---" << std::endl;
    try 
    {
        Span sp_grande(10000);
        std::vector<int> muchos_numeros;
        
        srand(time(NULL)); 
        
        for (int i = 0; i < 10000; i++)
        {
            muchos_numeros.push_back(rand() % 1000000);
        }
        
        std::cout << "Insertando 10.000 numeros con addNumbers()..." << std::endl;
        sp_grande.addNumbers(muchos_numeros.begin(), muchos_numeros.end());
        std::cout << "Insercion completada con exito." << std::endl;
        
        std::cout << "Shortest span calculado: " << sp_grande.shortestSpan() << std::endl;
        std::cout << "Longest span calculado: " << sp_grande.longestSpan() << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Excepcion por elementos insuficientes ---" << std::endl;
    try 
    {
        Span sp_vacio(5);
        std::cout << "Anadiendo 1 numero e intentando calcular el span..." << std::endl;
        sp_vacio.addNumber(42);
        sp_vacio.shortestSpan(); // Esto debe lanzar la excepcion
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Excepcion capturada: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Excepcion por superar el limite ---" << std::endl;
    try 
    {
        Span sp_lleno(2);
        std::cout << "Anadiendo 3 numeros a un Span de tamano 2..." << std::endl;
        sp_lleno.addNumber(1);
        sp_lleno.addNumber(2);
        sp_lleno.addNumber(3); // Esto debe lanzar la excepcion
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Excepcion capturada: " << e.what() << std::endl;
    }

    return 0;
}