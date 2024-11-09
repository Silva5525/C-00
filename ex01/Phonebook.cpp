/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:00:38 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/09 17:13:29 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/// @brief Initializer List for the PhoneBook constructor.
/// @details Initializes contactCount (number of contacts) and oldContact (index of the oldest contact)
PhoneBook::PhoneBook() : contactCount(0), oldContact(0) {}

/// @brief The PhoneBook class manages a list of contacts with a maximum size of 8.
/// @return The number of contacts in the PhoneBook.
int PhoneBook::getContactCount() const
{
	return (contactCount);
}

/// @brief The PhoneBook class manages a list of contacts with a maximum size of 8.
/// @details The class allows adding, displaying, and retrieving contacts by their index,
/// replacing the oldest contact if the list exceeds 8 entries.
/// Constructs a PhoneBook object with initial values for contactCount and oldContact.
/// Initializes contactCount (number of contacts) and oldContact (index of the oldest contact)
/// to 0, preparing the PhoneBook for adding new contacts.
/// @param contact The contact to add to the PhoneBook.
/// @param contactCount The number of contacts in the PhoneBook.
/// @param oldContact The index of the oldest contact in the PhoneBook.
void	PhoneBook::addContact(const Contact &contact)
{
	if (contactCount < 8)
	{
		contacts[contactCount] = contact;
		contactCount++;
	}
	else
	{
		contacts[oldContact] = contact;
		oldContact = (oldContact + 1) % 8;
	}
}

/// @brief formString function that returns a substring of the string.
/// if the string is longer than 10 characters, it returns the first 9 characters
/// followed by a period. Otherwise, it returns the string as is.
/// .length() or .size() are functions that returns the number of 
/// @param str the string to format.
/// @return the formatted string.
std::string formString(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

/// @brief Displays the details of a contact in the PhoneBook.
/// std::setw() is a function that sets the width of the next input/output field.
/// .substr() is a function that returns a substring of the string.
/// elements in the array.. i take length because its a string and not a vector.
void	PhoneBook::showContacts() const
{
	int i = 0;
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nick Name" << std::endl;
	while (i < contactCount)
	{
		std::cout << std::setw(10) << i << "|";
		
		std::cout << std::setw(10) << formString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formString(contacts[i].getNickName()) << std::endl;
		i++;
	}
}

/// @brief Displays the details of a contact in the PhoneBook.
/// @param i the index of the contact to display.
void	PhoneBook::displayDetails(int i) const 
{
	if (i < 0 || i >= contactCount)
		std::cout << "Please Sir.. may i have another Index? "  << std::endl;
	else
	{
		const Contact &contact = contacts[i];
		std::cout << "First Name: " << contact.getFirstName() << std::endl;
		std::cout << "Last Name: " << contact.getLastName() << std::endl;
		std::cout << "Nick Name: " << contact.getNickName() << std::endl;
		std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	}
