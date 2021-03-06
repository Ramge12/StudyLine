// ConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("원반 1을 %c에서 %c로 이동 \n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);						//작은 원반 n-1개를 (맨 아래의 원반을 제외한 나머지 원반을)
		printf("원반 %d을(를) %c에서 %c로 이동 \n", num, from, to);	//큰 원반(맨 아래의 원반) 1개를 A에서 C로 이동
		HanoiTowerMove(num - 1, by, from, to);						//작은 원반(위의 1단계에서 옮겨진 원반) n-1개를 B에서 C로 이동
	}
}

int main()
{
	//막대 A의 원반 3개를 막대 B를 경유하여 막대 C로 옮기기
	HanoiTowerMove(3, 'A', 'B', 'C');
    return 0;
}

