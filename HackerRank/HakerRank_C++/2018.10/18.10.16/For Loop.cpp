// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int firstNum;
	cin >> firstNum;
	int lastNum;
	cin >> lastNum;
	for (int i = firstNum; i <= lastNum; i++)
	{
		switch (i)
		{
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		case 4:
			cout << "four";
			break;
		case 5:
			cout << "five";
			break;
		case 6:
			cout << "six";
			break;
		case 7:
			cout << "seven";
			break;
		case 8:
			cout << "eight";
			break;
		case 9:
			cout << "nine";
			break;
		default:
			if (i % 2 == 0)cout << "even";
			else cout << "odd";
			break;
		}
		cout << endl;
	}

	return 0;
}

