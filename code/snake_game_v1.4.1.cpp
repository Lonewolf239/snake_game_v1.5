#include <iostream>
#include <locale>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

//основные игровые параметры
bool GameOver, Start = false, Language = true, First_start = true, wall_killing = true, dangerous = true, tmer = false, de1eting_file = false, help = true;
const int width = 40, height = 20;
int x = height / 2, y = width / 2, Super_Fruit_Spawn = rand() % 20, FruitX = rand() % 19, FruitY = rand() % 39, Super_FruitX = rand() % 19, Super_FruitY = rand() % 39, score = 0, level = 55, last_score_easily, last_score_medium, last_score_hard, seconds = 5, dificult = 1;
int tailX[100], tailY[100], nTail;
enum nDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
nDirection dir;

//костыли
void Setup();
void Draw();
void Logic();
void Input();
void Game_Over();
void Main_Menu();
void Warning();
void Level();
void Developer();
void Delete();
void soc_netw();

//main
int main() {
	srand(time(NULL));
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
		ifstream deleting_file("C:/Windows/Temp/Hight_Score.txt");
		if (deleting_file.is_open()) {
			cout << "The file system has been updated.\nYour file is no longer compatible.\nDELETING...\n";
			Sleep(1500);
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
			for (int i = 0; i <= 100; i += rand_loading) {
				system("cls");
				cout << "WW   WW  EEEEE  LL       CCCC    OOOO   MM   MM  EEEEE\nWW   WW  EE     LL      CC  CC  OO  OO  MMM MMM  EE\nWW W WW  EEEE   LL      CC      OO  OO  MM M MM  EEEE\nWWWWWWW  EE     LL      CC  CC  OO  OO  MM   NN  EE\n WW WW   EEEEE  LLLLLL   CCCC    OOOO   MM   MM  EEEEE" << endl << endl;
				cout << "IIIIII  NN  NN\n  II    NNN NN\n  II    NN NNN\n  II    NN  NN\nIIIIII  NN  NN" << endl << endl;
				cout << " SSSS   NN  NN   AAAA   KK  KK  EEEEE\nSS      NNN NN  AA  AA  KK EE   EE\n SSSS   NN NNN  AAAAAA  KKKK    EEEE\n    SS  NN  NN  AA  AA  KK KK   EE\n SSSS   NN  NN  AA  AA  KK  KK  EEEEE\n\n GGGG    AAAA   MM   MM EEEEE\nGG      AA  AA  MMM MMM EE\nGG GGG  AAAAAA  MM M MM EEEE\nGG  GG  AA  AA  MM   MM EE\n GGGG   AA  AA  MM   MM EEEEE" << endl << endl;
				cout << "  11      44\n1111      44  44\n  11      444444\n  11          44\n  11  **      44" << endl;
				cout << "Loading " << loading << "% [";
				for (int j = 0; j <= 100; j++) {
					if (j <= loading)
						cout << "#";
					else
						cout << "-";
				}
				cout << "]";
				Sleep(rand() % 300);
				loading += rand_loading;
				rand_loading = 1 + rand() % 15;
				if (loading > 100) {
					loading = 100;
					system("cls");
					cout << "WW   WW  EEEEE  LL       CCCC    OOOO   MM   MM  EEEEE\nWW   WW  EE     LL      CC  CC  OO  OO  MMM MMM  EE\nWW W WW  EEEE   LL      CC      OO  OO  MM M MM  EEEE\nWWWWWWW  EE     LL      CC  CC  OO  OO  MM   NN  EE\n WW WW   EEEEE  LLLLLL   CCCC    OOOO   MM   MM  EEEEE" << endl << endl;
					cout << "IIIIII  NN  NN\n  II    NNN NN\n  II    NN NNN\n  II    NN  NN\nIIIIII  NN  NN" << endl << endl;
					cout << " SSSS   NN  NN   AAAA   KK  KK  EEEEE\nSS      NNN NN  AA  AA  KK EE   EE\n SSSS   NN NNN  AAAAAA  KKKK    EEEE\n    SS  NN  NN  AA  AA  KK KK   EE\n SSSS   NN  NN  AA  AA  KK  KK  EEEEE\n\n GGGG    AAAA   MM   MM EEEEE\nGG      AA  AA  MMM MMM EE\nGG GGG  AAAAAA  MM M MM EEEE\nGG  GG  AA  AA  MM   MM EE\n GGGG   AA  AA  MM   MM EEEEE" << endl << endl;
					cout << "  11      44\n1111      44  44\n  11      444444\n  11          44\n  11  **      44" << endl;
					cout << "Loading " << loading << "% [";
					for (int j = 0; j <= 100; j++) {
						if (j <= loading)
							cout << "#";
						else
							cout << "-";
					}
					cout << "]";
					now_loading = false;
					break;
				}
			}
		}
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
	x = height / 2, y = width / 2, Super_Fruit_Spawn = rand() % 20, FruitX = rand() % 19, FruitY = rand() % 39, Super_FruitX = rand() % 19, Super_FruitY = rand() % 39, score = 0;
	First_start = false;
	Start = false;
	GameOver = false;
	nTail = 0;
	dir = STOP;
}
//рисовалка
void Draw() {
	system("cls");
	cout << "#########################################";
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == x && j == y)
				cout << "S";
			else if (i == FruitX && j == FruitY)
				cout << "f";
			else if (i == Super_FruitX && j == Super_FruitY && Super_Fruit_Spawn >= 10 && Super_Fruit_Spawn <= 12)
				cout << "F";
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						cout << "s";
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "#########################################";
	cout << endl;
	if (Language) {
		cout << "Score: " << score << endl;
		if (wall_killing)
			cout << "Walls kill: YES";
		if (!wall_killing)
			cout << "Walls kill: NO";
		cout << endl;
		if (level == 100)
			cout << "Difficulty: Easy";
		if (level == 55)
			cout << "Difficulty: Normal";
		if (level == 25)
			cout << "Difficulty: Hard";
		if (help) {
			cout << "\n============================\nf - Fruit (+1 pt)\nF - Super Fruit (+5 pt)\n";
			cout << "Movement: WASD\nExit: X";
		}
		else
			cout << endl << endl;
	}
	if (!Language) {
		cout << "Счёт: " << score << endl;
		if (wall_killing)
			cout << "Стены убивают: ДА";
		if (!wall_killing)
			cout << "Стены убивают: НЕТ";
		cout << endl;
		if (level == 100)
			cout << "Сложность: Легко";
		if (level == 55)
			cout << "Сложность: Нормально";
		if (level == 25)
			cout << "Сложность: Сложно";
		if (help) {
			cout << "\n============================\nf - Фрукт (+1 pt)\nF - Супер Фрукт (+5 pt)\n";
			cout << "Движение: WASD\nВыйти: X";
		}
		else
			cout << endl << endl;
	}
	Sleep(level);
}
//логика игры
void Logic() {
	int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
	tailX[0] = y;
	tailY[0] = x;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i], prev2Y = tailY[i];
		tailX[i] = prevX, tailY[i] = prevY;
		prevX = prev2X, prevY = prev2Y;
	}
	switch (dir)
	{
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
		nTail++;
		FruitX = rand() % 19, FruitY = rand() % 39;
		Super_Fruit_Spawn = rand() % 20;
	}
	if (x == Super_FruitX && y == Super_FruitY && Super_Fruit_Spawn >= 10 && Super_Fruit_Spawn <= 12) {
		score += 5;
		nTail++;
		FruitX = rand() % 19, FruitY = rand() % 39;
		Super_FruitX = rand() % 19, Super_FruitY = rand() % 39;
		Super_Fruit_Spawn = rand() % 20;
	}
	if (FruitX == Super_FruitX && FruitY == Super_FruitY && Super_Fruit_Spawn >= 10 && Super_Fruit_Spawn <= 12)
		FruitX = rand() % 19, FruitY = rand() % 39;
}
//управление
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			if (dir == RIGHT)
				break;
			dir = LEFT;
			break;
		case 'd':
			if (dir == LEFT)
				break;
			dir = RIGHT;
			break;
		case 's':
			if (dir == UP)
				break;
			dir = DOWN;
			break;
		case 'w':
			if (dir == DOWN)
				break;
			dir = UP;
			break;
		case 'x':
			GameOver = true;
			break;
		}
	}
}
//конец игры
void Game_Over() {
	system("cls");
	cout << endl << " GGGG    AAAA   MM   MM  EEEEE    OOOO   VV  VV  EEEEE  RRRRR\nGG      AA  AA  MMM MMM  EE      OO  OO  VV  VV  EE     RR  RR\nGG GGG  AAAAAA  MM M MM  EEEE    OO  OO  VV  VV  EEEE   RRRRR\nGG  GG  AA  AA  MM   MM  EE      OO  OO   VVVV   EE     RR  RR\n GGGG   AA  AA  MM   MM  EEEEE    OOOO     VV    EEEEE  RR  RR" << endl << endl;
	if (!Language)
		cout << "Твой счёт: " << score << endl;
	if (Language)
		cout << "Your score: " << score << endl;
	if (dificult == 0) {
		if (score > last_score_easily) {
			ofstream hightscore("C:/Windows/Temp/Hight_EScore.txt");
			if (hightscore.is_open())
				hightscore << score;
			hightscore.close();
		}
	}
	if (dificult == 1) {
		if (score > last_score_medium) {
			ofstream hightscore("C:/Windows/Temp/Hight_MScore.txt");
			if (hightscore.is_open())
				hightscore << score;
			hightscore.close();
		}
	}
	if (dificult == 2) {
		if (score > last_score_hard) {
			ofstream hightscore("C:/Windows/Temp/Hight_HScore.txt");
			if (hightscore.is_open())
				hightscore << score;
			hightscore.close();
		}
	}
	system("pause");
	Start = false;
	main();
}
//главное меню
void Main_Menu() {
	system("cls");
	int hight_score_hard = 0, hight_score_medium = 0, hight_score_easily = 0;
	ifstream hightscoreE("C:/Windows/Temp/Hight_EScore.txt");
	if (hightscoreE.is_open())
		hightscoreE >> hight_score_easily;
	hightscoreE.close();
	ifstream hightscoreM("C:/Windows/Temp/Hight_MScore.txt");
	if (hightscoreM.is_open())
		hightscoreM >> hight_score_medium;
	hightscoreM.close();
	ifstream hightscoreH("C:/Windows/Temp/Hight_HScore.txt");
	if (hightscoreH.is_open())
		hightscoreH >> hight_score_hard;
	hightscoreH.close();
		if (Language) {
			cout << "                  Snake_Game_v1.4.1" << endl;
			cout << "====================================================\n                      Main menu\n====================================================\n                     High score:\n                       Easy: " << hight_score_easily << "\n                      Medium: " << hight_score_medium << "\n                       Hard: " << hight_score_hard << "\n====================================================\n                       Start 1\n                      Settings 2\n                About the developers 3\n                  Русский/English 4\n              =========================\n                  Delete game data 7\n                       Exit 0\n\n\n\n\n\n\n\n\n\n" << endl;
		}
		if (!Language) {
			cout << "                     Snake_Game_v1.4.1" << endl;
			cout << "==============================================================\n                        Главное меню\n==============================================================\n                        Лучший счёт:\n                          Легко: " << hight_score_easily << "\n                        Нормально: " << hight_score_medium << "\n                         Сложно: " << hight_score_hard << "\n==============================================================\n                           Старт 1\n                         Настройки 2\n                      О Разработчиках 3\n                      Русский/English 4\n              ==================================\n                   Удалить игровые данные 7\n                           Выйти 0\n\n\n\n\n\n\n\n\n\n" << endl;
		}
	switch (_getch()) {
	case '1':
		if (dangerous)
			Warning();
		else
			Start = true;
		break;
	case '2':
		Level();
		break;
	case '3':
		Developer();
		break;
	case '4':
		system("cls");
		Language = !Language;
		Main_Menu();
		break;
	case '7':
		Delete();
		break;
	case '0':
		exit(0);
		break;
	default:
		Main_Menu();
	}
}
//предупреждение
void Warning() {
	tmer = true;
	while (tmer) {
		system("cls");
		cout << "          WW   WW   AAAA   RRRRR   NN  NN  IIIIII  NN  NN   GGGG\n          WW   WW  AA  AA  RR  RR  NNN NN    II    NNN NN  GG\n          WW W WW  AAAAAA  RRRRR   NN NNN    II    NN NNN  GG GGG\n          WWWWWWW  AA  AA  RR  RR  NN  NN    II    NN  NN  GG  GG\n           WW WW   AA  AA  RR  RR  NN  NN  IIIIII  NN  NN   GGGG" << endl << endl;
		if (!Language) {
			cout << "В данной игре графика выполнена в виде символов и постоянно мерцает\nВ следствие чего может быть опасна для людей с эпилепсией.\nЕсли вы больны эпилепсией, я попрошу вас закрыть это приложение в целях вашей же безопастности. Спасибо" << endl;
			cout << "Подождите " << seconds;
		}
		if (Language) {
			cout << "In this game, the graphics are in the form of symbols and flicker constantly\nAs a result of which it can be dangerous for people with epilepsy.\nIf you have epilepsy, I ask you to close this application for your own safety. Thanks" << endl;
			cout << "Wait " << seconds;
		}
		seconds--;
		if (seconds < 0) {
			tmer = false;
			system("cls");
		}
		else
			Sleep(950);
	}
	cout << "          WW   WW   AAAA   RRRRR   NN  NN  IIIIII  NN  NN   GGGG\n          WW   WW  AA  AA  RR  RR  NNN NN    II    NNN NN  GG\n          WW W WW  AAAAAA  RRRRR   NN NNN    II    NN NNN  GG GGG\n          WWWWWWW  AA  AA  RR  RR  NN  NN    II    NN  NN  GG  GG\n           WW WW   AA  AA  RR  RR  NN  NN  IIIIII  NN  NN   GGGG" << endl << endl;
	if (!Language) {
		cout << "В данной игре графика выполнена в виде символов и постоянно мерцает\nВ следствие чего может быть опасна для людей с эпилепсией.\nЕсли вы больны эпилепсией, я попрошу вас закрыть это приложение в целях вашей же безопастности. Спасибо" << endl;
		cout << "Принять и продолжить 1\nВыйти 2\n";
	}
	if (Language) {
		cout << "In this game, the graphics are in the form of symbols and flicker constantly\nAs a result of which it can be dangerous for people with epilepsy.\nIf you have epilepsy, I ask you to close this application for your own safety. Thanks" << endl;
		cout << "Accept and continue 1\nExit 2\n";
	}
	switch (_getch()) {
	case '1':
		Start = true, dangerous = false;
		break;
	case '2':
		exit(0);
		break;
	}
}
//настройки
void Level() {
	system("cls");
	if (Language) {
		cout << "========================\n	Settings\n========================\n";
		cout << "       Difficulty:\n         Easy 1\n        Normal 2\n         Hard 3" << endl;
		if (level == 100)
			cout << "    Difficulty: Easy";
		if (level == 55)
			cout << "    Difficulty: Normal";
		if (level == 25)
			cout << "    Difficulty: Hard";
		cout << endl << "========================" << endl;
		if (wall_killing)
			cout << "     Walls kill: YES 4";
		if (!wall_killing)
			cout << "     Walls kill: NO 4";
		cout << endl;
		if (help)
			cout << "     Show hints: YES 5";
		if (!help)
			cout << "     Show hints: NO 5";
		cout << "\n========================\n         Exit 6" << endl << endl << endl << endl;
	}
	if (!Language) {
		cout << "========================\n	Настройки\n========================\n";
		cout << "        Сложность:\n         Легко 1\n        Нормально 2\n         Сложно 3" << endl;
		if (level == 100)
			cout << "    Сложность: Легко";
		if (level == 55)
			cout << "    Сложность: Нормально";
		if (level == 25)
			cout << "    Сложность: Сложно";
		cout << endl << "========================" << endl;
		if (wall_killing)
			cout << "    Стены убивают: ДА 4";
		if (!wall_killing)
			cout << "    Стены убивают: НЕТ 4";
		cout << endl;
		if (help)
			cout << "      Подсказки: ДА 5";
		if (!help)
			cout << "      Подсказки: НЕТ 5";
		cout << "\n========================\n         Выход 6" << endl << endl << endl << endl;
	}
	cout << endl << endl;
	switch (_getch()) {
	case '1':
		dificult = 0;
		level = 100;
		Level();
		break;
	case '2':
		dificult = 1;
		level = 55;
		Level();
		break;
	case '3':
		dificult = 2;
		level = 25;
		Level();
		break;
	case '4':
		wall_killing = !wall_killing;
		Level();
		break;
	case '5':
		help = !help;
		Level();
		break;
	case '6':
		Main_Menu();
		break;
	default:
		Level();
	}
}
//о разработчике
void Developer() {
	system("cls");
	if (!Language)
		cout << "===================\n   Разработчики:\n===================\n Програмированние:\n    Lonewolf239\n===================\n Создание иконки:\n     ShiZa 123\n===================\n     Перевод:\n Google Translate\n===================\n    Соц.сети 1\n      Выйти 2\n===================\n\n\n\n\n\n\n\n\n" << endl << endl;
	if (Language)
		cout << "===================\n    Developers:\n===================\n   Programming:\n    Lonewolf239\n===================\n Creating an icon:\n     ShiZa 123\n===================\n   Translation:\n Google Translate\n===================\n Social networks 1\n      Exit 2\n===================\n\n\n\n\n\n\n\n\n" << endl << endl;
	switch (_getch()) {
	case '1':
		soc_netw();
		break;
	case '2':
		Main_Menu();
		break;
	default:
		Developer();
		break;
	}
}
//соц.сети
void soc_netw() {
	system("cls");
	if (Language) {
		cout << "    Social network:\n";
		cout << "======================\n     Lonewolf239:\n Discord: Bubba#4211\n    VK: @1blitz01\n Telegram: @an1onime\n======================\n      ShiZa 123:\n   VK: @0dumbgamer0\n   YouTube: Press 1\n======================\n       Exit 2\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl << endl << endl << endl << endl;
	}
	if (!Language) {
		cout << "      Соц. сети:\n";
		cout << "======================\n     Lonewolf239:\n Discord: Bubba#4211\n    VK: @1blitz01\n Telegram: @an1onime\n======================\n      ShiZa 123:\n   VK: @0dumbgamer0\n   YouTube: Нажми 1\n======================\n       Выйти 2\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl << endl << endl << endl << endl;
	}
	switch (_getch()) {
	case '1':
		system("explorer https://youtube.com/channel/UCADBHS6PgZ5DLSLuZ15jU9A");
		system("pause");
		Main_Menu();
		break;
	case '2':
		Main_Menu();
		break;
	default:
		soc_netw();
		break;
	}
}
//удаление рекорда
void Delete() {
	bool error = false;
	string ye;
	system("cls");
	if (!Language)
		cout << "Вы уверены что точно хотите удалить все игровые файлы? yes/no" << endl;
	if (Language)
		cout << "Are you sure you want to delete all game files? yes/no" << endl;
	cin >> ye;
	if (ye == "Yes" || ye == "yes" || ye == "Delete" || ye == "delete") {
		cout << endl << "		DELETING..." << endl;
		Sleep(1000);
		if (remove("C:/Windows/Temp/Hight_EScore.txt") != 0) {
			error = true;
			cout << "		         ERROR 000\n		DELETE FILES ERROR" << endl;
			Sleep(500);
		}
		if (remove("C:/Windows/Temp/Hight_MScore.txt") != 0) {
			error = true;
			cout << "		         ERROR 001\n		DELETE FILES ERROR" << endl;
			Sleep(500);
		}
		if (remove("C:/Windows/Temp/Hight_HScore.txt") != 0) {
			error = true;
			cout << "		         ERROR 002\n		DELETE FILES ERROR" << endl;
			Sleep(500);
		}
		if (!error) {
			last_score_easily = 0, last_score_medium = 0, last_score_hard = 0;
			cout << "		GAME DATA SUCCESSFULLY DELETED" << endl;
			Sleep(1500);
			Main_Menu();
		}
		else {
			last_score_easily = 0, last_score_medium = 0, last_score_hard = 0;
			cout << "		 GAME DATA DELETED" << endl;
			Sleep(1500);
			Main_Menu();
		}
	}
	else {
		cout << endl << endl << endl << endl << endl << "	 OOOO   KK  KK\n	OO  OO  KK KK\n	OO  OO  KKKK\n	OO  OO  KK KK\n	 OOOO   KK  KK" << endl << endl << endl << endl << endl << endl << endl << endl;
		Sleep(2000);
		Main_Menu();
	}
}