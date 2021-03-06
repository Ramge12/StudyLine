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
	Node* prev;
};

struct DLDeque
{
	Node* head;
	Node* tail;
};

typedef DLDeque Deque;

void DequeInit(Deque * pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}
int DQIsEmpty(Deque * pdeq)
{
	if (pdeq->head == NULL)	//head가 NULL이면 비어있는 덱!
		return true;
	else
		return false;
}
void DQAddFirst(Deque * pdeq, Data data)
{
	Node * newNode = new Node;
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;

	newNode->prev = NULL;
	pdeq->head = newNode;
}
void DQAddLast(Deque * pdeq, Data data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;

	newNode->next = NULL;
	pdeq->tail = newNode;
}
Data DQRemoveFirst(Deque * pdeq)
{
	Node * rnode = pdeq->head;
	Data rdata = pdeq->head->data;

	if (DQIsEmpty(pdeq))
	{
		cout << "Deque Memory Error" << endl;
		exit(-1);
	}

	pdeq->head = pdeq->head->next;
	delete(rnode);

	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return rdata;
}
Data DQRemoveLast(Deque * pdeq)
{
	Node * rnode = pdeq->tail;
	Data rdata = pdeq->tail->data;

	if (DQIsEmpty(pdeq))
	{
		cout << "Deque Memory Error" << endl;
		exit(-1);
	}

	pdeq->tail = pdeq->tail->prev;
	delete(rnode);

	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	return rdata;
}
Data DQGetFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		cout << "Deque Memory Error" << endl;
		exit(-1);
	}
	return pdeq->head->data;
}
Data DQGetLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		cout << "Deque Memory Error" << endl;
		exit(-1);
	}
	return pdeq->tail->data;
}
int main()
{

    return 0;
}

