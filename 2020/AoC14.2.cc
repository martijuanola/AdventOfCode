#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long int ulli;

void backtrack_rec(map <ulli, ulli>& m, const ulli& data, bitset<36>& adress, const vector<int>& X, int pos) {
	if(pos == X.size()) {
		m[adress.to_ullong()] = data;
		return;
	}

	adress.set(35-X[pos],0);
	backtrack_rec(m,data,adress,X,pos+1);
	adress.set(35-X[pos],1);
	backtrack_rec(m,data,adress,X,pos+1);
}

void backtrack(map <ulli, ulli>& m, const ulli& data, bitset<36>& adress, const vector<int>& X) {
	backtrack_rec(m,data,adress,X,0);
}

int main() {
	map <ulli, ulli> m;

	vector<int> X;
	bitset<36> mask;
	bitset<36> bin;

	string aux, aux2;
	while(cin >> aux) {
		if(aux == "mask") {
			cin >> aux >> aux;
			X.clear();
			for(int i = 0; i < aux.size(); i++) if(aux[i] == 'X') X.push_back(i);
			replace(aux.begin(), aux.end(), 'X', '0');
			mask = bitset<36> (aux);
		}
		else if(aux.substr(0,3) == "mem") {
			bitset<36> adress = bitset<36> (stoi(aux.substr(4,aux.size()-5)));
			adress = adress | mask;
			cin >> aux >> aux;
			ulli data = stoi(aux);
			backtrack(m,data,adress,X);
		}
	}

	ulli r = 0;
	map <ulli, ulli>::iterator it = m.begin();
	while(it != m.end()) {
		//cout << it->first << " || " << r << " + " << it->second << " = ";
		r += it->second;
		//cout << r << endl;
		it++;
	}
	cout << "res: " << r << endl;
}

