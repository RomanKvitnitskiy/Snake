#include "Game.h"

using namespace System;
using namespace System::Windows::Forms;

// точка входа
[STAThreadAttribute] 
void main(array<String^>^ args)
{
	// настройки для запуска формы
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// запускаем форму
	Snake::Game form;
	Application::Run(% form);
}

struct Vector2
{
	int x, y;
};

Vector2 direction; // snake direction
Vector2 positionFruit; // fruit position
Vector2 gameArea; // game area

// constructor
Snake::Game::Game(void)
{
	InitializeComponent();

	// play area size
	gameArea.x = 500;
	gameArea.y = 500;

	firstLaunch = true;
	NewGame();
}

/*---------------------------------------*/
// implementation of game actions
void Snake::Game::GeneratePositionFruit()
{
	// generate random fruit positions
	Random^ rand = gcnew Random();
	positionFruit.x = rand->Next(60, gameArea.x - 60); // 60 - смещение отноcительно боков формы
	positionFruit.y = rand->Next(150, gameArea.y - 150); // 150 - смещение верхней границы относительно верха формы

	// checking that the fruit was not created on the snake
	for (int i = 0; i < score; i++)
		if (positionFruit.x == Snake[i]->Location.X || positionFruit.y == Snake[i]->Location.Y)
			GeneratePositionFruit();

	// transform the values ​​to be a multiple of the step
	int tempX = positionFruit.x % step;
	positionFruit.x -= tempX;

	int tempY = positionFruit.y % step;
	positionFruit.y -= tempY;

	// assigning a position to the fruit
	fruit->Location = Point(positionFruit.x, positionFruit.y);

	// add fruit to the form
	this->Controls->Add(fruit);
}

void Snake::Game::Eating()
{
	// check head position and fruit position
	if (Snake[0]->Location.X == positionFruit.x && Snake[0]->Location.Y == positionFruit.y)
	{
		labelScore->Text = "Score: " + ++score;

		// add new element
		Snake[score] = gcnew PictureBox();
		Snake[score]->Location = Point(Snake[score - 1]->Location.X + step * direction.x, Snake[score - 1]->Location.Y - step * direction.y);
		Snake[score]->BackColor = Color::Blue;
		Snake[score]->Width = step;
		Snake[score]->Height = step;
		this->Controls->Add(Snake[score]);

		GeneratePositionFruit();
	}
}

void Snake::Game::Movement()
{
	// move each element of the snake
	for (int i = score; i >= 1; i--)
		Snake[i]->Location = Snake[i - 1]->Location;
	Snake[0]->Location = Point(Snake[0]->Location.X + direction.x * step, Snake[0]->Location.Y + direction.y * step);
}

void Snake::Game::EatYourSelf()
{
	// check the position of each part of the snake
	for (int i = 1; i < score; i++)
		if (Snake[0]->Location == Snake[i]->Location)
			GameOver();
}

void Snake::Game::GameOver()
{
	play = true;
	die = true;

	labelGameOver->Visible = true;
}

void Snake::Game::NewGame()
{
	// if initialization was removed all objects
	if (!firstLaunch)
	{
		this->Controls->Remove(fruit);

		for (int i = 0; i <= score; i++)
			this->Controls->Remove(Snake[i]);

		score = 0;
	}
	else 
	{
		firstLaunch = false;
	}

	// initialization of the snake
	Snake = gcnew array <PictureBox^, 1>(400);
	Snake[0] = gcnew PictureBox();
	Snake[0]->Location = Point(200, 200);
	Snake[0]->BackColor = Color::Yellow; 
	Snake[0]->Width = step;
	Snake[0]->Height = step;

	score = 0;
	this->Controls->Add(Snake[0]);

	// initialization of the fruit
	fruit = gcnew PictureBox();
	fruit->BackColor = Color::Red;
	fruit->Width = step;
	fruit->Height = step;
	GeneratePositionFruit();

	// set the update interval and start the timer for the update
	timer->Interval = updateInterval;
	timer->Start();

	// set direction at startup
	direction.x = 1;
	direction.y = 0;

	play = true;
	die = false;

	labelScore->Text = "Score: 0";

	// hide unnecessary components
	labelGameOver->Visible = false;
	groupBoxSettings->Visible = false;
}

void Snake::Game::CheckBorders()
{
	if (Snake[0]->Location.X >= RightBorder->Location.X || Snake[0]->Location.X <= LeftBorder->Location.X)
		GameOver();
	
	if (Snake[0]->Location.Y <= UpperBorder->Location.Y || Snake[0]->Location.Y >= LowerBorder->Location.Y)
		GameOver();
}

/*---------------------------------------*/
// Game events

System::Void Snake::Game::authorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Author: Kvitnytskyi Roman.\nGroup: CB-91", "Author");
	return System::Void();
}

System::Void Snake::Game::gameInfoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("The game copies the popular snake game\nThe main goal is to eat as much fruit as possible\nYou can't eat yourself and bump into a wall", "Game info");
	return System::Void();
}

System::Void Snake::Game::newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();
	return System::Void();
}

System::Void Snake::Game::pausecontinueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (play)
		play = false;
	else
	{
		play = true;
		timer->Start();
	}
	return System::Void();
}

System::Void Snake::Game::settingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (groupBoxSettings->Visible == false)
	{
		// stop game
		play = false;

		buttonApplySpeed->Enabled = true;
		numericUpDownSpeedSnake->Enabled = true;
		groupBoxSettings->Visible = true;
	}
	else
	{
		// start game
		play = true;
		timer->Start();

		buttonApplySpeed->Enabled = false;
		numericUpDownSpeedSnake->Enabled = false;
		groupBoxSettings->Visible = false;
	}
	return System::Void();
}

System::Void Snake::Game::buttonApplySpeed_Click(System::Object^ sender, System::EventArgs^ e)
{
	updateInterval = Convert::ToSingle(numericUpDownSpeedSnake->Value);
	timer->Interval = updateInterval;

	buttonApplySpeed->Enabled = false;
	numericUpDownSpeedSnake->Enabled = false;
	groupBoxSettings->Visible = false;

	// start game
	play = true;
	timer->Start();

	return System::Void();
}

System::Void Snake::Game::Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	// read keystrokes
	if (e->KeyCode.ToString() == "Right")
	{
		direction.x = 1;
		direction.y = 0;
	}
	else if (e->KeyCode.ToString() == "Left")
	{
		direction.x = -1;
		direction.y = 0;
	}
	else if (e->KeyCode.ToString() == "Up")
	{
		direction.x = 0;
		direction.y = -1;
	}
	else if (e->KeyCode.ToString() == "Down")
	{
		direction.x = 0;
		direction.y = 1;
	}

	return System::Void();
}

void Snake::Game::Game_update(Object^ object, EventArgs^ e)
{
	if (!die && play)
	{
		//sets the movement of the snake
		Movement();

		Eating(); //check for eaten fruit
		EatYourSelf(); // check for eaten yourself
		CheckBorders(); // collision check
	}
	else if (die && play)
	{
		timer->Stop();
		MessageBox::Show("Restart game?", "Game over", MessageBoxButtons::OK, MessageBoxIcon::Question);
		NewGame();
	}
	else if (!play && !die)
	{
		timer->Stop();
		MessageBox::Show("The game is stopped", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
