/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:10:28 by carlopez          #+#    #+#             */
/*   Updated: 2026/04/14 17:13:57 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include "MutantStack.hpp"

void test_comparativo() {
    std::cout << "\n--- COMPARATIVA: MutantStack vs std::list ---" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);

    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    
    std::cout << std::endl;

    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    mlist.push_back(3);

    std::cout << "std::list:   ";
    for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it)
        std::cout << *it << " ";
    
    std::cout << std::endl;
}