/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:49:12 by mkuipers      #+#    #+#                 */
/*   Updated: 2022/11/08 14:27:08 by mikuiper      ########   odam.nl         */
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
	private:
		int					_fixedValue;
		static int const	_fractionalBits;
};

// Prototype
std::ostream	&operator<<(std::ostream &output, Fixed const &Number);

#endif
