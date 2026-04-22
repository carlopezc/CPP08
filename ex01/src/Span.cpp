/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:11:04 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/04/22 18:33:52 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span() : N(0) {}

Span::Span (unsigned int N) : N(N) {}
        
Span::~Span() {}

Span& Span::operator=(const Span& other) {
    std::cout << "Assignment constructor called" << std::endl;
    if (this != &other){
        this->N = other.N;
        this->v = other.v;
    }
    return (*this);
}

Span::Span(const Span& other) : N(other.N), v(other.v) {}

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

    if (this->v.size() <= 1)
        throw EmptyException();

    std::vector<int> copia = this->v;
    std::sort(copia.begin(), copia.end());
    
    std::vector<int>::iterator it = copia.begin() + 1;
    
    unsigned int min_dist = *it - *(it - 1);
    unsigned int current_dist;
    
    while (it != copia.end())
    {
        current_dist = *it - *(it - 1);
        if (current_dist < min_dist)
            min_dist = current_dist;
        it++;
    }
    return (min_dist);
}