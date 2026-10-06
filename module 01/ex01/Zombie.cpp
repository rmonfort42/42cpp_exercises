/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:23:18 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/06 16:23:20 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	_name = "";
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " ..." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

std::string Zombie::getName(void) const
{
	return _name;
}
