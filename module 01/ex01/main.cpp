/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:05:00 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/06 17:05:00 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	std::cout << "--- horde of 5 ---" << std::endl;
	Zombie* horde = zombieHorde(5, "Walker");
	if (!horde)
	{
		std::cout << "zombieHorde returned NULL" << std::endl;
		return 1;
	}
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;

	std::cout << "--- horde of 1 ---" << std::endl;
	Zombie* one = zombieHorde(1, "Solo");
	one[0].announce();
	delete[] one;

	std::cout << "--- N = 0 ---" << std::endl;
	Zombie* none = zombieHorde(0, "Nobody");
	if (!none)
		std::cout << "no zombies allocated, pointer is NULL" << std::endl;

	std::cout << "--- done ---" << std::endl;
	return 0;
}
