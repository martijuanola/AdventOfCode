#include <iostream>
#include <sstream> 
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

void write_matrix(const vector<vector<pair<int,int> > >& m, const map<int, string>& its, const map<int, int>& itv) {
	for(int i = 0; i < m.size(); i++) {
		cout << i << " -> ";
		for(int j = 0; j < m[i].size(); j++) cout << its.find(m[i][j].first)->second << ", ";
		cout << endl;
	}
	cout << endl << endl;
}

int stoi_mine(const string& a) {
	stringstream aux(a);
	int r;
	aux >> r;
	return r;
} 

int new_color(map<string,int>& sti, map<int, string>& its, int& mp, string posnew) {
	map<string,int>::iterator it;
	int r;
	if((it = sti.find(posnew)) == sti.end()) {
		sti[posnew] = mp;
		its[mp] = posnew;
		r = mp;
		mp++;
	}
	else r = it->second;
	return r;
}

void new_rel(map<string,int>& sti, map<int,string>& its, int& mp, map<int, int>& itv, vector<vector<pair<int, int> > >& con, int n, string s) {
	map<int,int>::iterator it;

	int p1 = s.find(" "), p2 = s.find(" bag");
	int num = stoi_mine(s.substr(0,p1));
	string color = s.substr(p1+1,p2-p1-1);
	int col_num = new_color(sti,its,mp,color);

	
	it = itv.find(col_num);
	if(it == itv.end()) {
		vector<pair<int, int> > aux(1,make_pair(n,num));
		con.push_back(aux);
		itv[col_num] = con.size()-1;
	}
	else con[it->second].push_back(make_pair(n,num));
}

int contains(const vector<vector<pair<int, int> > >& con, map<int, int>& itv, int mp, int f) {
	map<int,int>::iterator it;
	int r = 0;
	vector<bool> seen(mp, false); // col numbers(sti)
	seen[f] = true;

	queue<int> q; // con positions(itv)
	if((it = itv.find(f)) != itv.end()) q.push(it->second);
	else return r;

	while(not q.empty()) {
		int c = q.front();
		for(int i = 0; i < con[c].size(); i++) {
			if(not seen[con[c][i].first]) {
				seen[con[c][i].first] = true;
				r++;
				if((it = itv.find(con[c][i].first)) != itv.end()) q.push(it->second);
			}
		}
		q.pop();
	}

	return r;	
}

int main() {
	map<string, int> sti;
	map<int, string> its;
	map<int, int> itv; // first the one owning the vector
	int mp = 0;
	vector<vector<pair<int, int> > > con; // bag that contains / number of
	string aux;
	while(getline(cin,aux)) {
		int q = aux.find("no other");
		if(q == -1) {
			int n, p = aux.find(" bags contain");
		
			n = new_color(sti,its,mp,aux.substr(0,p));
			aux = aux.substr(p+14,aux.size()-(p+14));

			p = aux.find(",");
			while(p != -1) {
				new_rel(sti, its, mp, itv, con, n, aux.substr(0,p));

				aux = aux.substr(p+2,aux.size()-(p+2));
				p = aux.find(",");
			}
			new_rel(sti, its, mp, itv, con, n, aux.substr(0,aux.size()-1));	
		}
	}
	write_matrix(con,its,itv);
	cout << contains(con,itv,mp,sti["shiny gold"]) << endl;
}







