#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void InserSort(int arr[], int n)
{
	int insData;
	for (int i = 1; i < n; i++)
	{
		insData = arr[i];	//정렬대상을 insData에 저장

		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];	//비교대상 한 칸 뒤로 밀기
			else
			{
				arr[j + 1] = insData;	//찾은 위치에 정렬대상 삽입!
				break;					//삽입위치 찾았으니 탈출!
			}
		}
	}
}

int main()
{

    return 0;
}

