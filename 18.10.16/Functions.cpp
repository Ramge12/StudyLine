// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d)
{
	int maxNum = 0;
	if (maxNum < a)maxNum = a;
	if (maxNum < b)maxNum = b;
	if (maxNum < c)maxNum = c;
	if (maxNum < d)maxNum = d;
	return maxNum;
}

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d", ans);

	return 0;
}