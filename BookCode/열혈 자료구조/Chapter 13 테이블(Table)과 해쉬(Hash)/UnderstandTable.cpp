#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;
struct EmpInfo
{
	int empNum;		//직원의 고유번호
	int age;		//직원의 나이
};

int main()
{
	EmpInfo empInfoArr[1000];
	EmpInfo ei;
	int eNum;

	cout << "사번과 나이 입력:" << endl;
	cin >> ei.empNum >> ei.age;
	empInfoArr[ei.empNum] = ei;		//단번에 저장

	cout << "확인하고픈 직원의 사번 입력:" << endl;
	cin >> eNum;

	ei = empInfoArr[eNum];		//단번에 이벽
	cout << "사번" << ei.empNum << "나이" << ei.age;
	return 0;
}