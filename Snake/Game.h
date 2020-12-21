#pragma once

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pausecontinueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ gameInfoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ authorToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBoxGameData;
	private: System::Windows::Forms::Label^ labelScore;
	private: System::Windows::Forms::GroupBox^ groupBoxSettings;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonApplySpeed;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSpeedSnake;
	private: System::Windows::Forms::PictureBox^ UpperBorder;
	private: System::Windows::Forms::PictureBox^ LowerBorder;
	private: System::Windows::Forms::PictureBox^ RightBorder;
	private: System::Windows::Forms::PictureBox^ LeftBorder;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ labelGameOver;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pausecontinueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->authorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxGameData = (gcnew System::Windows::Forms::GroupBox());
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->groupBoxSettings = (gcnew System::Windows::Forms::GroupBox());
			this->buttonApplySpeed = (gcnew System::Windows::Forms::Button());
			this->numericUpDownSpeedSnake = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UpperBorder = (gcnew System::Windows::Forms::PictureBox());
			this->LowerBorder = (gcnew System::Windows::Forms::PictureBox());
			this->RightBorder = (gcnew System::Windows::Forms::PictureBox());
			this->LeftBorder = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelGameOver = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBoxGameData->SuspendLayout();
			this->groupBoxSettings->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeedSnake))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpperBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LowerBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RightBorder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LeftBorder))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menuToolStripMenuItem,
					this->gameInfoToolStripMenuItem, this->authorToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(646, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newGameToolStripMenuItem,
					this->pausecontinueToolStripMenuItem, this->settingsToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			this->newGameToolStripMenuItem->Text = L"New game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::newGameToolStripMenuItem_Click);
			// 
			// pausecontinueToolStripMenuItem
			// 
			this->pausecontinueToolStripMenuItem->Name = L"pausecontinueToolStripMenuItem";
			this->pausecontinueToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			this->pausecontinueToolStripMenuItem->Text = L"Pause/continue";
			this->pausecontinueToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::pausecontinueToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			this->settingsToolStripMenuItem->Text = L"Settings";
			this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::settingsToolStripMenuItem_Click);
			// 
			// gameInfoToolStripMenuItem
			// 
			this->gameInfoToolStripMenuItem->Name = L"gameInfoToolStripMenuItem";
			this->gameInfoToolStripMenuItem->Size = System::Drawing::Size(92, 24);
			this->gameInfoToolStripMenuItem->Text = L"Game info";
			this->gameInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::gameInfoToolStripMenuItem_Click);
			// 
			// authorToolStripMenuItem
			// 
			this->authorToolStripMenuItem->Name = L"authorToolStripMenuItem";
			this->authorToolStripMenuItem->Size = System::Drawing::Size(68, 24);
			this->authorToolStripMenuItem->Text = L"Author";
			this->authorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::authorToolStripMenuItem_Click);
			// 
			// groupBoxGameData
			// 
			this->groupBoxGameData->Controls->Add(this->labelScore);
			this->groupBoxGameData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->groupBoxGameData->Location = System::Drawing::Point(12, 31);
			this->groupBoxGameData->Name = L"groupBoxGameData";
			this->groupBoxGameData->Size = System::Drawing::Size(143, 87);
			this->groupBoxGameData->TabIndex = 1;
			this->groupBoxGameData->TabStop = false;
			this->groupBoxGameData->Text = L"Game data";
			// 
			// labelScore
			// 
			this->labelScore->AutoSize = true;
			this->labelScore->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelScore->Location = System::Drawing::Point(6, 31);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(121, 36);
			this->labelScore->TabIndex = 2;
			this->labelScore->Text = L"Score: 0";
			// 
			// groupBoxSettings
			// 
			this->groupBoxSettings->Controls->Add(this->buttonApplySpeed);
			this->groupBoxSettings->Controls->Add(this->numericUpDownSpeedSnake);
			this->groupBoxSettings->Controls->Add(this->label2);
			this->groupBoxSettings->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxSettings->Location = System::Drawing::Point(147, 301);
			this->groupBoxSettings->Name = L"groupBoxSettings";
			this->groupBoxSettings->Size = System::Drawing::Size(391, 147);
			this->groupBoxSettings->TabIndex = 2;
			this->groupBoxSettings->TabStop = false;
			this->groupBoxSettings->Text = L"Settings";
			this->groupBoxSettings->Visible = false;
			// 
			// buttonApplySpeed
			// 
			this->buttonApplySpeed->Location = System::Drawing::Point(146, 84);
			this->buttonApplySpeed->Name = L"buttonApplySpeed";
			this->buttonApplySpeed->Size = System::Drawing::Size(84, 37);
			this->buttonApplySpeed->TabIndex = 4;
			this->buttonApplySpeed->Text = L"Apply";
			this->buttonApplySpeed->UseVisualStyleBackColor = true;
			this->buttonApplySpeed->Click += gcnew System::EventHandler(this, &Game::buttonApplySpeed_Click);
			// 
			// numericUpDownSpeedSnake
			// 
			this->numericUpDownSpeedSnake->Location = System::Drawing::Point(256, 29);
			this->numericUpDownSpeedSnake->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownSpeedSnake->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSpeedSnake->Name = L"numericUpDownSpeedSnake";
			this->numericUpDownSpeedSnake->Size = System::Drawing::Size(79, 31);
			this->numericUpDownSpeedSnake->TabIndex = 3;
			this->numericUpDownSpeedSnake->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(244, 21);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Enter the speed of the snake:";
			// 
			// UpperBorder
			// 
			this->UpperBorder->BackColor = System::Drawing::Color::Black;
			this->UpperBorder->Location = System::Drawing::Point(46, 150);
			this->UpperBorder->Name = L"UpperBorder";
			this->UpperBorder->Size = System::Drawing::Size(550, 10);
			this->UpperBorder->TabIndex = 3;
			this->UpperBorder->TabStop = false;
			// 
			// LowerBorder
			// 
			this->LowerBorder->BackColor = System::Drawing::Color::Black;
			this->LowerBorder->Location = System::Drawing::Point(46, 690);
			this->LowerBorder->Name = L"LowerBorder";
			this->LowerBorder->Size = System::Drawing::Size(550, 10);
			this->LowerBorder->TabIndex = 4;
			this->LowerBorder->TabStop = false;
			// 
			// RightBorder
			// 
			this->RightBorder->BackColor = System::Drawing::Color::Black;
			this->RightBorder->Location = System::Drawing::Point(586, 150);
			this->RightBorder->Name = L"RightBorder";
			this->RightBorder->Size = System::Drawing::Size(10, 550);
			this->RightBorder->TabIndex = 5;
			this->RightBorder->TabStop = false;
			// 
			// LeftBorder
			// 
			this->LeftBorder->BackColor = System::Drawing::Color::Black;
			this->LeftBorder->Location = System::Drawing::Point(46, 150);
			this->LeftBorder->Name = L"LeftBorder";
			this->LeftBorder->Size = System::Drawing::Size(10, 550);
			this->LeftBorder->TabIndex = 6;
			this->LeftBorder->TabStop = false;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Game::Game_update);
			// 
			// labelGameOver
			// 
			this->labelGameOver->AutoSize = true;
			this->labelGameOver->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGameOver->Location = System::Drawing::Point(229, 36);
			this->labelGameOver->Name = L"labelGameOver";
			this->labelGameOver->Size = System::Drawing::Size(179, 80);
			this->labelGameOver->TabIndex = 7;
			this->labelGameOver->Text = L"Game over!\r\nRestart game!";
			this->labelGameOver->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelGameOver->Visible = false;
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(646, 738);
			this->Controls->Add(this->labelGameOver);
			this->Controls->Add(this->LeftBorder);
			this->Controls->Add(this->RightBorder);
			this->Controls->Add(this->LowerBorder);
			this->Controls->Add(this->UpperBorder);
			this->Controls->Add(this->groupBoxSettings);
			this->Controls->Add(this->groupBoxGameData);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Snake";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxGameData->ResumeLayout(false);
			this->groupBoxGameData->PerformLayout();
			this->groupBoxSettings->ResumeLayout(false);
			this->groupBoxSettings->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeedSnake))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpperBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LowerBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RightBorder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LeftBorder))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		// ^ - управляемый класс
	/*---------------------------------------*/
	// game data
	private: PictureBox^ fruit; // fruit 
	private: array<PictureBox^>^ Snake; // snake
	private: bool play; // play
	private: bool die; // die
	private: bool firstLaunch; // first launch
	private: int step = 10; // step
	private: double updateInterval = 100; // update interval
	private: int score = 0; // score

	/*---------------------------------------*/
	// action games
	private: void GeneratePositionFruit(); // random fruit generation
	private: void Eating(); // checking whether we ate the fruit or not
	private: void Movement(); // for movement
	private: void EatYourSelf(); // check if she ate herself
	private: void GameOver(); // game over
	private: void NewGame(); // new game
	private: void CheckBorders(); // checking if we crashed

	 /*
		---------------------------------------------------------------------------------
		 Game events:
		---------------------------------------------------------------------------------
	*/

	// button click handlers
	private: System::Void authorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void gameInfoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pausecontinueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void settingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonApplySpeed_Click(System::Object^ sender, System::EventArgs^ e);

	// tracking keystrokes
	private: System::Void Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

	// game update indicated in timer
	private: void Game_update(Object^ object, EventArgs^ e);
};
}
