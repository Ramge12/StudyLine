// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

class Spell {
private:
	string scrollName;
public:
	Spell() : scrollName("") { }
	Spell(string name) : scrollName(name) { }
	virtual ~Spell() { }
	string revealScrollName() {
		return scrollName;
	}
};

class Fireball : public Spell {
private: int power;
public:
	Fireball(int power) : power(power) { }
	void revealFirepower() {
		cout << "Fireball: " << power << endl;
	}
};

class Frostbite : public Spell {
private: int power;
public:
	Frostbite(int power) : power(power) { }
	void revealFrostpower() {
		cout << "Frostbite: " << power << endl;
	}
};

class Thunderstorm : public Spell {
private: int power;
public:
	Thunderstorm(int power) : power(power) { }
	void revealThunderpower() {
		cout << "Thunderstorm: " << power << endl;
	}
};

class Waterbolt : public Spell {
private: int power;
public:
	Waterbolt(int power) : power(power) { }
	void revealWaterpower() {
		cout << "Waterbolt: " << power << endl;
	}
};

class SpellJournal {
public:
	static string journal;
	static string read() {
		return journal;
	}
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
	
	if (Fireball *fire = dynamic_cast<Fireball*>(spell))fire->revealFirepower();
	else if (Frostbite *frost = dynamic_cast<Frostbite*>(spell))frost->revealFrostpower();
	else if (Thunderstorm *thunder = dynamic_cast<Thunderstorm*>(spell))thunder->revealThunderpower();
	else if (Waterbolt *water = dynamic_cast<Waterbolt*>(spell))water->revealWaterpower();
	else
	{
		string temp = spell->revealScrollName();
		string temp_cm = SpellJournal::read();
		int a = temp.length();
		int b = temp_cm.length();
		vector<int> list;
		list.resize(b + 1);
		vector<vector<int>> LCS_list;
		for (int i = 0; i < a + 1; i++)LCS_list.push_back(list);

		for (int i = 0; i < a + 1; i++)
			for (int j = 0; j < b + 1; j++)
				LCS_list[i][j] = 0;
		for (int i = 0; i < a + 1; i++) {
			for (int j = 0; j < b + 1; j++) {
				if (i == 0 || j == 0) {
					LCS_list[0][0] = 0;
				}
				else if (temp[i - 1] == temp_cm[j - 1]) {
					LCS_list[i][j] = 1 + LCS_list[i - 1][j - 1];
				}
				else {
					LCS_list[i][j] = max(LCS_list[i - 1][j], LCS_list[i][j - 1]);
				}
			}

		}
		cout << LCS_list[a][b] << endl;
	}
}

class Wizard {
public:
	Spell * cast() {
		Spell *spell;
		string s; cin >> s;
		int power; cin >> power;
		if (s == "fire") {
			spell = new Fireball(power);
		}
		else if (s == "frost") {
			spell = new Frostbite(power);
		}
		else if (s == "water") {
			spell = new Waterbolt(power);
		}
		else if (s == "thunder") {
			spell = new Thunderstorm(power);
		}
		else {
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};

int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while (T--) {
		Spell *spell = Arawn.cast();
		counterspell(spell);
	}
	return 0;
}