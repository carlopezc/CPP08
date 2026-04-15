/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:43:21 by carlopez          #+#    #+#             */
/*   Updated: 2026/04/15 17:27:29 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

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

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    test_comparativo();
    return (0);
}