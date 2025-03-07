/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:04:37 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/07 17:56:57 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN"### Default constructor for "CYAN << "Intern" << GREEN" called. ###"RESET << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	std::cout << GREEN"### Copy constructor for "CYAN << "Intern" << GREEN" called. ###"RESET << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	std::cout << GREEN"### Copy assignment operator for "CYAN << "Intern" << GREEN" called. ###"RESET << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << GREEN"### Destructor for "CYAN << "Intern" << GREEN" called. ###"RESET << std::endl;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Intern: Form Not Found";
}

AForm *Intern::makePresidentialPardon(std::string target)
{
	std::cout << WHITE"Intern creates Presidential Pardon Form"RESET << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyRequest(std::string target)
{
	std::cout << WHITE"Intern creates Robotomy Request Form"RESET << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubberyCreation(std::string target)
{
	std::cout << WHITE"Intern creates Shrubbery Creation Form"RESET << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target) 
{
	std::string names[3] = {"presidential pardon", "robotomy request","shrubbery creation" };

	AForm* (Intern::*ptr[3])(std::string) = {
		&Intern::makePresidentialPardon,
		&Intern::makeRobotomyRequest,
		&Intern::makeShrubberyCreation,
	};
	
	for (size_t i = 0; i < 3; ++i) {
		if (names[i] == formName)
			return (this->*ptr[i])(target);
	}
	throw Intern::FormNotFoundException();
}
