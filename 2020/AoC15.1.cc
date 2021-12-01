#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
	map<int,pair<int,int> > m;
	map<int,int> count;
	count[0] = 0;
	char c;
	int last, pos = 1;
	while(cin >> last) {
		//cout << pos << " -> " << last << endl;
		m[last] = make_pair(pos,-1); 
		count[last] = 1;
		pos++;
		cin >> c;
	}
	while(pos <= 30000000) {
		if(pos % 1000000 == 0) cout << pos << endl;
		if(count[last] > 1) {
			last = m[last].second - m[last].first;
			//cout << pos << " -> " << last << endl;
			
			if(count.find(last) == count.end()) {
				m[last] = make_pair(pos,-1);
				count[last] = 1;
			}
			else {
				if(count[last] > 1) m[last].first = m[last].second;
				m[last].second = pos;
				count[last]++;
			}
		}
		else {
			if(count[0] > 1) m[0].first = m[0].second;
			if(count[0] == 0) m[0].first = pos;
			else m[0].second = pos;
			count[0]++;
			last = 0;
			//cout << pos << " -> " << 0 << endl;
		}
		pos++;
	}
	cout << last << endl;
}