#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _count(0), _oldest(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

static std::string promptField(std::string field)
{
	std::string input;

	while (!std::cin.eof())
	{
		std::cout << field << ": ";
		std::getline(std::cin, input);
		if (!input.empty())
			return (input);
		std::cout << "Field cannot be empty. Try again." << std::endl;
	}
	return(input);
}

void PhoneBook::addContact(void)
{
	std::string firstName, lastName, nickname, phone, secret;

	firstName = promptField("First name");
	lastName  = promptField("Last name");
	nickname  = promptField("Nickname");
	phone     = promptField("Phone number");
	secret    = promptField("Darkest secret");

	_contacts[_oldest].setFirstName(firstName);
	_contacts[_oldest].setLastName(lastName);
	_contacts[_oldest].setNickname(nickname);
	_contacts[_oldest].setPhoneNumber(phone);
	_contacts[_oldest].setDarkestSecret(secret);

	if (_count < 8)
		_count++;
	_oldest = (_oldest + 1) % 8;
}

std::string PhoneBook::_truncate(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::_displayTable(void) const
{
	std::cout << std::setw(10) << "Index" << "|"
	          << std::setw(10) << "First Name" << "|"
	          << std::setw(10) << "Last Name" << "|"
	          << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << i << "|"
		          << std::setw(10) << _truncate(_contacts[i].getFirstName()) << "|"
		          << std::setw(10) << _truncate(_contacts[i].getLastName()) << "|"
		          << std::setw(10) << _truncate(_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::searchContacts(void) const
{
	std::string input;
	int			idx;

	if (_count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	_displayTable();
	std::cout << "Enter an index: ";
	std::getline(std::cin, input);
	if (input.length() != 1 || input[0] < '0' || input[0] > '7'
		|| (input[0] - '0') >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	idx = input[0] - '0';
	std::cout << "First name: " << _contacts[idx].getFirstName() << std::endl;
	std::cout << "Last name: "  << _contacts[idx].getLastName() << std::endl;
	std::cout << "Nickname: "   << _contacts[idx].getNickname() << std::endl;
	std::cout << "Phone: "      << _contacts[idx].getPhoneNumber() << std::endl;
	std::cout << "Secret: "     << _contacts[idx].getDarkestSecret() << std::endl;
}
