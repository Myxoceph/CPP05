/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:00:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/06 13:43:38 by abakirca         ###   ########.fr       */
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

class AForm
{
	protected:
			std::string const name;
			bool isSigned;
			bool isExec;
			int const reqSign;
			int const reqExec;

	public:
			AForm();
			AForm(std::string const &newName, int newReqSign, int newReqExec);
			AForm(AForm const &copy);
			AForm &operator=(AForm const &copy);
			~AForm();
			std::string const getName() const;
			bool getIsSigned() const;
			bool getIsExec() const;
			void setIsExec(bool flag);
			int getReqSign() const;
			int getReqExec() const;
			void beSigned(Bureaucrat &b);
			virtual void execute(Bureaucrat const & executor) const = 0;

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

class FormIsNotSignedException : public std::exception
{
	public:
			const char* what() const throw();
};

class FormIsAlreadyExecutedException : public std::exception
{
	public:
			const char* what() const throw();
};

};

std::ostream& operator<<(std::ostream &os, const AForm &b);

#endif
