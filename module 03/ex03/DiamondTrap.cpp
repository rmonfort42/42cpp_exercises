/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:53:33 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/22 16:53:33 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	// With virtual inheritance there is only ONE shared ClapTrap sub-object.
	// We must use hardcoded values to guarantee correctness:
	// HP from FragTrap (100), EP from ScavTrap (50), AD from FragTrap (30)
	_hitPoints    = 100; // FragTrap value
	_energyPoints = 50;  // ScavTrap value
	_attackDamage = 30;  // FragTrap value
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

// Who am I
void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
