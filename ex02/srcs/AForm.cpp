/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:00:46 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/07 16:36:24 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("abakirca"), reqSign(42), reqExec(21)
{
	this->isSigned = false;
	std::cout << GREEN"### Default constructor for "CYAN << name << GREEN" Aform called. ###"RESET << std::endl;
}

AForm::AForm(std::string const &newName, int newReqSign, int newReqExec) : name(newName), reqSign(newReqSign), reqExec(newReqExec)
{
	if (newReqSign < 1 || newReqExec < 1)
		throw GradeTooHighException();
	else if (newReqSign > 150 || newReqExec > 150)
		throw GradeTooLowException();
	this->isSigned = false;
	std::cout << GREEN"### Constructor for "CYAN << name << GREEN" Aform called. ###"RESET << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.getName()), reqSign(copy.getReqSign()), reqExec(copy.getReqExec()) 
{
	*this = copy;
	std::cout << GREEN"### Copy constructor for "CYAN << name << GREEN" Aform called. ###"RESET << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		this->isSigned = copy.isSigned;
	}
	std::cout << GREEN"### Copy assignment operator for "CYAN << name << GREEN" Aform called. ###"RESET << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << GREEN"### Destructor for "CYAN << name << GREEN" Aform called. ###"RESET << std::endl;
}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int AForm::getReqSign() const
{
	return (this->reqSign);
}

int AForm::getReqExec() const
{
	return (this->reqExec);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getReqSign())
		throw GradeTooLowException();	
	else if (this->getIsSigned())
		throw FormIsAlreadySignedException();
	else
	{
		this->isSigned = true;
		std::cout << GREEN"Bureaucrat "CYAN << b.getName() << GREEN" has signed the "BLUE << this->getName() << GREEN" Aform!" << std::endl;
	}
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The form's grade is too low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The form's grade is too high!");
}

const char *AForm::FormIsAlreadySignedException::what() const throw()
{
	return ("The form is already signed!");
}

const char *AForm::FormIsNotSignedException::what() const throw()
{
	return ("The form is NOT signed!");
}

std::ostream& operator<<(std::ostream &os, const AForm &b)
{
	os << CYAN << b.getName() << WHITE" Aform is currently ";
	if (b.getIsSigned())
		os << GREEN"signed. "RESET << std::endl;
	else if (!b.getIsSigned())
		os << RED"not signed. "RESET << std::endl;
	os << CYAN << b.getName() << WHITE" Aform needs grade "YELLOW << b.getReqSign() << WHITE" to be signed and grade "YELLOW << b.getReqExec() << WHITE" to be executed!"RESET;
	return (os);
}
