﻿// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <list>
#include <math.h>
using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr) {
	vector<int> answer;
	for (int i = 0; i < arr.size()-1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (m == (arr[i] + arr[j])) {
				answer.push_back(i+1);
				answer.push_back(j+1);
				break;
			}
		}
	}
	return answer;
}

int main(){
	icecreamParlor(4, { 1,4,5,3,2 });
	return 0;
}