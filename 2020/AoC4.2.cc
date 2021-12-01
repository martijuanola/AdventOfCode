#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool type_validation(const string& type, const string& data) {
cout << "Validation of type " << type << ". String -> " << data << endl;

	if(type == "byr") { if(stoi(data) < 1920 or stoi(data) > 2002) return false; }
	else if(type == "iyr") { if(stoi(data) < 2010 or stoi(data) > 2020) return false; }
	else if(type == "eyr") { if(stoi(data) < 2020 or stoi(data) > 2030) return false; }
	else if(type == "hgt") {
		string m = data.substr(data.size()-2,2);
		string d = data.substr(0,data.size()-2);
		if((m != "cm" and m != "in") or (m == "cm" and (d < "150" or d > "193")) or (m == "in" and (d < "59" or d > "76"))) return false;
	}
	else if(type == "hcl") { if(data < "#000000" or data > "#ffffff") return false;}
	else if(type == "ecl") { if(not (data == "amb" or data == "blu" or data == "brn" or data == "gry" or data == "grn" or data == "hzl" or data == "oth")) return false;}
	else if(type == "pid") { if(data.size() != 9) return false; }
	
	return true;
}

void check_input(vector<string>& input, long& r, long& total, const map<string,int>& comp) {
cout << endl;
	total++;
	vector<bool> atr(8,false);
	bool valid = true;
	for(int i = 0; i < input.size() and valid; i++) {
		while(input[i] != "" and valid) {
			string type = input[i].substr(0,3);
			int p = comp.find(type)->second;
			if(atr[p]) return;
			else atr[p] = true;

			int pos = input[i].find(" ");

			if(not type_validation(type,input[i].substr(4,pos-4))) valid = false;

			if(pos == -1) input[i] = "";
			else input[i] = input[i].substr(pos+1);
		}
	}
	if(not valid) {
		input.clear();
		return;
	}
cout << "correct" << endl;

	int count = 0;
	for(int i = 0; i < 8; i++) if(atr[i]) count++;
	if(count == 8 or (count == 7 and not atr[7])) {
		r++;
		cout << "checked" << endl;
	}

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