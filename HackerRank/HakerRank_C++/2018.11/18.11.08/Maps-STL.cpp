// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	map<string, int> mp;
	
	int inputNum;
	cin >> inputNum;
	for (int i = 0; i < inputNum; i++)
	{
		int checkNum;
		cin >> checkNum;

		string command;
		cin >> command;
		switch (checkNum)
		{
		case 1:
			int mapNum;
			cin >> mapNum;
			if (mp.find(command) == mp.end())
			{
				mp.insert(make_pair(command, mapNum));
			}
			else
			{
				int mpNum = mp.at(command);
				mp.erase(mp.find(command));
				mp.insert(make_pair(command, mapNum + mpNum));
			}
			break;
		case 2:
			if (mp.find(command) != mp.end())
				mp.erase(mp.find(command));
			break;
		case 3:
			if (mp.find(command) != mp.end())
				cout << mp.at(command) << endl;
			else
				cout << 0 << endl;
			break;
		}
	}
	return 0;
}


