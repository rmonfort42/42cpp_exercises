/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:52:53 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/22 16:52:53 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// Constructor
	FragTrap(std::string name);

	// Copy constructor
	FragTrap(const FragTrap& other);

	// Assignment operator
	FragTrap& operator=(const FragTrap& other);

	// Destructor
	~FragTrap();

	// Special member function
	void highFivesGuys(void);
};

#endif
