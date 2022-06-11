#pragma once
#include <iostream>
typedef struct {
	int type;
	std::string name;
} pair;

class Board {
public:
	pair map[10][9];
	Board();
	void clear();
	int check();
};

static Board Map;
//將:  1
//帥: -1
//仕:  2
//士: -2
//象:  3
//相: -3
//車:+-4
//馬:+-5
//炮:+-6
//兵:  7
//卒: -7