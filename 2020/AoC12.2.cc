#include <iostream>
#include <iostream>
using namespace std;

enum card{
	N,E,S,W
};

struct pos{
	int x;
	int y;
	pos() {x = 0; y = 0;}
	friend ostream& operator<< (ostream& os, const pos& p) {
		return os << "(" << p.x << "," << p.y << ")";
	}
	pos(int a, int b) {x = a; y = b;} 
	void move(card c, int n) {
		if(c == N) this->y += n;
		else if(c == E) x += n;
		else if(c == S) y -= n;
		else if(c == W) x -= n;
	}
	void move_rel(const pos& p, int n) {
		x += n*p.x;
		y += n*p.y;
	}
	void rotate(int d) {
		int aux = x;
		if(d == 90) {
			x = y;
			y = -aux;
		}
		else if(d == 180) {
			x = -x;
			y = -y;
		}
		else if(d == 270) {
			x = -y;
			y = aux;
		}
	}
};

struct dir {
	card c;
	dir() {c = E;}
	dir(const dir& d) {c = d.c;}
	dir(char chr) {
		if(chr == 'N') c = N;
		else if(chr == 'E') c = E;
		else if(chr == 'S') c = S;
		else if(chr == 'W') c = W;
	}
	
	dir operator+ (int d) const {
		dir aux = dir(*this);
		aux.c = static_cast<card>((aux.c+(d/90)) % 4);
		return aux;
	}
	dir& operator+= (int d) {
		c = static_cast<card>((c+(d/90)) % 4);
		return *this;
	}
	dir& operator-= (int d) { return *this += 360-d;}

	friend ostream& operator<< (ostream& os, const dir& d) {
		switch(d.c) {
			case N: os << "North"; break;
			case E: os << "East"; break;
			case S: os << "South"; break;
			case W: os << "West"; break;
		}
		return os;
	}
};

int main() {
	pos ship = pos(), waypoint = pos(10,1);
	char c; int n;
	while(cin >> c >> n) {
		cout << ship << " "<< waypoint << endl;
		dir aux = dir(c);
		if(c == 'R') waypoint.rotate(n);
		else if(c == 'L') waypoint.rotate(360-n);
		else if(c == 'F') ship.move_rel(waypoint,n);
		else waypoint.move(aux.c,n);
	}
	cout << ship << " " << waypoint << endl; 
	cout << abs(ship.x) + abs(ship.y) << endl;
}






