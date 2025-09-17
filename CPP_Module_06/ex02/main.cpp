/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:45:24 by ngaurama          #+#    #+#             */
/*   Updated: 2025/06/12 22:26:15 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void)
{
    int num = rand() % 3;
    if (num == 0)
        return new A;
    else if (num == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identified A!\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified B!\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified C!\n";
    else
        std::cout << "Unidentified\n";
}

void identify(Base& p)
{
    try
    {
        A &classA = dynamic_cast<A&>(p);
        (void)classA;
        std::cout << "Identified A!\n";
    }
    catch(...) {}
    try
    {
        B &classB = dynamic_cast<B&>(p);
        (void)classB;
        std::cout << "Identified B!\n";
    }
    catch(...) {}
    try
    {
        C &classC = dynamic_cast<C&>(p);
        (void)classC;
        std::cout << "Identified C!\n";
    }
    catch(...) {}
}

int main()
{
    srand(time(NULL));   
    Base *ptr = generate();
    identify(ptr);
    identify(*ptr);
    delete ptr;
    return 0;
}
