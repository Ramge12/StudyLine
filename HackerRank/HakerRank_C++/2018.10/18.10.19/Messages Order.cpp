// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

class Message
{
public:

public:
	string msg_text;
	int index;

	Message() {}

	const string& get_text()
	{
		return msg_text;
	}

	bool operator < (Message &m)
	{
		if (index < m.index)
		{
			return true;
		}

		return false;
	}
};

class MessageFactory
{

public:
	MessageFactory() {}
	Message create_message(const string& text)
	{
		num++;
		Message ma;
		ma.index = num;
		ma.msg_text = text;
		return ma;
	}
	static int num;
};

int MessageFactory::num = 0;	//전역변수이므로 초기화 되지 않는다
//--------------------------------------------------------


class Recipient {
public:
	Recipient() {}
	void receive(const Message& msg) {
		messages_.push_back(msg);
	}
	void print_messages() {
		fix_order();
		for (auto& msg : messages_) {
			cout << msg.get_text() << endl;
		}
		messages_.clear();
	}
private:
	void fix_order() {
		sort(messages_.begin(), messages_.end());
	}
	vector<Message> messages_;
};

class Network {
public:
	static void send_messages(vector<Message> messages, Recipient& recipient) {
		// simulates the unpredictable network, where sent messages might arrive in unspecified order
		random_shuffle(messages.begin(), messages.end());
		for (auto msg : messages) {
			recipient.receive(msg);
		}
	}
};



int main() {
	MessageFactory message_factory;
	Recipient recipient;
	vector<Message> messages;
	string text;
	while (getline(cin, text)) {
		messages.push_back(message_factory.create_message(text));
	}
	Network::send_messages(messages, recipient);
	recipient.print_messages();
}
