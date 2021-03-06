#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#define STACK_LEN 100

typedef int Data;

struct ArrayStack
{
	Data stackArr[STACK_LEN];	//typedef int Data
	int topIndex;
};

typedef ArrayStack Stack;

void StackInit(Stack * pstack)		//스택의 초기화
{
	pstack->topIndex = -1;		//topIndex의 -1은 빈 상태를 의미함
}
int SIsEmpty(Stack * pstack)		//스택이 비었는지 확인
{
	if (pstack->topIndex == -1)	//스택이 비어있다면
		return true;
	else
		return false;
}
void SPush(Stack * pstack, Data data)	//스택의 push연산
{
	pstack->topIndex += 1;		//데이터 추가를 위한 인덱스 값 증가
	pstack->stackArr[pstack->topIndex] = data;	//데이터 저장
}
Data SPop(Stack * pstack)			//스택의 pop연산
{
	int rIdx;

	if (SIsEmpty(pstack)) {
		cout << "Stack Memory Error!" << endl;
		exit(-1);
	}

	rIdx = pstack->topIndex;	//삭제할 데이터가 저장된 인덱스 값 저장
	pstack->topIndex -= 1;		//pop연산의 결과로 topIndex 값 하나 감소

	return pstack->stackArr[rIdx];	//삭제되는 데이터 반환
}
Data SPeek(Stack * pstack)		//스택의 peek연산
{
	if (SIsEmpty(pstack))
	{
		cout << "Stack Memory Error!" << endl;
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];	//맨 위에 저장된 데이터 변환
}

int main()
{

    return 0;
}

