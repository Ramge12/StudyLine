// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
	vector<int> answer;
	string numberString;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			answer.push_back(atoi(numberString.c_str()));
			numberString = "";
		}
		else if (i == str.size() - 1)
		{
			numberString += str[i];
			answer.push_back(atoi(numberString.c_str()));
			numberString = "";
		}
		else
		{
			numberString += str[i];
		}
	}
	return answer;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}