#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int n;
	while(cin >> n) v.push_back(n);

	bool cont = true;
	for(int i = 0; i < v.size() and cont; i++) {
		for(int j = i+1; j < v.size() and cont; j++) {
			if(v[i]+v[j] == 2020) {
				cout << v[i] << " " << v[j] << " " << v[i]+v[j] << " " << v[i]*v[j] << endl;
				cont = 0;
			}
		}
	}
}