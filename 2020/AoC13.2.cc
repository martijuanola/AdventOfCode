#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

void print_stuff(const vector<pair<long long int, int> >& v, const vector<long long int>& vit, const vector<long long int>& vstep) {
	cout << "v\t\t";
	for(int j = 0; j < v.size(); j++) cout << "(" << v[j].first << "," << v[j].second << ")\t\t";
	cout << endl << "vit\t\t";
	for(int j = 0; j < v.size(); j++) cout << vit[j] << "\t\t";
	cout << endl << "vit*v.first\t";
	for(int j = 0; j < v.size(); j++) cout << vit[j]*v[j].first << "\t\t";
	cout << endl << "vstep\t\t";
	for(int j = 0; j < v.size(); j++) cout << vstep[j] << "\t\t";
	cout << endl << endl;
}

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.first > b.first;
}

int main() {
	int n, it = 0;
	string s;
	vector<pair<long long int, int> > v;
	long long int r = 1;

	cin >> n;
	while(getline(cin,s,',')) {
		if(s != "x") {
			v.push_back(make_pair(stoi(s),it));
		}
		it++;
	}
	int sol = v[0].first;
	sort(v.begin(),v.end(),comp);
	for(int i = v.size()-1; i >= 0; i--) v[i].second -= v[0].second;
	vector<long long int> vit(v.size(),1);
	vector<long long int> vstep(v.size(),1);

	long long int dif;
	for(int i = 1; i < v.size(); i++) {
		//print_stuff(v,vit,vstep);
//es troba el primer cas igual
		dif = v[i].first*vit[i]-v[0].first*vit[0];
		while(dif != v[i].second) {
			if(vit[i]*v[i].first > vit[0]*v[0].first + v[i].second) for(int j = 0; j < i; j++) vit[j] += vstep[j];
			else vit[i] = ceil(double(vit[0]*v[0].first+v[i].second)/v[i].first);
			dif = v[i].first*vit[i]-v[0].first*vit[0];
		}
//es guarda al vector
		vector<long long int> vit_aux = vit;
//s'abança una mica a tots
		for(int j = 0; j <= i; j++) vit[j] += vstep[j];
//es torna a buscar
		dif = v[i].first*vit[i]-v[0].first*vit[0];
		while(dif != v[i].second) {
			if(vit[i]*v[i].first > vit[0]*v[0].first + v[i].second) for(int j = 0; j < i; j++) vit[j] += vstep[j];
			else vit[i] = ceil(double(vit[0]*v[0].first+v[i].second)/v[i].first);
			dif = v[i].first*vit[i]-v[0].first*vit[0];
		}
//es guarda l'step
		for(int j = 0; j <= i; j++) vstep[j] = vit[j]-vit_aux[j];
//es recupera l'estat auxiliar
		vit = vit_aux;
	}

	//print_stuff(v,vit,vstep);

	for(int i = 0; i < v.size(); i++) {
		if(v[i].first == sol) {
			cout << vit[i]*v[i].first << endl;
			break;
		}
	}
}

//for(int i = 0; i < v.size(); i++) cout << "(" << v[i].first << "," << v[i].second << ") ";
	//cout << endl;