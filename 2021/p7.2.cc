#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;

int t = 18;

void printV(const vector<int>& v) {
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

void printM(const vector<vector<int> >& v) {
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<int> read() {
	vector<int> aux;
	char c;
	int i;

	while(cin >> i) {
		aux.push_back(i);
		cin >> c;
	}

	return aux;
}

int main() {
	vector<int> v = read();
	sort(v.begin(),v.end());

	printV(v);
	
	int min, minpos;
	for(int i = v[0]; i <= v[v.size()-1]; i++) {
		int fuel = 0;

		for(int j = 0; j < v.size(); j++) {
			int dif;
			if(v[j] < i) dif = i-v[j];
			else dif = v[j]-i;

			fuel += (1+dif) * dif/2;
		}

		if(fuel < min) {
			min = fuel;
			minpos = i;
		}
	}

	cout << "MIN: " << minpos << " -> " << min << endl;
}


// 1 + 2 + 3 = 6 = (1+3) * 3/2