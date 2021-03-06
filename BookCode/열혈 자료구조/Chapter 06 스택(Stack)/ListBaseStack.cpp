#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

typedef int Data;

struct Node
{
	Data data;
	Node* next;
};

struct ListStack
{
	Node* head;
};

typedef ListStack Stack;

void StackInit(Stack * pstack)		//스택 초기화
{
	pstack->head = NULL;
}
int SIsEmpty(Stack * pstack)		//스택 비었는지 학인
{
	if (pstack->head == NULL)
		return true;
	else
		return false;
}
void SPush(Stack * pstack, Data data)	//스택의 push 연산
{
	Node * newNode = new Node;	//새 노드 생성

	newNode->data = data;			//새 노드에 데이터 저장
	newNode->next = pstack->head;	//새노드가 최근에 추가된 노드를 가리킴

	pstack->head = newNode;			//포인터 변수 head가 새 노드를 가리킴
}
Data SPop(Stack * pstack)		//스택의 pop연산
{
	Data rdata;
	Node * rnode;

	if (SIsEmpty(pstack)) {
		cout << "stack Memory Error!" << endl;
		exit(-1);
	}

	rdata = pstack->head->data;	//삭제할 노드의 데이터를 임시로 저장
	rnode = pstack->head;		//삭제할 노드의 주소 값을 임시로 저장

	pstack->head = pstack->head->next;	//삭제할 노드의 다음 노드를 head가 가리킴
	delete(rnode);	//노드 삭제
	return rdata;	//삭제된 노드의 데이터 반환
}
Data SPeek(Stack * pstack)		//스택의 peek연산
{
	if (SIsEmpty(pstack)) {
		cout << "stack Memory Error!" << endl;
		exit(-1);
	}
	return pstack->head->data;	//head가 가리키는 노드에 저장된 데이터 반환
}

int main()
{

    return 0;
}

