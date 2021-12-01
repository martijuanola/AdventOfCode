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
	int r = 1;
	
	int trees = 0, j = 0;
	for(int i = 0; i < m.size(); i += 2) {
		if(m[i][j]) trees++;
		j = (j+1)%m[0].size();
	}
	cout << trees << endl;
}