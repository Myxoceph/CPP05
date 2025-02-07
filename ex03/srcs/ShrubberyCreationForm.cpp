/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:52:37 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/07 15:57:25 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137)
{
	this->target = "42 Kocaeli";
	std::cout << GREEN"### Default constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget) : AForm("Shrubbery Creation", 145, 137)
{
	this->target = newTarget;
	std::cout << GREEN"### Constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	*this = copy;
	std::cout << GREEN"### Copy constructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		this->target = copy.target;
	}
	std::cout << GREEN"### Copy assignment operator for "CYAN << name << GREEN" called. ###"RESET << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREEN"### Destructor for "CYAN << name << GREEN" called. ###"RESET << std::endl;
}

std::string ShrubberyCreationForm::getTarget()
{
	return (this->target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
	std::string fileName = target;
	if (!getIsSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getReqExec())
		throw AForm::GradeTooLowException();
	std::ofstream outFile;
	fileName.append("_shrubbery");
	outFile.open((fileName.c_str()), std::ios::out);
	if (!outFile.is_open())
		throw std::ofstream::failure("File cannot be opened");
	outFile <<
				"                        .\n"
				"                       .:.\n"
				"                       :|:\n"
				"                      .:|:.\n"
				"                      ::|::\n"
				"       :.             ::|::             .:\n"
				"       :|:.          .::|::.          .:|:\n"
				"       ::|:.         :::|:::         .:|::\n"
				"       `::|:.        :::|:::        .:|::'\n"
				"        ::|::.       :::|:::       .::|::\n"
				"        `::|::.      :::|:::      .::|::'\n"
				"         :::|::.     :::|:::     .::|::\n"
				"         `:::|::.    :::|:::    .::|::;'\n"
				"`::.      `:::|::.   :::|:::   .::|::;'      .:;'\n"
				" `:::..     ¹::|::.  :::|:::  .::|::¹    ..::;'\n"
				"   `:::::.    ':|::. :::|::: .::|:'   ,::::;'\n"
				"     `:::::.    ':|:::::|:::::|:'   :::::;'\n"
				"       `:::::.:::::|::::|::::|::::.,:::;'\n"
				"          ':::::::::|:::|:::|:::::::;:'\n"
				"             ':::::::|::|::|:::::::''\n"
				"                  `::::::::::;'\n"
				"                 .:;'' ::: ``::.\n"
				"                      :':':\n"
				"                        ;\n";
	outFile.close();
}
