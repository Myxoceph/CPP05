/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/04 19:01:15 by abakirca         ###   ########.fr       */
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
		
		ShrubberyCreationForm shrubberyForm("home");
		shrubberyForm.beSigned(bureaucrat);
		bureaucrat.executeForm(shrubberyForm);

		RobotomyRequestForm robotomyForm("Bob");
		robotomyForm.beSigned(bureaucrat);
		bureaucrat.executeForm(robotomyForm);

		PresidentialPardonForm pardonForm("Charlie");
		pardonForm.beSigned(bureaucrat);
		bureaucrat.executeForm(pardonForm);
	} 
	catch (std::exception &e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
