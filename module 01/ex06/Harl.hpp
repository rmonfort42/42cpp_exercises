/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:43:08 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/21 16:43:08 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
private:
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;

public:
	Harl(void);
	~Harl(void);

	void complain(const std::string& level) const;
};

#endif
