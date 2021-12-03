#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int n = 12;

int sbotid(const string& s) {
	int aux = 0;
	int val = 1;
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == '1') aux += val;
		val *= 2;
	}
	return aux;
}

int find(vector<string>& data, int p, bool max) {
	if(data.size() == 1) return sbotid(data[0]);

	int countZ = 0;
	for(int i = 0; i < data.size(); i++) if(data[i][p] == '0') countZ++;

	char c;
	if((countZ > data.size()/2 and max) or (countZ <= data.size()/2 and not max)) c = '1';
	else c = '0';


	for(int i = data.size()-1; i >= 0; i--) {
		if(data[i][p] == c) data.erase(data.begin()+i);
	}

	return find(data,p+1,max);
}

int main() {
	vector<string> data;
	string s;
	while(cin >> s) data.push_back(s);

	vector<string> dataAux = data;
	int gen = find(dataAux, 0, true);
	dataAux = data;
	int scr = find(dataAux, 0, false); 

	cout << gen << " " << scr << " " << gen*scr << endl;
}