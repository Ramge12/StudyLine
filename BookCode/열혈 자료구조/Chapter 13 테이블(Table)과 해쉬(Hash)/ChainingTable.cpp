#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;
#define STR_LEN 50

struct Person
{
	int ssn;			//주민등록번호
	char name[STR_LEN];	//이름
	char addr[STR_LEN];	//주소
};

typedef int Key;
typedef Person * Value;
typedef Slot * Data;	//노드에 저장한 데이터는 slot형 변수의 주소 값이다.

struct Slot
{
	Key key;
	Value val;
	Slot * next;		//다음 노드를 가리키는 포인터 변수
};
//----------------------------------------

#define MAX_TBL 100

typedef int HashFunc(Key k);

struct Table
{
	List tbl[MAX_TBL];
	HashFunc * hf;
};

void TBLInit(Table * pt, HashFunc * f)
{
	for (int i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));
	pt->hf = f;
}
void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot ns = { k,v };

	if(TBLSearch(pt, k) != NULL)	//키가 중복되었다면
	{
		cout << "키 중복 오류 발생" << endl;
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), ns);
	}
}
Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			LRemove(&(pt->tbl[hv]));
			return cSlot.val;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
				{
					LRemove(&(pt->tbl[hv]));
					return cSlot.val;
				}
			}
		}
	}
	return false;	//삭제할 대상이 존재하지 않는 경우
}
Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			return cSlot.val;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
					return cSlot.val;
			}
		}
	}
	return false;	//찾을 대상이 존재하지 않을 경우
}