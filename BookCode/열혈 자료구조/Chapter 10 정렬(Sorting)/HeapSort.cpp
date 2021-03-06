#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#include "UsefulHeap.h"
int PriComp(int n1, int n2)
{
	return n2 - n1;	//오름차순 정렬을 위한 문장
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	HeapInit(&heap, pc);

	//정렬대상을 가지고 힙을 구성한다.
	for (int i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	//순서대로 하나씩 꺼내서 정렬을 완성한다.
	for (int i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}


int main()
{

    return 0;
}

