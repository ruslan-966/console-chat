#include <iostream>
#include <Windows.h>
#include <memory>
#include "Message.h"
#include "Array.h"
#include "User.h"
#include "ConversationManager.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Array <Message> privateMessagePool;
	Array <Message> commonMessagePool;
	Array <User> allUsers;
	
	//ñîáñòâåííî òåêñò ïðîãðàììû:
	//std::unique_ptr<ConversationManager> cm (new ConversationManager(allUsers, privateMessagePool, commonMessagePool));		//ñîçäàåì ýêçåìïëÿð ìåíåäæåðà îáìåíà äàííûõ ñ ïîëüçîâàòåëåì
	std::unique_ptr<ConversationManager> cm(new ConversationManager());		//ñîçäàåì ýêçåìïëÿð ìåíåäæåðà îáìåíà äàííûõ ñ ïîëüçîâàòåëåì
	cm->start();
	return 0;
}