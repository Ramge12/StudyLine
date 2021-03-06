
#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:
	string name;
	int age;
	virtual void getdata() {
		cin >> this->name >> this->age;
	}
	virtual void putdata() {
		cout << this->name << " " << this->age << endl;
	}
};
class Professor :public Person
{
public:
	Professor() {
		cur_id = ++id;
	}
	static int id;
	int cur_id;
	int address;
	virtual void getdata() {
		cin >> name >> age >> address;
	};
	virtual void putdata() {
		cout << name <<" "<< age<< " " << address<< " " << cur_id << endl;
	};
};
int Professor::id = 0;			//static초기화

class Student :public Person
{
public:
	Student() {
		cur_id = ++id;
	}
	static int id;
	int cur_id;
	int marks[6];
	virtual void getdata() {
		cin >> name >> age;
		for (int i = 0; i < 6; i++)cin >> marks[i];
	};
	virtual void putdata() {
		int marksSum = 0;
		for (int i = 0; i<6; i++) {
			marksSum += marks[i];
		}
		cout << name<< " " << age << " " << marksSum << " " << cur_id << endl;
	};
};
int Student::id = 0;//static초기화
int main() {

	int  val;
	//cin >> n; //The number of objects that is going to be created.
	Person *per[4];

	for (int i = 0; i < 4; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i<4; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;

}
