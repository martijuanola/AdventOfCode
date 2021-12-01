#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

struct interval {
	int bl, tl;

	bool operator<(interval const &i2) const { 
		return bl < i2.bl;
	}
};

struct limit {
	string field;
	interval bi, ti;
};

bool fuse_intervals(set<interval>:: iterator it_i1, const interval& i2, bool& ignore) {
	if(it_i1->tl < i2.bl or it_i1->bl > i2.tl) return false;
	if(it_i1->bl <= i2.bl and it_i1->tl >= i2.tl) ignore = true;
	else {
		if(it_i1->bl > i2.bl) it_i1->bl = i2.bl;
		if(it_i1->tl < i2.tl) it_i1->tl = i2.tl;
	}
	return true;
}

void add_interval(set<interval>& big_interval, const interval& new_i) {
	set<interval>:: iterator it = big_interval.begin(), it_aux;
	bool fused = false, stop = false;

	while(it != big_interval.end()) {
		if(not fused) {
			fused = fuse_intervals(it,new_i,stop); // mirar com passar el contingut de l'iterador per referència
			it_aux = it;
		}
		else {
			//fuse with others
		}
		if(fused and stop) return;
		it++;
	}

	if(not fused) big_interval.insert(new_i);
}

int main() {
	string line, saux;
	vector<limit> limits;
	set<interval> big_interval;
	while(getline(cin,line) and line != "") {
		int pos = line.find(':');
		char c;
		limit aux;
		aux.field = line.substr(0,pos);
		line = line.substr(pos+2,line.size()-(pos+2));
		istringstream iss(line);
		iss >> aux.bi.bl >> c >> aux.bi.tl >> saux >> aux.ti.bl >> c >> aux.ti.tl;
		add_interval(big_interval, aux.bi);
		add_interval(big_interval, aux.ti);
		limits.push_back(aux);
	}
	while(getline(cin,line) and line != "nearby tickets:") {}


}