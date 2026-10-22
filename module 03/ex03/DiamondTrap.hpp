/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:53:37 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/22 16:53:37 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;

public:
	// Constructor
	DiamondTrap(std::string name);

	// Copy constructor
	DiamondTrap(const DiamondTrap& other);

	// Assignment operator
	DiamondTrap& operator=(const DiamondTrap& other);

	// Destructor
	~DiamondTrap();

	// Use ScavTrap's attack
	using ScavTrap::attack;

	// Special member function
	void whoAmI();
};

#endif
