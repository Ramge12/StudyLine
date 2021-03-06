// ConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int ISearch(int ar[], int first, int last, int target)
{
	//ar = 배열, first = 앞 부분 인덱스, last = 뒷 부분 인덱스 , target = 목표대상
	int mid;

	if (ar[first] > target || ar[last] < target)
		return -1;		//-1의 반환은 탐색의 실패를 의미

	//이진 탐색과의 차이점을 반영한 문장
	mid = ((double)(target - ar[first]) / (ar[last] - ar[first])*(last - first)) + first;

	if (ar[mid] == target)
		return mid;		//탐색된 타겟의 인덱스 값 반환
	else if (target < ar[mid])
		return ISearch(ar, first, mid - 1, target);
	else
		return ISearch(ar, mid + 1, last, target);
}

int main()
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		cout << "탐색실패" << endl;
	else
		cout << "타겟 저장 인덱스 : "<<idx<<endl;
    return 0;
}

