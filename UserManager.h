#pragma once
#include "User.h"
#include "DataManager.h"


class UserManager //класс для управления пользователями
{
public:

private:
	DataManager<User>* users;
};