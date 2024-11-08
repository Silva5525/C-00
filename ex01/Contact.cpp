/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:35:15 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/08 13:47:25 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/// @brief setDetails is a member function that sets the details of a contact
/// or replaces the details of a contact in the private section of the class.
void	Contact::setDetails(const std::string &firstChange, const std::string &lastChange,
				const std::string &nickChange, const std::string &phoneChange,
				const std::string &secretChange)
{
	firstName = firstChange;
	lastName = lastChange;
	nickName = nickChange;
	phoneNumber = phoneChange;
	darkestSecret = secretChange;
}

/// @brief the get_ter functions are member functions that return the details of a
/// contact if called. const is used to make sure that the member function does not
/// change the object it is called on. (safer, faster, and more efficient)
/// @return the called detail of a contact
std::string	Contact::getFirstName() const
{
	return (firstName);
}

std::string	Contact::getLastName() const
{
	return (lastName);
}

std::string	Contact::getNickName() const
{
	return (nickName);
}

std::string	Contact::getPhoneNumber() const
{
	return (phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (darkestSecret);
}

// #include <iostream>

/// @brief main tests the class Contact.
// int	main()
// {
// 	Contact contact;
// 	contact.setDetails("Wolfgang", "Cockies", "Amadeus", "123456789", "I like trains.");

// 	std::cout << "First Name: " << contact.getFirstName() << std::endl;
// 	std::cout << "Last Name: " << contact.getLastName() << std::endl;
// 	std::cout << "Nick Name: " << contact.getNickName() << std::endl;
// 	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
// 	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;

// 	return (0);
// }