// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	//배열을 어떻게 입력받을지...헷갈려서 검색해서 그 부분만 확인함 while쓸줄은 몰랐다 

	int firstNum, secondNum;
	cin >> firstNum >> secondNum;
	vector<vector<int>> Line(firstNum);

	for (int i = 0; i < firstNum; i++)
	{
		int inputNum;
		cin >> inputNum;
		for (int j = 0; j < inputNum; j++)	//여러개 입력해도 하나하나씩 읽을 수 있다
		{
			int inputVectorNum;
			cin >> inputVectorNum;
			Line[i].push_back(inputVectorNum);
		}
	}

	for (int i = 0; i < secondNum; i++)
	{
		int firstOut, secondOut;
		cin >> firstOut >> secondOut;				//입력받으면 바로 값을 보여준다
		cout << Line[firstOut][secondOut] << endl;
	}

	return 0;
}