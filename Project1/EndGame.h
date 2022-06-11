//#pragma once
//
//namespace Project1 {
//
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//
//	/// <summary>
//	/// EndGame 的摘要
//	/// </summary>
//	public ref class EndGame : public System::Windows::Forms::Form
//	{
//	public:
//		EndGame(void)
//		{
//			InitializeComponent();
//			//
//			//TODO:  在此加入建構函式程式碼
//			//
//		}
//
//	protected:
//		/// <summary>
//		/// 清除任何使用中的資源。
//		/// </summary>
//		~EndGame()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//	private: System::Windows::Forms::Button^ button1;
//	private: System::Windows::Forms::Button^ button2;
//	protected:
//
//	protected:
//
//	private:
//		/// <summary>
//		/// 設計工具所需的變數。
//		/// </summary>
//		System::ComponentModel::Container^ components;
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
//		/// 這個方法的內容。
//		/// </summary>
//		void InitializeComponent(void)
//		{
//			this->button1 = (gcnew System::Windows::Forms::Button());
//			this->button2 = (gcnew System::Windows::Forms::Button());
//			this->SuspendLayout();
//			// 
//			// button1
//			// 
//			this->button1->Location = System::Drawing::Point(30, 168);
//			this->button1->Name = L"button1";
//			this->button1->Size = System::Drawing::Size(100, 30);
//			this->button1->TabIndex = 0;
//			this->button1->Text = L"再來一次";
//			this->button1->UseVisualStyleBackColor = true;
//			this->button1->Click += gcnew System::EventHandler(this, &EndGame::button1_Click);
//			// 
//			// button2
//			// 
//			this->button2->Location = System::Drawing::Point(156, 168);
//			System::Drawing::Image^ myImage = gcnew System::Drawing::Bitmap("2.png");
//			this->BackgroundImage = myImage;
//			this->button2->Name = L"button2";
//			this->button2->Size = System::Drawing::Size(100, 30);
//			this->button2->TabIndex = 1;
//			this->button2->Text = L"結束遊戲";
//			this->button2->UseVisualStyleBackColor = true;
//			this->button2->Click += gcnew System::EventHandler(this, &EndGame::button2_Click);
//			// 
//			// EndGame
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
//			this->
//			this->ClientSize = System::Drawing::Size(282, 253);
//			this->Controls->Add(this->button2);
//			this->Controls->Add(this->button1);
//			this->Name = L"EndGame";
//			this->Text = L"EndGame";
//			this->Load += gcnew System::EventHandler(this, &EndGame::EndGame_Load);
//			this->ResumeLayout(false);
//
//		}
//#pragma endregion
//	private: System::Void EndGame_Load(System::Object^ sender, System::EventArgs^ e) {
//	}
//	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
//		this->Close();
//		//startGame = 1;
//	}
//	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
//		this->Close();
//	}
//	};
//}
