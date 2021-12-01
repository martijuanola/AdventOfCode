#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
int main() {
	int max = -1, my_seat;
	string aux;
	vector<bool> seats(128*8,false);
	while(cin >> aux) {
		int current = 0;
		for(int i = 0; i < 7; i++) {
			if(aux[i] == 'B') current += pow(2,6-i);
		}
		current *= 8;
		for(int i = 0; i < 3; i++) {
			if(aux[7+i] == 'R') current += pow(2,2-i);
		}
		if(current > max) max = current;
		seats[current] = true;
	}
	int i = 0;
	while(not seats[i]) i++;
	while(seats[i]) i++;

	cout << seats[i] << " " << i << endl; 

	cout << max << endl;
}