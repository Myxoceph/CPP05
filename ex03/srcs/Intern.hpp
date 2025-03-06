/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:04:40 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/06 15:30:44 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	public:
			Intern();
			Intern(Intern const &copy);
			Intern &operator=(Intern const &copy);
			~Intern();
			AForm *makeForm(std::string formName, std::string target);
			AForm* makePresidentialPardon(std::string target);
			AForm* makeRobotomyRequest(std::string target);
			AForm* makeShrubberyCreation(std::string target);

		class FormNotFoundException: public std::exception
		{
			const char* what() const throw();
		};
};

#endif
