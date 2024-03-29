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

class	Fixed {
	public:
		Fixed(void);								// Constructor
		Fixed(Fixed const &Source);					// Copy constructor
		~Fixed(void);								// Destructor
		Fixed	&operator=(Fixed const &Number);	// Implicitly-declared copy assignment operator
		int		getRawBits(void) const;				// Getter method
		void	setRawBits(int const raw);			// Setter method
	private:
		int					_fixedValue;
		static int const	_fractionalBits;
};

#endif