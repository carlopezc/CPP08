/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlotalcd <carlotalcd@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:55:06 by carlotalcd        #+#    #+#             */
/*   Updated: 2026/04/15 17:19:05 by carlotalcd       ###   ########.fr       */
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

        FullException() throw() {}
        FullException(const FullException&) throw() {}
        FullException& operator=(const FullException&) throw() { return *this; }
        virtual ~FullException() throw() {}

        virtual const char * what() const throw() {
            return ("Error: Full array");
        }
};

class EmptyException : public std::exception {
    public :

        EmptyException() throw() {}
        EmptyException(const EmptyException&) throw() {}
        EmptyException& operator=(const EmptyException&) throw() { return *this; }
        virtual ~EmptyException() throw() {}

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