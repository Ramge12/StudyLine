#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];		//피벗의 위치는 가장 왼쪽!
	int low = left + 1;
	int high = right;

	while (low <= high)	//교차되지 않을 떄까지 반복
	{
		//피벗보다 큰 값을 찾는 과정
		while (pivot > arr[low] && low <= right)		//3개(low,pivot,higt)상태가 일치할 경우를 대비해서
			low++;		//low를 오른쪽으로 이동

		//피버보다 작은 값을 찾는 과정
		while (pivot < arr[high] && high >= (left+1))
			high--;		//hight를 왼쪽으로 이동

		//교차되지 않은 상태라면 Swap 실행
		if (low <= high)
			Swap(arr, low, high);
	}
	
	Swap(arr, left, high);	//피벗과 high가 가리키는 대상 교환
	return high;			//옮겨진 피벗의 위치정보 반환
}
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);	//둘로 나눠서
		QuickSort(arr, left, pivot - 1);			//왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right);			//오른쪽 영역을 정렬
	}
}


int main()
{

    return 0;
}

