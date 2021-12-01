#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack_rec(const vector<int>& v, int pos, int e, int& r) {
	if(pos == e) {
		r++;
		return;
	}

	int dif = v[pos+1]-v[pos];
	if(dif > 0 and dif < 4) backtrack_rec(v,pos+1,e,r);
	dif = v[pos+2]-v[pos];
	if(dif > 0 and dif < 4) backtrack_rec(v,pos+2,e,r);
	dif = v[pos+3]-v[pos];
	if(dif > 0 and dif < 4) backtrack_rec(v,pos+3,e,r);
}

int backtrack(const vector<int>& v, int s, int e) {
	int r = 0;
	backtrack_rec(v,s,e,r);
	return r;
}


int main() {
	int x;
	vector<int> v(1,0);
	while(cin >> x) v.push_back(x);
	sort(v.begin(),v.end());
	v.push_back(v[v.size()-1]+3);
	
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

	long long int r = 1;

	vector<bool> ip(v.size(),false);
	ip[0] = ip[ip.size()-1] = true;
	for(int i = 0; i < v.size()-1; i++) {
		if(v[i+1]-v[i] == 3) {
			ip[i] = ip[i+1] = true;
		}
	}
	int pos = 0;
	for(int i = 1; i < ip.size(); i++) {
		if(ip[i]) {
			if(i-pos > 1) r *= backtrack(v,pos,i);
			pos = i;
		}
	}

	cout << r << endl;
}