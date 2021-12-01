#include <iostream>
#include <vector>
#include <string>
using namespace std;

int process_group(const vector<string>& group) {
	int r = 0;
	vector<int> abc(26,0);

	for(int i = 0; i < group.size(); i++) {
		for(int j = 0; j < group[i].size(); j++) {
			abc[group[i][j]-'a']++;
		}
	}

	for(int i = 0; i < abc.size(); i++) if(abc[i] == group.size()) r++;
	return r;
}

int main() {
	long long total = 0;
	string aux;
	vector<string> group;
	while(getline(cin,aux)) {
		if(aux == "") {
			total += process_group(group);
			group.clear();
		}
		else group.push_back(aux);
	}
	total += process_group(group);
	cout << total << endl;
}