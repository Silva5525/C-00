/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:00:54 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/08 21:41:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>

# include "Contact.hpp"

/// @brief The PhoneBook class manages a list of contacts with a maximum size of 8.
/// @details The class allows adding, displaying, and retrieving contacts by their index,
/// replacing the oldest contact if the list exceeds 8 entries.
/// @brief The class PhoneBook is a class that stores the details of a contact.
/// the private section of the class contains the details of a contact.
/// the public section of the class contains the member functions that set and
/// get the details of a contact.
/// @param contacts An array of Contact objects.
/// @param contactCount The number of contacts in the PhoneBook.
/// @param oldContact The index of the oldest contact in the PhoneBook.
/// @param addContact Adds a contact to the PhoneBook.
/// @param showContacts Displays the list of contacts in the PhoneBook.
/// @param displayDetails Displays the details of a contact in the PhoneBook.
class PhoneBook
{
	private:
		Contact	contacts[8];
		int		contactCount;
		int		oldContact;

	public:
		PhoneBook();
		void	addContact(const Contact &contact);
		void	showContacts() const;
		void	displayDetails(int i) const;
		int		getContactCount() const;
};

#endif
