
#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Rectangle
{
	int width;
	int height;
public:
	void display()
	{
		cout << width<<" "<<height << endl;
	}
	void input(int wd, int hi) {
		width=(wd);
		height=(hi);
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
};

class RectangleArea :public Rectangle
{
public:
	void read_input()
	{
		int firstNum, SecondNum;
		cin >> firstNum >> SecondNum;
		input(firstNum, SecondNum);
	}
	void display()
	{
		cout << getWidth() * getHeight() << endl;
	}
};

int main()
{
	/*
	* Declare a RectangleArea object
	*/
	RectangleArea r_area;

	/*
	* Read the width and height
	*/
	r_area.read_input();

	/*
	* Print the width and height
	*/
	r_area.Rectangle::display();

	/*
	* Print the area
	*/
	r_area.display();

	return 0;
}