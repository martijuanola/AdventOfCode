#include <iostream>
#include <string>
using namespace std;
int main() {
	int min, max;
	char c, aux;
	string s;

	int valids = 0;
	while(cin >> min >> aux >> max >> c >> aux >> s) {
		if((s[min-1] == c and s[max-1] != c) or (s[min-1] != c and s[max-1] == c)) valids++;
	}
	cout << valids << endl;
}