/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:24:29 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/08 16:25:33 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) { _type = type; }

const std::string& Weapon::getType() const { return _type; }

void Weapon::setType(std::string type) { _type = type; }
