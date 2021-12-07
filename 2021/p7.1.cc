#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;

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
	
	int min, minpos, fuel = 0, p = 0;
	for(int i = 0; i < v.size(); i++) fuel += v[i];
	fuel -= v.size()*v[0];
	min = fuel;
	minpos = 0;
	
	for(int i = v[0]+1; i <= v[v.size()-1]; i++) {
		while(p+1 < v.size() and v[p+1] < i) p++;
		fuel -= v.size() - p -1;
		fuel += p+1;

		if(fuel < min) {
			min = fuel;
			minpos = i;
		}
	}

	cout << "MIN: " << minpos << " -> " << min << endl;
}


