/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 21:31:45 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/21 21:31:45 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
}

Point &Point::operator=(const Point &other) {
	// Cannot reassign const members _x and _y
	// Point objects are immutable after construction
	(void)other;
	return *this;
}

Point::~Point() {
}

Fixed Point::getX(void) const {
	return this->_x;
}

Fixed Point::getY(void) const {
	return this->_y;
}
