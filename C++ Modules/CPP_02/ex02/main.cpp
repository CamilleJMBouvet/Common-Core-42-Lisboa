/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:22:40 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/26 17:07:42 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);

}

/* int main(void)
{
	Fixed a(2.5f);
    Fixed b(3.7f);
    Fixed c(2.5f);

    //------------------ Greater than > ------------------
    std::cout << "a > b: " << (a > b) << std::endl; // Expected output: 0
    std::cout << "b > a: " << (b > a) << std::endl; // Expected output: 1
	std::cout << std::endl;
    //------------------ Less than < ------------------
    std::cout << "a < b: " << (a < b) << std::endl; // Expected output: 1
    std::cout << "b < a: " << (b < a) << std::endl; // Expected output: 0
	std::cout << std::endl;
    //------------------ Greater than or equal to >= ------------------
    std::cout << "a >= b: " << (a >= b) << std::endl; // Expected output: 0
    std::cout << "b >= a: " << (b >= a) << std::endl; // Expected output: 1
    std::cout << "a >= c: " << (a >= c) << std::endl; // Expected output: 1
	std::cout << std::endl;
    //------------------ Less than or equal to <= ------------------
    std::cout << "a <= b: " << (a <= b) << std::endl; // Expected output: 1
    std::cout << "b <= a: " << (b <= a) << std::endl; // Expected output: 0
    std::cout << "a <= c: " << (a <= c) << std::endl; // Expected output: 1
	std::cout << std::endl;
    //------------------ Equal to == ------------------
    std::cout << "a == b: " << (a == b) << std::endl; // Expected output: 0
    std::cout << "a == c: " << (a == c) << std::endl; // Expected output: 1
	std::cout << std::endl;
    //------------------ Not equal to != ------------------
    std::cout << "a != b: " << (a != b) << std::endl; // Expected output: 1
    std::cout << "a != c: " << (a != c) << std::endl; // Expected output: 0
	std::cout << std::endl;
    //------------------ Addition + ------------------
    std::cout << "a + b: " << (a + b) << std::endl; // Expected output: 6.2
	std::cout << std::endl;
    //------------------ Subtraction - ------------------
    std::cout << "a - b: " << (a - b) << std::endl; // Expected output: -1.2
	std::cout << std::endl;
    //------------------ Multiplication * ------------------
    std::cout << "a * b: " << (a * b) << std::endl; // Expected output: 9.25
	std::cout << std::endl;
    //------------------ Division / ------------------
    std::cout << "a / b: " << (a / b) << std::endl; // Expected output: 0.675
	std::cout << std::endl;

    return 0;
} */
