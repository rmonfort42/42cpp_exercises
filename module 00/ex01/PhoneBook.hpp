#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	searchContacts(void) const;

private:
	Contact	_contacts[8];
	int	_count;
	int	_oldest;

	void		_displayTable(void) const;
	std::string	_truncate(std::string str) const;
};

#endif
