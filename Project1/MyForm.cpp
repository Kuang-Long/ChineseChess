#include "MyForm.h"

using namespace Project1;

void MyForm::InitializeComponent() {
	Map.clear();
	p1Win = 0;
	p2Win = 0;
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
	buttons = gcnew array<Button^, 2>(10, 9);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			buttons[i, j] = (gcnew System::Windows::Forms::Button());
			buttons[i, j]->Location = Point(pos[i][j].x, pos[i][j].y);
			buttons[i, j]->UseVisualStyleBackColor = true;
			buttons[i, j]->Height = 60;
			buttons[i, j]->Width = 60;
			if (Map.map[i][j].type == 0) {
				buttons[i, j]->Visible = 0;
			}
			else if (Map.map[i][j].type < 0) {
				buttons[i, j]->ForeColor = color.Red;
			}
			else if (Map.map[i][j].type > 0) {
				buttons[i, j]->ForeColor = color.Blue;
			}
			buttons[i, j]->Text = gcnew String(Map.map[i][j].name.c_str());
		}
	}
	endGame = (gcnew System::Windows::Forms::Button());
	p1Surr = (gcnew System::Windows::Forms::Button());
	p2Surr = (gcnew System::Windows::Forms::Button());
	for (int i = 0; i < 9; i++) {
		buttons[1, i]->Visible = 0;
		buttons[4, i]->Visible = 0;
		buttons[5, i]->Visible = 0;
		buttons[8, i]->Visible = 0;
	}
	this->SuspendLayout();
	// 
	// endGame
	// 
	resources->ApplyResources(this->endGame, L"endGame");
	this->endGame->Name = L"endGame";
	this->endGame->UseVisualStyleBackColor = true;
	this->endGame->Text = "結束遊戲";
	this->endGame->Width = 100;
	this->endGame->Height = 100;
	this->endGame->Location = Point(700, 342);
	this->endGame->Click += gcnew System::EventHandler(this, &MyForm::endGame_Click);
	// 
	// p1Surr
	// 
	resources->ApplyResources(this->p1Surr, L"p1Surr");
	this->p1Surr->Name = L"p1Surr";
	this->p1Surr->UseVisualStyleBackColor = true;
	this->p1Surr->Text = "紅方投降";
	this->p1Surr->BackColor = color.Red;
	this->p1Surr->ForeColor = color.White;
	this->p1Surr->Width = 100;
	this->p1Surr->Height = 100;
	this->p1Surr->Location = Point(700, 192);
	this->p1Surr->Click += gcnew System::EventHandler(this, &MyForm::p1Surr_Click);
	// 
	// p2Surr
	// 
	resources->ApplyResources(this->p2Surr, L"p2Surr");
	this->p2Surr->Name = L"p2Surr";
	this->p2Surr->UseVisualStyleBackColor = true;
	this->p2Surr->Text = "藍方投降";
	this->p2Surr->BackColor = color.Blue;
	this->p2Surr->ForeColor = color.White;
	this->p2Surr->Width = 100;
	this->p2Surr->Height = 100;
	this->p2Surr->Location = Point(700, 492);
	this->p2Surr->Click += gcnew System::EventHandler(this, &MyForm::p2Surr_Click);
	// 
	// buttons[0, 0]
	// 
	resources->ApplyResources(this->buttons[0, 0], L"buttons[0, 0]");
	this->buttons[0, 0]->Name = L"buttons[0, 0]";
	this->buttons[0, 0]->UseVisualStyleBackColor = true;
	this->buttons[0, 0]->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
	// 
	// buttons[0, 1]
	// 
	resources->ApplyResources(this->buttons[0, 1], L"buttons[0, 1]");
	this->buttons[0, 1]->Name = L"buttons[0, 1]";
	this->buttons[0, 1]->UseVisualStyleBackColor = true;
	this->buttons[0, 1]->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
	// 
	// buttons[0, 2]
	// 
	resources->ApplyResources(this->buttons[0, 2], L"buttons[0, 2]");
	this->buttons[0, 2]->Name = L"buttons[0, 2]";
	this->buttons[0, 2]->UseVisualStyleBackColor = true;
	this->buttons[0, 2]->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
	// 
	// buttons[0, 3]
	// 
	resources->ApplyResources(this->buttons[0, 3], L"buttons[0, 3]");
	this->buttons[0, 3]->Name = L"buttons[0, 3]";
	this->buttons[0, 3]->UseVisualStyleBackColor = true;
	this->buttons[0, 3]->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
	// 
	// buttons[0, 4]
	// 
	resources->ApplyResources(this->buttons[0, 4], L"buttons[0, 4]");
	this->buttons[0, 4]->Name = L"buttons[0, 4]";
	this->buttons[0, 4]->UseVisualStyleBackColor = true;
	this->buttons[0, 4]->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
	// 
	// buttons[0, 5]
	// 
	resources->ApplyResources(this->buttons[0, 5], L"buttons[0, 5]");
	this->buttons[0, 5]->Name = L"buttons[0, 5]";
	this->buttons[0, 5]->UseVisualStyleBackColor = true;
	this->buttons[0, 5]->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
	// 
	// buttons[0, 6]
	// 
	resources->ApplyResources(this->buttons[0, 6], L"buttons[0, 6]");
	this->buttons[0, 6]->Name = L"buttons[0, 6]";
	this->buttons[0, 6]->UseVisualStyleBackColor = true;
	this->buttons[0, 6]->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
	// 
	// buttons[0, 7]
	// 
	resources->ApplyResources(this->buttons[0, 7], L"buttons[0, 7]");
	this->buttons[0, 7]->Name = L"buttons[0, 7]";
	this->buttons[0, 7]->UseVisualStyleBackColor = true;
	this->buttons[0, 7]->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
	// 
	// buttons[0, 8]
	// 
	resources->ApplyResources(this->buttons[0, 8], L"buttons[0, 8]");
	this->buttons[0, 8]->Name = L"buttons[0, 8]";
	this->buttons[0, 8]->UseVisualStyleBackColor = true;
	this->buttons[0, 8]->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
	// 
	// buttons[1, 0]
	// 
	resources->ApplyResources(this->buttons[1, 0], L"buttons[1, 0]");
	this->buttons[1, 0]->Name = L"buttons[1, 0]";
	this->buttons[1, 0]->UseVisualStyleBackColor = true;
	this->buttons[1, 0]->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
	// 
	// buttons[1, 1]
	// 
	resources->ApplyResources(this->buttons[1, 1], L"buttons[1, 1]");
	this->buttons[1, 1]->Name = L"buttons[1, 1]";
	this->buttons[1, 1]->UseVisualStyleBackColor = true;
	this->buttons[1, 1]->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
	// 
	// buttons[1, 2]
	// 
	resources->ApplyResources(this->buttons[1, 2], L"buttons[1, 2]");
	this->buttons[1, 2]->Name = L"buttons[1, 2]";
	this->buttons[1, 2]->UseVisualStyleBackColor = true;
	this->buttons[1, 2]->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
	// 
	// buttons[1, 3]
	// 
	resources->ApplyResources(this->buttons[1, 3], L"buttons[1, 3]");
	this->buttons[1, 3]->Name = L"buttons[1, 3]";
	this->buttons[1, 3]->UseVisualStyleBackColor = true;
	this->buttons[1, 3]->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
	// 
	// buttons[1, 4]
	// 
	resources->ApplyResources(this->buttons[1, 4], L"buttons[1, 4]");
	this->buttons[1, 4]->Name = L"buttons[1, 4]";
	this->buttons[1, 4]->UseVisualStyleBackColor = true;
	this->buttons[1, 4]->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
	// 
	// buttons[1, 5]
	// 
	resources->ApplyResources(this->buttons[1, 5], L"buttons[1, 5]");
	this->buttons[1, 5]->Name = L"buttons[1, 5]";
	this->buttons[1, 5]->UseVisualStyleBackColor = true;
	this->buttons[1, 5]->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
	// 
	// buttons[1, 6]
	// 
	resources->ApplyResources(this->buttons[1, 6], L"buttons[1, 6]");
	this->buttons[1, 6]->Name = L"buttons[1, 6]";
	this->buttons[1, 6]->UseVisualStyleBackColor = true;
	this->buttons[1, 6]->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
	// 
	// buttons[1, 7]
	// 
	resources->ApplyResources(this->buttons[1, 7], L"buttons[1, 7]");
	this->buttons[1, 7]->Name = L"buttons[1, 7]";
	this->buttons[1, 7]->UseVisualStyleBackColor = true;
	this->buttons[1, 7]->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
	// 
	// buttons[1, 8]
	// 
	resources->ApplyResources(this->buttons[1, 8], L"buttons[1, 8]");
	this->buttons[1, 8]->Name = L"buttons[1, 8]";
	this->buttons[1, 8]->UseVisualStyleBackColor = true;
	this->buttons[1, 8]->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
	// 
	// buttons[2, 0]
	// 
	resources->ApplyResources(this->buttons[2, 0], L"buttons[2, 0]");
	this->buttons[2, 0]->Name = L"buttons[2, 0]";
	this->buttons[2, 0]->UseVisualStyleBackColor = true;
	this->buttons[2, 0]->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
	// 
	// buttons[2, 1]
	// 
	resources->ApplyResources(this->buttons[2, 1], L"buttons[2, 1]");
	this->buttons[2, 1]->Name = L"buttons[2, 1]";
	this->buttons[2, 1]->UseVisualStyleBackColor = true;
	this->buttons[2, 1]->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
	// 
	// buttons[2, 2]
	// 
	resources->ApplyResources(this->buttons[2, 2], L"buttons[2, 2]");
	this->buttons[2, 2]->Name = L"buttons[2, 2]";
	this->buttons[2, 2]->UseVisualStyleBackColor = true;
	this->buttons[2, 2]->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
	// 
	// buttons[2, 3]
	// 
	resources->ApplyResources(this->buttons[2, 3], L"buttons[2, 3]");
	this->buttons[2, 3]->Name = L"buttons[2, 3]";
	this->buttons[2, 3]->UseVisualStyleBackColor = true;
	this->buttons[2, 3]->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
	// 
	// buttons[2, 4]
	// 
	resources->ApplyResources(this->buttons[2, 4], L"buttons[2, 4]");
	this->buttons[2, 4]->Name = L"buttons[2, 4]";
	this->buttons[2, 4]->UseVisualStyleBackColor = true;
	this->buttons[2, 4]->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
	// 
	// buttons[2, 5]
	// 
	resources->ApplyResources(this->buttons[2, 5], L"buttons[2, 5]");
	this->buttons[2, 5]->Name = L"buttons[2, 5]";
	this->buttons[2, 5]->UseVisualStyleBackColor = true;
	this->buttons[2, 5]->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
	// 
	// buttons[2, 6]
	// 
	resources->ApplyResources(this->buttons[2, 6], L"buttons[2, 6]");
	this->buttons[2, 6]->Name = L"buttons[2, 6]";
	this->buttons[2, 6]->UseVisualStyleBackColor = true;
	this->buttons[2, 6]->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
	// 
	// buttons[2, 7]
	// 
	resources->ApplyResources(this->buttons[2, 7], L"buttons[2, 7]");
	this->buttons[2, 7]->Name = L"buttons[2, 7]";
	this->buttons[2, 7]->UseVisualStyleBackColor = true;
	this->buttons[2, 7]->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
	// 
	// buttons[2, 8]
	// 
	resources->ApplyResources(this->buttons[2, 8], L"buttons[2, 8]");
	this->buttons[2, 8]->Name = L"buttons[2, 8]";
	this->buttons[2, 8]->UseVisualStyleBackColor = true;
	this->buttons[2, 8]->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
	// 
	// buttons[3, 0]
	// 
	resources->ApplyResources(this->buttons[3, 0], L"buttons[3, 0]");
	this->buttons[3, 0]->Name = L"buttons[3, 0]";
	this->buttons[3, 0]->UseVisualStyleBackColor = true;
	this->buttons[3, 0]->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
	// 
	// buttons[3, 1]
	// 
	resources->ApplyResources(this->buttons[3, 1], L"buttons[3, 1]");
	this->buttons[3, 1]->Name = L"buttons[3, 1]";
	this->buttons[3, 1]->UseVisualStyleBackColor = true;
	this->buttons[3, 1]->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
	// 
	// buttons[3, 2]
	// 
	resources->ApplyResources(this->buttons[3, 2], L"buttons[3, 2]");
	this->buttons[3, 2]->Name = L"buttons[3, 2]";
	this->buttons[3, 2]->UseVisualStyleBackColor = true;
	this->buttons[3, 2]->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
	// 
	// buttons[3, 3]
	// 
	resources->ApplyResources(this->buttons[3, 3], L"buttons[3, 3]");
	this->buttons[3, 3]->Name = L"buttons[3, 3]";
	this->buttons[3, 3]->UseVisualStyleBackColor = true;
	this->buttons[3, 3]->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
	// 
	//  buttons[3, 4]
	// 
	resources->ApplyResources(this->buttons[3, 4], L"buttons[3, 4]");
	this->buttons[3, 4]->Name = L"buttons[3, 4]";
	this->buttons[3, 4]->UseVisualStyleBackColor = true;
	this->buttons[3, 4]->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
	// 
	//  buttons[3, 5]
	// 
	resources->ApplyResources(this->buttons[3, 5], L"buttons[3, 5]");
	this->buttons[3, 5]->Name = L"buttons[3, 5]";
	this->buttons[3, 5]->UseVisualStyleBackColor = true;
	this->buttons[3, 5]->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
	// 
	//  buttons[3, 6]
	// 
	resources->ApplyResources(this->buttons[3, 6], L"buttons[3, 6]");
	this->buttons[3, 6]->Name = L"buttons[3, 6]";
	this->buttons[3, 6]->UseVisualStyleBackColor = true;
	this->buttons[3, 6]->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
	// 
	// buttons[3, 7]
	// 
	resources->ApplyResources(this->buttons[3, 7], L"buttons[3, 7]");
	this->buttons[3, 7]->Name = L"buttons[3, 7]";
	this->buttons[3, 7]->UseVisualStyleBackColor = true;
	this->buttons[3, 7]->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
	// 
	// buttons[3, 8]
	// 
	resources->ApplyResources(this->buttons[3, 8], L"buttons[3, 8]");
	this->buttons[3, 8]->Name = L"buttons[3, 8]";
	this->buttons[3, 8]->UseVisualStyleBackColor = true;
	this->buttons[3, 8]->Click += gcnew System::EventHandler(this, &MyForm::button36_Click);
	// 
	// buttons[4, 0]
	// 
	resources->ApplyResources(this->buttons[4, 0], L"buttons[4, 0]");
	this->buttons[4, 0]->Name = L"buttons[4, 0]";
	this->buttons[4, 0]->UseVisualStyleBackColor = true;
	this->buttons[4, 0]->Click += gcnew System::EventHandler(this, &MyForm::button37_Click);
	// 
	// buttons[4, 1]
	// 
	resources->ApplyResources(this->buttons[4, 1], L"buttons[4, 1]");
	this->buttons[4, 1]->Name = L"buttons[4, 1]";
	this->buttons[4, 1]->UseVisualStyleBackColor = true;
	this->buttons[4, 1]->Click += gcnew System::EventHandler(this, &MyForm::button38_Click);
	// 
	// buttons[4, 2]
	// 
	resources->ApplyResources(this->buttons[4, 2], L"buttons[4, 2]");
	this->buttons[4, 2]->Name = L"buttons[4, 2]";
	this->buttons[4, 2]->UseVisualStyleBackColor = true;
	this->buttons[4, 2]->Click += gcnew System::EventHandler(this, &MyForm::button39_Click);
	// 
	// buttons[4, 3]
	// 
	resources->ApplyResources(this->buttons[4, 3], L"buttons[4, 3]");
	this->buttons[4, 3]->Name = L"buttons[4, 3]";
	this->buttons[4, 3]->UseVisualStyleBackColor = true;
	this->buttons[4, 3]->Click += gcnew System::EventHandler(this, &MyForm::button40_Click);
	// 
	// buttons[4, 4]
	// 
	resources->ApplyResources(this->buttons[4, 4], L"buttons[4, 4]");
	this->buttons[4, 4]->Name = L"buttons[4, 4]";
	this->buttons[4, 4]->UseVisualStyleBackColor = true;
	this->buttons[4, 4]->Click += gcnew System::EventHandler(this, &MyForm::button41_Click);
	// 
	// buttons[4, 5]
	// 
	resources->ApplyResources(this->buttons[4, 5], L"buttons[4, 5]");
	this->buttons[4, 5]->Name = L"buttons[4, 5]";
	this->buttons[4, 5]->UseVisualStyleBackColor = true;
	this->buttons[4, 5]->Click += gcnew System::EventHandler(this, &MyForm::button42_Click);
	// 
	// buttons[4, 6]
	// 
	resources->ApplyResources(this->buttons[4, 6], L"buttons[4, 6]");
	this->buttons[4, 6]->Name = L"buttons[4, 6]";
	this->buttons[4, 6]->UseVisualStyleBackColor = true;
	this->buttons[4, 6]->Click += gcnew System::EventHandler(this, &MyForm::button43_Click);
	// 
	// buttons[4, 7]
	// 
	resources->ApplyResources(this->buttons[4, 7], L"buttons[4, 7]");
	this->buttons[4, 7]->Name = L"buttons[4, 7]";
	this->buttons[4, 7]->UseVisualStyleBackColor = true;
	this->buttons[4, 7]->Click += gcnew System::EventHandler(this, &MyForm::button44_Click);
	// 
	// buttons[4, 8]
	// 
	resources->ApplyResources(this->buttons[4, 8], L"buttons[4, 8]");
	this->buttons[4, 8]->Name = L"buttons[4, 8]";
	this->buttons[4, 8]->UseVisualStyleBackColor = true;
	this->buttons[4, 8]->Click += gcnew System::EventHandler(this, &MyForm::button45_Click);
	// 
	// buttons[5, 0]
	// 
	resources->ApplyResources(this->buttons[5, 0], L"buttons[5, 0]");
	this->buttons[5, 0]->Name = L"buttons[5, 0]";
	this->buttons[5, 0]->UseVisualStyleBackColor = true;
	this->buttons[5, 0]->Click += gcnew System::EventHandler(this, &MyForm::button46_Click);
	// 
	// buttons[5, 1]
	// 
	resources->ApplyResources(this->buttons[5, 1], L"buttons[5, 1]");
	this->buttons[5, 1]->Name = L"buttons[5, 1]";
	this->buttons[5, 1]->UseVisualStyleBackColor = true;
	this->buttons[5, 1]->Click += gcnew System::EventHandler(this, &MyForm::button47_Click);
	// 
	// buttons[5, 2]
	// 
	resources->ApplyResources(this->buttons[5, 2], L"buttons[5, 2]");
	this->buttons[5, 2]->Name = L"buttons[5, 2]";
	this->buttons[5, 2]->UseVisualStyleBackColor = true;
	this->buttons[5, 2]->Click += gcnew System::EventHandler(this, &MyForm::button48_Click);
	// 
	// buttons[5, 3]
	// 
	resources->ApplyResources(this->buttons[5, 3], L"buttons[5, 3]");
	this->buttons[5, 3]->Name = L"buttons[5, 3]";
	this->buttons[5, 3]->UseVisualStyleBackColor = true;
	this->buttons[5, 3]->Click += gcnew System::EventHandler(this, &MyForm::button49_Click);
	// 
	// buttons[5, 4]
	// 
	resources->ApplyResources(this->buttons[5, 4], L"buttons[5, 4]");
	this->buttons[5, 4]->Name = L"buttons[5, 4]";
	this->buttons[5, 4]->UseVisualStyleBackColor = true;
	this->buttons[5, 4]->Click += gcnew System::EventHandler(this, &MyForm::button50_Click);
	// 
	// buttons[5, 5]
	// 
	resources->ApplyResources(this->buttons[5, 5], L"buttons[5, 5]");
	this->buttons[5, 5]->Name = L"buttons[5, 5]";
	this->buttons[5, 5]->UseVisualStyleBackColor = true;
	this->buttons[5, 5]->Click += gcnew System::EventHandler(this, &MyForm::button51_Click);
	// 
	// buttons[5, 6]
	// 
	resources->ApplyResources(this->buttons[5, 6], L"buttons[5, 6]");
	this->buttons[5, 6]->Name = L"buttons[5, 6]";
	this->buttons[5, 6]->UseVisualStyleBackColor = true;
	this->buttons[5, 6]->Click += gcnew System::EventHandler(this, &MyForm::button52_Click);
	// 
	// buttons[5, 7]
	// 
	resources->ApplyResources(this->buttons[5, 7], L"buttons[5, 7]");
	this->buttons[5, 7]->Name = L"buttons[5, 7]";
	this->buttons[5, 7]->UseVisualStyleBackColor = true;
	this->buttons[5, 7]->Click += gcnew System::EventHandler(this, &MyForm::button53_Click);
	// 
	// buttons[5, 8]
	// 
	resources->ApplyResources(this->buttons[5, 8], L"buttons[5, 8]");
	this->buttons[5, 8]->Name = L"buttons[5, 8]";
	this->buttons[5, 8]->UseVisualStyleBackColor = true;
	this->buttons[5, 8]->Click += gcnew System::EventHandler(this, &MyForm::button54_Click);
	// 
	// buttons[6, 0]
	// 
	resources->ApplyResources(this->buttons[6, 0], L"buttons[6, 0]");
	this->buttons[6, 0]->Name = L"buttons[6, 0]";
	this->buttons[6, 0]->UseVisualStyleBackColor = true;
	this->buttons[6, 0]->Click += gcnew System::EventHandler(this, &MyForm::button55_Click);
	// 
	// buttons[6, 1]
	// 
	resources->ApplyResources(this->buttons[6, 1], L"buttons[6, 1]");
	this->buttons[6, 1]->Name = L"buttons[6, 1]";
	this->buttons[6, 1]->UseVisualStyleBackColor = true;
	this->buttons[6, 1]->Click += gcnew System::EventHandler(this, &MyForm::button56_Click);
	// 
	// buttons[6, 2]
	// 
	resources->ApplyResources(this->buttons[6, 2], L"buttons[6, 2]");
	this->buttons[6, 2]->Name = L"buttons[6, 2]";
	this->buttons[6, 2]->UseVisualStyleBackColor = true;
	this->buttons[6, 2]->Click += gcnew System::EventHandler(this, &MyForm::button57_Click);
	// 
	// buttons[6, 3]
	// 
	resources->ApplyResources(this->buttons[6, 3], L"buttons[6, 3]");
	this->buttons[6, 3]->Name = L"buttons[6, 3]";
	this->buttons[6, 3]->UseVisualStyleBackColor = true;
	this->buttons[6, 3]->Click += gcnew System::EventHandler(this, &MyForm::button58_Click);
	// 
	// buttons[6, 4]
	// 
	resources->ApplyResources(this->buttons[6, 4], L"buttons[6, 4]");
	this->buttons[6, 4]->Name = L"buttons[6, 4]";
	this->buttons[6, 4]->UseVisualStyleBackColor = true;
	this->buttons[6, 4]->Click += gcnew System::EventHandler(this, &MyForm::button59_Click);
	// 
	// buttons[6, 5]
	// 
	resources->ApplyResources(this->buttons[6, 5], L"buttons[6, 5]");
	this->buttons[6, 5]->Name = L"buttons[6, 5]";
	this->buttons[6, 5]->UseVisualStyleBackColor = true;
	this->buttons[6, 5]->Click += gcnew System::EventHandler(this, &MyForm::button60_Click);
	// 
	// buttons[6, 6]
	// 
	resources->ApplyResources(this->buttons[6, 6], L"buttons[6, 6]");
	this->buttons[6, 6]->Name = L"buttons[6, 6]";
	this->buttons[6, 6]->UseVisualStyleBackColor = true;
	this->buttons[6, 6]->Click += gcnew System::EventHandler(this, &MyForm::button61_Click);
	// 
	// buttons[6, 7]
	// 
	resources->ApplyResources(this->buttons[6, 7], L"buttons[6, 7]");
	this->buttons[6, 7]->Name = L"buttons[6, 7]";
	this->buttons[6, 7]->UseVisualStyleBackColor = true;
	this->buttons[6, 7]->Click += gcnew System::EventHandler(this, &MyForm::button62_Click);
	// 
	// buttons[6, 8]
	// 
	resources->ApplyResources(this->buttons[6, 8], L"buttons[6, 8]");
	this->buttons[6, 8]->Name = L"buttons[6, 8]";
	this->buttons[6, 8]->UseVisualStyleBackColor = true;
	this->buttons[6, 8]->Click += gcnew System::EventHandler(this, &MyForm::button63_Click);
	// 
	// buttons[7, 0]
	// 
	resources->ApplyResources(this->buttons[7, 0], L"buttons[7, 0]");
	this->buttons[7, 0]->Name = L"buttons[7, 0]";
	this->buttons[7, 0]->UseVisualStyleBackColor = true;
	this->buttons[7, 0]->Click += gcnew System::EventHandler(this, &MyForm::button64_Click);
	// 
	// buttons[7, 1]
	// 
	resources->ApplyResources(this->buttons[7, 1], L"buttons[7, 1]");
	this->buttons[7, 1]->Name = L"buttons[7, 1]";
	this->buttons[7, 1]->UseVisualStyleBackColor = true;
	this->buttons[7, 1]->Click += gcnew System::EventHandler(this, &MyForm::button65_Click);
	// 
	// buttons[7, 2]
	// 
	resources->ApplyResources(this->buttons[7, 2], L"buttons[7, 2]");
	this->buttons[7, 2]->Name = L"buttons[7, 2]";
	this->buttons[7, 2]->UseVisualStyleBackColor = true;
	this->buttons[7, 2]->Click += gcnew System::EventHandler(this, &MyForm::button66_Click);
	// 
	// buttons[7, 3]
	// 
	resources->ApplyResources(this->buttons[7, 3], L"buttons[7, 3]");
	this->buttons[7, 3]->Name = L"buttons[7, 3]";
	this->buttons[7, 3]->UseVisualStyleBackColor = true;
	this->buttons[7, 3]->Click += gcnew System::EventHandler(this, &MyForm::button67_Click);
	// 
	// buttons[7, 4]
	// 
	resources->ApplyResources(this->buttons[7, 4], L"buttons[7, 4]");
	this->buttons[7, 4]->Name = L"buttons[7, 4]";
	this->buttons[7, 4]->UseVisualStyleBackColor = true;
	this->buttons[7, 4]->Click += gcnew System::EventHandler(this, &MyForm::button68_Click);
	// 
	// buttons[7, 5]
	// 
	resources->ApplyResources(this->buttons[7, 5], L"buttons[7, 5]");
	this->buttons[7, 5]->Name = L"buttons[7, 5]";
	this->buttons[7, 5]->UseVisualStyleBackColor = true;
	this->buttons[7, 5]->Click += gcnew System::EventHandler(this, &MyForm::button69_Click);
	// 
	// buttons[7, 6]
	// 
	resources->ApplyResources(this->buttons[7, 6], L"buttons[7, 6]");
	this->buttons[7, 6]->Name = L"buttons[7, 6]";
	this->buttons[7, 6]->UseVisualStyleBackColor = true;
	this->buttons[7, 6]->Click += gcnew System::EventHandler(this, &MyForm::button70_Click);
	// 
	// buttons[7, 7]
	// 
	resources->ApplyResources(this->buttons[7, 7], L"buttons[7, 7]");
	this->buttons[7, 7]->Name = L"buttons[7, 7]";
	this->buttons[7, 7]->UseVisualStyleBackColor = true;
	this->buttons[7, 7]->Click += gcnew System::EventHandler(this, &MyForm::button71_Click);
	// 
	// buttons[7, 8]
	// 
	resources->ApplyResources(this->buttons[7, 8], L"buttons[7, 8]");
	this->buttons[7, 8]->Name = L"buttons[7, 8]";
	this->buttons[7, 8]->UseVisualStyleBackColor = true;
	this->buttons[7, 8]->Click += gcnew System::EventHandler(this, &MyForm::button72_Click);
	// 
	// buttons[8, 0]
	// 
	resources->ApplyResources(this->buttons[8, 0], L"buttons[8, 0]");
	this->buttons[8, 0]->Name = L"buttons[8, 0]";
	this->buttons[8, 0]->UseVisualStyleBackColor = true;
	this->buttons[8, 0]->Click += gcnew System::EventHandler(this, &MyForm::button73_Click);
	// 
	// buttons[8, 1]
	// 
	resources->ApplyResources(this->buttons[8, 1], L"buttons[8, 1]");
	this->buttons[8, 1]->Name = L"buttons[8, 1]";
	this->buttons[8, 1]->UseVisualStyleBackColor = true;
	this->buttons[8, 1]->Click += gcnew System::EventHandler(this, &MyForm::button74_Click);
	// 
	// buttons[8, 2]
	// 
	resources->ApplyResources(this->buttons[8, 2], L"buttons[8, 2]");
	this->buttons[8, 2]->Name = L"buttons[8, 2]";
	this->buttons[8, 2]->UseVisualStyleBackColor = true;
	this->buttons[8, 2]->Click += gcnew System::EventHandler(this, &MyForm::button75_Click);
	// 
	// buttons[8, 3]
	// 
	resources->ApplyResources(this->buttons[8, 3], L"buttons[8, 3]");
	this->buttons[8, 3]->Name = L"buttons[8, 3]";
	this->buttons[8, 3]->UseVisualStyleBackColor = true;
	this->buttons[8, 3]->Click += gcnew System::EventHandler(this, &MyForm::button76_Click);
	// 
	// buttons[8, 4]
	// 
	resources->ApplyResources(this->buttons[8, 4], L"buttons[8, 4]");
	this->buttons[8, 4]->Name = L"buttons[8, 4]";
	this->buttons[8, 4]->UseVisualStyleBackColor = true;
	this->buttons[8, 4]->Click += gcnew System::EventHandler(this, &MyForm::button77_Click);
	// 
	// buttons[8, 5]
	// 
	resources->ApplyResources(this->buttons[8, 5], L"buttons[8, 5]");
	this->buttons[8, 5]->Name = L"buttons[8, 5]";
	this->buttons[8, 5]->UseVisualStyleBackColor = true;
	this->buttons[8, 5]->Click += gcnew System::EventHandler(this, &MyForm::button78_Click);
	// 
	// buttons[8, 6]
	// 
	resources->ApplyResources(this->buttons[8, 6], L"buttons[8, 6]");
	this->buttons[8, 6]->Name = L"buttons[8, 6]";
	this->buttons[8, 6]->UseVisualStyleBackColor = true;
	this->buttons[8, 6]->Click += gcnew System::EventHandler(this, &MyForm::button79_Click);
	// 
	// buttons[8, 7]
	// 
	resources->ApplyResources(this->buttons[8, 7], L"buttons[8, 7]");
	this->buttons[8, 7]->Name = L"buttons[8, 7]";
	this->buttons[8, 7]->UseVisualStyleBackColor = true;
	this->buttons[8, 7]->Click += gcnew System::EventHandler(this, &MyForm::button80_Click);
	// 
	// buttons[8, 8]
	// 
	resources->ApplyResources(this->buttons[8, 8], L"buttons[8, 8]");
	this->buttons[8, 8]->Name = L"buttons[8, 8]";
	this->buttons[8, 8]->UseVisualStyleBackColor = true;
	this->buttons[8, 8]->Click += gcnew System::EventHandler(this, &MyForm::button81_Click);
	// 
	// buttons[9, 0]
	// 
	resources->ApplyResources(this->buttons[9, 0], L"buttons[9, 0]");
	this->buttons[9, 0]->Name = L"buttons[9, 0]";
	this->buttons[9, 0]->UseVisualStyleBackColor = true;
	this->buttons[9, 0]->Click += gcnew System::EventHandler(this, &MyForm::button82_Click);
	// 
	// buttons[9, 1]
	// 
	resources->ApplyResources(this->buttons[9, 1], L"buttons[9, 1]");
	this->buttons[9, 1]->Name = L"buttons[9, 1]";
	this->buttons[9, 1]->UseVisualStyleBackColor = true;
	this->buttons[9, 1]->Click += gcnew System::EventHandler(this, &MyForm::button83_Click);
	// 
	// buttons[9, 2]
	// 
	resources->ApplyResources(this->buttons[9, 2], L"buttons[9, 2]");
	this->buttons[9, 2]->Name = L"buttons[9, 2]";
	this->buttons[9, 2]->UseVisualStyleBackColor = true;
	this->buttons[9, 2]->Click += gcnew System::EventHandler(this, &MyForm::button84_Click);
	// 
	// buttons[9, 3]
	// 
	resources->ApplyResources(this->buttons[9, 3], L"buttons[9, 3]");
	this->buttons[9, 3]->Name = L"buttons[9, 3]";
	this->buttons[9, 3]->UseVisualStyleBackColor = true;
	this->buttons[9, 3]->Click += gcnew System::EventHandler(this, &MyForm::button85_Click);
	// 
	// buttons[9, 4]
	// 
	resources->ApplyResources(this->buttons[9, 4], L"buttons[9, 4]");
	this->buttons[9, 4]->Name = L"buttons[9, 4]";
	this->buttons[9, 4]->UseVisualStyleBackColor = true;
	this->buttons[9, 4]->Click += gcnew System::EventHandler(this, &MyForm::button86_Click);
	// 
	// buttons[9, 5]
	// 
	resources->ApplyResources(this->buttons[9, 5], L"buttons[9, 5]");
	this->buttons[9, 5]->Name = L"buttons[9, 5]";
	this->buttons[9, 5]->UseVisualStyleBackColor = true;
	this->buttons[9, 5]->Click += gcnew System::EventHandler(this, &MyForm::button87_Click);
	// 
	// buttons[9, 6]
	// 
	resources->ApplyResources(this->buttons[9, 6], L"buttons[9, 6]");
	this->buttons[9, 6]->Name = L"buttons[9, 6]";
	this->buttons[9, 6]->UseVisualStyleBackColor = true;
	this->buttons[9, 6]->Click += gcnew System::EventHandler(this, &MyForm::button88_Click);
	// 
	// buttons[9, 7]
	// 
	resources->ApplyResources(this->buttons[9, 7], L"buttons[9, 7]");
	this->buttons[9, 7]->Name = L"buttons[9, 7]";
	this->buttons[9, 7]->UseVisualStyleBackColor = true;
	this->buttons[9, 7]->Click += gcnew System::EventHandler(this, &MyForm::button89_Click);
	// 
	// buttons[9, 8]
	// 
	resources->ApplyResources(this->buttons[9, 8], L"buttons[9, 8]");
	this->buttons[9, 8]->Name = L"buttons[9, 8]";
	this->buttons[9, 8]->UseVisualStyleBackColor = true;
	this->buttons[9, 8]->Click += gcnew System::EventHandler(this, &MyForm::button90_Click);
	// 
	// MyForm
	// 
	resources->ApplyResources(this, L"$this");
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			this->Controls->Add(this->buttons[i, j]);
		}
	}
	this->Controls->Add(endGame);
	this->Controls->Add(p1Surr);
	this->Controls->Add(p2Surr);
	this->DoubleBuffered = true;
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->Name = L"MyForm";
	this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
	this->ResumeLayout(false);

}
void menu::InitializeComponent() {
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	// 
	// button1
	// 
	this->button1->Location = System::Drawing::Point(100, 50);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(100, 50);
	this->button1->TabIndex = 0;
	this->button1->Text = L"開始遊戲";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &menu::button1_Click);
	// 
	// button2
	// 
	this->button2->Location = System::Drawing::Point(100, 150);
	this->button2->Name = L"button2";
	this->button2->Size = System::Drawing::Size(100, 50);
	this->button2->TabIndex = 1;
	this->button2->Text = L"結束遊戲";
	this->button2->UseVisualStyleBackColor = true;
	this->button2->Click += gcnew System::EventHandler(this, &menu::button2_Click);
	// 
	// menu
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(282, 253);
	this->Controls->Add(this->button2);
	this->Controls->Add(this->button1);
	this->Name = L"menu";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"Menu";
	this->ResumeLayout(false);
}
void EndGame::InitializeComponent() {
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	// 
	// button1
	// 
	this->button1->Location = System::Drawing::Point(30, 168);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(100, 30);
	this->button1->TabIndex = 0;
	this->button1->Text = L"再來一次";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &EndGame::button1_Click);
	// 
	// button2
	// 
	this->button2->Location = System::Drawing::Point(156, 168);
	System::Drawing::Image^ myImage = gcnew System::Drawing::Bitmap("2.png");
	this->BackgroundImage = myImage;
	this->button2->Name = L"button2";
	this->button2->Size = System::Drawing::Size(100, 30);
	this->button2->TabIndex = 1;
	this->button2->Text = L"結束遊戲";
	this->button2->UseVisualStyleBackColor = true;
	this->button2->Click += gcnew System::EventHandler(this, &EndGame::button2_Click);
	// 
	// EndGame
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	this->ClientSize = System::Drawing::Size(282, 253);
	this->Controls->Add(this->button2);
	this->Controls->Add(this->button1);
	this->Name = L"EndGame";
	this->Text = L"恭喜!";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Load += gcnew System::EventHandler(this, &EndGame::EndGame_Load);
	this->ResumeLayout(false);
}