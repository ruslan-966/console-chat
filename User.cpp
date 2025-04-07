#include "User.h"

User::User()
{
}

std::string User::getNickname() const
{
	return nickname;
}

std::string User::getLogin() const
{
	return login;
}

std::string User::getPassword() const
{
	return password;
}

void User::setNickname(std::string&& _nickname)
{
	nickname = _nickname;
}

void User::setLogin(std::string&& _login)
{
	login = _login;
}

void User::setPassword(std::string&& _password)
{
	password = _password;
}

bool User::checkPassword(std::string _password) const
{
	return (password == _password) ? true : false;
}
