#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	map <unsigned long long int,  bitset<36> > m;

	bitset<36> mask1, mask2;
	bitset<36> bin;

	string aux, aux2;
	while(cin >> aux) {
		if(aux == "mask") {
			cin >> aux >> aux;
			aux2 = aux;
			replace(aux.begin(), aux.end(), 'X', '0');
			replace(aux2.begin(), aux2.end(), 'X', '1');
			mask1 = bitset<36> (aux);
			mask2 = bitset<36> (aux2);
		}
		else if(aux.substr(0,3) == "mem") {
		 	unsigned long long int a;
			a = stoi(aux.substr(4,aux.size()-5));
			cin >> aux >> aux;
			bin = bitset<36> (stoi(aux));
			m[a] = ((bin | mask1) & mask2);
		}
	}
	unsigned long long int r = 0;
	map <unsigned long long int,  bitset<36> >::iterator it = m.begin();
	while(it != m.end()) {
		//cout << it->second << " -> " << (it->second).to_ullong() << endl;
		r += (it->second).to_ullong();
		it++;
	}
	cout << "res: " << r << endl;
}