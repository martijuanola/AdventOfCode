#include <iostream>
#include <string>
using namespace std;
int main() {
	int min, max;
	char c, aux;
	string s;

	int valids = 0;
	while(cin >> min >> aux >> max >> c >> aux >> s) {
		int count = 0;
		for(int i = 0 ; i < s.size() and count <= max; i++) {
			if(s[i] == c) count++;
		}
		if(count >= min and count <= max) valids++;
	}
	cout << valids << endl;
}