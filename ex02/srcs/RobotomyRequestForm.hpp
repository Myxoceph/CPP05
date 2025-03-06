/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:45:32 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/06 15:31:30 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
			std::string target;
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(std::string newTarget);
			RobotomyRequestForm(RobotomyRequestForm const &copy);
			RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
			~RobotomyRequestForm();
			std::string getTarget();
			void execute(Bureaucrat const & executor) const;
			
};

#endif
