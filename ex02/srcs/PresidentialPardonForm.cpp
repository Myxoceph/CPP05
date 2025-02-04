/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:49:22 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/04 18:31:30 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5)
{
	this->target = "42 Kocaeli";
	std::cout << GREEN"Default constructor for "CYAN << name << GREEN" called."RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget) : AForm("Presidential Pardon", 25, 5)
{
	this->target = newTarget;
	std::cout << GREEN"Constructor for "CYAN << name << GREEN" called."RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	*this = copy;
	std::cout << GREEN"Copy constructor for "CYAN << name << GREEN" called."RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		this->target = copy.target;
	}
	std::cout << GREEN"Copy assignment operator for "CYAN << name << GREEN" called."RESET << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREEN"Destructor for "CYAN << name << GREEN" called."RESET << std::endl;
}

std::string PresidentialPardonForm::getTarget()
{
	return (this->target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
	if (!getIsSigned())
		std::cout << RED"Bureaucrat "CYAN << executor.getName() << RED" cannot execute "BLUE << this->getName() << RED" to "BLUE << this->target << RED" because the form is not signed!"RESET << std::endl;
	if (executor.getGrade() > getReqExec())
		throw AForm::GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
