#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
using namespace std;

int t = 81;

void printV(const vector<int>& v) {
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

void printM(const vector<vector<int> >& v) {
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<int> read() {
	vector<int> aux;
	char c;
	int i;

	while(cin >> i) {
		aux.push_back(i);
		cin >> c;
	}

	return aux;
}

int main() {
	vector<int> v = read();
	vector<vector<int> > dp(9,vector<int>(t,0));

	for(int i = 0; i < 9; i++) dp[i][t-1] = 1;

	for(int j = t-2; j >= 0; j--) {
		for(int i = 0; i < 9; i++) {
			if(i == 0) dp[i][j] = dp[6][j+1] + dp[8][j+1];
			else dp[i][j] = dp[i-1][j+1];
		}
	}

	//printM(dp);

	int r = 0;
	for(int i = 0; i < v.size(); i++) r += dp[v[i]][0];
	cout << r << endl;
}