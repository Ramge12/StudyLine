#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void BubbleSort(int arr[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//데이터의 교환
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{

    return 0;
}

