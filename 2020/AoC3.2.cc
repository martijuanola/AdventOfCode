#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<vector<bool> > m;
	string aux;
	while(getline(cin, aux)) {
		vector<bool> aux2;
		for(int i = 0; i < aux.size(); i++) {
			if(aux[i] == '.') aux2.push_back(false);
			else aux2.push_back(true);
		}
		m.push_back(aux2);
	}
	long r = 1;

	vector<pair<int,int> > test;
	test.push_back(make_pair(1,1));
	test.push_back(make_pair(3,1));
	test.push_back(make_pair(5,1));
	test.push_back(make_pair(7,1));
	test.push_back(make_pair(1,2));
	
	for(int k = 0; k < test.size(); k++) {
		int trees = 0, j = 0;
		for(int i = 0; i < m.size(); i += test[k].second) {
			if(m[i][j]) trees++;
			j = (j+test[k].first) % m[0].size();
		}
		cout << "t " << trees << endl; 
		r *= trees;
	}
	cout << r << endl;
}