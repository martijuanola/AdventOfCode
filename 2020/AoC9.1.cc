#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int find(const vector<ll>& v, ll x, int l, int r) {
	if(r <= l and v[r] >= x) return r;
	else if(r <= l) return v.size();

	int mid = l + (r-l)/2;
	if(v[mid] == x) return mid;
	else if(v[mid] < x) return find(v,x,mid+1,r);
	else return find(v,x,l,mid);
}

bool correct(vector<ll> v, ll x) {
	sort(v.begin(),v.end());
	int pos1 = find(v,1+ x/2,0,v.size()-1);
	int pos2 = find(v,x,0,v.size()-1);
	for(int i = 0; i < v.size(); i++) {
		if(i == pos1 or i == pos2) cout << "| " << v[i] << " ";
		else cout << v[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < pos1; i++) {
		int sol = find(v,x-v[i],i,pos2-1);
		if(sol != v.size() and v[i]+v[sol] == x) {
			cout << "solution -> " << v[i] << " + " << v[sol] << " = "  << x << endl << endl;
			return true;
		}
	}

	return false;
}

int main() {
	int pre = 25, x, c = 0, ptr = 0;
	vector<ll> all;
	vector<ll> v(pre);
	for(int i = 0; i < pre; i++) cin >> v[i];
	all = v;
	while(cin >> x) {
		all.push_back(x);
		cout << x << " -- ";
		if(not correct(v,x)) {
			cout << "END -> "<< c << " " << x << endl;
			break;
		}
		v[ptr] = x;
		ptr = (ptr+1) % pre;
		c++;
	}

	int ptr1 = 0, ptr2 = 0;
	ll sum = all[ptr1];
	while(sum != x) {
		if(sum < x) {
			ptr2 += 1;
			sum += all[ptr2];
		}
		else if(sum > x) {
			sum -= all[ptr1];
			ptr1 += 1;
		}
	}
	int min = all[ptr1], max = all[ptr1];
	for(int i = ptr1; i < ptr2+1; i++) {
		cout << all[i] << " ";
		if(min < all[i]) min = all[i];
		else if(max > all[i]) max = all[i];
	}
	cout << endl;
	cout << min << " " << max << " "  << min + max << endl;
}











