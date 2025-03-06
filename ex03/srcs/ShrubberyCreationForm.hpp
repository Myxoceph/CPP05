/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:46:18 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/06 15:31:07 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
			std::string target;
	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string newTarget);
			ShrubberyCreationForm(ShrubberyCreationForm const &copy);
			ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
			~ShrubberyCreationForm();
			std::string getTarget();
			void execute(Bureaucrat const & executor) const;
			
};

#endif
