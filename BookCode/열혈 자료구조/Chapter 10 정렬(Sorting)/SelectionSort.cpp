#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void SelSort(int arr[], int n)
{
	int maxIdx;
	int temp;

	for (int i = 0; i < n - 1; i++)
	{
		maxIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}
		//교환
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main()
{

    return 0;
}

