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

int GetSSN(Person * p)
{
	return p->ssn;
}
void ShowPerInfo(Person * p)
{
	cout << "주민등록 번호" << p->ssn << endl;
	cout << "이름" << p->name << endl;
	cout << "주소" << p->addr << endl;
}
Person * MakePersonData(int ssn, char * name, char* addr)
{
	Person * newP = new Person;
	newP->ssn = ssn;
	strcpy(newP->name, name);	//문자열 복사
	strcpy(newP->addr, addr);
}

typedef int Key;		//주민등록번호
typedef Person * Value;

enum SlotStatus { EMPTY, DELETED, INUSE };

struct Slot
{
	Key key;
	Value val;
	enum SlotStatus status;
};

#define MAX_TBL 100

typedef int HashFunc(Key k);

struct Table
{
	Slot tbl[MAX_TBL];
	HashFunc * hf;
};

//테이블 초기화
void TBLInit(Table * pt, HashFunc * f)
{
	//모든 슬롯 초기화
	for (int i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	pt->hf = f;	//해쉬 함수 등록
}

//테이블에 키와 값을 저장
void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k);
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

//키를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k);
	if ((pt->tbl[hv]).status != INUSE)
	{
		return NULL;
	}
	else
	{
		(pt->tbl[hv]).status = DELETED;
		return (pt->tbl[hv]).val;	//소멸 대상의 값 반환
	}
}
//키를 근거로 테이블에서 데이터 탐색
Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val;	//탐색 대상의 값 변환
}