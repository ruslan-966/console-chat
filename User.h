#pragma once
#include <string>

class User 
{
public:

	User();
	User(std::string _login, std::string _nickname, std::string _password) : 
		login(_login), nickname(_nickname), password(_password) {}

	std::string getNickname() const;
	std::string getLogin() const;
	std::string getPassword() const;
	void setNickname(std::string&& _nickname);
	void setLogin(std::string&& _login);
	void setPassword(std::string&& _password);
	bool checkPassword(std::string _password) const;

private:

	std::string login;
	std::string nickname;
	std::string password;

};