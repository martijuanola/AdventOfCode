#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > read_matrix() {
	vector<vector<char> > r;
	string aux;
	while(getline(cin,aux)) {
		vector<char> vaux;
		for(int i = 0; i < aux.size(); i++) {
			vaux.push_back(aux[i]);
		}
		r.push_back(vaux);
	}
	return r;
}

void write_matrix(const vector<vector<char> >& m) {
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[i].size(); j++) cout << m[i][j];
		cout << endl; 
	}
	cout << endl;
}

int occupied_seats(vector<vector<char> >& m) {
	int r = 0;
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[i].size(); j++) if(m[i][j] == '#') r++;
	}
	return r;
}

int adjacent(const vector<vector<char> >& m, int x, int y) {
	int r = 0;
	for(int i = -1; i < 2; i++) {
		for(int j = -1; j < 2; j++) {
			if((i != 0 or j != 0) and y+i >= 0 and y+i < m.size() and x+j >= 0 and x+j < m[y].size() and m[y+i][x+j] == '#') r++;
		}
	}
	return r;
}

bool inside(const vector<vector<char> >& m, int y, int x) {
	if(x >= 0 and x < m[y].size() and y >= 0 and y < m.size()) return true;
	else return false;
}

int first_adjacent(const vector<vector<char> >& m, int x, int y) {
	int r = 0;
	
	int limits = 0, i = 1;
	vector<bool> d(8,false); //top and clockwise
	while(limits < 8) {
		if(not d[0] and (not inside(m,y-i,x) or m[y-i][x] != '.')) {
			d[0] = true;
			limits++;
			if(inside(m,y-i,x) and m[y-i][x] == '#') r++;
		}
		if(not d[1] and (not inside(m,y-i,x+i) or m[y-i][x+i] != '.')) {
			d[1] = true;
			limits++;
			if(inside(m,y-i,x+i) and m[y-i][x+i] == '#') r++;
		}
		if(not d[2] and (not inside(m,y,x+i) or m[y][x+i] != '.')) {
			d[2] = true;
			limits++;
			if(inside(m,y,x+i) and m[y][x+i] == '#') r++;
		}
		if(not d[3] and (not inside(m,y+i,x+i) or m[y+i][x+i] != '.')) {
			d[3] = true;
			limits++;
			if(inside(m,y+i,x+i) and m[y+i][x+i] == '#') r++;
		}
		if(not d[4] and (not inside(m,y+i,x) or m[y+i][x] != '.')) {
			d[4] = true;
			limits++;
			if(inside(m,y+i,x) and m[y+i][x] == '#') r++;
		}
		if(not d[5] and (not inside(m,y+i,x-i) or m[y+i][x-i] != '.')) {
			d[5] = true;
			limits++;
			if(inside(m,y+i,x-i) and m[y+i][x-i] == '#') r++;
		}
		if(not d[6] and (not inside(m,y,x-i) or m[y][x-i] != '.')) {
			d[6] = true;
			limits++;
			if(inside(m,y,x-i) and m[y][x-i] == '#') r++;
		}
		if(not d[7] and (not inside(m,y-i,x-i) or m[y-i][x-i] != '.')) {
			d[7] = true;
			limits++;
			if(inside(m,y-i,x-i) and m[y-i][x-i] == '#') r++;
		}

		i++;
	}

	return r;
}

bool step(vector<vector<char> >& m) {
	vector<pair<int,int> > changes;
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[i].size(); j++) {
			int aux = first_adjacent(m,j,i);
			if((m[i][j] == 'L' and aux == 0) or (m[i][j] == '#' and aux >= 5)) changes.push_back(make_pair(i,j));
		}
	}
	for(int i = 0; i < changes.size(); i++) {
		if(m[changes[i].first][changes[i].second] == 'L') m[changes[i].first][changes[i].second] = '#';
		else m[changes[i].first][changes[i].second] = 'L';
	}
	if(changes.size() == 0) return false;
	else return true;
}

int main() {
	vector<vector<char> > m = read_matrix();
	write_matrix(m);
	while(step(m)) {
		//write_matrix(m);
	}
	cout << occupied_seats(m) << endl;
}



