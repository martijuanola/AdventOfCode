#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
using namespace std;

map<int,int> read_order() {
	map<int,int> aux;
	int pos, order = 0;
	string s;
	cin >> s;
	bool end = false;
	pos = s.find(",");
	while(not end) {
		if(pos == -1) {
			aux.insert(make_pair(stoi(s),order));
			end = true;
		}
		else {
 			aux.insert(make_pair(stoi(s.substr(0,pos)),order));
			s = s.substr(pos+1,s.size()-1);
		}
		pos = s.find(",");
		order++;
	}
	return aux;
}

void print(const vector<vector<int> >& v) {
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int result(map<int,int>& order,const vector<vector<int> >& info, int max, int m) {
	int sum = 0, val;

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			int cv = info[m*5+i][j];
			if(order[cv] == max) val = cv;
			else if(order[cv] > max) {
				sum += cv;
			}
		}
	}
	return sum * val;
}

int main() {
	map<int,int> order = read_order();

	vector<vector<int> > info;
	
	vector<int> rows;
	vector<int> cols;

	int aux, m=0;
	//c 0 - 5
	//r 0 - 5
	//m 0 - n
	while(cin >> aux) {
		for(int r = 0; r < 5; r++) {
			vector<int> new_row;
			for(int c = 0; c < 5; c++) {
				if(r+c != 0) cin >> aux;
				new_row.push_back(aux);

				if(c == 0) rows.push_back(order[aux]);
				else if(order[aux] > rows[m*5+r]) rows[m*5+r] = order[aux];

				if(r == 0) cols.push_back(order[aux]);
				else if(order[aux] > cols[m*5+c]) cols[m*5+c] = order[aux];
			}
			info.push_back(new_row);
		}
		m++;
	}

	/*for(int i = 0; i < rows.size(); i++) cout << rows[i] << endl;
	cout << endl;
	for(int i = 0; i < rows.size(); i++) cout << cols[i] << endl;*/

	vector<int> mins(info.size()/5,order.size()+1);

	//find mins
	for(int i = 0; i < rows.size(); i++) {
		if(rows[i] < mins[i/5]) mins[i/5] = rows[i];
		if(cols[i] < mins[i/5]) mins[i/5] = cols[i];
	}

	//find max
	int max = 0, max_pos;
	for(int i = 0; i < mins.size(); i++) {
		if(mins[i] > max) {
			max = mins[i];
			max_pos = i;
		}
	}

	cout << result(order, info, max, max_pos) << endl;
}