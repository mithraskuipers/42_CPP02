/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:49:19 by mkuipers      #+#    #+#                 */
/*   Updated: 2022/11/07 14:21:24 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Orthodox Canonical Form
// Orthodox Canonical Form is also known as Orthodox Canonical Class Form (OCCF)
// It means you classes need to have a default constructor, copy constructor
// destructor, and copy assignment operator.
// - default constructor: used internally to initialize objects and data members
//   when no other value is available.
// - copy constructor: used in the implementation of call-by-value parameters.
// - assignment operator: used to assign one value to another.
// - destructor: invoked when an object is deleted.

// The main() was copy-pasted from the subject.

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
