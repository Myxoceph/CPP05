/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/04 16:30:35 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Bob", 1);
	Bureaucrat b("Jim", 130);
	Form high("Form1", 5, 2);
	try
	{
		std::cout << std::endl;
		std::cout << high << std::endl;
		a.signForm(high);
		b.signForm(high);
		std::cout << high << std::endl;
		a.signForm(high);
		std::cout << std::endl;
		Form low("Form2", 150, 152);
		a.signForm(high);
		b.signForm(high);
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}
