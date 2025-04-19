#include "ConversationManager.h"
#include "DataManager.h"

ConversationManager::ConversationManager()
{
}

ConversationManager::ConversationManager(Array<Message>& privateMessagePool, Array<Message>& commonMessagePool)
{
    allUsers = UserManager(std::move(std::make_unique<Array<User>>(10)));
}

void ConversationManager::cleanConsole()         // ������� �������
{
    system("cls");
}

void ConversationManager::start()
{
    this->greeting();
    bool isItNextLoop = false;
    int uNum{ -1 };
    //��������� ����
    while (true)
    {
        char choice = this->regOrComm();
        switch (choice)
        {
        case '1':
            if (isItNextLoop)
            {
                this->cleanConsole();
            }
            isItNextLoop = true;
            this->userRegistration();
            break;
        case '2':
            if (isItNextLoop)
            {
                this->cleanConsole();
                isItNextLoop = true;
            }
            else
            {
                std::cout << "\n\n��� ������������������ �������������, ������� � �.1.\n\n";
                break;
            }
            uNum = this->usersInput();		//����� ��������������������� ������������ �� ������� Users
            if (uNum > -1)
            {
                User user = allUsers.getUser(uNum);			//�������� ������ ����� ������������
                this->userMessChoise(user);
            }
            break;
        case '3':
            std::cout << "\n\n������ ��������� ���������.\n";
            return;
        }
    }
    for (int i = 0; i < ptrPrivCharts.getCount(); ++i)
    {
        delete ptrPrivCharts[i];
    }
}

void ConversationManager::greeting()
{
    this->cleanConsole();
	std::cout << "�����������!!\n\n";
}

char ConversationManager::regOrComm()
{
    char sim;
    std::cout << "�������� ���� �� ��������� ������� ���������:\n1 - ����������� ������ ������������.\n2 - ���� ������������������� ������������.\n3 - ��������� ������ ���������.\n������� ����� ������������ ��������: ";
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

bool ConversationManager::userRegistration()
{
    this->cleanConsole();
    std::cout << "\n\n����������� ������ ������������:\n\n";
    bool isSpellingBad = true;
    std::string log{""};
    std::string name{""};
    std::string pass{""};

    while (isSpellingBad)
    {
        std::cout << "��� ������ �� ������ �����������, ������� '!' � 'ENTER'.\n";
        std::cout << "����� (��������� �����, ����� � ���� ������� �������������): ";
        getline(std::cin, log);
        if (log.length() == 0)
        {
            std::cout << "\n\n������ ������ �� ����� ���� �������! ����� �� ������ ����������� ������ ������������.\n\n";
            return false;
        }
        if (log.length() == 1 && log[0] == '!')         // ����� �� ������� �������
        {
            this->cleanConsole();
            return false;
        }
        bool isSimbolBad = false;
        for (auto& c : log)                             // �������� ������������ ��������� ��������
        {
            if (!((c <= 57 && c >= 48) ||                     // ������ - �����
                  (c <= 90 && c >= 65) ||                     // ������ ��������� ��������� �����
                  (c <= 122 && c >= 97)||                     // ������ ��������� ��������� �����
                  (c == 95)))                                  // ������ ������ �������������
            {
                std::cout << "� ���������, � ������ ������� ������������ �������. \n����������� ������ ����� ������.\n\n";
                isSimbolBad = true;
                break;
            }
        }
        if (!isSimbolBad)                               //��� ������� ����������, ��������� �� ������������ ������
        {
            bool isLogUnique = true;
            for (int i = 0; i < allUsers.getCount(); ++i)
            {
                if (allUsers.findUserByLogin(std::move(log))) 
                {
                    isLogUnique = false;
                    break;
                }
            }
            if (isLogUnique)
                isSpellingBad = false;
            else
            {
                std::cout << "����� ����� ��� ���������������.\n������� ����� �����: ";
            }
        }
    }
    //std::cout << "������ �����: " << log << std::endl;

    isSpellingBad = true;
    while (isSpellingBad)
    {
        std::cout << "��� (������� �����, ����� � ���� ������� �������������): ";
        getline(std::cin, name);
        //std::cout << name[0] << (int)name[0] << std::endl;        // ������������ ���� � ����
        if (name.length() == 0)
        {
            std::cout << "\n\n������ ������ �� ����� ���� ������� ������������. ����� �� ������ ����������� ������������.\n\n";
            return false;
        }
        if (name.length() == 1 && name[0] == '!')         // ����� �� ������� �������
        {
            std::cout << "\n\n����������� ������ ������������ ���� ��������.\n\n";
            return false;
        }
        bool isSimbolBad = false;
        for (auto& c : name)                             // �������� ������������ ��������� ��������
        {
            if (!((c <= 57 && c >= 48) ||                     // ������ - �����
                (c <= -38 && c >= -64) ||                     // ������ ������� ����� �-�
                (c <= -6 && c >= -36)  ||                     // ������ ������� ����� �-�
                (c <= -1 && c >= -4)   ||                     // ������ ������� ����� �-�
                c == -88 || c == -72   ||                     // ������� �, �
                c == -5 || c == -37    ||                     // ������� �, �
                (c == 95)))                                   // ������ ������ �������������
            {
                /*      ***�������***
                for (auto& c1 : name)
                {
                    std::cout << c1 << "\t" << (int)c1 << std::endl;
                }
                */
                std::cout << "� ���������, � ����� ������� ������������ �������. \n���������� ������ ��� ���.\n\n";
                isSimbolBad = true;
                break;
            }
        }
        if (!isSimbolBad)                               //��� ������� ����������, ��������� �� ������������ ������
        {
            bool isLogUnique = true;
            for (int i = 0; i < allUsers.getCount(); ++i)
            {
                if (allUsers.findUserByNickname(std::move(name)))
                {
                    isLogUnique = false;
                    break;
                }
            }
            if (isLogUnique)
                isSpellingBad = false;
            else
            {
                std::cout << "������������ � ����� ������� ��� ����.\n������� ����� ��� ������������: ";
            }
        }
    }
    //std::cout << "������� ���: " << name << std::endl;                                            //***�������****

    while (true)
    {
        pass = "";
        std::cout << "������ (��������� �����, ����� � \n����������� �����, ����� ������� � ���������������� �����): ";
        char c;
        
        while ((c = _getch()) != '\r')
        {
            pass.push_back(c);
            _putch('*');
        }
        //std::cout << "\n��������� ������: "<< pass << std::endl;                                 //***�������****
        
        if (pass.length() == 1 && pass[0] == '!')         // ����� �� ������� �������
        {
            std::cout << "\n\n����������� ������ ������������ ���� ��������.\n\n";
            return false;
        }
        bool isSimbolBad = false;
        for (auto& c : pass)                             // �������� ������������ ��������� ��������
        {
            if (!(c <= 126 && c >= 34) or c=='!' or c == ' ')                  // ��� �������� ������� ������ �������� ASCII ����� ! � �������
            {
                std::cout << "\n������ �����������! ��� ������ ������ �������� ������.\n����������� ������ ������ ������: ";
                isSimbolBad = true;
                //std::cin.ignore(32767, '\n'); // ������� ������ ��������
                break;
            }
             
        }
        if (!isSimbolBad)
            //isSpellingBad = false;
            break;
    }
    //std::cout << "������ ������: " << pass << std::endl;                                          //***�������****
    //������� � ������ ������ ������������
    std::cout << "\n\n";
    allUsers.addUser(std::move(User(log, name, pass)));
    std::cout << "\n";
    //std::cout << "\n\n����� ������������ '" << name << "' ������� ���������������.\n\n";
    return true;
}

int ConversationManager::usersInput()
{
    std::string log{""};
    std::string pass{""};
    bool isLogGood = false;
    bool isPassGood = false;
    this->cleanConsole();
    std::cout << "\n\n���� ������������.\n\n";
    std::cout << "\n\n������� ����� ��� ������ '!' ��� ��������: ";
    getline(std::cin, log);
    if (log.length() == 1 && log == "!")
    {
        std::cout << "\n\n����������� ������������ ���� ��������.\n\n";
        return -1;
    }
    //���������� ������ ������������� �� ���������� ������
    int userNum{-1};
       
    if (!allUsers.findUserByLogin(std::move(log), userNum))      //��������� ����� �� ������
    {
        std::cout << "\n\n������ ��� ����� ������ ������������!\n\n";
        return -1;
    }
    
    std::cout << "\n\n������� ������: ";
    
    char c;
    while ((c = _getch()) != '\r')
    {
        pass.push_back(c);
        _putch('*');
    }
    // ���������� ������ � ������� ������������ �� �������
    if (pass != allUsers.getUser(userNum).getPassword())        //������ �� ������
    {
        std::cout << "\n\n������ ��� ����� ������ ������������.\n\n";
        userNum = -1;
    }
        
    return userNum;
}

void ConversationManager::userMessChoise(User& user)
{
    bool isRun = true;
    //��� ������������
    std::string name = user.getNickname();
    while (isRun)
    {
        this->cleanConsole();
        std::cout << "\n\n" << user.getNickname() << ", ��������� ��������:\n";
        std::cout << "��������:\n1 - ������� � ����� ���.\n2 - ������� � ������ �����.\n";
        
        //std::cout << "4 - ����������� ������� ��������� (���������� ���������: " << "countPM" << ").\n";
        std::cout << "3 - ��������� ������ � �����������.\n";
        std::cout << "\n��������� ������ : ";

        // ����������� ����� ������������
        char sim;
        while (true)
        {
            sim = _getch();

            if (sim == '1' || sim == '2' || sim == '3')
            {
                std::cout << sim << std::endl << std::endl;
                break;
            }
        }

        if (sim == '1')  //������� � ����� ���
        {
            outputCommonMessage(); //����� ��������� �� ������ ����

            std::cout << "\n\n������ �������� ��������� � ����� ���?\n����� 1- ��, ����� 2 - ����� �� ������ ����.: ";
            char sim;
            while (true)
            {
                sim = _getch();

                if (sim == '1' || sim == '2')
                {
                    std::cout << sim << std::endl << std::endl;
                    break;
                }
            }
            if (sim == '1')
            {

                inputCommonMessage(name);
            }
        }
        if (sim == '2')     //������� � ������ ����������
        {
            privateMesMenu(name);
        }
        if (sim == '3')         //��������� ������ � �����������
            isRun = false;
    }
}

void ConversationManager::outputPrivateMesage(User& user)
{
    {
        this->cleanConsole();
        std::cout << "\n���. ��� ������ ���������:\n\n";
        for (int i = 0; i < privateMessagePool.getCount(); ++i)
        {
            if (*privateMessagePool[i].getSendTo() == user.getNickname())
                std::cout << *privateMessagePool[i].getSendFrom() << " �������: " << *privateMessagePool[i].getMessage() << std::endl;
        }
        std::cout << "\n\n������� �� ����� �������, ��� �� ����� �� ������ ��������� ���� ������ ���������: ";
        char sim;
        sim = _getch();
    }
}

void ConversationManager::outputCommonMessage()
{
    this->cleanConsole();
    std::cout << "\n����� ���. ��� ���������:\n\n";
    for (int i = 0; i < commonMessagePool.getCount(); ++i)
    {
        std::cout << "'" << *commonMessagePool[i].getSendFrom() << "'" << " �������: " << *commonMessagePool[i].getMessage() << std::endl;
    }
}

void ConversationManager::inputPrivateMessage(User& user)
{
    this->cleanConsole();
    std::cout << "\n\n�������� ����� ������������, ��� �� �������� ���������: \n";
    int count = 0;
    for (int i = 0; i < allUsers.getCount(); ++i)
    {
        if (!(allUsers.getUser(i) == user))
        {
            std::cout << count << ". " << allUsers.getUser(i).getNickname() << std::endl;
            count++;
        }
    }
    int choise{ 0 };
    while (true)
    {
        choise = getIntValue();
        if (choise >= 0 && choise < count)   //������� ���������� �����
            break;
        else
        {
            std::cout << "\n\n�� ������� ������, ������ ������������ �� ������ �������� ���������. ���������� �����:";
        }
    }

    int index;
    allUsers.findUser(std::move(user), index);
    if (choise >= index) choise++;
    std::cout << "\n�������� ����� ��������� ��� " << allUsers.getUser(choise).getNickname() << ": ";
    std::string privateMes{ "" };
    getline(std::cin, privateMes);
    int mesNum = privateMessagePool.getCount();

    Message* ptrPrivateMes = new Message(mesNum, privateMes, user.getNickname(), allUsers.getUser(choise).getNickname());
    std::cout << "\n\n��������� ��������� ��� �������: " << mesNum << " \n\n";
    privateMessagePool.add(std::move(*ptrPrivateMes));
    delete ptrPrivateMes;
}

void ConversationManager::inputCommonMessage(std::string& name)
{
    this->cleanConsole();
    std::cout << "\n\n�������� ��������� ��� ����: ";
    std::string mes{ "" };
    getline(std::cin, mes);
    int mesNum = commonMessagePool.getCount();
    Message* ptrCommonMes = new Message(mesNum, mes, name);
    std::cout << "\n\n��������� ��������� ��� �������: " << mesNum << " \n\n";
    commonMessagePool.add(std::move(*ptrCommonMes));
    delete ptrCommonMes;
}

int ConversationManager::amountPrivateMessage(std::string& name)
{
    int countPM{ 0 };
    for (int i = 0; i < privateMessagePool.getCount(); ++i)
    {
        if (*privateMessagePool[i].getSendTo() == name)
        {
            countPM += 1;
        }
    }
    return countPM;
}
void ConversationManager::privateMesMenu(std::string& name)
{
    int mainID = allUsers.getPosNumber(name);
    //���� ������ ����� �� ��� �������: � ��� ���� ���� � ���� ���
    Array<int> haveChat;
    Array <int> noChart;
    for (int i = 0; i < ptrPrivCharts.getCount(); ++i)
    {
        if(ptrPrivCharts[i]->isItRightChat(mainID))
        {
            haveChat.add(ptrPrivCharts[i]->getAnotherUser(mainID));
        }
    }
    //haveChat.show();                            //�������
    for (int i = 0; i < allUsers.getCount(); ++i)
    {
        bool hasUserInChat = false;
        for (int j = 0; j < haveChat.getCount(); ++j)
        {
            if (haveChat[j] == i)
            {
                hasUserInChat = true;
                break;
            }
        }
        std::cout << "i = " << i << hasUserInChat << std::endl;
        if (!hasUserInChat &&(i != mainID))
            noChart.add(std::move(i));
    }
    //std::cout << "\n**************\n";
    //noChart.show();                         //�������
    //printPrivateMessagePool();    
    //char pause;
    //pause = _getch();

    this->cleanConsole();
    if (haveChat.getCount() == 0)
    {
        std::cout << "\n���� � ��� �� ������� �� ������ ���� � ��������������:";
    }
    else
    {
        std::cout << "\n\n ��������� ����:";
        for (int i = 0; i < haveChat.getCount(); ++i)
        {
            int ii = haveChat[i];
            std::cout << std::endl << i << " : '" << allUsers.getUser(ii).getNickname() << "'";
            //std::cout << std::endl << i << " - " << allUsers.getUser(ii).getNickname() << "��� - �� �� ���������� ���������: ";
        }
    }

    if (haveChat.getCount() > 0)
            std::cout << "\n\n�������� ����� ����� ������ ������������, ��� ��� �� ������ �������.";
    
    std::cout << " \n" << haveChat.getCount() << " : ������� ����� ���.\n";
    std::cout << haveChat.getCount() + 1 << " : ����� �� ����.";

    //std::cout << "\n\n��� �����: ";
    int choise{ 0 };
    while (true)
    {
        choise = getIntValue();
       
        if (choise >= 0 && choise <= haveChat.getCount() + 1)   //������� ���������� �����
            break;
        else
        {
            std::cout << "\n\n�� ������� ������, ��� �� ������ ������� �� ������. ���������� �����:";
        }
    }
    if (choise >= 0 && choise < haveChat.getCount())        //��������� � �������� � � ��� ������������
    {
        readWritePrivateChat(mainID, haveChat[choise]);
    }
    else if (choise == haveChat.getCount())                 //������� ����� ���
    {
        createNewChart(mainID, noChart);
    }
    else if (choise == haveChat.getCount()+1)               //����� �� ������� �����
    {
        return;
    }
}

void ConversationManager::readWritePrivateChat(int frstUserNum, int secndUserNum)
{
    //PrivateChat* a;
    int iConst{0};
    // ���� �� �����, ���� ���.
    for (int i = 0; i < ptrPrivCharts.getCount(); ++i)
    {
        //a = ptrPrivCharts[i];
        if (ptrPrivCharts[i]->isTwoUsersOk(frstUserNum, secndUserNum))          //������ ��� ������
        {
            iConst = i;
            break;
        }
    }
    Array<int> ar = ptrPrivCharts[iConst]->getArr();                                              //�������� ������ � �������� ����
    std::cout << "\n\n";
    if (ar.getCount() > 0)
    {
        std::cout << "���:\n\n";
    }
    for (int i = 0; i < ar.getCount(); ++i)
    {
        int num = ar[i];
        std::string mes = *privateMessagePool.get(num).getMessage();
        std::string sender = *privateMessagePool.get(num).getSendFrom();
        std::cout << "'" << sender << "' �������:" << mes << std::endl;
    }
    std::cout << "\n���� ������ �������� ��������� ������������ " << allUsers.getUser(secndUserNum).getNickname() << ", ������� ����� 1, ����� �� ���� - 2: ";
    char sim;
    while (true)
    {
        sim = _getch();

        if (sim == '1' || sim == '2')
        {
            std::cout << sim << std::endl << std::endl;
            break;
        }
    }
    if (sim == '1')
    {
        std::cout << "\n\n���������: ";
        std::string mes{ "" };
        getline(std::cin, mes);
        int mesNum = privateMessagePool.getCount();
        std::string usName = allUsers.getUser(frstUserNum).getNickname();
        Message* ptrPrivateMes = new Message(mesNum, mes, usName);
        privateMessagePool.add(std::move(*ptrPrivateMes));
        delete ptrPrivateMes;
        
        ptrPrivCharts[iConst]->setMesNumber(mesNum);
        
    }
}

void ConversationManager::createNewChart(int mainID, Array<int>& noChart)
{
    if (noChart.getCount() > 0)
    {
        this->cleanConsole();
        std::cout << "\n\n�������� ���� �������������, � �������� ����� ������� ����� ���:";
        for (int i = 0; i < noChart.getCount(); ++i)
        {
            int a = noChart[i];
            std::cout << std::endl << i << " - '" << allUsers.getUser(a).getNickname() << "'";
        }
        std::cout << "\n�������� ����� ������������ ��� ������� " << noChart.getCount() << " ��� �� ����� �� ����: ";
        int choise{ 0 };
        while (true)
        {
            choise = getIntValue();
            if (choise >= 0 && choise <= noChart.getCount())   //������� ���������� �����
                break;
            else
            {
                std::cout << "\n\n�� ������� ������, ��� �� ������ ������� �� ������. ���������� �����:";
            }
        }
        int a = noChart[choise];
        writeNewChart(mainID, a);
    }
    else 
    {
        std::cout << "\n\n������ �� �������� �������������, � �������� �� � ��� �� ���� ������� ����.";
        std::cout << "\n��� �����������, ������� ����� �������.";
        char wait;
        wait = _getch();
        return;
    }
}

void ConversationManager::writeNewChart(int mainID, int otherUserNum)
{
    this->cleanConsole();

    std::cout << "\n\n��� �������� ������ ����, ������� ��������� ������������ " << allUsers.getUser(otherUserNum).getNickname() << ".\n";
    std::cout << "���������: ";
    std::string mes{ "" };
    getline(std::cin, mes);
    int mesNum = privateMessagePool.getCount();
    std::string usName = allUsers.getUser(mainID).getNickname();
    Message* ptrPrivateMes = new Message(mesNum, mes, usName);
    privateMessagePool.add(std::move(*ptrPrivateMes));
    delete ptrPrivateMes;
    PrivateChat* ptrCh = new PrivateChat(mainID, otherUserNum);     //������� ������ !!!!!!!!!!!!!!!!!!!!!!!!!!
    ptrCh->setMesNumber(mesNum);
    ptrPrivCharts.add(std::move(ptrCh));
    ptrCh = nullptr;            //����������������, �������� ������  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void ConversationManager::printPrivateMessagePool()
{
    std::cout << "\nprivateMessagePool:\n";
    for (int i = 0; i < privateMessagePool.getCount(); ++i)
    {
        std::cout << "\nposition " << i << " : " << *privateMessagePool[i].getMessage() << "; ��������: " << *privateMessagePool[i].getSendFrom();
    }

    std::cout << "\n\n ptrPrivCharts:\n";
    for (int i = 0; i < ptrPrivCharts.getCount(); ++i)
    {
        std::cout << "\nprivateChart " << i << " : ";
        PrivateChat* a = ptrPrivCharts[i];
        a->printAllPartners();
        Array<int> m = a->getArr();
        m.show();
    }
}

