/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:49:16 by mkuipers      #+#    #+#                 */
/*   Updated: 2022/11/08 14:34:36 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Constructor
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixedValue = 0;
	return ;
}

// Int constructor.
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	
	// This will bitshift everything to the left, basically squaring it for each shifted bit.
	this->_fixedValue = intValue * (1 << this->_fractionalBits);
	return ;
}

// Float constructor.
// Uses roundf() as specified in the subject.
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;

	// This will bitshift everything to the left, basically squaring it for each shifted bit.
	this->_fixedValue = roundf(floatValue * (1 << this->_fractionalBits));
	return ;
}

// Copy constructor.
Fixed::Fixed(const Fixed &Source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = Source;
}

// Operator overloading via 'assignation operator'.
// Here we change the meaning (= overloading) of the equals sign (= operator).
Fixed	&Fixed::operator=(Fixed const &Decimals)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedValue = Decimals.getRawBits();
	return (*this);
}

// Operator overloading via 'assignation operator'.
// Here we change the meaning (= overloading) of the insertion operator
// Inserts a floating-point representation of the fixed-point number into the
// output stream object passed as parameter.
Fixed	&Fixed::operator<<(Fixed const &Decimals)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedValue = Decimals.getRawBits();
	return (*this);
}

// This belongs to the << operator overloading above.
// std::ostream can write sequences of characters 
std::ostream	&operator<<(std::ostream &output, Fixed const &Decimals)
{
	return (output << Decimals.toFloat());
}

// Destructor.
// Automatically called when the object's life comes to an end (e.g. end of program).
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;	
}

// Getter method.
// Basically provided in the subject.
// It does hardly anything. It serves only to access the private _fixedValue.
// To replicate the subject output, I commented out the print statement.
int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

// Setter method.
// Basically provided in the subject.
// It does hardly anything. It serves only to access the private _fixedValue.
// To replicate the subject output, I commented out the print statement.
void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called"<< std::endl;
	this->_fixedValue = raw;
}

// To int converter.
int		Fixed::toInt(void) const
{
	return (this->_fixedValue) / (1 << this->_fractionalBits);
}

// To float converter.
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedValue) / (1 << this->_fractionalBits));
}
