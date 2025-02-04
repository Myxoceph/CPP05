/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:00:46 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/04 16:28:38 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("abakirca"), reqSign(42), reqExec(21)
{
	this->isSigned = false;
	std::cout << GREEN"Default constructor for "CYAN << name << GREEN" form called."RESET << std::endl;
}

Form::Form(std::string const &newName, int newReqSign, int newReqExec) : name(newName), reqSign(newReqSign), reqExec(newReqExec)
{
	if (newReqSign < 1 || newReqExec < 1)
		throw GradeTooHighException();
	else if (newReqSign > 150 || newReqExec > 150)
		throw GradeTooLowException();
	this->isSigned = false;
	std::cout << GREEN"Constructor for "CYAN << name << GREEN" form called."RESET << std::endl;
}

Form::Form(const Form &copy) : name(copy.getName()), reqSign(copy.getReqSign()), reqExec(copy.getReqExec()) 
{
	*this = copy;
	std::cout << GREEN"Copy constructor for "CYAN << name << GREEN" form called."RESET << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		this->isSigned = copy.isSigned;
	}
	std::cout << GREEN"Copy assignment operator for "CYAN << name << GREEN" form called."RESET << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << GREEN"Destructor for "CYAN << name << GREEN" form called."RESET << std::endl;
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getReqSign() const
{
	return (this->reqSign);
}

int Form::getReqExec() const
{
	return (this->reqExec);
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getReqSign())
		std::cout << GREEN"Bureaucrat "CYAN << b.getName() << GREEN" couldn't signed the "BLUE << this->getName() << GREEN" form because they have a grade of "YELLOW << b.getGrade() << GREEN " and the form requires "BLUE << this->getReqSign() << GREEN" grade!"RESET << std::endl; 
	else if (this->getIsSigned())
		throw FormIsAlreadySignedException();
	else
	{
		this->isSigned = true;
		std::cout << GREEN"Bureaucrat "CYAN << b.getName() << GREEN" has signed the "BLUE << this->getName() << GREEN" form!" << std::endl;
	}
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char *Form::FormIsAlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}

std::ostream& operator<<(std::ostream &os, const Form &b)
{
	os << CYAN << b.getName() << WHITE" form is currently ";
	if (b.getIsSigned())
		os << GREEN"signed. "RESET << std::endl;
	else if (!b.getIsSigned())
		os << RED"not signed. "RESET << std::endl;
	os << CYAN << b.getName() << WHITE" form needs grade "YELLOW << b.getReqSign() << WHITE" to be signed and grade "YELLOW << b.getReqExec() << WHITE" to be executed!"RESET;
	return (os);
}
