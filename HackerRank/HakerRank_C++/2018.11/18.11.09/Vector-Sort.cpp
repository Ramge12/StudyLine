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
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int number;
	cin >> number;
	vector<int> answer;
	for (int i = 0; i < number; i++)
	{
		int dummy;
		cin >> dummy;
		answer.push_back(dummy);
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)cout << answer[i]<<" ";
	
	return 0;
}