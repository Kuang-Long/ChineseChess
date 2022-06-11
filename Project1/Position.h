#pragma once
class P {
public:
	int x;
	int y;
	P() {
		x = 0;
		y = 0;
	}
	P(int a, int b) {
		x = a;
		y = b;
	}
	P& operator=(const P& a) {
		x = a.x;
		y = a.y;
		return *this;
	}
	bool operator==(const P& a) {
		return (x == a.x && y == a.y) ? 1 : 0;
	}
};