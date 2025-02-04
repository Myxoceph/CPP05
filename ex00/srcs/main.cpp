/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/04 14:57:45 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Bob", 1);
		Bureaucrat b("Jim", 149);
		Bureaucrat c;
		std::cout << a << std::endl;
		a.decGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		b.decGrade();
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		b.decGrade();
		std::cout << b << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
