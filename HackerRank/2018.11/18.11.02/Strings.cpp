// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	string firstString;
	cin >> firstString;
	string secondString;
	cin >> secondString;

	cout << firstString.size()<<" "<<secondString.size() << endl;
	cout << firstString + secondString << endl;
	char dummy;
	dummy = firstString[0];
	firstString[0] = secondString[0];
	secondString[0] = dummy;
	cout << firstString + " " + secondString << endl;
	return 0;
}