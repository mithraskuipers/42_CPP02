/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:49:19 by mkuipers      #+#    #+#                 */
/*   Updated: 2022/11/11 11:21:08 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//	Orthodox Canonical Form is also known as Orthodox Canonical Class Form.
//	It means you classes need to have a default constructor, copy constructor
//	destructor, and copy assignment operator.
//	- default constructor: used internally to initialize objects and data members
//	when no other value is available.
//	- copy constructor: a copy constructor is a member function that initializes
//	an object using another object of the same class
//	- assignment operator: used to assign one value to another.
//	- destructor: invoked when an object is deleted.

//	const to the right side of the method, makes the method a "constant" member 
//	function. This means that the function is denied permission to change the
//	values of the data members in their class.

// >>
// When shifting right with a logical right shift (>>), the least-significant 
// bit is lost and a 0 is inserted on the right-side. For positive numbers, a 
// single logical right shift divides a number by 2, removing any remainders. 

// <<
// When shifting left with a logical left shift (<<), the most-significant
// is lost, and a 0 bit is inserted on the left-side. For positive numbers, a 
// single logical left shift multiplies a number by 2, possibly introducing
// inaccurate remainders.

#include "./../includes/Fixed.hpp"

int main(void)
{
	Fixed a; 	// This calls the constructor
	Fixed b(a);	// This calls the copy constructor, copy assignment operator, and getRawBits().
	Fixed c; 	// This calls the constructor

	c = b;		// This calls the copy assignment operator and getRawBits method
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
