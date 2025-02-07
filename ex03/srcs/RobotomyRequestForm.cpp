/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:52:15 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/07 15:57:25 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{
	this->target = "42 Kocaeli";
	std::cout << GREEN"### Default constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget) : AForm("Robotomy Request", 72, 45)
{
	this->target = newTarget;
	std::cout << GREEN"### Constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	*this = copy;
	std::cout << GREEN"### Copy constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		this->target = copy.target;
	}
	std::cout << GREEN"### Copy assignment operator for "CYAN << name << GREEN" called. ###"RESET << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREEN"### Destructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

std::string RobotomyRequestForm::getTarget()
{
	return (this->target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
	if (!getIsSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getReqExec())
		throw AForm::GradeTooLowException();
	std::cout << BLUE"🤖🤖 ---- Drilling noises ---- 🤖🤖"RESET << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << BLUE << target << WHITE" has been robotomized successfully."RESET << std::endl;
	else
		std::cout << WHITE"Robotomy of "BLUE << target << RED" failed."RESET << std::endl;
}
