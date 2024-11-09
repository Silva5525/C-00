/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:00:38 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/09 09:56:49 by wdegraf          ###   ########.fr       */
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

/// @brief Displays the details of a contact in the PhoneBook.
/// std::setw() is a function that sets the width of the next input/output field.
/// .substr() is a function that returns a substring of the string.
/// .length() or .size() are functions that returns the number of 
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
		
		if (contacts[i].getFirstName().length() > 10)
			std::cout << std::setw(10) << contacts[i].getFirstName().substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].getFirstName();
		std::cout << "|";

		if (contacts[i].getLastName().length() > 10)
			std::cout << std::setw(10) << contacts[i].getLastName().substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].getLastName();
		std::cout << "|";

		if (contacts[i].getNickName().length() > 10)
			std::cout << std::setw(10) << contacts[i].getNickName().substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].getNickName();
		std::cout << std::endl;

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
}

/// @brief Makes sure the input is not empty. and asks for a new input.
/// @param prompt the message to display to the user.
/// @return the non-empty input.
/// @brief Whats new C++? .empty() is a function that returns true if the string is empty. +98
std::string getNonEmptyInput(const std::string &prompt)
{
	std::string input;
	while (1)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Please Sir.. may i have some more Characters?" << std::endl;
		else
			return (input);
	}
}

/// @brief Displays the details of a contact in the PhoneBook.

/// @brief Whats new C++? all C++98
/// std::cin.ignore() is a function that clears the input buffer. 
/// std::getline() is a function that reads a line from an input stream and
/// stores it in a string.
/// std::string is a class that represents a sequence of characters.
/// std::setw() is a function that sets the width of the next input/output field.
/// With PhoneBook phonebook; we create a instance (object) of the class PhoneBook.
/// object is required to hold contacts and execute operations on them. 
/// By instantiating it in main, we ensure the phoneBook object lives
/// for the duration of the program, allowing users to interact with a single, 
/// persistent phonebook instance until they exit.
int	main(void)
{
	int i = 0;
	PhoneBook	phonebook;
	std::string order;

	while (1)
	{
		std::cout << "Enter a command: (ADD, SEARCH, EXIT) ";
		std::getline(std::cin, order);
		
		if(order == "ADD")
		{
			Contact contact;
			std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

			firstName = getNonEmptyInput("Enter the first name: ");
			lastName = getNonEmptyInput("Enter the last name: ");
			nickName = getNonEmptyInput("Enter the nick name: ");
			phoneNumber = getNonEmptyInput("Enter the phone number: ");
			darkestSecret = getNonEmptyInput("Enter the darkest secret: ");

			contact.setDetails(firstName, lastName, nickName, phoneNumber, darkestSecret);
			phonebook.addContact(contact);
		}
		else if (order == "SEARCH")
		{
			phonebook.showContacts();
			std::cout << "Sir? Which contact[i] would you like to see? ";
			if (!(std::cin >> i) || i < 0 || i >= phonebook.getContactCount())
			{
				std::cout << "Please Sir.. may i have another Index? "  << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else
			{
				std::cin.ignore();
				phonebook.displayDetails(i);
			}
		}
		else if (order == "EXIT")
			break;
		else
			std::cout << "Please Sir.. may i have another Order? (ADD, SEARCH, EXIT) "  << std::endl;
	
	}
	return (0);
}
