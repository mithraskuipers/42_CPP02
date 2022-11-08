/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:49:19 by mkuipers      #+#    #+#                 */
/*   Updated: 2022/11/08 14:38:36 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Orthodox Canonical Form is also known as Orthodox Canonical Class Form (OCCF)
// It means you classes need to have a default constructor, copy constructor
// destructor, and copy assignment operator.
// - default constructor: used internally to initialize objects and data members
//   when no other value is available.
// - copy constructor: used in the implementation of call-by-value parameters.
// - assignment operator: used to assign one value to another.
// - destructor: invoked when an object is deleted.

// Note: This is basically an extension of CPP02 EX00.
// The main() was copy-pasted from the subject.


// TODO: ADD OPERATOR OVERLOAD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include "./../includes/Fixed.hpp"

int	main( void )
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
	return 0;
}

/*
Below you find the output created by this program when running this particular main().

Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
*/
