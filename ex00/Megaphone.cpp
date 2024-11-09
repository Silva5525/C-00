/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:20:21 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/08 12:41:20 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/// @brief This program takes a string as an argument and prints it in uppercase
/// if no argument is given, it prints "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
/// @brief C++ whats new? std:: is a namespacerefering to the Standard Library.
/// cout is an object of the iostream class, which is used to output data.
/// cin is an object of the iostream class, which is used to read input data.
/// endl is an object of the iostream class, which is used to insert a new line.
/// toupper is a function that converts a character to uppercase.
/// static_cast<type> is a keyword that performs a non-conversion type cast in a
/// type-safe way.. Its prefered comparsed to (type) because it is more explicit.
/// the type has to be in <char> because toupper returns an int.
/// @param argc Argument count
/// @param argv Argument vector
/// @return 0 on success
int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
		}
		std::cout << std::endl;
	}
	return (0);
}