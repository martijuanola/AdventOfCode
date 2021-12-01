#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void check_input(vector<string>& input, long& r, long& total, const map<string,int>& comp) {
	vector<bool> atr(8,false);
	for(int i = 0; i < input.size(); i++) {
		while(input[i] != "") {
			string type = input[i].substr(0,3);
			int p = comp.find(type)->second;
			if(atr[p]) return;
			else atr[p] = true;
			int pos = input[i].find(" ");
			if(pos == -1) input[i] = "";
			else input[i] = input[i].substr(pos+1);
		}
	}

	int count = 0;
	for(int i = 0; i < 8; i++) if(atr[i]) count++;
	if(count == 8 or (count == 7 and not atr[7])) r++;
	total++;
	input.clear();
}

int main() {
	map<string,int> comp;
	comp["byr"] = 0; comp["iyr"] = 1; comp["eyr"] = 2; comp["hgt"] = 3;
	comp["hcl"] = 4; comp["ecl"] = 5; comp["pid"] = 6; comp["cid"] = 7;

	long r = 0, total = 0;
	vector<string> input;
	string aux;
	while(getline(cin,aux)) {
		if(aux == "") check_input(input, r, total, comp);
		else input.push_back(aux);
	}
	check_input(input, r, total, comp);
	cout << r << " " << total << endl;
}