#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int n = 12;

int main() {
	vector<int> zeros(n,0);
	int count = 0;
	string s;
	while(cin >> s) {
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') zeros[i]++;
		}
		count++;
	}
	
	int gamma = 0, epsilon = 0;
	int val = 1;

	for(int i = n-1; i >= 0; i--) {
		if(zeros[i] < ceil(count/2)) gamma += val;
		else epsilon += val;
		val *= 2;
	}

	cout << gamma << " " << epsilon << " " << gamma+epsilon << " " << gamma*epsilon << endl;
}