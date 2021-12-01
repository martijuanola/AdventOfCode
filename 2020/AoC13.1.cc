#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main() {
	int n, aux, best = -1, which = 0;
	cin >> n;
	string s;
	while(getline(cin,s,',')) {
		if(s != "x") {
			aux = stoi(s);
			int p = ceil(double(n)/aux)*aux - n;
			cout << aux << " " << p << endl;
			if(best == -1 or p < best) {
				best = p;
				which = aux;
			}
		}
	}
	cout << "sol -> " << which << " " << best << endl;
}