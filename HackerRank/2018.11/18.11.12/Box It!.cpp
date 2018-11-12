
#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Box
{
private:
	int length;
	int breadth;
	int height;
public:
	Box() :length(0), breadth(0), height(0) {};
	Box(int l, int b, int h) :length(l), breadth(b), height(h) {};
	Box(Box & box) {
		length = box.length;
		breadth = box.breadth;
		height = box.height;
	};
	int getLength() { return length; }
	int getBreadth() { return breadth; }
	int getHeight() { return height; }
	long long CalculateVolume()
	{
		long long dummy1, dummy2, dummy3;
		dummy1 = length;
		dummy2 = breadth;
		dummy3 = height;
		return dummy1 * dummy2 * dummy3;
	}

	bool operator< (Box & b)
	{
		if (length < b.length)
		{
			return true;
		}
		else if (breadth < b.breadth && length == b.length)
		{
			return true;
		}
		else if (height<b.height && breadth == b.breadth && length == b.length)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

ostream& operator<<(ostream& os,Box& B)
{
	os << B.getLength() <<" "<< B.getBreadth()<<" " << B.getHeight();
	return os;
}

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i<n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox<temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}