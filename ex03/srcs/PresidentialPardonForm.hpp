/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:41:50 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/06 15:31:02 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
			std::string target;
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(std::string newTarget);
			PresidentialPardonForm(PresidentialPardonForm const &copy);
			PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
			~PresidentialPardonForm();
			std::string getTarget();
			void execute(Bureaucrat const & executor) const;
};

#endif
