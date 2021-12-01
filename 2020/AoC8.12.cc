#include <iostream>
#include <vector>
using namespace std;

bool run(vector<pair<string,int> > inst, int& pc, int& acc, vector<int>& visited) {
	visited.clear();
	pc = 0, acc = 0;
	bool cont = true;
	while(pc < inst.size() and cont) {
		if(inst[pc].first == "jmp" or inst[pc].first == "nop") visited.push_back(pc);
		if(inst[pc].first == "") cont = false;
		else if(inst[pc].first == "jmp") {
			inst[pc].first = "";
			pc += inst[pc].second;
		}
		else {
			if(inst[pc].first == "acc") acc += inst[pc].second;
			inst[pc].first = "";
			pc++;
		}
	}
	return cont;
}

bool run2(vector<pair<string,int> > inst, int& pc, int& acc) {
	pc = 0, acc = 0;
	bool cont = true;
	while(pc < inst.size() and cont) {
		if(inst[pc].first == "") cont = false;
		else if(inst[pc].first == "jmp") {
			inst[pc].first = "";
			pc += inst[pc].second;
		}
		else {
			if(inst[pc].first == "acc") acc += inst[pc].second;
			inst[pc].first = "";
			pc++;
		}
	}
	return cont;
}

int main() {
	int pc = 0, acc = 0, aux;
	string saux;
	vector<pair<string,int> > inst;
	vector<int> visited;
	while(cin >> saux >> aux) {
		inst.push_back(make_pair(saux,aux));
	}
	if(run(inst,pc,acc,visited)) cout << acc << endl;
	
	int i = 0;
	while(not run2(inst,pc,acc)) {
		cout << i << endl;
		if(i != 0) {
			if(inst[visited[i-1]].first == "jmp") inst[visited[i-1]].first = "nop";
			else inst[visited[i-1]].first = "jmp";
		} 
		if(inst[visited[i]].first == "jmp") inst[visited[i]].first = "nop";
		else inst[visited[i]].first = "jmp";
		i++;
	}
	cout << acc << endl;
}



