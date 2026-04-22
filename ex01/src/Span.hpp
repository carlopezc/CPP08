/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:55:06 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/04/22 18:15:15 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>

class FullException : public std::exception {
    public :

        virtual const char * what() const throw() {
            return ("Error: Full array");
        }
};

class EmptyException : public std::exception {
    public :

        virtual const char * what() const throw() {
            return ("Error: insuficient elements");
        }
};

class Span {
    
    private:
        unsigned int N;
        std::vector<int> v;

    public:
        Span();
        Span (unsigned int N);
        ~Span();
        Span& operator=(const Span&);
        Span(const Span& other);
        
        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end) {
            unsigned int distance = std::distance(begin, end);
            if (this->v.size() + distance > this->N)
                throw FullException();
            this->v.insert(this->v.end(), begin, end);
        };
};

#endif