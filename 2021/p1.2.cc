#include <iostream>
using namespace std;

int main() {
	long long count = 0;
	long long a = -1, b = -1, c = -1, d = -1;
	while(cin >> d) {
		if(a != -1 and d>a) count++;
		a = b;
		b = c;
		c = d;
	}
	cout << count << endl;
}