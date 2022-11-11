/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:49:19 by mkuipers      #+#    #+#                 */
/*   Updated: 2022/11/11 11:19:29 by mikuiper      ########   odam.nl         */
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

int	main( void )
{
	Fixed		a;
	// Because * operator overload we can multiply classes.
	// Because of our constructors, we can give it both an int and float.
	// 5.05 becomes 5.05078 and 2 becomes 2.
	// In Fixed.cpp you see that the * operator simply takes what is left
	// (i.e. 'this') of it and what is right of it (provided argument)
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	
	std::cout << "a before ++a:\t" << a << std::endl;
	std::cout << "a after ++a:\t" << ++a << std::endl;
	std::cout << "a before a++:\t" << a << std::endl;
	std::cout << "a after a++:\t" << a++ << std::endl;
	std::cout << std::endl;
	std::cout << "a:\t\t" << a << std::endl;
	// This shows that 5.05 * 2 is not 10.10, but 10.1016
	std::cout << "b:\t\t" << b << std::endl;
	std::cout << "max(a, b):\t" << Fixed::max(a, b) << std::endl;

	// Operator overload demonstration lines
	// ++ operator
	// std::cout << a++ << std::endl; // a++ increment only done after printing, so will still show 0.0078125
	// std::cout << a << std::endl; // Now the a++ incrementation is done. It will print 0.0117188
	// std::cout << ++a << std::endl; // ++a increment is done before printing. It will now print 0.015625
	// -- operator
	// std::cout << a-- << std::endl; // a-- increment only done after printing, so will still show 0.015625
	// std::cout << a << std::endl; // Now the a-- incrementation is done. It will print 0.0117188
	// std::cout << --a << std::endl; // --a increment is done before printing. It will now print 0.0078125
	// == operator
	// int	test_equal;
	// test_equal = a==b; 
	// std::cout << "a==b: " << test_equal << std::endl;
	// != operator
	// int	test_notequal;
	// test_notequal = a!=b; 
	// std::cout << "a!=b: " << test_notequal << std::endl;
	return 0;
}

/*
Below you find the output created when running this main().

Default constructor called
Int constructor called
Float constructor called
Float constructor called
Destructor called
Destructor called
0 						<------------------------------
Copy constructor called
Copy assignment operator called
0.00390625				<------------------------------
Destructor called
0.00390625				<------------------------------
Copy constructor called
Copy assignment operator called
0.00390625				<------------------------------
Destructor called
0.0078125				<------------------------------
10.1016					<------------------------------
10.1016					<------------------------------
Destructor called
Destructor called
*/

// why bitshift?
// 