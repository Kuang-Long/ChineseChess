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
//�N:  1
//��: -1
//�K:  2
//�h: -2
//�H:  3
//��: -3
//��:+-4
//��:+-5
//��:+-6
//�L:  7
//��: -7