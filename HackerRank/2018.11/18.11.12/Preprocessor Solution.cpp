
#include "stdafx.h"


#include <iostream>
#include <vector>
using namespace std;
#define INF (unsigned)!((int)0)
#define FUNCTION(name, op) void name(int& a, int b) { if (b op a) a = b; }
//각각 이름과 operator형 (+,-,<등) 을 받아 함수를 만든다 
#define io(v) cin>>v
#define toStr(str) #str
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)

	FUNCTION(minimum, <)
	FUNCTION(maximum, >)

	int main() {
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result = ) << ' ' << ans;
	return 0;

}