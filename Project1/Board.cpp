#pragma once
#include "Board.h"
Board::Board() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			map[i][j].name = "";
			map[i][j].type = 0;
		}
	}
	/// <summary>
	/// 紅方 (-1)
	/// </summary>
	map[0][0].name = "車"; map[0][0].type = -4;
	map[0][8].name = "車"; map[0][8].type = -4;
	map[0][1].name = "傌"; map[0][1].type = -5;
	map[0][7].name = "傌"; map[0][7].type = -5;
	map[0][2].name = "相"; map[0][2].type = -3;
	map[0][6].name = "相"; map[0][6].type = -3;
	map[0][3].name = "仕"; map[0][3].type = -2;
	map[0][5].name = "仕"; map[0][5].type = -2;
	map[0][4].name = "帥"; map[0][4].type = -1;
	map[2][1].name = "炮"; map[2][1].type = -6;
	map[2][7].name = "炮"; map[2][7].type = -6;
	map[3][0].name = "兵"; map[3][0].type = -7;
	map[3][2].name = "兵"; map[3][2].type = -7;
	map[3][4].name = "兵"; map[3][4].type = -7;
	map[3][6].name = "兵"; map[3][6].type = -7;
	map[3][8].name = "兵"; map[3][8].type = -7;
	/// <summary>
	/// 藍方 (+1)
	/// </summary>
	map[9][0].name = "車"; map[9][0].type = 4;
	map[9][8].name = "車"; map[9][8].type = 4;
	map[9][1].name = "馬"; map[9][1].type = 5;
	map[9][7].name = "馬"; map[9][7].type = 5;
	map[9][2].name = "象"; map[9][2].type = 3;
	map[9][6].name = "象"; map[9][6].type = 3;
	map[9][3].name = "士"; map[9][3].type = 2;
	map[9][5].name = "士"; map[9][5].type = 2;
	map[9][4].name = "將"; map[9][4].type = 1;
	map[7][1].name = "砲"; map[7][1].type = 6;
	map[7][7].name = "砲"; map[7][7].type = 6;
	map[6][0].name = "卒"; map[6][0].type = 7;
	map[6][2].name = "卒"; map[6][2].type = 7;
	map[6][4].name = "卒"; map[6][4].type = 7;
	map[6][6].name = "卒"; map[6][6].type = 7;
	map[6][8].name = "卒"; map[6][8].type = 7;
}
void Board::clear(){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			map[i][j].name = "";
			map[i][j].type = 0;
		}
	}
	/// <summary>
	/// 紅方 (-1)
	/// </summary>
	map[0][0].name = "車"; map[0][0].type = -4;
	map[0][8].name = "車"; map[0][8].type = -4;
	map[0][1].name = "傌"; map[0][1].type = -5;
	map[0][7].name = "傌"; map[0][7].type = -5;
	map[0][2].name = "相"; map[0][2].type = -3;
	map[0][6].name = "相"; map[0][6].type = -3;
	map[0][3].name = "仕"; map[0][3].type = -2;
	map[0][5].name = "仕"; map[0][5].type = -2;
	map[0][4].name = "帥"; map[0][4].type = -1;
	map[2][1].name = "炮"; map[2][1].type = -6;
	map[2][7].name = "炮"; map[2][7].type = -6;
	map[3][0].name = "兵"; map[3][0].type = -7;
	map[3][2].name = "兵"; map[3][2].type = -7;
	map[3][4].name = "兵"; map[3][4].type = -7;
	map[3][6].name = "兵"; map[3][6].type = -7;
	map[3][8].name = "兵"; map[3][8].type = -7;
	/// <summary>
	/// 藍方 (+1)
	/// </summary>
	map[9][0].name = "車"; map[9][0].type = 4;
	map[9][8].name = "車"; map[9][8].type = 4;
	map[9][1].name = "馬"; map[9][1].type = 5;
	map[9][7].name = "馬"; map[9][7].type = 5;
	map[9][2].name = "象"; map[9][2].type = 3;
	map[9][6].name = "象"; map[9][6].type = 3;
	map[9][3].name = "士"; map[9][3].type = 2;
	map[9][5].name = "士"; map[9][5].type = 2;
	map[9][4].name = "將"; map[9][4].type = 1;
	map[7][1].name = "砲"; map[7][1].type = 6;
	map[7][7].name = "砲"; map[7][7].type = 6;
	map[6][0].name = "卒"; map[6][0].type = 7;
	map[6][2].name = "卒"; map[6][2].type = 7;
	map[6][4].name = "卒"; map[6][4].type = 7;
	map[6][6].name = "卒"; map[6][6].type = 7;
	map[6][8].name = "卒"; map[6][8].type = 7;
}
int Board::check() {
	bool a = 0;
	bool b = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < 6; j++) {
			if (map[i][j].type == -1) {
				a = 1;
				break;
			}
		}
	}
	for (int i = 7; i < 10; i++) {
		for (int j = 3; j < 6; j++) {
			if (map[i][j].type == 1) {
				b = 1;
				break;
			}
		}
	}
	if (a == 0) {
		return 2;
	}
	else if (b == 0) {
		return 1;
	}
	return 0;
}