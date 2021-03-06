// ConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;				//-1의 반환은 탐색의 실패를 의미
	mid = (first + last) / 2;	//탐색대상의 중앙을 찾는다.

	if (ar[mid] == target)
		return mid;				//탐색된 타겟의 인덱스 값 변환
	else if (target < ar[mid])
		return BSearchRecur(ar, first, mid - 1, target);
	else
		return BSearchRecur(ar, mid + 1, last, target);
}

int main()
{
	int arr[] = { 1,3,5,7,9 };
	int idx;
	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);	// 7의 위치 검색
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);	// 4의 위치 검색
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);
    return 0;
}

