/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:00:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/06 15:31:40 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class Bureaucrat;

class Form
{
	private:
			std::string const name;
			bool isSigned;
			int const reqSign;
			int const reqExec;
	public:
			Form();
			Form(std::string const &newName, int newReqSign, int newReqExec);
			Form(Form const &copy);
			Form &operator=(Form const &copy);
			~Form();
			std::string const getName() const;
			bool getIsSigned() const;
			int getReqSign() const;
			int getReqExec() const;
			void beSigned(Bureaucrat &b);

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

			class FormIsAlreadySignedException : public std::exception
			{
				public:
						const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream &os, const Form &b);

#endif
