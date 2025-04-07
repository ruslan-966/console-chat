#include "ConversationManager.h"

void ConversationManager::cleanConsole()         // Очищаем консоль
{
    system("cls");
}

void ConversationManager::greeting()
{
    this->cleanConsole();
	std::cout << "Приветствую!!\n\n";
}

char ConversationManager::regOrComm()
{
    char sim;
    std::cout << "Выберите один из возможных режимов программы:\n1 - Регистрация нового пользователя.\n2 - Вход зарегистрированного пользователя.\n3 - Завершить работу программы.\nВведите номер планируемого действия: ";
    while (true)
    {
        sim = _getch();
        
        if (sim == '1' or sim == '2' or sim == '3')
        {
            std::cout << sim << std::endl << std::endl;
            return sim;
        }
    }
}

bool ConversationManager::userRegistration(Array<User>& allUsers)
{
    std::cout << "\n\nРегистрация нового пользователя:\n\n";
    bool isSpellingBad = true;
    std::string log{""};
    std::string name{""};
    std::string pass{""};

    while (isSpellingBad)
    {
        std::cout << "Для выхода из режима регистрации, введите '!'.\n";
        std::cout << "Логин (латинские буквы, цифры и знак нижнего подчёркивания): ";
        getline(std::cin, log);
        if (log.length() == 0)
        {
            std::cout << "\n\nПустая строка не может быть логином! Вышли из режима Регистрации нового пользователя.\n\n";
            return false;
        }
        if (log.length() == 1 && log[0] == '!')         // выход на верхний уровень
        {
            return false;
        }
        bool isSimbolBad = false;
        for (auto& c : log)                             // контроль правильности введенных символов
        {
            if (!((c <= 57 && c >= 48) ||                     // символ - цифра
                  (c <= 90 && c >= 65) ||                     // символ заглавная латинская буква
                  (c <= 122 && c >= 97)||                     // символ прописная латинская буква
                  (c == 95)))                                  // символ нижнее подчеркивание
            {
                std::cout << "К сожалению, в логине нашлись недопустимые символы. \nПопытайтесь ввести логин заново.\n\n";
                isSimbolBad = true;
                break;
            }
        }
        if (!isSimbolBad)                               //Все символы правильные, проверяем на уникальность логина
        {
            bool isLogUnique = true;
            for (int i = 0; i < allUsers.getCount(); ++i)
            {
                if (allUsers[i].getLogin() == log) 
                {
                    isLogUnique = false;
                    break;
                }
            }
            if (isLogUnique)
                isSpellingBad = false;
            else
            {
                std::cout << "Такой логин уже зарегистрирован.\nВведите новый логин: ";
            }
        }
    }
    //std::cout << "Введен логин: " << log << std::endl;

    isSpellingBad = true;
    while (isSpellingBad)
    {
        std::cout << "Имя (русские буквы, цифры и знак нижнего подчёркивания): ";
        getline(std::cin, name);
        if (name.length() == 0)
        {
            std::cout << "\n\nПустая строка не может быть имененм пользователя. Вышли из режима регистрации пользователя.\n\n";
            return false;
        }
        if (name.length() == 1 && name[0] == '!')         // выход на верхний уровень
        {
            std::cout << "\n\nРегистрация нового пользователя была прервана.\n\n";
            return false;
        }
        bool isSimbolBad = false;
        for (auto& c : name)                             // контроль правильности введенных символов
        {
            if (!((c <= 57 && c >= 48) ||                     // символ - цифра
                (c <= -38 && c >= -64) ||                     // символ русская буква А-Ъ
                (c <= -6 && c >= -36)  ||                     // символ русская буква Ь-ъ
                (c <= -1 && c >= -4)   ||                     // символ русская буква ь-я
                c == -88 || c == -72   ||                     // символы Ё, ё
                (c == 95)))                                   // символ нижнее подчеркивание
            {
                /*      ***Отладка***
                for (auto& c1 : name)
                {
                    std::cout << c1 << "\t" << (int)c1 << std::endl;
                }
                */
                std::cout << "К сожалению, в имени нашлись недопустимые символы. \nПопробуйте ввести еще раз.\n\n";
                isSimbolBad = true;
                break;
            }
        }
        if (!isSimbolBad)                               //Все символы правильные, проверяем на уникальность логина
        {
            bool isLogUnique = true;
            for (int i = 0; i < allUsers.getCount(); ++i)
            {
                if (allUsers[i].getNickname() == name)
                {
                    isLogUnique = false;
                    break;
                }
            }
            if (isLogUnique)
                isSpellingBad = false;
            else
            {
                std::cout << "Пользователь с таким имененм уже есть.\nВведите новое имя пользователя: ";
            }
        }
    }
    //std::cout << "Введено имя: " << name << std::endl;                                            //***Отладка****

    isSpellingBad = true;
    while (isSpellingBad)
    {
        pass = "";
        std::cout << "Пароль (латинские буквы, цифры и \nспециальные знаки, кроме пробела и восклицательного знака): ";
        char c;
        
        while ((c = _getch()) != '\r')
        {
            pass.push_back(c);
            _putch('*');
        }
        //std::cout << "\nСчитанный пароль: "<< pass << std::endl;                                 //***Отладка****
        
        if (pass.length() == 1 && pass[0] == '!')         // выход на верхний уровень
        {
            std::cout << "\n\nРегистрация нового пользователя была прервана.\n\n";
            return false;
        }
        bool isSimbolBad = false;
        for (auto& c : pass)                             // контроль правильности введенных символов
        {
            if (!(c <= 126 && c >= 34) or c=='!' or c == ' ')                  // Все печатные символы первой страницы ASCII кроме ! и пробела
            {
                std::cout << "\nБудьте внимательны! При наборе пароля допущена ошибка.\nПопытайтесь ввести пароль заново: ";
                isSimbolBad = true;
                //std::cin.ignore(32767, '\n'); // удаляем лишние значения
                break;
            }
             
        }
        if (!isSimbolBad)
            isSpellingBad = false;
    }
    //std::cout << "Введен пароль: " << pass << std::endl;                                          //***Отладка****
    //Заносим в массив нового пользователя
    User* ptrUser = new User(log, name, pass);
    allUsers.add(std::move(*ptrUser));
    delete ptrUser;
    std::cout << "\n\nНовый пользователь '" << name << "' успешно зарегистрирован.\n\n";
    return true;
}

int ConversationManager::usersInput(Array<User>& allUsers)
{
    std::string log{""};
    std::string pass{""};
    bool isLogGood = false;
    bool isPassGood = false;
    this->cleanConsole();
    std::cout << "\n\nВведите логин или символ '!' для возврата: ";
    getline(std::cin, log);
    if (log.length() == 1 && log == "!")
    {
        std::cout << "\n\nВерификация пользователя была прервана.\n\n";
        return -1;
    }
    //перебираем массив пользователей на совпадение логина
    int userNum{-1};
    for (int i = 0; i < allUsers.getCount(); ++i)
    {
        if (allUsers[i].getLogin() == log)
        {
            userNum = i;
            break;
        }
    }
    
    std::cout << "\n\nВведите пароль: ";
    
    char c;
    while ((c = _getch()) != '\r')
    {
        pass.push_back(c);
        _putch('*');
    }
    // сравниваем пароль с данными пользователя из массива
    if (pass != allUsers[userNum].getPassword())        //логин и пароль не совпали
    {
        std::cout << "\n\nОшибка при вводе логина или пароля.\n\n";
        userNum = -1;
    }
        
    return userNum;
}

void ConversationManager::userMessChoise(User& user, Array<User>& allUsers, Array<PrivateMessage>& arrPM, Array<CommonMessage>& arrCM)
{
    this->cleanConsole();
    std::cout << "\n\n" << user.getNickname() << ", привет!\n\n";
    std::cout << "Выберите:\n1 - написать сообщение в общий чат.\n2 - написать сообщение в чат пользователя.\n";
    std::cout << "3 - просмотреть сообщения из общего чата (количество сообщений: " << arrCM.getCount() << ").\n";

    //проверяем наличие частных сообщений
    std::string name = user.getNickname();
    int countPM{0};
    Array <int> numbersFromPM;
    
    for (int i = 0; i < arrPM.getCount(); ++i)
    {
        if (*arrPM[i].getSendTo() == name)
        {
            numbersFromPM.add(std::move(i));
        }
    }

    std::cout << "4 - просмотреть частные сообщения (количество сообщений: " << numbersFromPM.getCount() << ").\n";
    std::cout << "5 - завершить работу с сообщениями.\n";
    std::cout << "\nРезультат выбора : ";
    // отслеживаем выбор пользователя
    char sim;
    bool isSimOK = false;
    while (!isSimOK)
    {
        sim = _getch();

        if (sim == '1' || sim == '2' || sim == '3' || sim == '4' || sim == '5')
        {
            std::cout << sim << std::endl << std::endl;
            isSimOK = true;
        }
    }
    
    if (sim == '1')  //написать сообщение в общий чат
    {
        this->cleanConsole();
        std::cout << "\n\nНаберите сообщение для всех: ";
        std::string mes{ "" };
        getline(std::cin, mes);
        int mesNum = arrCM.getCount();
        CommonMessage* ptrCommonMes = new CommonMessage(mesNum, mes, name);
        std::cout << "\n\nСообщение сохранено под номером: " << mesNum << " \n\n";
        arrCM.add(std::move(*ptrCommonMes));
        delete ptrCommonMes;
    }
    if (sim == '2')     //написать сообщение в чат пользоватля
    {
        this->cleanConsole();
        std::cout << "\n\nВыберите номер пользователя, что бы написать сообщение: \n";
        
        struct usersList    //временная структура для создания списка пользователей
        {
            int num;
            std::string name;
            int numInAllUsers;
        };
        Array <usersList> strList;
        int count{0};
        for (int i = 0; i < allUsers.getCount(); ++i) 
        {
            if (user.getNickname() != allUsers[i].getNickname())
            {
                usersList* ptrUL = new usersList;
                ptrUL->name = allUsers[i].getNickname();
                ptrUL->num = count;
                ptrUL->numInAllUsers = i;
                strList.add(std::move(*ptrUL));
                delete ptrUL;
                count += 1;
            }
        }
        for (int i = 0; i < strList.getCount(); ++i)
        {
            std::cout << strList[i].num << ". " << strList[i].name << std::endl;
        }
        bool isNumNotOK = true;
        int choise = getIntValue();
        
        //просто код
        std::string mes{ "" };
        getline(std::cin, mes);
        int mesNum = arrCM.getCount();
        CommonMessage* ptrCommonMes = new CommonMessage(mesNum, mes, name);
        std::cout << "\n\nСообщение сохранено под номером: " << mesNum << " \n\n";
        arrCM.add(std::move(*ptrCommonMes));
        delete ptrCommonMes;
        // продолжение следует
    }
       
}

