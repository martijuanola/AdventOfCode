#include <iostream>
using namespace std;

int main() {
	int x = 0, y = 0, aim = 0, aux;
	string s;
	while(cin >> s >> aux) {
		if(s == "forward") {
			x += aux;
			y += aux*aim;
		}
		else if(s == "down") aim += aux;
		else if(s == "up") aim -= aux;
	}
	cout << x*y << endl;
}