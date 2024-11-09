/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:15:18 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/09 10:26:31 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/// @brief Makes sure the input is not empty. and asks for a new input.
/// @param prompt the message to display to the user.
/// @return the non-empty input.
/// @brief Whats new C++? .empty() is a function that returns true if the string is empty. +98
std::string	getNonEmptyInput(const std::string &prompt)
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

/// @brief Checks if a string is a number.
/// @param str string to check.
/// @return true if the string is a number, false otherwise.
bool	isNumber(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

/// @brief handles the add command.
/// @param phonebook the phonebook to add a contact to.
void	doADD(PhoneBook &phonebook)
{
	Contact contact;
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	firstName = getNonEmptyInput("Enter the first name: ");
	lastName = getNonEmptyInput("Enter the last name: ");
	nickName = getNonEmptyInput("Enter the nick name: ");
	while (!(isNumber(phoneNumber = getNonEmptyInput("Enter the phone number: "))))
	{
		std::cout << "Please Sir.. could you use a Number? "  << std::endl;
	}
	darkestSecret = getNonEmptyInput("Enter the darkest secret: ");

	contact.setDetails(firstName, lastName, nickName, phoneNumber, darkestSecret);
	phonebook.addContact(contact);
}

/// @brief handles the search command.
/// @param phonebook the phonebook to search in.
void	doSearch(const PhoneBook &phonebook)
{
	int i = 0;

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
	PhoneBook	phonebook;
	std::string order;

	while (1)
	{
		std::cout << "Enter a command: (ADD, SEARCH, EXIT) ";
		std::getline(std::cin, order);
		
		if(order == "ADD")
			doADD(phonebook);
		else if (order == "SEARCH")
			doSearch(phonebook);
		else if (order == "EXIT")
			break;
		else
			std::cout << "Please Sir.. may i have another Order? (ADD, SEARCH, EXIT) "  << std::endl;
	
	}
	return (0);
}
