#include <iostream>
#include <cmath>
#include <locale>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <algorithm>
#include <sstream>
#pragma comment(lib, "user32")
#pragma comment(lib, "winmm.lib")

using namespace std;


//HD Lonewolf239
bool HB_Lonewolf239 = false;
int td_day, td_mon;
int bd_day = 4, bd_mon = 8;

//основные игровые параметры
RECT r;
POINT p;
bool GameOver = false, PlayerWin = false, Start = false, Language = true, First_start = true,
wall_killing = true, dangerous = true, tmer = false, de1eting_file = false,
help = true, wasd = true, OST = true;
const int width = 40, height = 20;
int x = height / 2, y = width / 2, FruitX = rand() % 19, FruitY = rand() % 39,
Super_FruitX = rand() % 19, Super_FruitY = rand() % 39, score = 0, level = 55, last_score_easily, last_score_medium,
last_score_hard, seconds = 5, dificult = 1, win;
float factor = 1.5;
float Super_Fruit_Spawn = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
float Super_Fruit_Spawn_Probability = static_cast<float>(0.2);
int tailX[350], tailY[350], nTail, direct;
enum nDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
nDirection dir;
string warning_key, space_score, factor_space,
off_on = " ON  ", yes_no = "YES            \033[0m4\033[36m|\n",
yes_no1 = "YES            \033[0m5\033[36m|\n", difficulty_level = "Normal         \033[0m3\033[36m|\n";

//костыли
void Setup();
void Draw();
void Logic();
void Input();
void Game_Over();
void Main_Menu();
void Warning();
void settings();
void records();
void Developer();
void Delete();
void soc_netw();

//main
int main() {
	system("mode con cols=130 lines=30");
	HWND consoleWindow = GetConsoleWindow();
	GetWindowRect(consoleWindow, &r);
	x = GetSystemMetrics(SM_CXSCREEN) / 2 - (r.right - r.left) / 2;
	y = GetSystemMetrics(SM_CYSCREEN) / 2 - (r.bottom - r.top) / 2;
	SetWindowPos(consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	HANDLE consoleHandle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD consoleMode;
	GetConsoleMode(consoleHandle, &consoleMode);
	SetConsoleMode(consoleHandle, consoleMode & ~(ENABLE_QUICK_EDIT_MODE | ENABLE_EXTENDED_FLAGS | ENABLE_INSERT_MODE));;
	time_t now = time(nullptr);
	tm local_time;
	localtime_s(&local_time, &now);
	td_day = local_time.tm_mday;
	td_mon = local_time.tm_mon + 1;
	if (td_day == bd_day && td_mon == bd_mon)
		HB_Lonewolf239 = true;
	srand(static_cast<unsigned int>(time(NULL)));
	setlocale(LC_CTYPE, "rus");
	system("cls");
	ifstream hightscoreE("C:/Windows/Temp/Hight_EScore.txt");
	if (hightscoreE.is_open())
		hightscoreE >> last_score_easily;
	hightscoreE.close();
	ifstream hightscoreM("C:/Windows/Temp/Hight_MScore.txt");
	if (hightscoreM.is_open())
		hightscoreM >> last_score_medium;
	hightscoreM.close();
	ifstream hightscoreH("C:/Windows/Temp/Hight_HScore.txt");
	if (hightscoreH.is_open())
		hightscoreH >> last_score_hard;
	hightscoreH.close();
	if (First_start) {
		GetCursorPos(&p);
		SetCursorPos(9000000, 9000000);
		BlockInput(true);
		ifstream key("C:/Windows/Temp/Warning_Disabling.txt");
		if (key.is_open())
			key >> warning_key;
		key.close();
		if (warning_key == "fCFjW0n|ZbuuGrkWCJl?gFShQW6?Hu2xiG?g")
			dangerous = false;
		ifstream deleting_file("C:/Windows/Temp/Hight_Score.txt");
		if (deleting_file.is_open()) {
			for (int i = 0; i < 2 + rand() % 3; i++) {
				cout << "The file system has been updated.\n"
						"Your file is no longer compatible.\n"
						"DELETING.";
				Sleep(200);
				system("cls");
				cout << "The file system has been updated.\n"
					"Your file is no longer compatible.\n"
					"DELETING..";
				Sleep(200);
				system("cls");
				cout << "The file system has been updated.\n"
					"Your file is no longer compatible.\n"
					"DELETING...";
				Sleep(200);
				system("cls");
			}
			deleting_file >> last_score_easily;
			de1eting_file = true;
		}
		deleting_file.close();
		if (de1eting_file) {
			if (remove("C:/Windows/Temp/Hight_Score.txt") == 0)
				cout << "SUCCESSFULLY DELETED"<< endl;
			else {
				cout << "ERROR DELETING"<< endl;
			}
			Sleep(1500);
			ofstream hightscore("C:/Windows/Temp/Hight_EScore.txt");
			if (hightscore.is_open())
				hightscore << last_score_easily;
			hightscore.close();
			de1eting_file = false;
		}
		system("cls");
		bool now_loading = true;
		int loading = 0, rand_loading = 0;
		while (now_loading) {
			rand_loading = 1 + rand() % 10;
			system("cls");
			cout << "WW   WW  EEEEE  LL       CCCC    OOOO   MM   MM  EEEEE\n"
				"WW   WW  EE     LL      CC  CC  OO  OO  MMM MMM  EE\n"
				"WW W WW  EEEE   LL      CC      OO  OO  MM M MM  EEEE\n"
				"WWWWWWW  EE     LL      CC  CC  OO  OO  MM   NN  EE\n"
				" WW WW   EEEEE  LLLLLL   CCCC    OOOO   MM   MM  EEEEE"
				<< endl << endl <<
				"IIIIII  NN  NN\n"
				"  II    NNN NN\n"
				"  II    NN NNN\n"
				"  II    NN  NN\n"
				"IIIIII  NN  NN"
				<< endl << endl <<
				" SSSS   NN  NN   AAAA   KK  KK  EEEEE\n"
				"SS      NNN NN  AA  AA  KK EE   EE\n"
				" SSSS   NN NNN  AAAAAA  KKKK    EEEE\n"
				"    SS  NN  NN  AA  AA  KK KK   EE\n"
				" SSSS   NN  NN  AA  AA  KK  KK  EEEEE\n\n"
				" GGGG    AAAA   MM   MM EEEEE\n"
				"GG      AA  AA  MMM MMM EE\n"
				"GG GGG  AAAAAA  MM M MM EEEE\n"
				"GG  GG  AA  AA  MM   MM EE\n"
				" GGGG   AA  AA  MM   MM EEEEE"
				<< endl << endl <<
				"VV  VV    11      55555\n"
				"VV  VV  1111      55\n"
				"VV  VV    11      55555\n"
				" VVVV     11          55\n"
				"  VV      11  **  55555"
				<< endl <<
				"\033[32mLoading " << loading << "% [";
			for (int j = 0; j <= 99; j++) {
				if (j <= loading)
					cout << "=";
				else
					cout << " ";
			}
			cout << "]\033[0m";
			Sleep(rand() % 300);
			loading += rand_loading;
			rand_loading = 1 + rand() % 20;
			if (loading >= 100) {
				loading = 100;
				system("cls");
				cout << "WW   WW  EEEEE  LL       CCCC    OOOO   MM   MM  EEEEE\n"
					"WW   WW  EE     LL      CC  CC  OO  OO  MMM MMM  EE\n"
					"WW W WW  EEEE   LL      CC      OO  OO  MM M MM  EEEE\n"
					"WWWWWWW  EE     LL      CC  CC  OO  OO  MM   NN  EE\n"
					" WW WW   EEEEE  LLLLLL   CCCC    OOOO   MM   MM  EEEEE"
					<< endl << endl <<
					"IIIIII  NN  NN\n"
					"  II    NNN NN\n"
					"  II    NN NNN\n"
					"  II    NN  NN\n"
					"IIIIII  NN  NN"
					<< endl << endl <<
					" SSSS   NN  NN   AAAA   KK  KK  EEEEE\n"
					"SS      NNN NN  AA  AA  KK EE   EE\n"
					" SSSS   NN NNN  AAAAAA  KKKK    EEEE\n"
					"    SS  NN  NN  AA  AA  KK KK   EE\n"
					" SSSS   NN  NN  AA  AA  KK  KK  EEEEE\n\n"
					" GGGG    AAAA   MM   MM EEEEE\n"
					"GG      AA  AA  MMM MMM EE\n"
					"GG GGG  AAAAAA  MM M MM EEEE\n"
					"GG  GG  AA  AA  MM   MM EE\n"
					" GGGG   AA  AA  MM   MM EEEEE"
					<< endl << endl <<
					"VV  VV    11      55555\n"
					"VV  VV  1111      55\n"
					"VV  VV    11      55555\n"
					" VVVV     11          55\n"
					"  VV      11  **  55555"
					<< endl <<
					"\033[32mLoading " << loading << "% [";
				for (int j = 0; j <= 98; j++) {
					if (j <= loading)
						cout << "=";
				}
				cout << "]\033[0m";
				now_loading = false;
				break;
			}
		}
		Sleep(1000);
		SetCursorPos(p.x, p.y);
		BlockInput(false);
		PlaySound(MAKEINTRESOURCE(1), GetModuleHandle(NULL), SND_RESOURCE | SND_LOOP | SND_ASYNC);
	}
	Setup();
	Main_Menu();
	while (!GameOver && Start) {
		Draw();
		Logic();
		Input();
	}
	if (GameOver)
		Game_Over();
	return 0;
}
//начальная установка
void Setup() {
	x = height / 2, y = width / 2, Super_Fruit_Spawn = static_cast<float>(rand()) / static_cast<float>(RAND_MAX), FruitX = rand() % 19, FruitY = rand() % 39, Super_FruitX = rand() % 19, Super_FruitY = rand() % 39, score = 0;
	First_start = false;
	PlayerWin = false;
	Start = false;
	GameOver = false;
	nTail = 0;
	dir = STOP;
}
//рисовалка
void Draw() {
	system("cls");
	cout << "\033[36m|=========== \033[31mSnake_Game_v1.5\033[36m ===========|\033[0m\n";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			for (int k = 0; k < nTail; k++) {
				if (tailX[k] == FruitY && tailY[k] == FruitX)
					FruitX = rand() % 19, FruitY = rand() % 39;
				if (tailX[k] == Super_FruitY && tailY[k] == Super_FruitX)
					Super_FruitX = rand() % 19, Super_FruitY = rand() % 39;
			}
			if (j == 0 || j == width - 1)
				cout << "\033[36m|\033[0m";
			if (i == x && j == y)
				cout << "\033[33mS\033[0m";
			else if (i == FruitX && j == FruitY)
				cout << "\033[32mf\033[0m";
			else if (i == Super_FruitX && j == Super_FruitY && Super_Fruit_Spawn <= Super_Fruit_Spawn_Probability)
				cout << "\033[32mF\033[0m";
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						cout << "\033[33ms\033[0m";
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "\033[36m|=======================================|\n";
	if (Language) {
		cout << "|\033[0mScore: \033[33m" << score << space_score;
		if (level == 100)
			cout << "|\033[0mDifficulty: \033[33mEasy                       \033[36m|\n";
		if (level == 55)
			cout << "|\033[0mDifficulty: \033[33mNormal                     \033[36m|\n";
		if (level == 25)
			cout << "|\033[0mDifficulty: \033[33mHard                       \033[36m|\n";
		if (wall_killing)
			cout << "|\033[0mWalls kill: \033[33mYES                        \033[36m|\n";
		if (!wall_killing)
			cout << "|\033[0mWalls kill: \033[33mNO                         \033[36m|\n";
		cout << "|=======================================|\033[0m\n";
		if (help) {
			cout << "\033[36m|\033[32mf - Fruit (+1 pt)                      \033[36m|\n"	\
				"|\033[32mF - Super Fruit (+10 pt)               \033[36m|\n"				\
				"|\033[32mMovement: WASD\\Arrows       Exit: ESC\\X\033[36m|\n"			\
				"|=======================================|\033[0m";
		}
	}
	if (!Language) {
		cout << "|\033[0mСчёт: \033[33m" << score << space_score;
		if (level == 100)
			cout << "|\033[0mСложность: \033[33mЛегко                       \033[36m|\n";
		if (level == 55)
			cout << "|\033[0mСложность: \033[33mНормально                   \033[36m|\n";
		if (level == 25)
			cout << "|\033[0mСложность: \033[33mСложно                      \033[36m|\n";
		if (wall_killing)
			cout << "|\033[0mСтены убивают: \033[33mДА                      \033[36m|\n";
		if (!wall_killing)
			cout << "|\033[0mСтены убивают: \033[33mНЕТ                     \033[36m|\n";
		cout << "|=======================================|\033[0m\n";
		if (help) {
			cout << "\033[36m|\033[32mf - Фрукт (+1 pt)                      \033[36m|\n"	\
				"|\033[32mF - Супер Фрукт (+10 pt)               \033[36m|\n"				\
				"|\033[32mДвижение: WASD\\Стрелочки   Выйти: ESC\\X\033[36m|\n"				\
				"|=======================================|\033[0m";
		}
	}
	Sleep(level);
}
//логика игры
void Logic() {
	int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
	tailX[0] = y;
	tailY[0] = x;
	switch (dir) {
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	}
	for (int i = 0; i < nTail; i++) {
		if (x == tailY[i] && tailX[i] == y)
			GameOver = true;
	}
	if (wall_killing) {
		if (x > height - 1 || x < 0 || y > width - 2 || y < 0)
			GameOver = true;
	}
	if (!wall_killing) {
		if (x > height - 1)
			x = 0;
		if (x < 0)
			x = height - 1;
		if (y > width - 2)
			y = 0;
		if (y < 0)
			y = width - 2;
	}
	if (x == FruitX && y == FruitY) {
		score++;
		if (score >= 300) {
			win = 2 + rand() % 3;
			GameOver = true;
			PlayerWin = true;
		}
		nTail++;
		FruitX = rand() % 19, FruitY = rand() % 39;
		Super_FruitX = rand() % 19, Super_FruitY = rand() % 39;
		Super_Fruit_Spawn = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	}
	if (x == Super_FruitX && y == Super_FruitY) {
		if (Super_Fruit_Spawn <= Super_Fruit_Spawn_Probability) {
			score += 10;
			if (score >= 300) {
				win = 2 + rand() % 3;
				GameOver = true;
				PlayerWin = true;
			}
			nTail++;
			FruitX = rand() % 19, FruitY = rand() % 39;
			Super_Fruit_Spawn = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		}
		Super_FruitX = rand() % 19, Super_FruitY = rand() % 39;
	}
	if (FruitX == Super_FruitX && FruitY == Super_FruitY && Super_Fruit_Spawn <= Super_Fruit_Spawn_Probability)
		FruitX = rand() % 19, FruitY = rand() % 39;
	if (Language) {
		if (score < 10)
			space_score = "                               \033[36m|\n";
		else if (score >= 10 && score < 100)
			space_score = "                              \033[36m|\n";
		else
			space_score = "                             \033[36m|\n";
	}
	else {
		if (score < 10)
			space_score = "                                \033[36m|\n";
		else if (score >= 10 && score < 100)
			space_score = "                               \033[36m|\n";
		else
			space_score = "                              \033[36m|\n";
	}
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i], prev2Y = tailY[i];
		tailX[i] = prevX, tailY[i] = prevY;
		prevX = prev2X, prevY = prev2Y;
	}
}
//управление
void Input() {
	if (_kbhit()) {
		direct = _getch();
		if (direct == 224)
			direct = _getch();
		if (direct == 65 || direct == 97 || direct == 228 || direct == 148 || direct == 75) {
			if (dir == RIGHT)
				return;
			dir = LEFT;
		}
		if (direct == 68 || direct == 100 || direct == 162 || direct == 130 || direct == 77) {
			if (dir == LEFT)
				return;
			dir = RIGHT;
		}
		if (direct == 83 || direct == 115 || direct == 235 || direct == 155 || direct == 80) {
			if (dir == UP)
				return;
			dir = DOWN;
		}
		if (direct == 87 || direct == 119 || direct == 230 || direct == 150 || direct == 72) {
			if (dir == DOWN)
				return;
			dir = UP;
		}
		if (direct == 27 || direct ==  120 || direct == 88 || direct == 231 || direct == 151) {
			GameOver = true;
		}
	}
}
//конец игры
void Game_Over() {
	system("cls");
	int _score = score;
	string old_score, new_score, string_factor;
	if (score < 10) {
		if(Language)
		old_score = "|\033[0mInitial score:\033[33m      ";
		else
			old_score = "|\033[0mНачальный счёт:\033[33m     ";
	}
	else if (score >= 10 && score < 100) {
		if (Language)
			old_score = "|\033[0mInitial score:\033[33m     ";
		else
			old_score = "|\033[0mНачальный счёт:\033[33m    ";
	}
	else if (score >= 100 && score < 1000) {
		if (Language)
			old_score = "|\033[0mInitial score:\033[33m    ";
		else
			old_score = "|\033[0mНачальный счёт:\033[33m   ";
	}
	else {
		if (Language)
			old_score = "|\033[0mInitial score:\033[33m   ";
		else
			old_score = "|\033[0mНачальный счёт:\033[33m  ";
	}
	if (PlayerWin)
		factor *= win;
	score *= factor;
	if (factor == 0.5 || factor == 1.5 || factor == 2.5 || factor == 3.5 || factor == 4.5 || factor == 5.5 || factor == 6.5) {
		if (Language)
			string_factor = "|\033[0mDiffic. facror:\033[33m  x";
		else
			string_factor = "|\033[0mКоэф. сложности:\033[33m x";
	}
	else if (factor < 10) {
		if (Language)
			string_factor = "|\033[0mDiffic. facror:\033[33m    x";
		else
			string_factor = "|\033[0mКоэф. сложности:\033[33m   x";
	}
	else if (factor < 100) {
		if (Language)
			string_factor = "|\033[0mDiffic. facror:\033[33m   x";
		else
			string_factor = "|\033[0mКоэф. сложности:\033[33m  x";
	}
	else {
		if (Language)
			string_factor = "|\033[0mDiffic. facror:\033[33m  x";
		else
			string_factor = "|\033[0mКоэф. сложности:\033[33m x";
	}
	if (score < 10) {
		if (Language)
			new_score = "|\033[0mYour score:\033[33m         ";
		else
			new_score = "|\033[0mТвой счёт:\033[33m          ";
	}
	else if (score < 100) {
		if (Language)
			new_score = "|\033[0mYour score:\033[33m        ";
		else
			new_score = "|\033[0mТвой счёт:\033[33m         ";
	}
	else if (score < 1000) {
		if (Language)
			new_score = "|\033[0mYour score:\033[33m       ";
		else
			new_score = "|\033[0mТвой счёт:\033[33m        ";
	}
	else if (score < 10000) {
		if (Language)
			new_score = "|\033[0mYour score:\033[33m      ";
		else
			new_score = "|\033[0mТвой счёт:\033[33m       ";
	}
	else {
		if (Language)
			new_score = "|\033[0mYour score:\033[33m     ";
		else
			new_score = "|\033[0mТвой счёт:\033[33m      ";
	}
	if (Language)
		cout << "\033[36m|=====================|\n"
		"|\033[31m      GAME OVER      \033[36m|\n"
		"|=====================|\n"
		<< old_score << _score << "\033[36m|\n"
		<< string_factor << factor << "\033[36m|\n"
		<< new_score << score << "\033[36m|\n"
		"|=====================|\n"
		"|\033[33mPress any key...     \033[36m|\n"
		"|=====================|\033[0m";
	else
		cout << "\033[36m|=====================|\n"
		"|\033[31m      GAME OVER      \033[36m|\n"
		"|=====================|\n"
		<< old_score << _score << "\033[36m|\n"
		<< string_factor << factor << "\033[36m|\n"
		<< new_score << score << "\033[36m|\n"
		"|=====================|\n"
		"|\033[33mPress any key...     \033[36m|\n"
		"|=====================|\033[0m";
	if (dificult == 0) {
		if (wall_killing)
			factor = 1;
		else
			factor = 0.5;
		if (score > last_score_easily) {
			ofstream hightscore("C:/Windows/Temp/Hight_EScore.txt");
			if (hightscore.is_open())
				hightscore << score;
			hightscore.close();
		}
	}
	if (dificult == 1) {
		if (wall_killing)
			factor = 1.5;
		else
			factor = 1;
		if (score > last_score_medium) {
			ofstream hightscore("C:/Windows/Temp/Hight_MScore.txt");
			if (hightscore.is_open())
				hightscore << score;
			hightscore.close();
		}
	}
	if (dificult == 2) {
		if (wall_killing)
			factor = 2;
		else
			factor = 1.5;
		if (score > last_score_hard) {
			ofstream hightscore("C:/Windows/Temp/Hight_HScore.txt");
			if (hightscore.is_open())
				hightscore << score;
			hightscore.close();
		}
	}
	system("pause >NUL");
	Start = false;
	main();
}
//главное меню
void Main_Menu() {
	while (!Start) {
		system("cls");
		if (Language) {
			cout << "\033[36m|==== \033[31mSnake_Game_v1.5\033[36m ====|\n";
			if (HB_Lonewolf239)
				cout <<
				"|\033[33m   Happy Birthday,       \033[36m|\n"			\
				"|\033[33m          Lonewolf239!   \033[36m|\n"			\
				"|=========================|\n";
			cout << "|        Main menu        |\n"						\
				"|=========================|\n"							\
				"|\033[0mStart:                  1\033[36m|\n"			\
				"|\033[0mRecords:                2\033[36m|\n"			\
				"|\033[0mAbout the developers:   3\033[36m|\n"			\
				"|\033[0mSettings:               4\033[36m|\n"			\
				"|=========================|\n"							\
				"|\033[0mTelegram:               6\033[36m|\n"			\
				"|\033[0mDelete game data:       7\033[36m|\n"			\
				"|=========================|\n"							\
				"|\033[0mBug report:         Space\033[36m|\n"			\
				"|\033[0mQuit game:            ESC\033[36m|\n"			\
				"|=========================|\033[0m\n";
		}
		else {
			cout << "\033[36m|==== \033[31mSnake_Game_v1.5\033[36m ====|\n";
			if (HB_Lonewolf239)
				cout << "|\033[33m   С Днём Рождения,      \033[36m|\n"	\
				"|\033[33m          Lonewolf239!   \033[36m|\n"			\
				"|=========================|\n";

			cout << "|      Главное меню       |\n"						\
				"|=========================|\n"							\
				"|\033[0mСтарт:                  1\033[36m|\n"			\
				"|\033[0mРекорды:                2\033[36m|\n"			\
				"|\033[0mО разработчиках:        3\033[36m|\n"			\
				"|\033[0mНастройки:              4\033[36m|\n"			\
				"|=========================|\n"							\
				"|\033[0mTelegram:               6\033[36m|\n"			\
				"|\033[0mУдалить игровые файлы:  7\033[36m|\n"			\
				"|=========================|\n"							\
				"|\033[0mBug report:         Space\033[36m|\n"			\
				"|\033[0mВыйти из игры:        ESC\033[36m|\n"			\
				"|=========================|\033[0m\n";
		}
		int choice = _getch();
		switch (choice) {
		case 49:
			if (Language)
				space_score = "                              \033[36m|\n";
			else
				space_score = "                                \033[36m|\n";
			if (level == 100) {
				if (wall_killing)
					factor = 1;
				else
					factor = 0.5;
			}
			if (level == 55) {
				if (wall_killing)
					factor = 1.5;
				else
					factor = 1;
			}
			if (level == 25) {
				if (wall_killing)
					factor = 2;
				else
					factor = 1.5;
			}
			if (dangerous)
				Warning();
			else {
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				CONSOLE_CURSOR_INFO structCursorInfo;
				GetConsoleCursorInfo(handle, &structCursorInfo);
				structCursorInfo.bVisible = FALSE;
				SetConsoleCursorInfo(handle, &structCursorInfo);
				Start = true;
			}
			break;
		case 50:
			records();
			break;
		case 51:
			Developer();
			break;
		case 52:
			settings();
			break;
		case 54:
			system("explorer https://t.me/+VLJzjVRg8ElkZWYy");
			break;
		case 55:
			Delete();
			break;
		case 32:
			system("explorer https://t.me/Lonewolf239_BugReportBOT");
			break;
		case 27:
			exit(0);
			break;
		case 124:
			system("cls");
			if (!Language)
				cout << "Как ты это нашёл? Методом тыка? А может глянул в коде...\nВведите коэффициент (max 5): ";
			if (Language)
				cout << "How did you find it? Poke method? Or maybe you looked in the code...\nEnter the coefficient (max 5): ";
			cin >> factor;
			if (factor == 666) {
				Start = true;
				break;
			}
			if (factor < 0)
				factor = 0;
			if (factor > 5)
				factor = 5;
			Start = true;
			break;
		}
	}
}
//предупреждение
void Warning() {
	GetCursorPos(&p);
	SetCursorPos(9000000, 9000000);
	BlockInput(true);
	bool next = false;
	tmer = true;
	while (tmer) {
		system("cls");
		if (Language)
			cout << "\033[36m|=======================================|\n"					\
			"|\033[31m                WARNING                \033[36m|\n"					\
			"|=======================================|\n"									\
			"|\033[0mIn this game, the graphics are in the  \033[36m|\n"					\
			"|\033[0mform of symbols and flicker constantly.\033[36m|\n"					\
			"|\033[0mAs a result of which it can be         \033[36m|\n"					\
			"|\033[0mdangerous for people with epilepsy.    \033[36m|\n"					\
			"|\033[0mIf you have epilepsy,                  \033[36m|\n"					\
			"|\033[0mI ask you to close this application    \033[36m|\n"					\
			"|\033[0mfor your own safety.                   \033[36m|\n"					\
			"|\033[0mThanks.                                \033[36m|\n"					\
			"|\033[0mWait: \033[33m" << seconds << "                                \033[36m|\n"	\
			"|=======================================|\033[0m";
		else
			cout << "\033[36m|=======================================|\n"					\
			"|\033[31m                WARNING                \033[36m|\n"					\
			"|=======================================|\n"									\
			"|\033[0mВ данной игре графика выполнена в виде \033[36m|\n"					\
			"|\033[0mсимволов и постоянно мерцает.          \033[36m|\n"					\
			"|\033[0mВ следствие чего может быть опасна для \033[36m|\n"					\
			"|\033[0mлюдей с эпилепсией.                    \033[36m|\n"					\
			"|\033[0mЕсли вы больны эпилепсией, я прошу вас \033[36m|\n"					\
			"|\033[0mзакрыть это приложение в целях вашей же\033[36m|\n"					\
			"|\033[0mбезопастности.                         \033[36m|\n"					\
			"|\033[0mСпасибо.                               \033[36m|\n"					\
			"|\033[0mОжидайте: \033[33m" << seconds << "                            \033[36m|\n"	\
			"|=======================================|\033[0m";
		seconds--;
		if (seconds < 0) {
			tmer = false;
			system("cls");
		}
		else
			Sleep(1000);
	}
	SetCursorPos(p.x, p.y);
	BlockInput(false);
	while (!Start) {
		system("cls");
		if (Language)
			cout << "\033[36m|=======================================|\n"					\
			"|\033[31m                WARNING                \033[36m|\n"					\
			"|=======================================|\n"									\
			"|\033[0mIn this game, the graphics are in the  \033[36m|\n"					\
			"|\033[0mform of symbols and flicker constantly.\033[36m|\n"					\
			"|\033[0mAs a result of which it can be         \033[36m|\n"					\
			"|\033[0mdangerous for people with epilepsy.    \033[36m|\n"					\
			"|\033[0mIf you have epilepsy,                  \033[36m|\n"					\
			"|\033[0mI ask you to close this application    \033[36m|\n"					\
			"|\033[0mfor your own safety.                   \033[36m|\n"					\
			"|\033[0mThanks.                                \033[36m|\n"					\
			"|=======================================|\n"									\
			"|\033[33mAccept and continue: Space             \033[36m|\n"					\
			"|\033[31mExit: ESC                              \033[36m|\n"					\
			"|=======================================|\033[0m";
		else
			cout << "\033[36m|=======================================|\n"					\
			"|\033[31m                WARNING                \033[36m|\n"					\
			"|=======================================|\n"									\
			"|\033[0mВ данной игре графика выполнена в виде \033[36m|\n"					\
			"|\033[0mсимволов и постоянно мерцает.          \033[36m|\n"					\
			"|\033[0mВ следствие чего может быть опасна для \033[36m|\n"					\
			"|\033[0mлюдей с эпилепсией.                    \033[36m|\n"					\
			"|\033[0mЕсли вы больны эпилепсией, я прошу вас \033[36m|\n"					\
			"|\033[0mзакрыть это приложение в целях вашей же\033[36m|\n"					\
			"|\033[0mбезопастности.                         \033[36m|\n"					\
			"|\033[0mСпасибо.                               \033[36m|\n"					\
			"|=======================================|\n"									\
			"|\033[33mПринять и продолжить: Space            \033[36m|\n"					\
			"|\033[31mВыйти: ESC                             \033[36m|\n"					\
			"|=======================================|\033[0m";
		int choice = _getch();
		switch (choice) {
		case 32:
			next = true;
			break;
		case 27:
			exit(0);
			break;
		}
		if (next) {
			ofstream key("C:/Windows/Temp/Warning_Disabling.txt");
			if (key.is_open())
				key << "fCFjW0n|ZbuuGrkWCJl?gFShQW6?Hu2xiG?g";
			key.close();
			Start = true, dangerous = false;
		}
	}
}
//настройки
void settings() {
	while (!Start) {
		system("cls");
		if (factor == 1 || factor == 2) {
			if (Language)
				factor_space = "       \033[36m|\n";
			else
				factor_space = "      \033[36m|\n";
		}
		else {
			if (Language)
				factor_space = "     \033[36m|\n";
			else
				factor_space = "    \033[36m|\n";
		}
		if (Language)
			cout << "\033[36m|========= \033[31mSettings \033[36m=========|\n"			\
			"|\033[0mDifficulty factor: \033[33mx" << factor << factor_space << \
			"|============================|\n"											\
			"|\033[0mРусский\\\033[33mEnglish\033[0m            1\033[36m|\n"			\
			"|\033[0mMusic:\033[33m" << off_on << "\033[0m                2\033[36m|\n"	\
			"|\033[0mDifficulty: \033[33m" << difficulty_level << \
			"|\033[0mWalls kill: \033[33m" << yes_no << \
			"|\033[0mShow hints: \033[33m" << yes_no1 << \
			"|============================|\n"											\
			"|\033[0mExit                     ESC\033[36m|\n"							\
			"|============================|\033[0m";
		else
			cout << "\033[36m|========= \033[31mSettings \033[36m=========|\n"			\
			"|\033[0mКоэф-ент сложности: \033[33mx" << factor << factor_space << \
			"|============================|\n"											\
			"|\033[33mРусский\033[0m\\English            1\033[36m|\n"					\
			"|\033[0mМузыка:\033[33m" << off_on << "\033[0m               2\033[36m|\n"	\
			"|\033[0mСложность: \033[33m" << difficulty_level << \
			"|\033[0mСтены убивают: \033[33m" << yes_no << \
			"|\033[0mПодсказки: \033[33m" << yes_no1 << \
			"|============================|\n"											\
			"|\033[0mВыйти                    ESC\033[36m|\n"							\
			"|============================|\033[0m";
		int choice = _getch();
		switch (choice) {
		case 49:
			Language = !Language;
			if (Language) {
				if (dificult == 0)
					difficulty_level = "Easy           \033[0m3\033[36m|\n";
				else if (dificult == 1)
					difficulty_level = "Normal         \033[0m3\033[36m|\n";
				else
					difficulty_level = "Hard           \033[0m3\033[36m|\n";
				if (!wall_killing)
					yes_no = "NO             \033[0m4\033[36m|\n";
				else
					yes_no = "YES            \033[0m4\033[36m|\n";
				if (!help)
					yes_no1 = "NO             \033[0m5\033[36m|\n";
				else
					yes_no1 = "YES            \033[0m5\033[36m|\n";
			}
			else {
				if (dificult == 0)
					difficulty_level = "Легко           \033[0m3\033[36m|\n";
				else if (dificult == 1)
					difficulty_level = "Нормально       \033[0m3\033[36m|\n";
				else
					difficulty_level = "Сложно          \033[0m3\033[36m|\n";
				if (!wall_killing)
					yes_no = "НЕТ         \033[0m4\033[36m|\n";
				else
					yes_no = "ДА          \033[0m4\033[36m|\n";
				if (!help)
					yes_no1 = "НЕТ             \033[0m5\033[36m|\n";
				else
					yes_no1 = "ДА              \033[0m5\033[36m|\n";

			}
			break;
		case 50:
			OST = !OST;
			if (OST) {
				PlaySound(MAKEINTRESOURCE(1), GetModuleHandle(NULL), SND_RESOURCE | SND_LOOP | SND_ASYNC);
				off_on = " ON  ";
			}
			else {
				PlaySound(nullptr, nullptr, 0);
				off_on = " OFF ";
			}
			break;
		case 51:
			if (dificult == 0) {
				if (Language)
					difficulty_level = "Normal         \033[0m3\033[36m|\n";
				else
					difficulty_level = "Нормально       \033[0m3\033[36m|\n";
				if (wall_killing)
					factor = 1.5;
				else
					factor = 1;
				dificult = 1;
				level = 55;
			}
			else if (dificult == 1) {
				if (Language)
					difficulty_level = "Hard           \033[0m3\033[36m|\n";
				else
					difficulty_level = "Сложно          \033[0m3\033[36m|\n";
				if (wall_killing)
					factor = 2;
				else
					factor = 1.5;
				dificult = 2;
				level = 25;
			}
			else {
				if (Language)
					difficulty_level = "Easy           \033[0m3\033[36m|\n";
				else
					difficulty_level = "Легко           \033[0m3\033[36m|\n";
				if (wall_killing)
					factor = 1;
				else
					factor = 0.5;
				dificult = 0;
				level = 100;
			}
			break;
		case 52:
			if (dificult == 0) {
				if (!wall_killing)
					factor = 1;
				else
					factor = 0.5;
			}
			else if (dificult == 1) {
				if (!wall_killing)
					factor = 1.5;
				else
					factor = 1;
			}
			else {
				if (!wall_killing)
					factor = 2;
				else
					factor = 1.5;
			}
			wall_killing = !wall_killing;
			if (!wall_killing) {
				if (Language)
					yes_no = "NO             \033[0m4\033[36m|\n";
				else
					yes_no = "НЕТ         \033[0m4\033[36m|\n";
			}
			else {
				if (Language)
					yes_no = "YES            \033[0m4\033[36m|\n";
				else
					yes_no = "ДА          \033[0m4\033[36m|\n";
			}
			break;
		case 53:
			help = !help;
			if (!help) {
				if (Language)
					yes_no1 = "NO             \033[0m5\033[36m|\n";
				else
					yes_no1 = "НЕТ             \033[0m5\033[36m|\n";
			}
			else {
				if (Language)
					yes_no1 = "YES            \033[0m5\033[36m|\n";
				else
					yes_no1 = "ДА              \033[0m5\033[36m|\n";
			}
			break;
		case 27:
			Main_Menu();
			break;
		}
	}
}
//рекорды
void records() {
	system("cls");
	int hight_score_hard = 0, hight_score_medium = 0, hight_score_easily = 0;
	string str_hight_score_hard, str_hight_score_medium, str_hight_score_easily;
	ifstream hightscoreE("C:/Windows/Temp/Hight_EScore.txt");
	if (hightscoreE.is_open()) {
		hightscoreE >> hight_score_easily;
		hightscoreE.close();
		if (hight_score_easily < 10) {
			if (Language)
				str_hight_score_easily = to_string(hight_score_easily) + "              \033[36m|\n";
			else
				str_hight_score_easily = to_string(hight_score_easily) + "            \033[36m|\n";
		}
		else if (hight_score_easily < 100) {
			if (Language)
				str_hight_score_easily = to_string(hight_score_easily) + "             \033[36m|\n";
			else
				str_hight_score_easily = to_string(hight_score_easily) + "           \033[36m|\n";
		}
		else if (hight_score_easily < 1000) {
			if (Language)
				str_hight_score_easily = to_string(hight_score_easily) + "            \033[36m|\n";
			else
				str_hight_score_easily = to_string(hight_score_easily) + "          \033[36m|\n";
		}
		else if (hight_score_easily < 10000) {
			if (Language)
				str_hight_score_easily = to_string(hight_score_easily) + "           \033[36m|\n";
			else
				str_hight_score_easily = to_string(hight_score_easily) + "         \033[36m|\n";
		}
		else {
			if (Language)
				str_hight_score_easily = "\033[33m       CHEATER!\033[36m|\n";
			else
				str_hight_score_easily = "\033[33m       ЧИТЕР!\033[36m|\n";
		}
	}
	else {
		if (Language)
			str_hight_score_easily = "\033[31m           NONE\033[36m|\n";
		else
			str_hight_score_easily = "\033[31m         NONE\033[36m|\n";
	}
	ifstream hightscoreM("C:/Windows/Temp/Hight_MScore.txt");
	if (hightscoreM.is_open()) {
		hightscoreM >> hight_score_medium;
		hightscoreM.close();
		if (hight_score_medium < 10) {
			if (Language)
				str_hight_score_medium = to_string(hight_score_medium) + "            \033[36m|\n";
			else
				str_hight_score_medium = to_string(hight_score_medium) + "        \033[36m|\n";
		}
		else if (hight_score_medium < 100) {
			if (Language)
				str_hight_score_medium = to_string(hight_score_medium) + "           \033[36m|\n";
			else
				str_hight_score_medium = to_string(hight_score_medium) + "       \033[36m|\n";
		}
		else if (hight_score_medium < 1000) {
			if (Language)
				str_hight_score_medium = to_string(hight_score_medium) + "          \033[36m|\n";
			else
				str_hight_score_medium = to_string(hight_score_medium) + "      \033[36m|\n";
		}
		else if (hight_score_medium < 10000) {
			if (Language)
				str_hight_score_medium = to_string(hight_score_medium) + "         \033[36m|\n";
			else
				str_hight_score_medium = to_string(hight_score_medium) + "     \033[36m|\n";
		}
		else {
			if (Language)
				str_hight_score_medium = "\033[33m     CHEATER!\033[36m|\n";
			else
				str_hight_score_medium = "\033[33m   ЧИТЕР!\033[36m|\n";
		}
	}
	else {
		if (Language)
			str_hight_score_medium = "\033[31m         NONE\033[36m|\n";
		else
			str_hight_score_medium = "\033[31m     NONE\033[36m|\n";
	}
	ifstream hightscoreH("C:/Windows/Temp/Hight_HScore.txt");
	if (hightscoreH.is_open()) {
		hightscoreH >> hight_score_hard;
		hightscoreH.close();
		if (hight_score_hard < 10) {
			if (Language)
				str_hight_score_hard = to_string(hight_score_hard) + "              \033[36m|\n";
			else
				str_hight_score_hard = to_string(hight_score_hard) + "           \033[36m|\n";
		}
		else if (hight_score_hard < 100) {
			if (Language)
				str_hight_score_hard = to_string(hight_score_hard) + "             \033[36m|\n";
			else
				str_hight_score_hard = to_string(hight_score_hard) + "          \033[36m|\n";
		}
		else if (hight_score_hard < 1000) {
			if (Language)
				str_hight_score_hard = to_string(hight_score_hard) + "            \033[36m|\n";
			else
				str_hight_score_hard = to_string(hight_score_hard) + "         \033[36m|\n";
		}
		else if (hight_score_hard < 10000) {
			if (Language)
				str_hight_score_hard = to_string(hight_score_hard) + "           \033[36m|\n";
			else
				str_hight_score_hard = to_string(hight_score_hard) + "        \033[36m|\n";
		}
		else {
			if (Language)
				str_hight_score_hard = "\033[33m       CHEATER!\033[36m|\n";
			else
				str_hight_score_hard = "\033[33m      ЧИТЕР!\033[36m|\n";
		}
	}
	else {
		if (Language)
			str_hight_score_hard = "\033[31m           NONE\033[36m|\n";
		else
			str_hight_score_hard = "\033[31m        NONE\033[36m|\n";
	}
	if (Language)
		cout << "\033[36m|=== \033[31mHight Scores: \033[36m===|\n"
		"|\033[0mHard: \033[33m" << str_hight_score_hard <<
		"|\033[0mMedium: \033[33m" << str_hight_score_medium <<
		"|\033[0mEasy: \033[33m" << str_hight_score_easily <<
		"|=====================|\n"
		"|\033[33mPress any key...     \033[36m|\n"
		"|=====================|\033[0m";
	else
		cout << "\033[36m|===== \033[31mРекорды: \033[36m=====|\n"
		"|\033[0mСложно: \033[33m" << str_hight_score_hard <<
		"|\033[0mНормально: \033[33m" << str_hight_score_medium <<
		"|\033[0mЛегко: \033[33m" << str_hight_score_easily <<
		"|====================|\n"
		"|\033[33mPress any key...    \033[36m|\n"
		"|====================|\033[0m";
	system("pause >NUL");
	Main_Menu();
}
//о разработчике
void Developer() {
	while (!Start) {
		system("cls");
		if (!Language)
			cout << "\033[36m|==== \033[31mРазработчики \033[36m====|\n"	\
			"|\033[33mПрограмированние:     \033[36m|\n"			\
			"|\033[0mLonewolf239           \033[36m|\n"				\
			"|======================|\n"							\
			"|\033[33mДизайн:               \033[36m|\n"			\
			"|\033[0mLonewolf239           \033[36m|\n"				\
			"|======================|\n"							\
			"|\033[33mСоздание иконки:      \033[36m|\n"			\
			"|\033[0mShiZa 123             \033[36m|\n"				\
			"|======================|\n"							\
			"|\033[33mПеревод:              \033[36m|\n"			\
			"|\033[0mGoogle Translate      \033[36m|\n"				\
			"|======================|\n"							\
			"|\033[0mСоц.сети:        Space\033[36m|\n"				\
			"|\033[0mОформить заказ:  Enter\033[36m|\n"				\
			"|\033[0mВыйти:             ESC\033[36m|\n"				\
			"|======================|\033[0m"						\
			<< endl << endl;
		else
			cout << "\033[36m|===== \033[31mDevelopers \033[36m=====|\n"	\
			"|\033[33mProgramming:          \033[36m|\n"			\
			"|\033[0mLonewolf239           \033[36m|\n"				\
			"|======================|\n"							\
			"|\033[33mDesign:               \033[36m|\n"			\
			"|\033[0mLonewolf239           \033[36m|\n"				\
			"|======================|\n"							\
			"|\033[33mCreating an icon:     \033[36m|\n"			\
			"|\033[0mShiZa 123             \033[36m|\n"				\
			"|======================|\n"							\
			"|\033[33mTranslation:          \033[36m|\n"			\
			"|\033[0mGoogle Translate      \033[36m|\n"				\
			"|======================|\n"							\
			"|\033[0mSoc. networks:   Space\033[36m|\n"				\
			"|\033[0mPlace an order:  Enter\033[36m|\n"				\
			"|\033[0mExit:              ESC\033[36m|\n"				\
			"|======================|\033[0m"						\
			<< endl << endl;
		int dev = _getch();
		switch (dev) {
		case 32:
			soc_netw();
			break;
		case 27:
			Main_Menu();
			break;
		case 13:
			system("explorer https://t.me/Lonewolf239_OrderBOT");
		}
	}
}
//соц.сети
void soc_netw() {
	system("cls");
	if (Language)
		cout << "\033[36m|=== \033[31mSocial network \033[36m===|\n"
		"|\033[33mLonewolf239:          \033[36m|\n"
		"|\033[0mDiscord: Bubba#4211   \033[36m|\n"
		"|\033[0mVK: @1blitz01         \033[36m|\n"
		"|\033[0mTelegram: @an1onime   \033[36m|\n"
		"|======================|\n"
		"|\033[33mShiZa 123:            \033[36m|\n"
		"|\033[0mVK: @0dumbgamer0      \033[36m|\n"
		"|\033[0mYouTube: Press: \033[33mSpace \033[36m|\n"
		"|======================|\n"
		"|\033[33mPress any key...      \033[36m|\n"
		"|======================|\033[0m";
	else
		cout << "\033[36m|====== \033[31mСоц. сети \033[36m======|\n"
		"|\033[33mLonewolf239:           \033[36m|\n"
		"|\033[0mDiscord: Bubba#4211    \033[36m|\n"
		"|\033[0mVK: @1blitz01          \033[36m|\n"
		"|\033[0mTelegram: @an1onime    \033[36m|\n"
		"|=======================|\n"
		"|\033[33mShiZa 123:             \033[36m|\n"
		"|\033[0mVK: @0dumbgamer0       \033[36m|\n"
		"|\033[0mYouTube: Нажми: \033[33mSpace  \033[36m|\n"
		"|=======================|\n"
		"|\033[33mPress any key...       \033[36m|\n"
		"|=======================|\033[0m";
	int choice = _getch();
	if (choice == 32)
		system("explorer https://youtube.com/channel/UCADBHS6PgZ5DLSLuZ15jU9A");
	Main_Menu();
}
//удаление рекорда
void Delete() {
	bool error = false;
	string ye;
	system("cls");
	if (!Language)
		cout << "Вы уверены что точно хотите удалить все игровые файлы? \033[32myes\033[0m/\033[31mno\033[0m" << endl;
	if (Language)
		cout << "Are you sure you want to delete all game files? \033[32myes\033[0m/\033[31mno\033[0m" << endl;
	cin >> ye;
	GetCursorPos(&p);
	SetCursorPos(9000000, 9000000);
	BlockInput(true);
	transform(ye.begin(), ye.end(), ye.begin(), [](unsigned char c) { return tolower(c); });
	if (ye == "yes" || ye == "delete") {
		system("cls");
		for (int i = 0; i < 3 + rand() % 4; i++) {
			cout << "DELETING.";
			Sleep(200);
			system("cls");
			cout << "DELETING..";
			Sleep(200);
			system("cls");
			cout << "DELETING...";
			Sleep(200);
			system("cls");
		}
		if (remove("C:/Windows/Temp/Hight_EScore.txt") != 0) {
			error = true;
			cout << "ERROR 000\n"
					"DELETE FILES ERROR" << endl;
			Sleep(250);
		}
		if (remove("C:/Windows/Temp/Hight_MScore.txt") != 0) {
			error = true;
			cout << "ERROR 001\n"
					"DELETE FILES ERROR" << endl;
			Sleep(250);
		}
		if (remove("C:/Windows/Temp/Hight_HScore.txt") != 0) {
			error = true;
			cout << "ERROR 002\n"
					"DELETE FILES ERROR" << endl;
			Sleep(250);
		}
		if (remove("C:/Windows/Temp/Warning_Disabling.txt") != 0) {
			error = true;
			cout << "ERROR 003\n"
					"DELETE FILES ERROR" << endl;
			Sleep(250);
		}
		if (!error) {
			last_score_easily = 0, last_score_medium = 0, last_score_hard = 0;
			cout << "GAME DATA SUCCESSFULLY DELETED" << endl;
			Sleep(1000);
		}
		else {
			last_score_easily = 0, last_score_medium = 0, last_score_hard = 0;
			cout << "GAME DATA DELETED" << endl;
			Sleep(1000);
		}
		SetCursorPos(p.x, p.y);
		BlockInput(false);
		Main_Menu();
	}
	else {
		cout << endl << endl << endl << endl << endl << "	 OOOO   KK  KK\n	OO  OO  KK KK\n	OO  OO  KKKK\n	OO  OO  KK KK\n	 OOOO   KK  KK" << endl << endl << endl << endl << endl << endl << endl << endl;
		Sleep(1500);
		SetCursorPos(p.x, p.y);
		BlockInput(false);
		Main_Menu();
	}
}