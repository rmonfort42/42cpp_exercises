/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:48:42 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/08 16:49:18 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);
	void attack(void) const;
private:
	std::string _name;
	Weapon* _weapon;
};

#endif
