#pragma once
#include "Board.h"
#include "Position.h"
#include <math.h>

class Piece {
private:
	int Id;
	P pos;
public:
	Piece(int x) {
		Id = x;
	}
	int getId() {
		return Id;
	}
	P getPos() {
		return pos;
	}
};

class King :public Piece {
public:
	King(int a) :Piece(a){}
	bool canMove(int startx, int starty, int endx, int endy) {
		if (getId() == -1) {
			int i;
			for (i = 7; i < 10; i++) {
				if (Map.map[i][endy].type == 1) {
					break;
				}
			}
			if (i < 10) {
				int j;
				for (j = endx + 1; j < i; j++) {
					if (Map.map[j][endy].type != 0) {
						break;
					}
				}
				if (j == i) {
					return 0;
				}
			}
		}
		if (getId() == 1) {
			int i;
			for (i = 0; i < 3; i++) {
				if (Map.map[i][endy].type == -1) {
					break;
				}
			}
			if (i < 3) {
				int j;
				for (j = endx - 1; j > i; j--) {
					if (Map.map[j][endy].type != 0) {
						break;
					}
				}
				if (j == i) {
					return 0;
				}
			}
		}
		if (pow(startx - endx, 2) + pow(starty - endy, 2) == 1 &&
			Map.map[startx][starty].type * Map.map[endx][endy].type <= 0 &&
			((endx >= 0 && endx <= 2 && endy >= 3 && endy <= 5) || (endx >= 7 && endx <= 9 && endy >= 3 && endy <= 5))) {
			return 1;
		}
		return 0;
	}
};

class Guard :public Piece {
public:
	Guard(int a) :Piece(a) {}
	bool canMove(int startx, int starty, int endx, int endy) {
		if (starty != endy) {
			bool rKingCheck = false;
			bool bKingCheck = false;
			bool otherPiece = false;
			int i, j;
			for (i = 0; i < 3; i++) {
				if (Map.map[i][starty].type == -1) {
					rKingCheck = true;
					break;
				}
			}
			for (j = 7; j < 10; j++) {
				if (Map.map[j][starty].type == 1) {
					bKingCheck = true;
					break;
				}
			}
			if (rKingCheck && bKingCheck && i < startx && j > startx) {
				for (int k = i + 1; k < startx; k++) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				for (int k = j - 1; k > startx; k--) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				if (!otherPiece) {
					return 0;
				}
			}
		}
		if (pow(startx - endx, 2) + pow(starty - endy, 2) == 2 &&
			Map.map[startx][starty].type * Map.map[endx][endy].type <= 0 &&
			((endx >= 0 && endx <= 2 && endy >= 3 && endy <= 5) || (endx >= 7 && endx <= 9 && endy >= 3 && endy <= 5))) {
			return 1;
		}
		return 0;
	}
};

class Minister :public Piece {
public:
	Minister(int a) :Piece(a) {};
	bool canMove(int startx, int starty, int endx, int endy) {
		if (starty != endy) {
			bool rKingCheck = false;
			bool bKingCheck = false;
			bool otherPiece = false;
			int i, j;
			for (i = 0; i < 3; i++) {
				if (Map.map[i][starty].type == -1) {
					rKingCheck = true;
					break;
				}
			}
			for (j = 7; j < 10; j++) {
				if (Map.map[j][starty].type == 1) {
					bKingCheck = true;
					break;
				}
			}
			if (rKingCheck && bKingCheck && i < startx && j > startx) {
				for (int k = i + 1; k < startx; k++) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				for (int k = j - 1; k > startx; k--) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				if (!otherPiece) {
					return 0;
				}
			}
		}
		if (pow(startx - endx, 2) + pow(starty - endy, 2) == 8 &&
			Map.map[startx][starty].type * Map.map[endx][endy].type <= 0) {
			if (Map.map[startx][starty].type > 0) {
				if (endx >= 5 && endx <= 9 && Map.map[(startx + endx) / 2][(starty + endy) / 2].type == 0) {
					return 1;
				}
			}
			else if (Map.map[startx][starty].type < 0) {
				if (endx >= 0 && endx <= 4 && Map.map[(startx + endx) / 2][(starty + endy) / 2].type == 0) {
					return 1;
				}
			}
		}
		return 0;
	}
};

class Horses :public Piece {
public:
	Horses(int a) :Piece(a) {};
	bool canMove(int startx, int starty, int endx, int endy) {
		if (starty != endy) {
			bool rKingCheck = false;
			bool bKingCheck = false;
			bool otherPiece = false;
			int i, j;
			for (i = 0; i < 3; i++) {
				if (Map.map[i][starty].type == -1) {
					rKingCheck = true;
					break;
				}
			}
			for (j = 7; j < 10; j++) {
				if (Map.map[j][starty].type == 1) {
					bKingCheck = true;
					break;
				}
			}
			if (rKingCheck && bKingCheck && i < startx && j > startx) {
				for (int k = i + 1; k < startx; k++) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				for (int k = j - 1; k > startx; k--) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				if (!otherPiece) {
					return 0;
				}
			}
		}
		if (pow(startx - endx, 2) + pow(starty - endy, 2) == 5 &&
			Map.map[startx][starty].type * Map.map[endx][endy].type <= 0) {
			if (fabs(startx - endx) == 2) {
				int sign = (startx - endx > 0 ? -1 : 1);
				if (Map.map[startx + sign][starty].type == 0) {
					return 1;
				}
			}
			if (fabs(starty - endy) == 2) {
				int sign = (starty - endy > 0 ? -1 : 1);
				if (Map.map[startx][starty + sign].type == 0) {
					return 1;
				}
			}
		}
		return 0;
	}
};

class Chariots :public Piece {
public:
	Chariots(int a) :Piece(a) {}
	bool canMove(int startx, int starty, int endx, int endy) {
		if (starty != endy) {
			bool rKingCheck = false;
			bool bKingCheck = false;
			bool otherPiece = false;
			int i, j;
			for (i = 0; i < 3; i++) {
				if (Map.map[i][starty].type == -1) {
					rKingCheck = true;
					break;
				}
			}
			for (j = 7; j < 10; j++) {
				if (Map.map[j][starty].type == 1) {
					bKingCheck = true;
					break;
				}
			}
			if (rKingCheck && bKingCheck && i < startx && j > startx) {
				for (int k = i + 1; k < startx; k++) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				for (int k = j - 1; k > startx; k--) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				if (!otherPiece) {
					return 0;
				}
			}
		}
		int tmpx = startx - endx;
		int tmpy = starty - endy;
		if (Map.map[startx][starty].type * Map.map[endx][endy].type <= 0 &&
			(!(tmpx && tmpy)) && (tmpx + tmpy)) {
			if (tmpx != 0) {
				int sign = (tmpx > 0 ? -1 : 1);
				for (int i = 1; i < fabs(tmpx); i++) {
					if (Map.map[startx + sign * i][starty].type) {
						return 0;
					}
				}
			}
			else {
				int sign = (tmpy > 0 ? -1 : 1);
				for (int i = 1; i < fabs(tmpy); i++) {
					if (Map.map[startx][starty + sign * i].type) {
						return 0;
					}
				}
			}
			return 1;
		}
		return 0;
	}
};

class Cannons :public Piece {
public:
	Cannons(int a) :Piece(a) {}
	bool canMove(int startx, int starty, int endx, int endy) {
		if (starty != endy) {
			bool rKingCheck = false;
			bool bKingCheck = false;
			bool otherPiece = false;
			int i, j;
			for (i = 0; i < 3; i++) {
				if (Map.map[i][starty].type == -1) {
					rKingCheck = true;
					break;
				}
			}
			for (j = 7; j < 10; j++) {
				if (Map.map[j][starty].type == 1) {
					bKingCheck = true;
					break;
				}
			}
			if (rKingCheck && bKingCheck && i < startx && j > startx) {
				for (int k = i + 1; k < startx; k++) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				for (int k = j - 1; k > startx; k--) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				if (!otherPiece) {
					return 0;
				}
			}
		}
		if (Map.map[startx][starty].type * Map.map[endx][endy].type <= 0 &&
			(!((startx - endx) && (starty - endy))) && ((startx - endx) + (starty - endy))) {
			int gapCheck = 0;
			if (startx - endx != 0) {
				int sign = (startx - endx > 0 ? -1 : 1);
				for (int i = 1; i < fabs(startx - endx); i++) {
					if (Map.map[startx + sign * i][starty].type) {
						gapCheck++;
					}
				}
			}
			else {
				int sign = (starty - endy > 0 ? -1 : 1);
				for (int i = 1; i < fabs(starty - endy); i++) {
					if (Map.map[startx][starty + sign * i].type) {
						gapCheck++;
					}
				}
			}
			if (Map.map[endx][endy].type != 0) {
				if (gapCheck == 1) {
					return 1;
				}
			}
			else {
				if (gapCheck == 0) {
					return 1;
				}
			}
		}
		return 0;
	}
};

class Soldiers :public Piece {
public:
	Soldiers(int a) :Piece(a) {}
	bool canMove(int startx, int starty, int endx, int endy) {
		if (starty != endy) {
			bool rKingCheck = false;
			bool bKingCheck = false;
			bool otherPiece = false;
			int i, j;
			for (i = 0; i < 3; i++) {
				if (Map.map[i][starty].type == -1) {
					rKingCheck = true;
					break;
				}
			}
			for (j = 7; j < 10; j++) {
				if (Map.map[j][starty].type == 1) {
					bKingCheck = true;
					break;
				}
			}
			if (rKingCheck && bKingCheck && i < startx && j > startx) {
				for (int k = i + 1; k < startx; k++) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				for (int k = j - 1; k > startx; k--) {
					if (Map.map[k][starty].type != 0) {
						otherPiece = true;
					}
				}
				if (!otherPiece) {
					return 0;
				}
			}
		}
		if (Map.map[startx][starty].type == 7) {
			if (startx >= 5 && startx <= 9) {
				if (Map.map[startx][starty].type * Map.map[endx][endy].type <= 0 &&
					starty - endy == 0 && startx - endx == 1) {
					return 1;
				}
			}
			else {
				if (Map.map[startx][starty].type * Map.map[endx][endy].type <= 0 &&
					pow(startx - endx, 2) + pow(starty - endy, 2) == 1 && startx - endx >= 0) {
					return 1;
				}
			}
		}
		if (Map.map[startx][starty].type == -7) {
			if (startx >= 5 && startx <= 9) {
				if (Map.map[startx][starty].type * Map.map[endx][endy].type <= 0 &&
					pow(startx - endx, 2) + pow(starty - endy, 2) == 1 && startx - endx <= 0) {
					return 1;
				}
			}
			else {
				if (Map.map[startx][starty].type * Map.map[endx][endy].type <= 0 &&
					starty - endy == 0 && startx - endx == -1) {
					return 1;
				}
			}
		}
		return 0;
	}
};