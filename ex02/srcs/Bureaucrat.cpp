/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:48:16 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/07 16:05:27 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("abakirca")
{
	this->grade = 42;
	std::cout << GREEN"### Default constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &newName, int newGrade) : name(newName)
{
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = newGrade;
	std::cout << GREEN"### Constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
	std::cout << GREEN"### Copy constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		this->grade = copy.grade;
	}
	std::cout << GREEN"### Copy assignment operator for "CYAN << name << GREEN" called. ###"RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREEN"### Destructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incGrade()
{
	if (this->grade > 1)
		this->grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decGrade()
{
	if (this->grade < 150)
		this->grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << CYAN << b.getName() << WHITE", bureaucrat grade "YELLOW << b.getGrade() << RESET;
	return (os);
}

void Bureaucrat::signForm(AForm &Aform)
{
	Aform.beSigned(*this);
}

void Bureaucrat::executeForm(const AForm &form) const 
{
	try
	{
		form.execute(*this);
		std::cout << CYAN << this->getName() << WHITE" executed "BLUE <<  form.getName() << RESET << std::endl;
	} 
	catch (std::exception &e) 
	{
		std::cout << RED"Failed to execute "BLUE << form.getName() << RED": " << e.what() << RESET << std::endl;
	}
}
