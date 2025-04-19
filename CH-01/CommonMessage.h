#pragma once
#include <string>

using namespace std;

class CommonMessage
{
private:
	unsigned int _numMessage;
	string _message;
	string _sendFrom;
public:
	//������������
	CommonMessage();
	CommonMessage(int, string&, string&);
	//����������
	~CommonMessage();
	//�������
	int getNumMessage() const;
	string getMessage() const;
	string getSendFrom() const;
	//�������
	void setNumMessage(int);
	void setMessage(string);
	void setSendFrom(string);

};

