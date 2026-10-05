#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (!std::cin.eof())
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
			break;
	}
	return 0;
}
