/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:48:19 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/06 15:30:37 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class AForm;

class Bureaucrat
{
	private:
			std::string const name;
			int grade;
	public:
			Bureaucrat();
			Bureaucrat(std::string const &newName, int newGrade);
			Bureaucrat(Bureaucrat const &copy);
			Bureaucrat &operator=(Bureaucrat const &copy);
			~Bureaucrat();
			const std::string getName() const;
			int getGrade() const;
			void incGrade();
			void decGrade();
			void signForm(AForm &Aform);
			void executeForm(AForm const &form) const;

			class GradeTooHighException : public std::exception
			{
				public:
						const char* what() const throw();
			};

			class GradeTooLowException : public std::exception
			{
				public:
						const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

#endif
