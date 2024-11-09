/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:11:16 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/08 21:40:34 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

/// @brief class Contact is a class that stores the details of a contact.
/// the private section of the class contains the details of a contact.
/// the public section of the class contains the member functions that set and
/// get the details of a contact.
/// @brief We use camelCase for class names because it is the most common naming
/// convention for classes in C++. It is also the naming convention used in the
/// C++ Standard Library.
/// @brief setDetails is a member function that sets the details of a contact 
/// in the private section of the class. 
class Contact
{
	private:
		std::string	firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	
	public:
		void setDetails(const std::string &firstChange, const std::string &lastChange,
				const std::string &nickChange, const std::string &phoneChange,
				const std::string &secretChange);
	
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif
