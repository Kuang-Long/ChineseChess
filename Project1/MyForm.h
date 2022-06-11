#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

static bool startGame = 0;
static bool p1Win = 0;
static bool p2Win = 0;
static bool player = 0;
static P startL;
static P endL;
/// <summary>
/// 90個button的位置
/// </summary>
static P pos[10][9] =
{ 
	{P(40, 65),  P(106,65),  P(172, 65),   P(238, 65),  P(304, 65),  P(370,65),  P(436, 65),   P(502, 65),  P(568, 65) },
	{P(40, 131), P(106,131), P(172, 131),  P(238, 131), P(304, 131), P(370,131), P(436, 131),  P(502, 131), P(568, 131) },
	{P(40, 197), P(106,197), P(172, 197),  P(238, 197), P(304, 197), P(370,197), P(436, 197),  P(502, 197), P(568, 197) },
	{P(40, 263), P(106,263), P(172, 263),  P(238, 263), P(304, 263), P(370,263), P(436, 263),  P(502, 263), P(568, 263) },
	{P(40, 329), P(106,329), P(172, 329),  P(238, 329), P(304, 329), P(370,329), P(436, 329),  P(502, 329), P(568, 329) },
	{P(40, 395), P(106,395), P(172, 395),  P(238, 395), P(304, 395), P(370,395), P(436, 395),  P(502, 395), P(568, 395) },
	{P(40, 461), P(106,461), P(172, 461),  P(238, 461), P(304, 461), P(370,461), P(436, 461),  P(502, 461), P(568, 461) },
	{P(40, 527), P(106,527), P(172, 527),  P(238, 527), P(304, 527), P(370,527), P(436, 527),  P(502, 527), P(568, 527) },
	{P(40, 593), P(106,593), P(172, 593),  P(238, 593), P(304, 593), P(370,593), P(436, 593),  P(502, 593), P(568, 593) },
	{P(40, 659), P(106,659), P(172, 659),  P(238, 659), P(304, 659), P(370,659), P(436, 659),  P(502, 659), P(568, 659) } 
};



namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm(void) {
			InitializeComponent();
		}

		/// <summary>
		/// click的次數, 0為尚未click
		/// </summary>
		bool clickTimes;
		Color color;
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}
		array<Button^, 2>^ buttons;
		Button^ endGame;
		Button^ p1Surr;
		Button^ p2Surr;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void);
		
#pragma endregion
	private:
		System::Void endGame_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		System::Void p1Surr_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
			p2Win = 1;
		}
		System::Void p2Surr_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
			p1Win = 1;
		}
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 0;
				int t = 0;
				if (Map.map[0][0].type == 1 || Map.map[0][0].type == -1) {
					King k(Map.map[0][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][0].type == 2 || Map.map[0][0].type == -2) {
					Guard k(Map.map[0][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][0].type == 3 || Map.map[0][0].type == -3) {
					Minister k(Map.map[0][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][0].type == 5 || Map.map[0][0].type == -5) {
					Horses k(Map.map[0][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][0].type == 4 || Map.map[0][0].type == -4) {
					Chariots k(Map.map[0][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][0].type == 6 || Map.map[0][0].type == -6) {
					Cannons k(Map.map[0][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][0].type == 7 || Map.map[0][0].type == -7) {
					Soldiers k(Map.map[0][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[0, 0]->BackColor == color.Pink) {
					Map.map[0][0] = Map.map[startL.x][startL.y];
					buttons[0, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 0]->BackColor = color.White;
					if (Map.map[0][0].type < 0) {
						buttons[0, 0]->ForeColor = color.Red;
					}
					else {
						buttons[0, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 1;
				int t = 0;
				if (Map.map[0][1].type == 1 || Map.map[0][1].type == -1) {
					King k(Map.map[0][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][1].type == 2 || Map.map[0][1].type == -2) {
					Guard k(Map.map[0][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][1].type == 3 || Map.map[0][1].type == -3) {
					Minister k(Map.map[0][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][1].type == 5 || Map.map[0][1].type == -5) {
					Horses k(Map.map[0][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][1].type == 4 || Map.map[0][1].type == -4) {
					Chariots k(Map.map[0][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][1].type == 6 || Map.map[0][1].type == -6) {
					Cannons k(Map.map[0][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][1].type == 7 || Map.map[0][1].type == -7) {
					Soldiers k(Map.map[0][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 1;
				if (buttons[0, 1]->BackColor == color.Pink) {
					Map.map[0][1] = Map.map[startL.x][startL.y];
					buttons[0, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 1]->BackColor = color.White;
					if (Map.map[0][1].type < 0) {
						buttons[0, 1]->ForeColor = color.Red;
					}
					else {
						buttons[0, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 2;
				int t = 0;
				if (Map.map[0][2].type == 1 || Map.map[0][2].type == -1) {
					King k(Map.map[0][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][2].type == 2 || Map.map[0][2].type == -2) {
					Guard k(Map.map[0][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][2].type == 3 || Map.map[0][2].type == -3) {
					Minister k(Map.map[0][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][2].type == 5 || Map.map[0][2].type == -5) {
					Horses k(Map.map[0][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][2].type == 4 || Map.map[0][2].type == -4) {
					Chariots k(Map.map[0][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][2].type == 6 || Map.map[0][2].type == -6) {
					Cannons k(Map.map[0][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][2].type == 7 || Map.map[0][2].type == -7) {
					Soldiers k(Map.map[0][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[0, 2]->BackColor == color.Pink) {
					Map.map[0][2] = Map.map[startL.x][startL.y];
					buttons[0, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 2]->BackColor = color.White;
					if (Map.map[0][2].type < 0) {
						buttons[0, 2]->ForeColor = color.Red;
					}
					else {
						buttons[0, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 3;
				int t = 0;
				if (Map.map[0][3].type == 1 || Map.map[0][3].type == -1) {
					King k(Map.map[0][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][3].type == 2 || Map.map[0][3].type == -2) {
					Guard k(Map.map[0][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][3].type == 3 || Map.map[0][3].type == -3) {
					Minister k(Map.map[0][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][3].type == 5 || Map.map[0][3].type == -5) {
					Horses k(Map.map[0][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][3].type == 4 || Map.map[0][3].type == -4) {
					Chariots k(Map.map[0][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][3].type == 6 || Map.map[0][3].type == -6) {
					Cannons k(Map.map[0][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][3].type == 7 || Map.map[0][3].type == -7) {
					Soldiers k(Map.map[0][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[0, 3]->BackColor == color.Pink) {
					Map.map[0][3] = Map.map[startL.x][startL.y];
					buttons[0, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 3]->BackColor = color.White;
					if (Map.map[0][3].type < 0) {
						buttons[0, 3]->ForeColor = color.Red;
					}
					else {
						buttons[0, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 4;
				int t = 0;
				if (Map.map[0][4].type == 1 || Map.map[0][4].type == -1) {
					King k(Map.map[0][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][4].type == 2 || Map.map[0][4].type == -2) {
					Guard k(Map.map[0][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][4].type == 3 || Map.map[0][4].type == -3) {
					Minister k(Map.map[0][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][4].type == 5 || Map.map[0][4].type == -5) {
					Horses k(Map.map[0][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][4].type == 4 || Map.map[0][4].type == -4) {
					Chariots k(Map.map[0][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][4].type == 6 || Map.map[0][4].type == -6) {
					Cannons k(Map.map[0][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][4].type == 7 || Map.map[0][4].type == -7) {
					Soldiers k(Map.map[0][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[0, 4]->BackColor == color.Pink) {
					Map.map[0][4] = Map.map[startL.x][startL.y];
					buttons[0, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 4]->BackColor = color.White;
					if (Map.map[0][4].type < 0) {
						buttons[0, 4]->ForeColor = color.Red;
					}
					else {
						buttons[0, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 5;
				int t = 0;
				if (Map.map[0][5].type == 1 || Map.map[0][5].type == -1) {
					King k(Map.map[0][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][5].type == 2 || Map.map[0][5].type == -2) {
					Guard k(Map.map[0][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][5].type == 3 || Map.map[0][5].type == -3) {
					Minister k(Map.map[0][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][5].type == 5 || Map.map[0][5].type == -5) {
					Horses k(Map.map[0][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][5].type == 4 || Map.map[0][5].type == -4) {
					Chariots k(Map.map[0][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][5].type == 6 || Map.map[0][5].type == -6) {
					Cannons k(Map.map[0][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][5].type == 7 || Map.map[0][5].type == -7) {
					Soldiers k(Map.map[0][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[0, 5]->BackColor == color.Pink) {
					Map.map[0][5] = Map.map[startL.x][startL.y];
					buttons[0, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 5]->BackColor = color.White;
					if (Map.map[0][5].type < 0) {
						buttons[0, 5]->ForeColor = color.Red;
					}
					else {
						buttons[0, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 6;
				int t = 0;
				if (Map.map[0][6].type == 1 || Map.map[0][6].type == -1) {
					King k(Map.map[0][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][6].type == 2 || Map.map[0][6].type == -2) {
					Guard k(Map.map[0][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][6].type == 3 || Map.map[0][6].type == -3) {
					Minister k(Map.map[0][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][6].type == 5 || Map.map[0][6].type == -5) {
					Horses k(Map.map[0][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][6].type == 4 || Map.map[0][6].type == -4) {
					Chariots k(Map.map[0][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][6].type == 6 || Map.map[0][6].type == -6) {
					Cannons k(Map.map[0][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][6].type == 7 || Map.map[0][6].type == -7) {
					Soldiers k(Map.map[0][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[0, 6]->BackColor == color.Pink) {
					Map.map[0][6] = Map.map[startL.x][startL.y];
					buttons[0, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 6]->BackColor = color.White;
					if (Map.map[0][6].type < 0) {
						buttons[0, 6]->ForeColor = color.Red;
					}
					else {
						buttons[0, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 7;
				int t = 0;
				if (Map.map[0][7].type == 1 || Map.map[0][7].type == -1) {
					King k(Map.map[0][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][7].type == 2 || Map.map[0][7].type == -2) {
					Guard k(Map.map[0][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][7].type == 3 || Map.map[0][7].type == -3) {
					Minister k(Map.map[0][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][7].type == 5 || Map.map[0][7].type == -5) {
					Horses k(Map.map[0][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][7].type == 4 || Map.map[0][7].type == -4) {
					Chariots k(Map.map[0][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][7].type == 6 || Map.map[0][7].type == -6) {
					Cannons k(Map.map[0][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][7].type == 7 || Map.map[0][7].type == -7) {
					Soldiers k(Map.map[0][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[0, 7]->BackColor == color.Pink) {
					Map.map[0][7] = Map.map[startL.x][startL.y];
					buttons[0, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 7]->BackColor = color.White;
					if (Map.map[0][7].type < 0) {
						buttons[0, 7]->ForeColor = color.Red;
					}
					else {
						buttons[0, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 0;
				startL.y = 8;
				int t = 0;
				if (Map.map[0][8].type == 1 || Map.map[0][8].type == -1) {
					King k(Map.map[0][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][8].type == 2 || Map.map[0][8].type == -2) {
					Guard k(Map.map[0][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][8].type == 3 || Map.map[0][8].type == -3) {
					Minister k(Map.map[0][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][8].type == 5 || Map.map[0][8].type == -5) {
					Horses k(Map.map[0][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][8].type == 4 || Map.map[0][8].type == -4) {
					Chariots k(Map.map[0][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][8].type == 6 || Map.map[0][8].type == -6) {
					Cannons k(Map.map[0][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[0][8].type == 7 || Map.map[0][8].type == -7) {
					Soldiers k(Map.map[0][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(0, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[0, 8]->BackColor == color.Pink) {
					Map.map[0][8] = Map.map[startL.x][startL.y];
					buttons[0, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[0, 8]->BackColor = color.White;
					if (Map.map[0][8].type < 0) {
						buttons[0, 8]->ForeColor = color.Red;
					}
					else {
						buttons[0, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 0;
				int t = 0;
				if (Map.map[1][0].type == 1 || Map.map[1][0].type == -1) {
					King k(Map.map[1][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][0].type == 2 || Map.map[1][0].type == -2) {
					Guard k(Map.map[1][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][0].type == 3 || Map.map[1][0].type == -3) {
					Minister k(Map.map[1][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][0].type == 5 || Map.map[1][0].type == -5) {
					Horses k(Map.map[1][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][0].type == 4 || Map.map[1][0].type == -4) {
					Chariots k(Map.map[1][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][0].type == 6 || Map.map[1][0].type == -6) {
					Cannons k(Map.map[1][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][0].type == 7 || Map.map[1][0].type == -7) {
					Soldiers k(Map.map[1][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 0]->BackColor == color.Pink) {
					Map.map[1][0] = Map.map[startL.x][startL.y];
					buttons[1, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 0]->BackColor = color.White;
					if (Map.map[1][0].type < 0) {
						buttons[1, 0]->ForeColor = color.Red;
					}
					else {
						buttons[1, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 1;
				int t = 0;
				if (Map.map[1][1].type == 1 || Map.map[1][1].type == -1) {
					King k(Map.map[1][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][1].type == 2 || Map.map[1][1].type == -2) {
					Guard k(Map.map[1][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][1].type == 3 || Map.map[1][1].type == -3) {
					Minister k(Map.map[1][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][1].type == 5 || Map.map[1][1].type == -5) {
					Horses k(Map.map[1][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][1].type == 4 || Map.map[1][1].type == -4) {
					Chariots k(Map.map[1][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][1].type == 6 || Map.map[1][1].type == -6) {
					Cannons k(Map.map[1][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][1].type == 7 || Map.map[1][1].type == -7) {
					Soldiers k(Map.map[1][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 1]->BackColor == color.Pink) {
					Map.map[1][1] = Map.map[startL.x][startL.y];
					buttons[1, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 1]->BackColor = color.White;
					if (Map.map[1][1].type < 0) {
						buttons[1, 1]->ForeColor = color.Red;
					}
					else {
						buttons[1, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 2;
				int t = 0;
				if (Map.map[1][2].type == 1 || Map.map[1][2].type == -1) {
					King k(Map.map[1][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][2].type == 2 || Map.map[1][2].type == -2) {
					Guard k(Map.map[1][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][2].type == 3 || Map.map[1][2].type == -3) {
					Minister k(Map.map[1][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][2].type == 5 || Map.map[1][2].type == -5) {
					Horses k(Map.map[1][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][2].type == 4 || Map.map[1][2].type == -4) {
					Chariots k(Map.map[1][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][2].type == 6 || Map.map[1][2].type == -6) {
					Cannons k(Map.map[1][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][2].type == 7 || Map.map[1][2].type == -7) {
					Soldiers k(Map.map[1][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 2]->BackColor == color.Pink) {
					Map.map[1][2] = Map.map[startL.x][startL.y];
					buttons[1, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 2]->BackColor = color.White;
					if (Map.map[1][2].type < 0) {
						buttons[1, 2]->ForeColor = color.Red;
					}
					else {
						buttons[1, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 3;
				int t = 0;
				if (Map.map[1][3].type == 1 || Map.map[1][3].type == -1) {
					King k(Map.map[1][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][3].type == 2 || Map.map[1][3].type == -2) {
					Guard k(Map.map[1][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][3].type == 3 || Map.map[1][3].type == -3) {
					Minister k(Map.map[1][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][3].type == 5 || Map.map[1][3].type == -5) {
					Horses k(Map.map[1][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][3].type == 4 || Map.map[1][3].type == -4) {
					Chariots k(Map.map[1][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][3].type == 6 || Map.map[1][3].type == -6) {
					Cannons k(Map.map[1][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][3].type == 7 || Map.map[1][3].type == -7) {
					Soldiers k(Map.map[1][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 3]->BackColor == color.Pink) {
					Map.map[1][3] = Map.map[startL.x][startL.y];
					buttons[1, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 3]->BackColor = color.White;
					if (Map.map[1][3].type < 0) {
						buttons[1, 3]->ForeColor = color.Red;
					}
					else {
						buttons[1, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 4;
				int t = 0;
				if (Map.map[1][4].type == 1 || Map.map[1][4].type == -1) {
					King k(Map.map[1][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][4].type == 2 || Map.map[1][4].type == -2) {
					Guard k(Map.map[1][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][4].type == 3 || Map.map[1][4].type == -3) {
					Minister k(Map.map[1][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][4].type == 5 || Map.map[1][4].type == -5) {
					Horses k(Map.map[1][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][4].type == 4 || Map.map[1][4].type == -4) {
					Chariots k(Map.map[1][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][4].type == 6 || Map.map[1][4].type == -6) {
					Cannons k(Map.map[1][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][4].type == 7 || Map.map[1][4].type == -7) {
					Soldiers k(Map.map[1][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 4]->BackColor == color.Pink) {
					Map.map[1][4] = Map.map[startL.x][startL.y];
					buttons[1, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 4]->BackColor = color.White;
					if (Map.map[1][4].type < 0) {
						buttons[1, 4]->ForeColor = color.Red;
					}
					else {
						buttons[1, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink ) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 5;
				int t = 0;
				if (Map.map[1][5].type == 1 || Map.map[1][5].type == -1) {
					King k(Map.map[1][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][5].type == 2 || Map.map[1][5].type == -2) {
					Guard k(Map.map[1][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][5].type == 3 || Map.map[1][5].type == -3) {
					Minister k(Map.map[1][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][5].type == 5 || Map.map[1][5].type == -5) {
					Horses k(Map.map[1][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][5].type == 4 || Map.map[1][5].type == -4) {
					Chariots k(Map.map[1][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][5].type == 6 || Map.map[1][5].type == -6) {
					Cannons k(Map.map[1][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][5].type == 7 || Map.map[1][5].type == -7) {
					Soldiers k(Map.map[1][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 5]->BackColor == color.Pink) {
					Map.map[1][5] = Map.map[startL.x][startL.y];
					buttons[1, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 5]->BackColor = color.White;
					if (Map.map[1][5].type < 0) {
						buttons[1, 5]->ForeColor = color.Red;
					}
					else {
						buttons[1, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 6;
				int t = 0;
				if (Map.map[1][6].type == 1 || Map.map[1][6].type == -1) {
					King k(Map.map[1][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][6].type == 2 || Map.map[1][6].type == -2) {
					Guard k(Map.map[1][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][6].type == 3 || Map.map[1][6].type == -3) {
					Minister k(Map.map[1][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][6].type == 5 || Map.map[1][6].type == -5) {
					Horses k(Map.map[1][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][6].type == 4 || Map.map[1][6].type == -4) {
					Chariots k(Map.map[1][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][6].type == 6 || Map.map[1][6].type == -6) {
					Cannons k(Map.map[1][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][6].type == 7 || Map.map[1][6].type == -7) {
					Soldiers k(Map.map[1][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 6]->BackColor == color.Pink) {
					Map.map[1][6] = Map.map[startL.x][startL.y];
					buttons[1, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 6]->BackColor = color.White;
					if (Map.map[1][6].type < 0) {
						buttons[1, 6]->ForeColor = color.Red;
					}
					else {
						buttons[1, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 7;
				int t = 0;
				if (Map.map[1][7].type == 1 || Map.map[1][7].type == -1) {
					King k(Map.map[1][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][7].type == 2 || Map.map[1][7].type == -2) {
					Guard k(Map.map[1][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][7].type == 3 || Map.map[1][7].type == -3) {
					Minister k(Map.map[1][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][7].type == 5 || Map.map[1][7].type == -5) {
					Horses k(Map.map[1][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][7].type == 4 || Map.map[1][7].type == -4) {
					Chariots k(Map.map[1][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][7].type == 6 || Map.map[1][7].type == -6) {
					Cannons k(Map.map[1][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][7].type == 7 || Map.map[1][7].type == -7) {
					Soldiers k(Map.map[1][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 7]->BackColor == color.Pink) {
					Map.map[1][7] = Map.map[startL.x][startL.y];
					buttons[1, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 7]->BackColor = color.White;
					if (Map.map[1][7].type < 0) {
						buttons[1, 7]->ForeColor = color.Red;
					}
					else {
						buttons[1, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 1;
				startL.y = 8;
				int t = 0;
				if (Map.map[1][8].type == 1 || Map.map[1][8].type == -1) {
					King k(Map.map[1][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][8].type == 2 || Map.map[1][8].type == -2) {
					Guard k(Map.map[1][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][8].type == 3 || Map.map[1][8].type == -3) {
					Minister k(Map.map[1][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][8].type == 5 || Map.map[1][8].type == -5) {
					Horses k(Map.map[1][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][8].type == 4 || Map.map[1][8].type == -4) {
					Chariots k(Map.map[1][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][8].type == 6 || Map.map[1][8].type == -6) {
					Cannons k(Map.map[1][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[1][8].type == 7 || Map.map[1][8].type == -7) {
					Soldiers k(Map.map[1][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(1, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[1, 8]->BackColor == color.Pink) {
					Map.map[1][8] = Map.map[startL.x][startL.y];
					buttons[1, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[1, 8]->BackColor = color.White;
					if (Map.map[1][8].type < 0) {
						buttons[1, 8]->ForeColor = color.Red;
					}
					else {
						buttons[1, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 0;
				int t = 0;
				if (Map.map[2][0].type == 1 || Map.map[2][0].type == -1) {
					King k(Map.map[2][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][0].type == 2 || Map.map[2][0].type == -2) {
					Guard k(Map.map[2][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][0].type == 3 || Map.map[2][0].type == -3) {
					Minister k(Map.map[2][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][0].type == 5 || Map.map[2][0].type == -5) {
					Horses k(Map.map[2][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][0].type == 4 || Map.map[2][0].type == -4) {
					Chariots k(Map.map[2][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][0].type == 6 || Map.map[2][0].type == -6) {
					Cannons k(Map.map[2][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][0].type == 7 || Map.map[2][0].type == -7) {
					Soldiers k(Map.map[2][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 0]->BackColor == color.Pink) {
					Map.map[2][0] = Map.map[startL.x][startL.y];
					buttons[2, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 0]->BackColor = color.White;
					if (Map.map[2][0].type < 0) {
						buttons[2, 0]->ForeColor = color.Red;
					}
					else {
						buttons[2, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 1;
				int t = 0;
				if (Map.map[2][1].type == 1 || Map.map[2][1].type == -1) {
					King k(Map.map[2][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][1].type == 2 || Map.map[2][1].type == -2) {
					Guard k(Map.map[2][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][1].type == 3 || Map.map[2][1].type == -3) {
					Minister k(Map.map[2][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][1].type == 5 || Map.map[2][1].type == -5) {
					Horses k(Map.map[2][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][1].type == 4 || Map.map[2][1].type == -4) {
					Chariots k(Map.map[2][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][1].type == 6 || Map.map[2][1].type == -6) {
					Cannons k(Map.map[2][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][1].type == 7 || Map.map[2][1].type == -7) {
					Soldiers k(Map.map[2][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 1]->BackColor == color.Pink) {
					Map.map[2][1] = Map.map[startL.x][startL.y];
					buttons[2, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 1]->BackColor = color.White;
					if (Map.map[2][1].type < 0) {
						buttons[2, 1]->ForeColor = color.Red;
					}
					else {
						buttons[2, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 2;
				int t = 0;
				if (Map.map[2][2].type == 1 || Map.map[2][2].type == -1) {
					King k(Map.map[2][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][2].type == 2 || Map.map[2][2].type == -2) {
					Guard k(Map.map[2][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][2].type == 3 || Map.map[2][2].type == -3) {
					Minister k(Map.map[2][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][2].type == 5 || Map.map[2][2].type == -5) {
					Horses k(Map.map[2][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][2].type == 4 || Map.map[2][2].type == -4) {
					Chariots k(Map.map[2][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][2].type == 6 || Map.map[2][2].type == -6) {
					Cannons k(Map.map[2][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][2].type == 7 || Map.map[2][2].type == -7) {
					Soldiers k(Map.map[2][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 2]->BackColor == color.Pink) {
					Map.map[2][2] = Map.map[startL.x][startL.y];
					buttons[2, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 2]->BackColor = color.White;
					if (Map.map[2][2].type < 0) {
						buttons[2, 2]->ForeColor = color.Red;
					}
					else {
						buttons[2, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 3;
				int t = 0;
				if (Map.map[2][3].type == 1 || Map.map[2][3].type == -1) {
					King k(Map.map[2][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][3].type == 2 || Map.map[2][3].type == -2) {
					Guard k(Map.map[2][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][3].type == 3 || Map.map[2][3].type == -3) {
					Minister k(Map.map[2][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][3].type == 5 || Map.map[2][3].type == -5) {
					Horses k(Map.map[2][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][3].type == 4 || Map.map[2][3].type == -4) {
					Chariots k(Map.map[2][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][3].type == 6 || Map.map[2][3].type == -6) {
					Cannons k(Map.map[2][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][3].type == 7 || Map.map[2][3].type == -7) {
					Soldiers k(Map.map[2][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 3]->BackColor == color.Pink) {
					Map.map[2][3] = Map.map[startL.x][startL.y];
					buttons[2, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 3]->BackColor = color.White;
					if (Map.map[2][3].type < 0) {
						buttons[2, 3]->ForeColor = color.Red;
					}
					else {
						buttons[2, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 4;
				int t = 0;
				if (Map.map[2][4].type == 1 || Map.map[2][4].type == -1) {
					King k(Map.map[2][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][4].type == 2 || Map.map[2][4].type == -2) {
					Guard k(Map.map[2][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][4].type == 3 || Map.map[2][4].type == -3) {
					Minister k(Map.map[2][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][4].type == 5 || Map.map[2][4].type == -5) {
					Horses k(Map.map[2][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][4].type == 4 || Map.map[2][4].type == -4) {
					Chariots k(Map.map[2][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][4].type == 6 || Map.map[2][4].type == -6) {
					Cannons k(Map.map[2][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][4].type == 7 || Map.map[2][4].type == -7) {
					Soldiers k(Map.map[2][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 4]->BackColor == color.Pink) {
					Map.map[2][4] = Map.map[startL.x][startL.y];
					buttons[2, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 4]->BackColor = color.White;
					if (Map.map[2][4].type < 0) {
						buttons[2, 4]->ForeColor = color.Red;
					}
					else {
						buttons[2, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 5;
				int t = 0;
				if (Map.map[2][5].type == 1 || Map.map[2][5].type == -1) {
					King k(Map.map[2][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][5].type == 2 || Map.map[2][5].type == -2) {
					Guard k(Map.map[2][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][5].type == 3 || Map.map[2][5].type == -3) {
					Minister k(Map.map[2][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][5].type == 5 || Map.map[2][5].type == -5) {
					Horses k(Map.map[2][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][5].type == 4 || Map.map[2][5].type == -4) {
					Chariots k(Map.map[2][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][5].type == 6 || Map.map[2][5].type == -6) {
					Cannons k(Map.map[2][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][5].type == 7 || Map.map[2][5].type == -7) {
					Soldiers k(Map.map[2][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 5]->BackColor == color.Pink) {
					Map.map[2][5] = Map.map[startL.x][startL.y];
					buttons[2, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 5]->BackColor = color.White;
					if (Map.map[2][5].type < 0) {
						buttons[2, 5]->ForeColor = color.Red;
					}
					else {
						buttons[2, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 6;
				int t = 0;
				if (Map.map[2][6].type == 1 || Map.map[2][6].type == -1) {
					King k(Map.map[2][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][6].type == 2 || Map.map[2][6].type == -2) {
					Guard k(Map.map[2][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][6].type == 3 || Map.map[2][6].type == -3) {
					Minister k(Map.map[2][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][6].type == 5 || Map.map[2][6].type == -5) {
					Horses k(Map.map[2][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][6].type == 4 || Map.map[2][6].type == -4) {
					Chariots k(Map.map[2][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][6].type == 6 || Map.map[2][6].type == -6) {
					Cannons k(Map.map[2][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][6].type == 7 || Map.map[2][6].type == -7) {
					Soldiers k(Map.map[2][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 6]->BackColor == color.Pink) {
					Map.map[2][6] = Map.map[startL.x][startL.y];
					buttons[2, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 6]->BackColor = color.White;
					if (Map.map[2][6].type < 0) {
						buttons[2, 6]->ForeColor = color.Red;
					}
					else {
						buttons[2, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 7;
				int t = 0;
				if (Map.map[2][7].type == 1 || Map.map[2][7].type == -1) {
					King k(Map.map[2][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][7].type == 2 || Map.map[2][7].type == -2) {
					Guard k(Map.map[2][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][7].type == 3 || Map.map[2][7].type == -3) {
					Minister k(Map.map[2][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][7].type == 5 || Map.map[2][7].type == -5) {
					Horses k(Map.map[2][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][7].type == 4 || Map.map[2][7].type == -4) {
					Chariots k(Map.map[2][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][7].type == 6 || Map.map[2][7].type == -6) {
					Cannons k(Map.map[2][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][7].type == 7 || Map.map[2][7].type == -7) {
					Soldiers k(Map.map[2][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 7]->BackColor == color.Pink) {
					Map.map[2][7] = Map.map[startL.x][startL.y];
					buttons[2, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 7]->BackColor = color.White;
					if (Map.map[2][7].type < 0) {
						buttons[2, 7]->ForeColor = color.Red;
					}
					else {
						buttons[2, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 2;
				startL.y = 8;
				int t = 0;
				if (Map.map[2][8].type == 1 || Map.map[2][8].type == -1) {
					King k(Map.map[2][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][8].type == 2 || Map.map[2][8].type == -2) {
					Guard k(Map.map[2][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][8].type == 3 || Map.map[2][8].type == -3) {
					Minister k(Map.map[2][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][8].type == 5 || Map.map[2][8].type == -5) {
					Horses k(Map.map[2][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][8].type == 4 || Map.map[2][8].type == -4) {
					Chariots k(Map.map[2][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][8].type == 6 || Map.map[2][8].type == -6) {
					Cannons k(Map.map[2][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[2][8].type == 7 || Map.map[2][8].type == -7) {
					Soldiers k(Map.map[2][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(2, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[2, 8]->BackColor == color.Pink) {
					Map.map[2][8] = Map.map[startL.x][startL.y];
					buttons[2, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[2, 8]->BackColor = color.White;
					if (Map.map[2][8].type < 0) {
						buttons[2, 8]->ForeColor = color.Red;
					}
					else {
						buttons[2, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 0;
				int t = 0;
				if (Map.map[3][0].type == 1 || Map.map[3][0].type == -1) {
					King k(Map.map[3][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][0].type == 2 || Map.map[3][0].type == -2) {
					Guard k(Map.map[3][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][0].type == 3 || Map.map[3][0].type == -3) {
					Minister k(Map.map[3][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][0].type == 5 || Map.map[3][0].type == -5) {
					Horses k(Map.map[3][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][0].type == 4 || Map.map[3][0].type == -4) {
					Chariots k(Map.map[3][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][0].type == 6 || Map.map[3][0].type == -6) {
					Cannons k(Map.map[3][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][0].type == 7 || Map.map[3][0].type == -7) {
					Soldiers k(Map.map[3][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 0]->BackColor == color.Pink) {
					Map.map[3][0] = Map.map[startL.x][startL.y];
					buttons[3, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 0]->BackColor = color.White;
					if (Map.map[3][0].type < 0) {
						buttons[3, 0]->ForeColor = color.Red;
					}
					else {
						buttons[3, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 1;
				int t = 0;
				if (Map.map[3][1].type == 1 || Map.map[3][1].type == -1) {
					King k(Map.map[3][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][1].type == 2 || Map.map[3][1].type == -2) {
					Guard k(Map.map[3][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][1].type == 3 || Map.map[3][1].type == -3) {
					Minister k(Map.map[3][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][1].type == 5 || Map.map[3][1].type == -5) {
					Horses k(Map.map[3][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][1].type == 4 || Map.map[3][1].type == -4) {
					Chariots k(Map.map[3][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][1].type == 6 || Map.map[3][1].type == -6) {
					Cannons k(Map.map[3][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][1].type == 7 || Map.map[3][1].type == -7) {
					Soldiers k(Map.map[3][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 1]->BackColor == color.Pink) {
					Map.map[3][1] = Map.map[startL.x][startL.y];
					buttons[3, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 1]->BackColor = color.White;
					if (Map.map[3][1].type < 0) {
						buttons[3, 1]->ForeColor = color.Red;
					}
					else {
						buttons[3, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 2;
				int t = 0;
				if (Map.map[3][2].type == 1 || Map.map[3][2].type == -1) {
					King k(Map.map[3][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][2].type == 2 || Map.map[3][2].type == -2) {
					Guard k(Map.map[3][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][2].type == 3 || Map.map[3][2].type == -3) {
					Minister k(Map.map[3][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][2].type == 5 || Map.map[3][2].type == -5) {
					Horses k(Map.map[3][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][2].type == 4 || Map.map[3][2].type == -4) {
					Chariots k(Map.map[3][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][2].type == 6 || Map.map[3][2].type == -6) {
					Cannons k(Map.map[3][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][2].type == 7 || Map.map[3][2].type == -7) {
					Soldiers k(Map.map[3][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 2]->BackColor == color.Pink) {
					Map.map[3][2] = Map.map[startL.x][startL.y];
					buttons[3, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 2]->BackColor = color.White;
					if (Map.map[3][2].type < 0) {
						buttons[3, 2]->ForeColor = color.Red;
					}
					else {
						buttons[3, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 3;
				int t = 0;
				if (Map.map[3][3].type == 1 || Map.map[3][3].type == -1) {
					King k(Map.map[3][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][3].type == 2 || Map.map[3][3].type == -2) {
					Guard k(Map.map[3][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][3].type == 3 || Map.map[3][3].type == -3) {
					Minister k(Map.map[3][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][3].type == 5 || Map.map[3][3].type == -5) {
					Horses k(Map.map[3][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][3].type == 4 || Map.map[3][3].type == -4) {
					Chariots k(Map.map[3][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][3].type == 6 || Map.map[3][3].type == -6) {
					Cannons k(Map.map[3][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][3].type == 7 || Map.map[3][3].type == -7) {
					Soldiers k(Map.map[3][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 3]->BackColor == color.Pink) {
					Map.map[3][3] = Map.map[startL.x][startL.y];
					buttons[3, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 3]->BackColor = color.White;
					if (Map.map[3][3].type < 0) {
						buttons[3, 3]->ForeColor = color.Red;
					}
					else {
						buttons[3, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 4;
				int t = 0;
				if (Map.map[3][4].type == 1 || Map.map[3][4].type == -1) {
					King k(Map.map[3][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][4].type == 2 || Map.map[3][4].type == -2) {
					Guard k(Map.map[3][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][4].type == 3 || Map.map[3][4].type == -3) {
					Minister k(Map.map[3][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][4].type == 5 || Map.map[3][4].type == -5) {
					Horses k(Map.map[3][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][4].type == 4 || Map.map[3][4].type == -4) {
					Chariots k(Map.map[3][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][4].type == 6 || Map.map[3][4].type == -6) {
					Cannons k(Map.map[3][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][4].type == 7 || Map.map[3][4].type == -7) {
					Soldiers k(Map.map[3][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 4]->BackColor == color.Pink) {
					Map.map[3][4] = Map.map[startL.x][startL.y];
					buttons[3, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 4]->BackColor = color.White;
					if (Map.map[3][4].type < 0) {
						buttons[3, 4]->ForeColor = color.Red;
					}
					else {
						buttons[3, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 5;
				int t = 0;
				if (Map.map[3][5].type == 1 || Map.map[3][5].type == -1) {
					King k(Map.map[3][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][5].type == 2 || Map.map[3][5].type == -2) {
					Guard k(Map.map[3][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][5].type == 3 || Map.map[3][5].type == -3) {
					Minister k(Map.map[3][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][5].type == 5 || Map.map[3][5].type == -5) {
					Horses k(Map.map[3][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][5].type == 4 || Map.map[3][5].type == -4) {
					Chariots k(Map.map[3][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][5].type == 6 || Map.map[3][5].type == -6) {
					Cannons k(Map.map[3][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][5].type == 7 || Map.map[3][5].type == -7) {
					Soldiers k(Map.map[3][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 5]->BackColor == color.Pink) {
					Map.map[3][5] = Map.map[startL.x][startL.y];
					buttons[3, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 5]->BackColor = color.White;
					if (Map.map[3][5].type < 0) {
						buttons[3, 5]->ForeColor = color.Red;
					}
					else {
						buttons[3, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 6;
				int t = 0;
				if (Map.map[3][6].type == 1 || Map.map[3][6].type == -1) {
					King k(Map.map[3][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][6].type == 2 || Map.map[3][6].type == -2) {
					Guard k(Map.map[3][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][6].type == 3 || Map.map[3][6].type == -3) {
					Minister k(Map.map[3][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][6].type == 5 || Map.map[3][6].type == -5) {
					Horses k(Map.map[3][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][6].type == 4 || Map.map[3][6].type == -4) {
					Chariots k(Map.map[3][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][6].type == 6 || Map.map[3][6].type == -6) {
					Cannons k(Map.map[3][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][6].type == 7 || Map.map[3][6].type == -7) {
					Soldiers k(Map.map[3][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 6]->BackColor == color.Pink) {
					Map.map[3][6] = Map.map[startL.x][startL.y];
					buttons[3, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 6]->BackColor = color.White;
					if (Map.map[3][6].type < 0) {
						buttons[3, 6]->ForeColor = color.Red;
					}
					else {
						buttons[3, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 7;
				int t = 0;
				if (Map.map[3][7].type == 1 || Map.map[3][7].type == -1) {
					King k(Map.map[3][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][7].type == 2 || Map.map[3][7].type == -2) {
					Guard k(Map.map[3][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][7].type == 3 || Map.map[3][7].type == -3) {
					Minister k(Map.map[3][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][7].type == 5 || Map.map[3][7].type == -5) {
					Horses k(Map.map[3][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][7].type == 4 || Map.map[3][7].type == -4) {
					Chariots k(Map.map[3][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][7].type == 6 || Map.map[3][7].type == -6) {
					Cannons k(Map.map[3][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][7].type == 7 || Map.map[3][7].type == -7) {
					Soldiers k(Map.map[3][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 7]->BackColor == color.Pink) {
					Map.map[3][7] = Map.map[startL.x][startL.y];
					buttons[3, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 7]->BackColor = color.White;
					if (Map.map[3][7].type < 0) {
						buttons[3, 7]->ForeColor = color.Red;
					}
					else {
						buttons[3, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 3;
				startL.y = 8;
				int t = 0;
				if (Map.map[3][8].type == 1 || Map.map[3][8].type == -1) {
					King k(Map.map[3][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][8].type == 2 || Map.map[3][8].type == -2) {
					Guard k(Map.map[3][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][8].type == 3 || Map.map[3][8].type == -3) {
					Minister k(Map.map[3][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][8].type == 5 || Map.map[3][8].type == -5) {
					Horses k(Map.map[3][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][8].type == 4 || Map.map[3][8].type == -4) {
					Chariots k(Map.map[3][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][8].type == 6 || Map.map[3][8].type == -6) {
					Cannons k(Map.map[3][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[3][8].type == 7 || Map.map[3][8].type == -7) {
					Soldiers k(Map.map[3][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(3, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[3, 8]->BackColor == color.Pink) {
					Map.map[3][8] = Map.map[startL.x][startL.y];
					buttons[3, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[3, 8]->BackColor = color.White;
					if (Map.map[3][8].type < 0) {
						buttons[3, 8]->ForeColor = color.Red;
					}
					else {
						buttons[3, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 0;
				int t = 0;
				if (Map.map[4][0].type == 1 || Map.map[4][0].type == -1) {
					King k(Map.map[4][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][0].type == 2 || Map.map[4][0].type == -2) {
					Guard k(Map.map[4][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][0].type == 3 || Map.map[4][0].type == -3) {
					Minister k(Map.map[4][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][0].type == 5 || Map.map[4][0].type == -5) {
					Horses k(Map.map[4][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][0].type == 4 || Map.map[4][0].type == -4) {
					Chariots k(Map.map[4][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][0].type == 6 || Map.map[4][0].type == -6) {
					Cannons k(Map.map[4][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][0].type == 7 || Map.map[4][0].type == -7) {
					Soldiers k(Map.map[4][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 0]->BackColor == color.Pink) {
					Map.map[4][0] = Map.map[startL.x][startL.y];
					buttons[4, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 0]->BackColor = color.White;
					if (Map.map[4][0].type < 0) {
						buttons[4, 0]->ForeColor = color.Red;
					}
					else {
						buttons[4, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 1;
				int t = 0;
				if (Map.map[4][1].type == 1 || Map.map[4][1].type == -1) {
					King k(Map.map[4][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][1].type == 2 || Map.map[4][1].type == -2) {
					Guard k(Map.map[4][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][1].type == 3 || Map.map[4][1].type == -3) {
					Minister k(Map.map[4][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][1].type == 5 || Map.map[4][1].type == -5) {
					Horses k(Map.map[4][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][1].type == 4 || Map.map[4][1].type == -4) {
					Chariots k(Map.map[4][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][1].type == 6 || Map.map[4][1].type == -6) {
					Cannons k(Map.map[4][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][1].type == 7 || Map.map[4][1].type == -7) {
					Soldiers k(Map.map[4][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 1]->BackColor == color.Pink) {
					Map.map[4][1] = Map.map[startL.x][startL.y];
					buttons[4, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 1]->BackColor = color.White;
					if (Map.map[4][1].type < 0) {
						buttons[4, 1]->ForeColor = color.Red;
					}
					else {
						buttons[4, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button39_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 2;
				int t = 0;
				if (Map.map[4][2].type == 1 || Map.map[4][2].type == -1) {
					King k(Map.map[4][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][2].type == 2 || Map.map[4][2].type == -2) {
					Guard k(Map.map[4][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][2].type == 3 || Map.map[4][2].type == -3) {
					Minister k(Map.map[4][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][2].type == 5 || Map.map[4][2].type == -5) {
					Horses k(Map.map[4][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][2].type == 4 || Map.map[4][2].type == -4) {
					Chariots k(Map.map[4][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][2].type == 6 || Map.map[4][2].type == -6) {
					Cannons k(Map.map[4][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][2].type == 7 || Map.map[4][2].type == -7) {
					Soldiers k(Map.map[4][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 2]->BackColor == color.Pink) {
					Map.map[4][2] = Map.map[startL.x][startL.y];
					buttons[4, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 2]->BackColor = color.White;
					if (Map.map[4][2].type < 0) {
						buttons[4, 2]->ForeColor = color.Red;
					}
					else {
						buttons[4, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button40_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 3;
				int t = 0;
				if (Map.map[4][3].type == 1 || Map.map[4][3].type == -1) {
					King k(Map.map[4][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][3].type == 2 || Map.map[4][3].type == -2) {
					Guard k(Map.map[4][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][3].type == 3 || Map.map[4][3].type == -3) {
					Minister k(Map.map[4][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][3].type == 5 || Map.map[4][3].type == -5) {
					Horses k(Map.map[4][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][3].type == 4 || Map.map[4][3].type == -4) {
					Chariots k(Map.map[4][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][3].type == 6 || Map.map[4][3].type == -6) {
					Cannons k(Map.map[4][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][3].type == 7 || Map.map[4][3].type == -7) {
					Soldiers k(Map.map[4][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 3]->BackColor == color.Pink) {
					Map.map[4][3] = Map.map[startL.x][startL.y];
					buttons[4, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 3]->BackColor = color.White;
					if (Map.map[4][3].type < 0) {
						buttons[4, 3]->ForeColor = color.Red;
					}
					else {
						buttons[4, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button41_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 4;
				int t = 0;
				if (Map.map[4][4].type == 1 || Map.map[4][4].type == -1) {
					King k(Map.map[4][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][4].type == 2 || Map.map[4][4].type == -2) {
					Guard k(Map.map[4][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][4].type == 3 || Map.map[4][4].type == -3) {
					Minister k(Map.map[4][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][4].type == 5 || Map.map[4][4].type == -5) {
					Horses k(Map.map[4][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][4].type == 4 || Map.map[4][4].type == -4) {
					Chariots k(Map.map[4][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][4].type == 6 || Map.map[4][4].type == -6) {
					Cannons k(Map.map[4][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][4].type == 7 || Map.map[4][4].type == -7) {
					Soldiers k(Map.map[4][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 4]->BackColor == color.Pink) {
					Map.map[4][4] = Map.map[startL.x][startL.y];
					buttons[4, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 4]->BackColor = color.White;
					if (Map.map[4][4].type < 0) {
						buttons[4, 4]->ForeColor = color.Red;
					}
					else {
						buttons[4, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button42_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 5;
				int t = 0;
				if (Map.map[4][5].type == 1 || Map.map[4][5].type == -1) {
					King k(Map.map[4][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][5].type == 2 || Map.map[4][5].type == -2) {
					Guard k(Map.map[4][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][5].type == 3 || Map.map[4][5].type == -3) {
					Minister k(Map.map[4][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][5].type == 5 || Map.map[4][5].type == -5) {
					Horses k(Map.map[4][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][5].type == 4 || Map.map[4][5].type == -4) {
					Chariots k(Map.map[4][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][5].type == 6 || Map.map[4][5].type == -6) {
					Cannons k(Map.map[4][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][5].type == 7 || Map.map[4][5].type == -7) {
					Soldiers k(Map.map[4][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 5]->BackColor == color.Pink) {
					Map.map[4][5] = Map.map[startL.x][startL.y];
					buttons[4, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 5]->BackColor = color.White;
					if (Map.map[4][5].type < 0) {
						buttons[4, 5]->ForeColor = color.Red;
					}
					else {
						buttons[4, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button43_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 6;
				int t = 0;
				if (Map.map[4][6].type == 1 || Map.map[4][6].type == -1) {
					King k(Map.map[4][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][6].type == 2 || Map.map[4][6].type == -2) {
					Guard k(Map.map[4][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][6].type == 3 || Map.map[4][6].type == -3) {
					Minister k(Map.map[4][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][6].type == 5 || Map.map[4][6].type == -5) {
					Horses k(Map.map[4][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][6].type == 4 || Map.map[4][6].type == -4) {
					Chariots k(Map.map[4][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][6].type == 6 || Map.map[4][6].type == -6) {
					Cannons k(Map.map[4][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][6].type == 7 || Map.map[4][6].type == -7) {
					Soldiers k(Map.map[4][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 6]->BackColor == color.Pink) {
					Map.map[4][6] = Map.map[startL.x][startL.y];
					buttons[4, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 6]->BackColor = color.White;
					if (Map.map[4][6].type < 0) {
						buttons[4, 6]->ForeColor = color.Red;
					}
					else {
						buttons[4, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button44_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 7;
				int t = 0;
				if (Map.map[4][7].type == 1 || Map.map[4][7].type == -1) {
					King k(Map.map[4][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][7].type == 2 || Map.map[4][7].type == -2) {
					Guard k(Map.map[4][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][7].type == 3 || Map.map[4][7].type == -3) {
					Minister k(Map.map[4][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][7].type == 5 || Map.map[4][7].type == -5) {
					Horses k(Map.map[4][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][7].type == 4 || Map.map[4][7].type == -4) {
					Chariots k(Map.map[4][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][7].type == 6 || Map.map[4][7].type == -6) {
					Cannons k(Map.map[4][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][7].type == 7 || Map.map[4][7].type == -7) {
					Soldiers k(Map.map[4][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 7]->BackColor == color.Pink) {
					Map.map[4][7] = Map.map[startL.x][startL.y];
					buttons[4, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 7]->BackColor = color.White;
					if (Map.map[4][7].type < 0) {
						buttons[4, 7]->ForeColor = color.Red;
					}
					else {
						buttons[4, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button45_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 4;
				startL.y = 8;
				int t = 0;
				if (Map.map[4][8].type == 1 || Map.map[4][8].type == -1) {
					King k(Map.map[4][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][8].type == 2 || Map.map[4][8].type == -2) {
					Guard k(Map.map[4][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][8].type == 3 || Map.map[4][8].type == -3) {
					Minister k(Map.map[4][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][8].type == 5 || Map.map[4][8].type == -5) {
					Horses k(Map.map[4][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][8].type == 4 || Map.map[4][8].type == -4) {
					Chariots k(Map.map[4][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][8].type == 6 || Map.map[4][8].type == -6) {
					Cannons k(Map.map[4][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[4][8].type == 7 || Map.map[4][8].type == -7) {
					Soldiers k(Map.map[4][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(4, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[4, 8]->BackColor == color.Pink) {
					Map.map[4][8] = Map.map[startL.x][startL.y];
					buttons[4, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[4, 8]->BackColor = color.White;
					if (Map.map[4][8].type < 0) {
						buttons[4, 8]->ForeColor = color.Red;
					}
					else {
						buttons[4, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button46_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 0;
				int t = 0;
				if (Map.map[5][0].type == 1 || Map.map[5][0].type == -1) {
					King k(Map.map[5][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][0].type == 2 || Map.map[5][0].type == -2) {
					Guard k(Map.map[5][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][0].type == 3 || Map.map[5][0].type == -3) {
					Minister k(Map.map[5][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][0].type == 5 || Map.map[5][0].type == -5) {
					Horses k(Map.map[5][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][0].type == 4 || Map.map[5][0].type == -4) {
					Chariots k(Map.map[5][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][0].type == 6 || Map.map[5][0].type == -6) {
					Cannons k(Map.map[5][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][0].type == 7 || Map.map[5][0].type == -7) {
					Soldiers k(Map.map[5][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 0]->BackColor == color.Pink) {
					Map.map[5][0] = Map.map[startL.x][startL.y];
					buttons[5, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 0]->BackColor = color.White;
					if (Map.map[5][0].type < 0) {
						buttons[5, 0]->ForeColor = color.Red;
					}
					else {
						buttons[5, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button47_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 1;
				int t = 0;
				if (Map.map[5][1].type == 1 || Map.map[5][1].type == -1) {
					King k(Map.map[5][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][1].type == 2 || Map.map[5][1].type == -2) {
					Guard k(Map.map[5][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][1].type == 3 || Map.map[5][1].type == -3) {
					Minister k(Map.map[5][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][1].type == 5 || Map.map[5][1].type == -5) {
					Horses k(Map.map[5][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][1].type == 4 || Map.map[5][1].type == -4) {
					Chariots k(Map.map[5][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][1].type == 6 || Map.map[5][1].type == -6) {
					Cannons k(Map.map[5][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][1].type == 7 || Map.map[5][1].type == -7) {
					Soldiers k(Map.map[5][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 1]->BackColor == color.Pink) {
					Map.map[5][1] = Map.map[startL.x][startL.y];
					buttons[5, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 1]->BackColor = color.White;
					if (Map.map[5][1].type < 0) {
						buttons[5, 1]->ForeColor = color.Red;
					}
					else {
						buttons[5, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button48_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 2;
				int t = 0;
				if (Map.map[5][2].type == 1 || Map.map[5][2].type == -1) {
					King k(Map.map[5][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][2].type == 2 || Map.map[5][2].type == -2) {
					Guard k(Map.map[5][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][2].type == 3 || Map.map[5][2].type == -3) {
					Minister k(Map.map[5][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][2].type == 5 || Map.map[5][2].type == -5) {
					Horses k(Map.map[5][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][2].type == 4 || Map.map[5][2].type == -4) {
					Chariots k(Map.map[5][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][2].type == 6 || Map.map[5][2].type == -6) {
					Cannons k(Map.map[5][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][2].type == 7 || Map.map[5][2].type == -7) {
					Soldiers k(Map.map[5][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 2]->BackColor == color.Pink) {
					Map.map[5][2] = Map.map[startL.x][startL.y];
					buttons[5, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 2]->BackColor = color.White;
					if (Map.map[5][2].type < 0) {
						buttons[5, 2]->ForeColor = color.Red;
					}
					else {
						buttons[5, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button49_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 3;
				int t = 0;
				if (Map.map[5][3].type == 1 || Map.map[5][3].type == -1) {
					King k(Map.map[5][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][3].type == 2 || Map.map[5][3].type == -2) {
					Guard k(Map.map[5][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][3].type == 3 || Map.map[5][3].type == -3) {
					Minister k(Map.map[5][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][3].type == 5 || Map.map[5][3].type == -5) {
					Horses k(Map.map[5][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][3].type == 4 || Map.map[5][3].type == -4) {
					Chariots k(Map.map[5][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][3].type == 6 || Map.map[5][3].type == -6) {
					Cannons k(Map.map[5][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][3].type == 7 || Map.map[5][3].type == -7) {
					Soldiers k(Map.map[5][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 3]->BackColor == color.Pink) {
					Map.map[5][3] = Map.map[startL.x][startL.y];
					buttons[5, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 3]->BackColor = color.White;
					if (Map.map[5][3].type < 0) {
						buttons[5, 3]->ForeColor = color.Red;
					}
					else {
						buttons[5, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button50_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 4;
				int t = 0;
				if (Map.map[5][4].type == 1 || Map.map[5][4].type == -1) {
					King k(Map.map[5][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][4].type == 2 || Map.map[5][4].type == -2) {
					Guard k(Map.map[5][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][4].type == 3 || Map.map[5][4].type == -3) {
					Minister k(Map.map[5][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][4].type == 5 || Map.map[5][4].type == -5) {
					Horses k(Map.map[5][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][4].type == 4 || Map.map[5][4].type == -4) {
					Chariots k(Map.map[5][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][4].type == 6 || Map.map[5][4].type == -6) {
					Cannons k(Map.map[5][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][4].type == 7 || Map.map[5][4].type == -7) {
					Soldiers k(Map.map[5][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 4]->BackColor == color.Pink) {
					Map.map[5][4] = Map.map[startL.x][startL.y];
					buttons[5, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 4]->BackColor = color.White;
					if (Map.map[5][4].type < 0) {
						buttons[5, 4]->ForeColor = color.Red;
					}
					else {
						buttons[5, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button51_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 5;
				int t = 0;
				if (Map.map[5][5].type == 1 || Map.map[5][5].type == -1) {
					King k(Map.map[5][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][5].type == 2 || Map.map[5][5].type == -2) {
					Guard k(Map.map[5][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][5].type == 3 || Map.map[5][5].type == -3) {
					Minister k(Map.map[5][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][5].type == 5 || Map.map[5][5].type == -5) {
					Horses k(Map.map[5][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][5].type == 4 || Map.map[5][5].type == -4) {
					Chariots k(Map.map[5][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][5].type == 6 || Map.map[5][5].type == -6) {
					Cannons k(Map.map[5][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][5].type == 7 || Map.map[5][5].type == -7) {
					Soldiers k(Map.map[5][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 5]->BackColor == color.Pink) {
					Map.map[5][5] = Map.map[startL.x][startL.y];
					buttons[5, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 5]->BackColor = color.White;
					if (Map.map[5][5].type < 0) {
						buttons[5, 5]->ForeColor = color.Red;
					}
					else {
						buttons[5, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button52_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 6;
				int t = 0;
				if (Map.map[5][6].type == 1 || Map.map[5][6].type == -1) {
					King k(Map.map[5][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][6].type == 2 || Map.map[5][6].type == -2) {
					Guard k(Map.map[5][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][6].type == 3 || Map.map[5][6].type == -3) {
					Minister k(Map.map[5][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][6].type == 5 || Map.map[5][6].type == -5) {
					Horses k(Map.map[5][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][6].type == 4 || Map.map[5][6].type == -4) {
					Chariots k(Map.map[5][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][6].type == 6 || Map.map[5][6].type == -6) {
					Cannons k(Map.map[5][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][6].type == 7 || Map.map[5][6].type == -7) {
					Soldiers k(Map.map[5][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 6]->BackColor == color.Pink) {
					Map.map[5][6] = Map.map[startL.x][startL.y];
					buttons[5, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 6]->BackColor = color.White;
					if (Map.map[5][6].type < 0) {
						buttons[5, 6]->ForeColor = color.Red;
					}
					else {
						buttons[5, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button53_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 7;
				int t = 0;
				if (Map.map[5][7].type == 1 || Map.map[5][7].type == -1) {
					King k(Map.map[5][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][7].type == 2 || Map.map[5][7].type == -2) {
					Guard k(Map.map[5][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][7].type == 3 || Map.map[5][7].type == -3) {
					Minister k(Map.map[5][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][7].type == 5 || Map.map[5][7].type == -5) {
					Horses k(Map.map[5][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][7].type == 4 || Map.map[5][7].type == -4) {
					Chariots k(Map.map[5][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][7].type == 6 || Map.map[5][7].type == -6) {
					Cannons k(Map.map[5][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][7].type == 7 || Map.map[5][7].type == -7) {
					Soldiers k(Map.map[5][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 7]->BackColor == color.Pink) {
					Map.map[5][7] = Map.map[startL.x][startL.y];
					buttons[5, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 7]->BackColor = color.White;
					if (Map.map[5][7].type < 0) {
						buttons[5, 7]->ForeColor = color.Red;
					}
					else {
						buttons[5, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button54_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 5;
				startL.y = 8;
				int t = 0;
				if (Map.map[5][8].type == 1 || Map.map[5][8].type == -1) {
					King k(Map.map[5][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][8].type == 2 || Map.map[5][8].type == -2) {
					Guard k(Map.map[5][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][8].type == 3 || Map.map[5][8].type == -3) {
					Minister k(Map.map[5][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][8].type == 5 || Map.map[5][8].type == -5) {
					Horses k(Map.map[5][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][8].type == 4 || Map.map[5][8].type == -4) {
					Chariots k(Map.map[5][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][8].type == 6 || Map.map[5][8].type == -6) {
					Cannons k(Map.map[5][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[5][8].type == 7 || Map.map[5][8].type == -7) {
					Soldiers k(Map.map[5][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(5, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[5, 8]->BackColor == color.Pink) {
					Map.map[5][8] = Map.map[startL.x][startL.y];
					buttons[5, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[5, 8]->BackColor = color.White;
					if (Map.map[5][8].type < 0) {
						buttons[5, 8]->ForeColor = color.Red;
					}
					else {
						buttons[5, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button55_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 0;
				int t = 0;
				if (Map.map[6][0].type == 1 || Map.map[6][0].type == -1) {
					King k(Map.map[6][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][0].type == 2 || Map.map[6][0].type == -2) {
					Guard k(Map.map[6][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][0].type == 3 || Map.map[6][0].type == -3) {
					Minister k(Map.map[6][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][0].type == 5 || Map.map[6][0].type == -5) {
					Horses k(Map.map[6][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][0].type == 4 || Map.map[6][0].type == -4) {
					Chariots k(Map.map[6][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][0].type == 6 || Map.map[6][0].type == -6) {
					Cannons k(Map.map[6][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][0].type == 7 || Map.map[6][0].type == -7) {
					Soldiers k(Map.map[6][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 0]->BackColor == color.Pink) {
					Map.map[6][0] = Map.map[startL.x][startL.y];
					buttons[6, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 0]->BackColor = color.White;
					if (Map.map[6][0].type < 0) {
						buttons[6, 0]->ForeColor = color.Red;
					}
					else {
						buttons[6, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button56_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 1;
				int t = 0;
				if (Map.map[6][1].type == 1 || Map.map[6][1].type == -1) {
					King k(Map.map[6][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][1].type == 2 || Map.map[6][1].type == -2) {
					Guard k(Map.map[6][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][1].type == 3 || Map.map[6][1].type == -3) {
					Minister k(Map.map[6][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][1].type == 5 || Map.map[6][1].type == -5) {
					Horses k(Map.map[6][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][1].type == 4 || Map.map[6][1].type == -4) {
					Chariots k(Map.map[6][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][1].type == 6 || Map.map[6][1].type == -6) {
					Cannons k(Map.map[6][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][1].type == 7 || Map.map[6][1].type == -7) {
					Soldiers k(Map.map[6][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 1]->BackColor == color.Pink) {
					Map.map[6][1] = Map.map[startL.x][startL.y];
					buttons[6, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 1]->BackColor = color.White;
					if (Map.map[6][1].type < 0) {
						buttons[6, 1]->ForeColor = color.Red;
					}
					else {
						buttons[6, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button57_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 2;
				int t = 0;
				if (Map.map[6][2].type == 1 || Map.map[6][2].type == -1) {
					King k(Map.map[6][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][2].type == 2 || Map.map[6][2].type == -2) {
					Guard k(Map.map[6][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][2].type == 3 || Map.map[6][2].type == -3) {
					Minister k(Map.map[6][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][2].type == 5 || Map.map[6][2].type == -5) {
					Horses k(Map.map[6][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][2].type == 4 || Map.map[6][2].type == -4) {
					Chariots k(Map.map[6][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][2].type == 6 || Map.map[6][2].type == -6) {
					Cannons k(Map.map[6][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][2].type == 7 || Map.map[6][2].type == -7) {
					Soldiers k(Map.map[6][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 2]->BackColor == color.Pink) {
					Map.map[6][2] = Map.map[startL.x][startL.y];
					buttons[6, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 2]->BackColor = color.White;
					if (Map.map[6][2].type < 0) {
						buttons[6, 2]->ForeColor = color.Red;
					}
					else {
						buttons[6, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button58_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 3;
				int t = 0;
				if (Map.map[6][3].type == 1 || Map.map[6][3].type == -1) {
					King k(Map.map[6][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][3].type == 2 || Map.map[6][3].type == -2) {
					Guard k(Map.map[6][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][3].type == 3 || Map.map[6][3].type == -3) {
					Minister k(Map.map[6][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][3].type == 5 || Map.map[6][3].type == -5) {
					Horses k(Map.map[6][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][3].type == 4 || Map.map[6][3].type == -4) {
					Chariots k(Map.map[6][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][3].type == 6 || Map.map[6][3].type == -6) {
					Cannons k(Map.map[6][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][3].type == 7 || Map.map[6][3].type == -7) {
					Soldiers k(Map.map[6][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 3]->BackColor == color.Pink) {
					Map.map[6][3] = Map.map[startL.x][startL.y];
					buttons[6, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 3]->BackColor = color.White;
					if (Map.map[6][3].type < 0) {
						buttons[6, 3]->ForeColor = color.Red;
					}
					else {
						buttons[6, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button59_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 4;
				int t = 0;
				if (Map.map[6][4].type == 1 || Map.map[6][4].type == -1) {
					King k(Map.map[6][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][4].type == 2 || Map.map[6][4].type == -2) {
					Guard k(Map.map[6][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][4].type == 3 || Map.map[6][4].type == -3) {
					Minister k(Map.map[6][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][4].type == 5 || Map.map[6][4].type == -5) {
					Horses k(Map.map[6][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][4].type == 4 || Map.map[6][4].type == -4) {
					Chariots k(Map.map[6][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][4].type == 6 || Map.map[6][4].type == -6) {
					Cannons k(Map.map[6][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][4].type == 7 || Map.map[6][4].type == -7) {
					Soldiers k(Map.map[6][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 4]->BackColor == color.Pink) {
					Map.map[6][4] = Map.map[startL.x][startL.y];
					buttons[6, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 4]->BackColor = color.White;
					if (Map.map[6][4].type < 0) {
						buttons[6, 4]->ForeColor = color.Red;
					}
					else {
						buttons[6, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button60_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 5;
				int t = 0;
				if (Map.map[6][5].type == 1 || Map.map[6][5].type == -1) {
					King k(Map.map[6][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][5].type == 2 || Map.map[6][5].type == -2) {
					Guard k(Map.map[6][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][5].type == 3 || Map.map[6][5].type == -3) {
					Minister k(Map.map[6][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][5].type == 5 || Map.map[6][5].type == -5) {
					Horses k(Map.map[6][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][5].type == 4 || Map.map[6][5].type == -4) {
					Chariots k(Map.map[6][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][5].type == 6 || Map.map[6][5].type == -6) {
					Cannons k(Map.map[6][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][5].type == 7 || Map.map[6][5].type == -7) {
					Soldiers k(Map.map[6][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 5]->BackColor == color.Pink) {
					Map.map[6][5] = Map.map[startL.x][startL.y];
					buttons[6, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 5]->BackColor = color.White;
					if (Map.map[6][5].type < 0) {
						buttons[6, 5]->ForeColor = color.Red;
					}
					else {
						buttons[6, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button61_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 6;
				int t = 0;
				if (Map.map[6][6].type == 1 || Map.map[6][6].type == -1) {
					King k(Map.map[6][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][6].type == 2 || Map.map[6][6].type == -2) {
					Guard k(Map.map[6][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][6].type == 3 || Map.map[6][6].type == -3) {
					Minister k(Map.map[6][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][6].type == 5 || Map.map[6][6].type == -5) {
					Horses k(Map.map[6][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][6].type == 4 || Map.map[6][6].type == -4) {
					Chariots k(Map.map[6][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][6].type == 6 || Map.map[6][6].type == -6) {
					Cannons k(Map.map[6][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][6].type == 7 || Map.map[6][6].type == -7) {
					Soldiers k(Map.map[6][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 6]->BackColor == color.Pink) {
					Map.map[6][6] = Map.map[startL.x][startL.y];
					buttons[6, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 6]->BackColor = color.White;
					if (Map.map[6][6].type < 0) {
						buttons[6, 6]->ForeColor = color.Red;
					}
					else {
						buttons[6, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button62_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 7;
				int t = 0;
				if (Map.map[6][7].type == 1 || Map.map[6][7].type == -1) {
					King k(Map.map[6][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][7].type == 2 || Map.map[6][7].type == -2) {
					Guard k(Map.map[6][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][7].type == 3 || Map.map[6][7].type == -3) {
					Minister k(Map.map[6][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][7].type == 5 || Map.map[6][7].type == -5) {
					Horses k(Map.map[6][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][7].type == 4 || Map.map[6][7].type == -4) {
					Chariots k(Map.map[6][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][7].type == 6 || Map.map[6][7].type == -6) {
					Cannons k(Map.map[6][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][7].type == 7 || Map.map[6][7].type == -7) {
					Soldiers k(Map.map[6][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 7]->BackColor == color.Pink) {
					Map.map[6][7] = Map.map[startL.x][startL.y];
					buttons[6, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 7]->BackColor = color.White;
					if (Map.map[6][7].type < 0) {
						buttons[6, 7]->ForeColor = color.Red;
					}
					else {
						buttons[6, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button63_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 6;
				startL.y = 8;
				int t = 0;
				if (Map.map[6][8].type == 1 || Map.map[6][8].type == -1) {
					King k(Map.map[6][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][8].type == 2 || Map.map[6][8].type == -2) {
					Guard k(Map.map[6][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][8].type == 3 || Map.map[6][8].type == -3) {
					Minister k(Map.map[6][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][8].type == 5 || Map.map[6][8].type == -5) {
					Horses k(Map.map[6][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][8].type == 4 || Map.map[6][8].type == -4) {
					Chariots k(Map.map[6][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][8].type == 6 || Map.map[6][8].type == -6) {
					Cannons k(Map.map[6][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[6][8].type == 7 || Map.map[6][8].type == -7) {
					Soldiers k(Map.map[6][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(6, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[6, 8]->BackColor == color.Pink) {
					Map.map[6][8] = Map.map[startL.x][startL.y];
					buttons[6, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[6, 8]->BackColor = color.White;
					if (Map.map[6][8].type < 0) {
						buttons[6, 8]->ForeColor = color.Red;
					}
					else {
						buttons[6, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button64_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 0;
				int t = 0;
				if (Map.map[7][0].type == 1 || Map.map[7][0].type == -1) {
					King k(Map.map[7][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][0].type == 2 || Map.map[7][0].type == -2) {
					Guard k(Map.map[7][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][0].type == 3 || Map.map[7][0].type == -3) {
					Minister k(Map.map[7][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][0].type == 5 || Map.map[7][0].type == -5) {
					Horses k(Map.map[7][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][0].type == 4 || Map.map[7][0].type == -4) {
					Chariots k(Map.map[7][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][0].type == 6 || Map.map[7][0].type == -6) {
					Cannons k(Map.map[7][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][0].type == 7 || Map.map[7][0].type == -7) {
					Soldiers k(Map.map[7][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 0]->BackColor == color.Pink) {
					Map.map[7][0] = Map.map[startL.x][startL.y];
					buttons[7, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 0]->BackColor = color.White;
					if (Map.map[7][0].type < 0) {
						buttons[7, 0]->ForeColor = color.Red;
					}
					else {
						buttons[7, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button65_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 1;
				int t = 0;
				if (Map.map[7][1].type == 1 || Map.map[7][1].type == -1) {
					King k(Map.map[7][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][1].type == 2 || Map.map[7][1].type == -2) {
					Guard k(Map.map[7][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][1].type == 3 || Map.map[7][1].type == -3) {
					Minister k(Map.map[7][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][1].type == 5 || Map.map[7][1].type == -5) {
					Horses k(Map.map[7][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][1].type == 4 || Map.map[7][1].type == -4) {
					Chariots k(Map.map[7][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][1].type == 6 || Map.map[7][1].type == -6) {
					Cannons k(Map.map[7][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][1].type == 7 || Map.map[7][1].type == -7) {
					Soldiers k(Map.map[7][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 1]->BackColor == color.Pink) {
					Map.map[7][1] = Map.map[startL.x][startL.y];
					buttons[7, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 1]->BackColor = color.White;
					if (Map.map[7][1].type < 0) {
						buttons[7, 1]->ForeColor = color.Red;
					}
					else {
						buttons[7, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button66_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 2;
				int t = 0;
				if (Map.map[7][2].type == 1 || Map.map[7][2].type == -1) {
					King k(Map.map[7][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][2].type == 2 || Map.map[7][2].type == -2) {
					Guard k(Map.map[7][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][2].type == 3 || Map.map[7][2].type == -3) {
					Minister k(Map.map[7][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][2].type == 5 || Map.map[7][2].type == -5) {
					Horses k(Map.map[7][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][2].type == 4 || Map.map[7][2].type == -4) {
					Chariots k(Map.map[7][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][2].type == 6 || Map.map[7][2].type == -6) {
					Cannons k(Map.map[7][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][2].type == 7 || Map.map[7][2].type == -7) {
					Soldiers k(Map.map[7][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 2]->BackColor == color.Pink) {
					Map.map[7][2] = Map.map[startL.x][startL.y];
					buttons[7, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 2]->BackColor = color.White;
					if (Map.map[7][2].type < 0) {
						buttons[7, 2]->ForeColor = color.Red;
					}
					else {
						buttons[7, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button67_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 3;
				int t = 0;
				if (Map.map[7][3].type == 1 || Map.map[7][3].type == -1) {
					King k(Map.map[7][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][3].type == 2 || Map.map[7][3].type == -2) {
					Guard k(Map.map[7][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][3].type == 3 || Map.map[7][3].type == -3) {
					Minister k(Map.map[7][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][3].type == 5 || Map.map[7][3].type == -5) {
					Horses k(Map.map[7][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][3].type == 4 || Map.map[7][3].type == -4) {
					Chariots k(Map.map[7][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][3].type == 6 || Map.map[7][3].type == -6) {
					Cannons k(Map.map[7][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][3].type == 7 || Map.map[7][3].type == -7) {
					Soldiers k(Map.map[7][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 3]->BackColor == color.Pink) {
					Map.map[7][3] = Map.map[startL.x][startL.y];
					buttons[7, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 3]->BackColor = color.White;
					if (Map.map[7][3].type < 0) {
						buttons[7, 3]->ForeColor = color.Red;
					}
					else {
						buttons[7, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button68_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 4;
				int t = 0;
				if (Map.map[7][4].type == 1 || Map.map[7][4].type == -1) {
					King k(Map.map[7][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][4].type == 2 || Map.map[7][4].type == -2) {
					Guard k(Map.map[7][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][4].type == 3 || Map.map[7][4].type == -3) {
					Minister k(Map.map[7][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][4].type == 5 || Map.map[7][4].type == -5) {
					Horses k(Map.map[7][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][4].type == 4 || Map.map[7][4].type == -4) {
					Chariots k(Map.map[7][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][4].type == 6 || Map.map[7][4].type == -6) {
					Cannons k(Map.map[7][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][4].type == 7 || Map.map[7][4].type == -7) {
					Soldiers k(Map.map[7][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 4]->BackColor == color.Pink) {
					Map.map[7][4] = Map.map[startL.x][startL.y];
					buttons[7, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 4]->BackColor = color.White;
					if (Map.map[7][4].type < 0) {
						buttons[7, 4]->ForeColor = color.Red;
					}
					else {
						buttons[7, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button69_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 5;
				int t = 0;
				if (Map.map[7][5].type == 1 || Map.map[7][5].type == -1) {
					King k(Map.map[7][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][5].type == 2 || Map.map[7][5].type == -2) {
					Guard k(Map.map[7][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][5].type == 3 || Map.map[7][5].type == -3) {
					Minister k(Map.map[7][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][5].type == 5 || Map.map[7][5].type == -5) {
					Horses k(Map.map[7][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][5].type == 4 || Map.map[7][5].type == -4) {
					Chariots k(Map.map[7][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][5].type == 6 || Map.map[7][5].type == -6) {
					Cannons k(Map.map[7][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][5].type == 7 || Map.map[7][5].type == -7) {
					Soldiers k(Map.map[7][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 5]->BackColor == color.Pink) {
					Map.map[7][5] = Map.map[startL.x][startL.y];
					buttons[7, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 5]->BackColor = color.White;
					if (Map.map[7][5].type < 0) {
						buttons[7, 5]->ForeColor = color.Red;
					}
					else {
						buttons[7, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button70_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 6;
				int t = 0;
				if (Map.map[7][6].type == 1 || Map.map[7][6].type == -1) {
					King k(Map.map[7][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][6].type == 2 || Map.map[7][6].type == -2) {
					Guard k(Map.map[7][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][6].type == 3 || Map.map[7][6].type == -3) {
					Minister k(Map.map[7][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][6].type == 5 || Map.map[7][6].type == -5) {
					Horses k(Map.map[7][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][6].type == 4 || Map.map[7][6].type == -4) {
					Chariots k(Map.map[7][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][6].type == 6 || Map.map[7][6].type == -6) {
					Cannons k(Map.map[7][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][6].type == 7 || Map.map[7][6].type == -7) {
					Soldiers k(Map.map[7][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 6]->BackColor == color.Pink) {
					Map.map[7][6] = Map.map[startL.x][startL.y];
					buttons[7, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 6]->BackColor = color.White;
					if (Map.map[7][6].type < 0) {
						buttons[7, 6]->ForeColor = color.Red;
					}
					else {
						buttons[7, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button71_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 7;
				int t = 0;
				if (Map.map[7][7].type == 1 || Map.map[7][7].type == -1) {
					King k(Map.map[7][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][7].type == 2 || Map.map[7][7].type == -2) {
					Guard k(Map.map[7][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][7].type == 3 || Map.map[7][7].type == -3) {
					Minister k(Map.map[7][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][7].type == 5 || Map.map[7][7].type == -5) {
					Horses k(Map.map[7][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][7].type == 4 || Map.map[7][7].type == -4) {
					Chariots k(Map.map[7][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][7].type == 6 || Map.map[7][7].type == -6) {
					Cannons k(Map.map[7][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][7].type == 7 || Map.map[7][7].type == -7) {
					Soldiers k(Map.map[7][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 7]->BackColor == color.Pink) {
					Map.map[7][7] = Map.map[startL.x][startL.y];
					buttons[7, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 7]->BackColor = color.White;
					if (Map.map[7][7].type < 0) {
						buttons[7, 7]->ForeColor = color.Red;
					}
					else {
						buttons[7, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button72_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 7;
				startL.y = 8;
				int t = 0;
				if (Map.map[7][8].type == 1 || Map.map[7][8].type == -1) {
					King k(Map.map[7][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][8].type == 2 || Map.map[7][8].type == -2) {
					Guard k(Map.map[7][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][8].type == 3 || Map.map[7][8].type == -3) {
					Minister k(Map.map[7][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][8].type == 5 || Map.map[7][8].type == -5) {
					Horses k(Map.map[7][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][8].type == 4 || Map.map[7][8].type == -4) {
					Chariots k(Map.map[7][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][8].type == 6 || Map.map[7][8].type == -6) {
					Cannons k(Map.map[7][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[7][8].type == 7 || Map.map[7][8].type == -7) {
					Soldiers k(Map.map[7][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(7, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[7, 8]->BackColor == color.Pink) {
					Map.map[7][8] = Map.map[startL.x][startL.y];
					buttons[7, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[7, 8]->BackColor = color.White;
					if (Map.map[7][8].type < 0) {
						buttons[7, 8]->ForeColor = color.Red;
					}
					else {
						buttons[7, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button73_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 0;
				int t = 0;
				if (Map.map[8][0].type == 1 || Map.map[8][0].type == -1) {
					King k(Map.map[8][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][0].type == 2 || Map.map[8][0].type == -2) {
					Guard k(Map.map[8][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][0].type == 3 || Map.map[8][0].type == -3) {
					Minister k(Map.map[8][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][0].type == 5 || Map.map[8][0].type == -5) {
					Horses k(Map.map[8][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][0].type == 4 || Map.map[8][0].type == -4) {
					Chariots k(Map.map[8][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][0].type == 6 || Map.map[8][0].type == -6) {
					Cannons k(Map.map[8][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][0].type == 7 || Map.map[8][0].type == -7) {
					Soldiers k(Map.map[8][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 0]->BackColor == color.Pink) {
					Map.map[8][0] = Map.map[startL.x][startL.y];
					buttons[8, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 0]->BackColor = color.White;
					if (Map.map[8][0].type < 0) {
						buttons[8, 0]->ForeColor = color.Red;
					}
					else {
						buttons[8, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button74_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 1;
				int t = 0;
				if (Map.map[8][1].type == 1 || Map.map[8][1].type == -1) {
					King k(Map.map[8][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][1].type == 2 || Map.map[8][1].type == -2) {
					Guard k(Map.map[8][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][1].type == 3 || Map.map[8][1].type == -3) {
					Minister k(Map.map[8][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][1].type == 5 || Map.map[8][1].type == -5) {
					Horses k(Map.map[8][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][1].type == 4 || Map.map[8][1].type == -4) {
					Chariots k(Map.map[8][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][1].type == 6 || Map.map[8][1].type == -6) {
					Cannons k(Map.map[8][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][1].type == 7 || Map.map[8][1].type == -7) {
					Soldiers k(Map.map[8][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 1]->BackColor == color.Pink) {
					Map.map[8][1] = Map.map[startL.x][startL.y];
					buttons[8, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 1]->BackColor = color.White;
					if (Map.map[8][1].type < 0) {
						buttons[8, 1]->ForeColor = color.Red;
					}
					else {
						buttons[8, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button75_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 2;
				int t = 0;
				if (Map.map[8][2].type == 1 || Map.map[8][2].type == -1) {
					King k(Map.map[8][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][2].type == 2 || Map.map[8][2].type == -2) {
					Guard k(Map.map[8][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][2].type == 3 || Map.map[8][2].type == -3) {
					Minister k(Map.map[8][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][2].type == 5 || Map.map[8][2].type == -5) {
					Horses k(Map.map[8][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][2].type == 4 || Map.map[8][2].type == -4) {
					Chariots k(Map.map[8][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][2].type == 6 || Map.map[8][2].type == -6) {
					Cannons k(Map.map[8][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][2].type == 7 || Map.map[8][2].type == -7) {
					Soldiers k(Map.map[8][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 2]->BackColor == color.Pink) {
					Map.map[8][2] = Map.map[startL.x][startL.y];
					buttons[8, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 2]->BackColor = color.White;
					if (Map.map[8][2].type < 0) {
						buttons[8, 2]->ForeColor = color.Red;
					}
					else {
						buttons[8, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button76_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 3;
				int t = 0;
				if (Map.map[8][3].type == 1 || Map.map[8][3].type == -1) {
					King k(Map.map[8][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][3].type == 2 || Map.map[8][3].type == -2) {
					Guard k(Map.map[8][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][3].type == 3 || Map.map[8][3].type == -3) {
					Minister k(Map.map[8][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][3].type == 5 || Map.map[8][3].type == -5) {
					Horses k(Map.map[8][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][3].type == 4 || Map.map[8][3].type == -4) {
					Chariots k(Map.map[8][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][3].type == 6 || Map.map[8][3].type == -6) {
					Cannons k(Map.map[8][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][3].type == 7 || Map.map[8][3].type == -7) {
					Soldiers k(Map.map[8][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 3]->BackColor == color.Pink) {
					Map.map[8][3] = Map.map[startL.x][startL.y];
					buttons[8, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 3]->BackColor = color.White;
					if (Map.map[8][3].type < 0) {
						buttons[8, 3]->ForeColor = color.Red;
					}
					else {
						buttons[8, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button77_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 4;
				int t = 0;
				if (Map.map[8][4].type == 1 || Map.map[8][4].type == -1) {
					King k(Map.map[8][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][4].type == 2 || Map.map[8][4].type == -2) {
					Guard k(Map.map[8][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][4].type == 3 || Map.map[8][4].type == -3) {
					Minister k(Map.map[8][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][4].type == 5 || Map.map[8][4].type == -5) {
					Horses k(Map.map[8][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][4].type == 4 || Map.map[8][4].type == -4) {
					Chariots k(Map.map[8][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][4].type == 6 || Map.map[8][4].type == -6) {
					Cannons k(Map.map[8][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][4].type == 7 || Map.map[8][4].type == -7) {
					Soldiers k(Map.map[8][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 4]->BackColor == color.Pink) {
					Map.map[8][4] = Map.map[startL.x][startL.y];
					buttons[8, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 4]->BackColor = color.White;
					if (Map.map[8][4].type < 0) {
						buttons[8, 4]->ForeColor = color.Red;
					}
					else {
						buttons[8, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button78_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 5;
				int t = 0;
				if (Map.map[8][5].type == 1 || Map.map[8][5].type == -1) {
					King k(Map.map[8][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][5].type == 2 || Map.map[8][5].type == -2) {
					Guard k(Map.map[8][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][5].type == 3 || Map.map[8][5].type == -3) {
					Minister k(Map.map[8][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][5].type == 5 || Map.map[8][5].type == -5) {
					Horses k(Map.map[8][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][5].type == 4 || Map.map[8][5].type == -4) {
					Chariots k(Map.map[8][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][5].type == 6 || Map.map[8][5].type == -6) {
					Cannons k(Map.map[8][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][5].type == 7 || Map.map[8][5].type == -7) {
					Soldiers k(Map.map[8][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 5]->BackColor == color.Pink) {
					Map.map[8][5] = Map.map[startL.x][startL.y];
					buttons[8, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 5]->BackColor = color.White;
					if (Map.map[8][5].type < 0) {
						buttons[8, 5]->ForeColor = color.Red;
					}
					else {
						buttons[8, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button79_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 6;
				int t = 0;
				if (Map.map[8][6].type == 1 || Map.map[8][6].type == -1) {
					King k(Map.map[8][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][6].type == 2 || Map.map[8][6].type == -2) {
					Guard k(Map.map[8][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][6].type == 3 || Map.map[8][6].type == -3) {
					Minister k(Map.map[8][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][6].type == 5 || Map.map[8][6].type == -5) {
					Horses k(Map.map[8][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][6].type == 4 || Map.map[8][6].type == -4) {
					Chariots k(Map.map[8][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][6].type == 6 || Map.map[8][6].type == -6) {
					Cannons k(Map.map[8][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][6].type == 7 || Map.map[8][6].type == -7) {
					Soldiers k(Map.map[8][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 6]->BackColor == color.Pink) {
					Map.map[8][6] = Map.map[startL.x][startL.y];
					buttons[8, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 6]->BackColor = color.White;
					if (Map.map[8][6].type < 0) {
						buttons[8, 6]->ForeColor = color.Red;
					}
					else {
						buttons[8, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button80_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 7;
				int t = 0;
				if (Map.map[8][7].type == 1 || Map.map[8][7].type == -1) {
					King k(Map.map[8][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][7].type == 2 || Map.map[8][7].type == -2) {
					Guard k(Map.map[8][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][7].type == 3 || Map.map[8][7].type == -3) {
					Minister k(Map.map[8][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][7].type == 5 || Map.map[8][7].type == -5) {
					Horses k(Map.map[8][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][7].type == 4 || Map.map[8][7].type == -4) {
					Chariots k(Map.map[8][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][7].type == 6 || Map.map[8][7].type == -6) {
					Cannons k(Map.map[8][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][7].type == 7 || Map.map[8][7].type == -7) {
					Soldiers k(Map.map[8][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 7]->BackColor == color.Pink) {
					Map.map[8][7] = Map.map[startL.x][startL.y];
					buttons[8, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 7]->BackColor = color.White;
					if (Map.map[8][7].type < 0) {
						buttons[8, 7]->ForeColor = color.Red;
					}
					else {
						buttons[8, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button81_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 8;
				startL.y = 8;
				int t = 0;
				if (Map.map[8][8].type == 1 || Map.map[8][8].type == -1) {
					King k(Map.map[8][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][8].type == 2 || Map.map[8][8].type == -2) {
					Guard k(Map.map[8][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][8].type == 3 || Map.map[8][8].type == -3) {
					Minister k(Map.map[8][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][8].type == 5 || Map.map[8][8].type == -5) {
					Horses k(Map.map[8][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][8].type == 4 || Map.map[8][8].type == -4) {
					Chariots k(Map.map[8][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][8].type == 6 || Map.map[8][8].type == -6) {
					Cannons k(Map.map[8][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[8][8].type == 7 || Map.map[8][8].type == -7) {
					Soldiers k(Map.map[8][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(8, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[8, 8]->BackColor == color.Pink) {
					Map.map[8][8] = Map.map[startL.x][startL.y];
					buttons[8, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[8, 8]->BackColor = color.White;
					if (Map.map[8][8].type < 0) {
						buttons[8, 8]->ForeColor = color.Red;
					}
					else {
						buttons[8, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button82_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 0;
				int t = 0;
				if (Map.map[9][0].type == 1 || Map.map[9][0].type == -1) {
					King k(Map.map[9][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][0].type == 2 || Map.map[9][0].type == -2) {
					Guard k(Map.map[9][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][0].type == 3 || Map.map[9][0].type == -3) {
					Minister k(Map.map[9][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][0].type == 5 || Map.map[9][0].type == -5) {
					Horses k(Map.map[9][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][0].type == 4 || Map.map[9][0].type == -4) {
					Chariots k(Map.map[9][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][0].type == 6 || Map.map[9][0].type == -6) {
					Cannons k(Map.map[9][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][0].type == 7 || Map.map[9][0].type == -7) {
					Soldiers k(Map.map[9][0].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 0, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 0]->BackColor == color.Pink) {
					Map.map[9][0] = Map.map[startL.x][startL.y];
					buttons[9, 0]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 0]->BackColor = color.White;
					if (Map.map[9][0].type < 0) {
						buttons[9, 0]->ForeColor = color.Red;
					}
					else {
						buttons[9, 0]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button83_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 1;
				int t = 0;
				if (Map.map[9][1].type == 1 || Map.map[9][1].type == -1) {
					King k(Map.map[9][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][1].type == 2 || Map.map[9][1].type == -2) {
					Guard k(Map.map[9][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][1].type == 3 || Map.map[9][1].type == -3) {
					Minister k(Map.map[9][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][1].type == 5 || Map.map[9][1].type == -5) {
					Horses k(Map.map[9][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][1].type == 4 || Map.map[9][1].type == -4) {
					Chariots k(Map.map[9][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][1].type == 6 || Map.map[9][1].type == -6) {
					Cannons k(Map.map[9][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][1].type == 7 || Map.map[9][1].type == -7) {
					Soldiers k(Map.map[9][1].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 1, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 1]->BackColor == color.Pink) {
					Map.map[9][1] = Map.map[startL.x][startL.y];
					buttons[9, 1]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 1]->BackColor = color.White;
					if (Map.map[9][1].type < 0) {
						buttons[9, 1]->ForeColor = color.Red;
					}
					else {
						buttons[9, 1]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button84_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 2;
				int t = 0;
				if (Map.map[9][2].type == 1 || Map.map[9][2].type == -1) {
					King k(Map.map[9][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][2].type == 2 || Map.map[9][2].type == -2) {
					Guard k(Map.map[9][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][2].type == 3 || Map.map[9][2].type == -3) {
					Minister k(Map.map[9][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][2].type == 5 || Map.map[9][2].type == -5) {
					Horses k(Map.map[9][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][2].type == 4 || Map.map[9][2].type == -4) {
					Chariots k(Map.map[9][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][2].type == 6 || Map.map[9][2].type == -6) {
					Cannons k(Map.map[9][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][2].type == 7 || Map.map[9][2].type == -7) {
					Soldiers k(Map.map[9][2].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 2, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 2]->BackColor == color.Pink) {
					Map.map[9][2] = Map.map[startL.x][startL.y];
					buttons[9, 2]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 2]->BackColor = color.White;
					if (Map.map[9][2].type < 0) {
						buttons[9, 2]->ForeColor = color.Red;
					}
					else {
						buttons[9, 2]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button85_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 3;
				int t = 0;
				if (Map.map[9][3].type == 1 || Map.map[9][3].type == -1) {
					King k(Map.map[9][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][3].type == 2 || Map.map[9][3].type == -2) {
					Guard k(Map.map[9][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][3].type == 3 || Map.map[9][3].type == -3) {
					Minister k(Map.map[9][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][3].type == 5 || Map.map[9][3].type == -5) {
					Horses k(Map.map[9][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][3].type == 4 || Map.map[9][3].type == -4) {
					Chariots k(Map.map[9][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][3].type == 6 || Map.map[9][3].type == -6) {
					Cannons k(Map.map[9][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][3].type == 7 || Map.map[9][3].type == -7) {
					Soldiers k(Map.map[9][3].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 3, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 3]->BackColor == color.Pink) {
					Map.map[9][3] = Map.map[startL.x][startL.y];
					buttons[9, 3]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 3]->BackColor = color.White;
					if (Map.map[9][3].type < 0) {
						buttons[9, 3]->ForeColor = color.Red;
					}
					else {
						buttons[9, 3]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button86_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 4;
				int t = 0;
				if (Map.map[9][4].type == 1 || Map.map[9][4].type == -1) {
					King k(Map.map[9][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][4].type == 2 || Map.map[9][4].type == -2) {
					Guard k(Map.map[9][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][4].type == 3 || Map.map[9][4].type == -3) {
					Minister k(Map.map[9][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][4].type == 5 || Map.map[9][4].type == -5) {
					Horses k(Map.map[9][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][4].type == 4 || Map.map[9][4].type == -4) {
					Chariots k(Map.map[9][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][4].type == 6 || Map.map[9][4].type == -6) {
					Cannons k(Map.map[9][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][4].type == 7 || Map.map[9][4].type == -7) {
					Soldiers k(Map.map[9][4].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 4, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 4]->BackColor == color.Pink) {
					Map.map[9][4] = Map.map[startL.x][startL.y];
					buttons[9, 4]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 4]->BackColor = color.White;
					if (Map.map[9][4].type < 0) {
						buttons[9, 4]->ForeColor = color.Red;
					}
					else {
						buttons[9, 4]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button87_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 5;
				int t = 0;
				if (Map.map[9][5].type == 1 || Map.map[9][5].type == -1) {
					King k(Map.map[9][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][5].type == 2 || Map.map[9][5].type == -2) {
					Guard k(Map.map[9][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][5].type == 3 || Map.map[9][5].type == -3) {
					Minister k(Map.map[9][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][5].type == 5 || Map.map[9][5].type == -5) {
					Horses k(Map.map[9][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][5].type == 4 || Map.map[9][5].type == -4) {
					Chariots k(Map.map[9][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][5].type == 6 || Map.map[9][5].type == -6) {
					Cannons k(Map.map[9][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][5].type == 7 || Map.map[9][5].type == -7) {
					Soldiers k(Map.map[9][5].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 5, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 5]->BackColor == color.Pink) {
					Map.map[9][5] = Map.map[startL.x][startL.y];
					buttons[9, 5]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 5]->BackColor = color.White;
					if (Map.map[9][5].type < 0) {
						buttons[9, 5]->ForeColor = color.Red;
					}
					else {
						buttons[9, 5]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
			if (Map.check() == 2) {
				p2Win = 1;
				this->Close();
			}
			else if (Map.check() == 1) {
				p1Win = 1;
				this->Close();
			}
		}
		System::Void button88_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 6;
				int t = 0;
				if (Map.map[9][6].type == 1 || Map.map[9][6].type == -1) {
					King k(Map.map[9][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][6].type == 2 || Map.map[9][6].type == -2) {
					Guard k(Map.map[9][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][6].type == 3 || Map.map[9][6].type == -3) {
					Minister k(Map.map[9][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][6].type == 5 || Map.map[9][6].type == -5) {
					Horses k(Map.map[9][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][6].type == 4 || Map.map[9][6].type == -4) {
					Chariots k(Map.map[9][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][6].type == 6 || Map.map[9][6].type == -6) {
					Cannons k(Map.map[9][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][6].type == 7 || Map.map[9][6].type == -7) {
					Soldiers k(Map.map[9][6].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 6, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 6]->BackColor == color.Pink) {
					Map.map[9][6] = Map.map[startL.x][startL.y];
					buttons[9, 6]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 6]->BackColor = color.White;
					if (Map.map[9][6].type < 0) {
						buttons[9, 6]->ForeColor = color.Red;
					}
					else {
						buttons[9, 6]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button89_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 7;
				int t = 0;
				if (Map.map[9][7].type == 1 || Map.map[9][7].type == -1) {
					King k(Map.map[9][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][7].type == 2 || Map.map[9][7].type == -2) {
					Guard k(Map.map[9][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][7].type == 3 || Map.map[9][7].type == -3) {
					Minister k(Map.map[9][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][7].type == 5 || Map.map[9][7].type == -5) {
					Horses k(Map.map[9][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][7].type == 4 || Map.map[9][7].type == -4) {
					Chariots k(Map.map[9][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][7].type == 6 || Map.map[9][7].type == -6) {
					Cannons k(Map.map[9][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][7].type == 7 || Map.map[9][7].type == -7) {
					Soldiers k(Map.map[9][7].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 7, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 7]->BackColor == color.Pink) {
					Map.map[9][7] = Map.map[startL.x][startL.y];
					buttons[9, 7]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 7]->BackColor = color.White;
					if (Map.map[9][7].type < 0) {
						buttons[9, 7]->ForeColor = color.Red;
					}
					else {
						buttons[9, 7]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void button90_Click(System::Object^ sender, System::EventArgs^ e) {
			clickTimes = (clickTimes == 0) ? 1 : 0;
			if (clickTimes == 1) {
				startL.x = 9;
				startL.y = 8;
				int t = 0;
				if (Map.map[9][8].type == 1 || Map.map[9][8].type == -1) {
					King k(Map.map[9][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][8].type == 2 || Map.map[9][8].type == -2) {
					Guard k(Map.map[9][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][8].type == 3 || Map.map[9][8].type == -3) {
					Minister k(Map.map[9][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][8].type == 5 || Map.map[9][8].type == -5) {
					Horses k(Map.map[9][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][8].type == 4 || Map.map[9][8].type == -4) {
					Chariots k(Map.map[9][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][8].type == 6 || Map.map[9][8].type == -6) {
					Cannons k(Map.map[9][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
				else if (Map.map[9][8].type == 7 || Map.map[9][8].type == -7) {
					Soldiers k(Map.map[9][8].type);
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							if (k.canMove(9, 8, i, j)) {
								buttons[i, j]->BackColor = color.Pink;
								buttons[i, j]->Visible = 1;
							}
						}
					}
				}
			}
			else {
				endL.x = 0;
				endL.y = 0;
				if (buttons[9, 8]->BackColor == color.Pink) {
					Map.map[9][8] = Map.map[startL.x][startL.y];
					buttons[9, 8]->Text = buttons[startL.x, startL.y]->Text;
					buttons[9, 8]->BackColor = color.White;
					if (Map.map[9][8].type < 0) {
						buttons[9, 8]->ForeColor = color.Red;
					}
					else {
						buttons[9, 8]->ForeColor = color.Blue;
					}
					Map.map[startL.x][startL.y].name = "";
					Map.map[startL.x][startL.y].type = 0;
					buttons[startL.x, startL.y]->BackColor = color.White;
					buttons[startL.x, startL.y]->Visible = 0;
					buttons[startL.x, startL.y]->Text = "";
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (buttons[i, j]->BackColor == color.Pink) {
							buttons[i, j]->BackColor = color.White;
							if (Map.map[i][j].type == 0) {
								buttons[i, j]->Visible = 0;
							}
						}
					}
				}
			}
		}
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		}
	};

	public ref class menu : public System::Windows::Forms::Form
	{
	public:
		menu(void) {
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~menu() {
			if (components){
				delete components;
			}
		}
	public: 
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void);
		
#pragma endregion
	public:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
			startGame = 1;
		}
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};

	public ref class EndGame : public System::Windows::Forms::Form
	{
	public:
		EndGame(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~EndGame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
		private: System::Void EndGame_Load(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
			startGame = 1;
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
