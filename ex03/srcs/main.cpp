/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/07 16:02:27 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* zpf;
	Bureaucrat b("Jarvis", 42);
	std::cout << std::endl;
	try 
	{
		rrf = someRandomIntern.makeForm("shrubbery creation", "42 Kocaeli");
		std::cout << std::endl;
		std::cout << rrf << std::endl;
		std::cout << std::endl;
		b.signForm(*rrf);
		b.executeForm(*rrf);
		std::cout << std::endl;
		std::cout << b << std::endl;
		std::cout << rrf << std::endl;
		std::cout << std::endl;
		delete rrf;
		std::cout << std::endl;
		zpf = someRandomIntern.makeForm("some random form", "Ahmet");
	} 
	catch (std::exception &e) 
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}
