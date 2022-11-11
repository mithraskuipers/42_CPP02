/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:37:56 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/11/11 10:49:53 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

/******************************************************************************/
/* Constructors                                                               */
/******************************************************************************/

// Constructor
// To replicate the subject output, I commented out the print statement.
Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	_fixedValue = 0;
	return ;
}

// Int constructor.
// To replicate the subject output, I commented out the print statement.
Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
	// This will bitshift everything to the left, basically squaring it for each shifted bit.
	this->_fixedValue = intValue * (1 << this->_fractionalBits);
	return ;
}

// Float constructor.
// Uses roundf() as specified in the subject.
// To replicate the subject output, I commented out the print statement.
Fixed::Fixed(const float floatValue)
{
	// std::cout << "Float constructor called" << std::endl;
	// This will bitshift everything to the left, basically squaring it for each shifted bit.
	this->_fixedValue = roundf(floatValue * (1 << this->_fractionalBits));
	return ;
}

// Copy constructor.
// To replicate the subject output, I commented out the print statement.
Fixed::Fixed(const Fixed &Source)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = Source;
}

// Destructor.
// Automatically called when the object's life comes to an end (e.g. end of program).
// To replicate the subject output, I commented out the print statement.
Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

// Operator overloading via 'assignation operator'.
// Here we change the meaning (= overloading) of the equals sign (= operator).
// To replicate the subject output, I commented out the print statement.
Fixed	&Fixed::operator=(Fixed const &Number)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedValue = Number.getRawBits();
	return (*this);
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
int	Fixed::toInt(void) const
{
	return (this->_fixedValue) / (1 << this->_fractionalBits);
}

// To float converter.
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedValue) / (1 << this->_fractionalBits));
}

/******************************************************************************/
/* min / max                                                                  */
/******************************************************************************/

// min()
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

// min() for consts
Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

// max()
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

// max() for consts
Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (b);
	return (a);
}

/******************************************************************************/
/* operator overload                                                          */
/* assignation operator <<                                                    */
/******************************************************************************/

// Operator overloading via 'assignation operator'.
// Here we change the meaning (= overloading) of the insertion operator
// Inserts a floating-point representation of the fixed-point number into the
// output stream object passed as parameter.
// To replicate the subject output, I commented out the print statement.
Fixed	&Fixed::operator<<(Fixed const &Number)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedValue = Number.getRawBits();
	return (*this);
}

// This belongs to the << operator overloading above.
// std::ostream can write sequences of characters 
std::ostream	&operator<<(std::ostream &output, Fixed const &Number)
{
	output << Number.toFloat();
	return (output);
}

/******************************************************************************/
/* operator overload                                                          */
/* comparison operators > < >= <= == !=                                       */
/******************************************************************************/

// > operator overload
bool Fixed::operator>(Fixed const &Number) const
{
	return (this->_fixedValue > Number.getRawBits());
}

// < operator overload
bool Fixed::operator<(Fixed const &Number) const
{
	return (this->_fixedValue < Number.getRawBits());
}

// >= operator overload
bool Fixed::operator>=(Fixed const &Number) const
{
	return (this->_fixedValue >= Number.getRawBits());
}

// <= operator overload
bool Fixed::operator<=(Fixed const &Number) const
{
	return (this->_fixedValue <= Number.getRawBits());
}

// == operator overload
bool Fixed::operator==(Fixed const &Number) const
{
	return (this->_fixedValue == Number.getRawBits());
}

// != operator overload
bool Fixed::operator!=(Fixed const &Number) const
{
	return (this->_fixedValue != Number.getRawBits());
}

/******************************************************************************/
/* operator overload                                                          */
/* arithmetic operators + - * /                                               */
/******************************************************************************/

// overload +
Fixed	Fixed::operator+(Fixed const &Number) const
{
	return (Fixed(this->toFloat() + Number.toFloat()));
}

// overload - 
Fixed	Fixed::operator-(Fixed const &Number) const
{
	return (Fixed(this->toFloat() - Number.toFloat()));
}

// overload *
Fixed	Fixed::operator*(Fixed const &Number) const
{
	// std::cout << "* overload: this->toFloat() is: " << this->toFloat() << std::endl;
	// std::cout << "* overload: Number.toFloat() is:" << Number.toFloat() << std::endl;
	return (Fixed(this->toFloat() * Number.toFloat()));
}

// overload /
Fixed	Fixed::operator/(Fixed const &Number) const
{
	return (Fixed(this->toFloat() / Number.toFloat()));
}

/******************************************************************************/
/* operator overload                                                          */
/* incredement / decrement operators ++var var++ --var var--                  */
/******************************************************************************/

// ++ operator
Fixed Fixed::operator++(void)
{
	this->_fixedValue++;
	return (*this);
}

// ++ operator
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedValue++;
	return (tmp);
}

// -- operator
Fixed Fixed::operator--(void)
{
	this->_fixedValue--;
	return (*this);
}

// -- operator
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedValue--;
	return (tmp);
}
