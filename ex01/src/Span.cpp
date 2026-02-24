/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:11:04 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/02/24 12:50:38 by carlotalcd       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span() : N(0) {
    std::cout << "Default Span constructor called" << std::endl;
}

Span::Span (unsigned int N) : N(N)
{
    std::cout << "Parametric Span constructor called" << std::endl;
}
        
Span::~Span() {
    std::cout << "Default Span destructor called" << std::endl;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Assignment constructor called" << std::endl;
    if (this != &other){
        this->N = other.N;
        this->v = other.v;
    }
    return (*this);
}

Span::Span(const Span& other) : N(other.N), v(other.v) {
    std::cout << "Copy constructor called" << std::endl;
}

void Span::addNumber(int number)
{
    if (this->v.size() >= this->N)
        throw FullException();
    else
        this->v.push_back(number);
}

unsigned int Span::longestSpan() const{

    std::vector<int>::const_iterator min;
    std::vector<int>::const_iterator max;


    if (this->v.size() <= 1)
        throw EmptyException();
    
    min = std::min_element(this->v.begin(), this->v.end());
    max = std::max_element(this->v.begin(), this->v.end());

    return (*max - *min);
}

unsigned int Span::shortestSpan() const{

    unsigned int min_dist;
    size_t iterator;
    unsigned int current_dist;

    if (this->v.size() <= 1)
        throw EmptyException();

    std::vector<int> copia = this->v;

    std::sort(copia.begin(), copia.end());
    min_dist = copia[1] - copia[0];
    
    iterator = 1;
    while (iterator < copia.size())
    {
        current_dist = copia[iterator] - copia[iterator - 1];
        if (current_dist < min_dist)
            min_dist = current_dist;
        iterator++;
    }
    return (min_dist);
}