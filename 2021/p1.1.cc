#include <iostream>
using namespace std;

int main() {
	long long count = 0;
	long long a = -1, b = -1;
	while(cin >> b) {
		if(a != -1 and a < b) count++;
		a = b;
	}
	cout << count << endl;
}