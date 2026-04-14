/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:44:18 by carlopez          #+#    #+#             */
/*   Updated: 2026/04/14 17:06:11 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>

class MutantStack : public std::stack<T> {

    public :
    MutantStack() : std::stack<T>() {}
    virtual ~MutantStack() {}
    MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) 
        {
            std::stack<T>::operator=(other);
        }
        return (*this);
    }
    
    typedef typename std::stack<T>::container_type::iterator iterator;
    
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
    
};


#endif