/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/06 13:36:15 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
	try 
	{
		Bureaucrat bureaucrat("Alice", 1);
		ShrubberyCreationForm shrubberyForm("Home");
		std::cout << std::endl;
		shrubberyForm.beSigned(bureaucrat);
		bureaucrat.executeForm(shrubberyForm);
		bureaucrat.executeForm(shrubberyForm);
		std::cout << std::endl;
		RobotomyRequestForm robotomyForm("Bob");
		std::cout << std::endl;
		robotomyForm.beSigned(bureaucrat);
		bureaucrat.executeForm(robotomyForm);
		std::cout << std::endl;
		PresidentialPardonForm pardonForm("Charlie");
		std::cout << std::endl;
		pardonForm.beSigned(bureaucrat);
		bureaucrat.executeForm(pardonForm);
		std::cout << std::endl;
	} 
	catch (std::exception &e) 
	{
		std::cout << RED"Exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}
