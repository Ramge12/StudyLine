// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
	int listSize=0;
public:
	LRUCache(int capacity)
	{
		listSize = capacity;
		tail = NULL;
		head = NULL;
		mp.clear();
	}
	int get(int key)
	{
		map<int, Node*>::iterator it;
		it = mp.find(key);
		if (it == mp.end()) {
			return -1;
		}
		return it->second->value;
	}
	void set(int key, int value)
	{
		// 1 정보를 토대로 노드 생성
		Node* newNode = new Node(NULL,NULL,key, value);
		/*	LRU
			가장 최근에 사용한 객체를 우선적으로 살리고
			가장 사용하지 않은 객체를 지우고 새로운 객체를 넣는다	*/
		
		if (mp.find(key) == mp.end())
		{
			if (mp.size() < listSize)
			{
				//mp.insert(make_pair(key, newNode));	//맵에 추가한다
				if (head == NULL)					//맵에 아무 노드도 없는 경우
				{
					head = newNode;					//이번에 만드 노드가 head 이자 tail
					tail = newNode;
					mp[key] = newNode;
					return;
				}
				else								//맵에 노드가 있는 경우
				{
					head->prev = newNode;			//이번에 만든 노드가 head가 된다 tail은 영향받지 않는다.
					newNode->next = head;
					head = newNode;
					mp[key] = newNode;
					return;
				}
			}
			else if (mp.size() == listSize)
			{
				newNode->next = head;
				head->prev = newNode;
				newNode->prev = NULL;
				head = newNode;
				mp[key] = newNode;
				mp.erase(tail->key);//tail값을 이용해 삭제
				Node* pevNode = tail;
				tail = pevNode->prev;
				tail->next = NULL;
				delete pevNode;
				return;
			}
		}
		else						//맵에 노드가 있는 경우
		{
			mp.at(key)->value = value;			//맵에서 값을 바꾸어준다
			Node* dummy = mp.at(key);			//노드의 값을 받아온다.
												//경우 노드가 head이거나 tail인 경우
			Node* temp1 = dummy->next;
			Node* temp2 = dummy->prev;
			if (head == dummy) { return; }
			else if (temp1 == NULL)
			{
				dummy->prev = NULL;
				dummy->next = head;
				head->prev = dummy;
				head = dummy;

				temp2->next = NULL;
				temp2 = NULL;
				return;
			}
			else
			{
				dummy->prev = NULL;
				dummy->next = head;
				head->prev = dummy;
				head = dummy;

				temp2->next = temp1;
				temp1->prev = temp2;
				return;
			}
		}
	}
};

int main() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
	return 0;
}