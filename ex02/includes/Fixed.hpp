/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:49:12 by mkuipers      #+#    #+#                 */
/*   Updated: 2022/11/11 09:33:32 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
	public:
		Fixed(void);								// Constructor
		Fixed(const int intValue);					// New: This will convert the int to float
		Fixed(const float floatValue);				// New: This will convert the float to 
		Fixed(Fixed const &Source);					// Copy constructor
		~Fixed(void);								// Destructor
		Fixed	&operator=(Fixed const &Number);	// Implicitly-declared copy assignment operator
		Fixed	&operator<<(Fixed const &Number);	// Overload the insertion operator
		int		getRawBits(void) const;				// Getter method
		void	setRawBits(int const raw);			// Setter method
		int		toInt(void) const;					// New: Converts the fixed-point value to int value
		float	toFloat(void) const;				// New: Converts the fixed-point value to floating-point value

		// Prototypes methods: min / max
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);

		// Operator overload: Comparison operators
		// The lines below say that the comparison operators will get different meanings
		// The new meanings can be found in Fixed.cpp		
		bool	operator>(Fixed const &Number) const;
		bool	operator<(Fixed const &Number) const;
		bool	operator>=(Fixed const &Number) const;
		bool	operator<=(Fixed const &Number) const;
		bool	operator==(Fixed const &Number) const;
		bool	operator!=(Fixed const &Number) const;

		// Operator overload: Arithmetic operators
		// The lines below say that the arithmetic s will get different meanings
		// The new meanings can be found in Fixed.cpp
		Fixed	operator+(Fixed const &Number) const;
		Fixed	operator-(Fixed const &Number) const;
		Fixed	operator*(Fixed const &Number) const;
		Fixed	operator/(Fixed const &Number) const;

		// Operator overload: Increment/Decrement operators
		// The lines below say that the comparison operators will get different meanings
		// The new meanings can be found in Fixed.cpp
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);
	private:
		int					_fixedValue;
		static int const	_fractionalBits;
};

// Prototypes
// Operator overload: <<
std::ostream	&operator<<(std::ostream &output, Fixed const &Number);

#endif
