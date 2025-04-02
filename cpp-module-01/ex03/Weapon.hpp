/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:44:59 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 09:14:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
public:
	Weapon(void);
	Weapon(const std::string &);
	Weapon(const Weapon &);
	Weapon &operator=(const Weapon &);
	~Weapon();

	const std::string &getType(void) const;
	void setType(const std::string &);

private:
	std::string __type;
};
