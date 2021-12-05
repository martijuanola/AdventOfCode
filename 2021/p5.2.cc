#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
using namespace std;

int n = 1000;

void print(const vector<vector<int> >& v) {
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void read(vector<vector<int> >& map) {
	int x1,y1,x2,y2;
	string s1;
	char c1,c2;
	while(cin >> x1 >> c1 >> y1 >> s1 >> x2 >> c2 >> y2) {
		if(x1 == x2) {
			if(y1 > y2) swap(y1,y2);
			for(int i = y1; i <= y2; i++) map[i][x1]++;
		}
		else if(y1 == y2) {
			if(x1 > x2) swap(x1,x2);
			for(int i = x1; i <= x2; i++) map[y1][i]++;
		}
		else if((x1 < x2 and y1 < y2) or (x1 > x2 and y1 > y2)) {
			if(x1 > x2 and y1 > y2) {
				swap(x1,x2);
				swap(y1,y2);
			}
			for(int i = x1; i <= x2; i++) map[y1+(i-x1)][i]++;
		}
		else if((x1 < x2 and y1 > y2) or (x1 > x2 and y1 < y2)) {
			if(x1 > x2 and y1 < y2) {
				swap(x1,x2);
				swap(y1,y2);
			}
			for(int i = x1; i <= x2; i++) map[y1-(i-x1)][i]++;
		}
	}
}

long long result(const vector<vector<int> >& map) {
	long long count = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) if(map[i][j] > 1) count++;
	}
	return count;
}

int main() {

	vector<vector<int> > map(n,vector<int>(n,0));

	read(map);

	//print(map);

	cout << result(map) << endl;

}