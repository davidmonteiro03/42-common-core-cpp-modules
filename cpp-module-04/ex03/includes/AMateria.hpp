/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:31:11 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 11:23:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class AMateria
{
public:
	AMateria(const std::string &);
	AMateria(const AMateria &);
	AMateria &operator=(const AMateria &);
	virtual ~AMateria();

	const std::string &getType(void) const;
	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &);

protected:
	std::string _type;
};
