/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:49:12 by mkuipers      #+#    #+#                 */
/*   Updated: 2022/10/25 16:55:47 by mkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _raw;
		static int const _fract_bits = 8;       
}

#endif