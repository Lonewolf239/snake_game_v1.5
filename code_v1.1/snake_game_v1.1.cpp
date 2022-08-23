#include <iostream>
#include <locale>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

//основные игровые параметры
bool GameOver, Start, Language = true, First_start = true, wall_killing = true;
const int width = 40, height = 20, window_width = 60, window_height = 30;
int x = height / 2, y = width / 2, FruitX = rand() % height, FruitY = rand() % width, score = 0, level = 55, last_score;
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
void language();
void Delete();

//main
int main() {
	setlocale(LC_CTYPE, "rus");
	system("cls");
	if (First_start) {
		cout << " SSSS   NN  NN   AAAA   KK  KK  EEEEE\nSS      NNN NN  AA  AA  KK EE   EE\n SSSS   NN NNN  AAAAAA  KKKK    EEEE\n    SS  NN  NN  AA  AA  KK KK   EE\n SSSS   NN  NN  AA  AA  KK  KK  EEEEE\n\n GGGG    AAAA   MM   MM EEEEE\nGG      AA  AA  MMM MMM EE\nGG GGG  AAAAAA  MM M MM EEEE\nGG  GG  AA  AA  MM   MM EE\n GGGG   AA  AA  MM   MM EEEEE\n\n   11       0000\n 1111      00  00\n   11      00  00\n   11      00  00\n   11  **   0000" << endl << endl;
		system("pause");
	}
	fstream hightscore("C:/Windows/Temp/Hight_Score.txt");
	if (hightscore.is_open())
		hightscore >> last_score;
	hightscore.close();
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
	x = height / 2, y = width / 2, FruitX = rand() % height-1, FruitY = rand() % width-1, score = 0;
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
	}
	cout << endl << endl;
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
		FruitX = rand() % height-1, FruitY = rand() % width-1;
	}
}

//управление
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
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
	if (score > last_score) {
		ofstream hightscore("C:/Windows/Temp/Hight_Score.txt");
		if (hightscore.is_open())
			hightscore << score;
		hightscore.close();
	}
	system("pause");
	Start = false;
	main();
}

//главное меню
void Main_Menu() {
	system("cls");
	int hight_score = 0;
	ifstream hightscore("C:/Windows/Temp/Hight_Score.txt");
	if (hightscore.is_open())
		hightscore >> hight_score;
	hightscore.close();
	if (!Language) {
		cout << "Лучший счёт: " << hight_score << endl << endl;
		cout << "Добро пожаловать в мою вторую тестовую игру Snake_game_v1.1\n___________________________________________________________\nУправление:\nДвижение: WASD\nВыход: X\n___________________________________________________________\nПожалуйста перед началом игры прочти предупреждение\nНачать 1\nПредупреждение 2\nНастройки 3\nО разработчике 4\nРусский/English 5"  << endl << "\n_____________________\nУдалить все игровые файлы 0" << endl << endl;
	}
	if (Language) {
		cout << "High score: " << hight_score << endl << endl;
		cout << "Welcome to my second test game Snake_game_v1.1\n_____________________________________________________________\nControls:\nMovement: WASD\nExit: X\n_____________________________________________________________\nPlease read the warning before starting the game\nStart 1\nWarning 2\nSettings 3\nAbout Developer 4\nРусский/English 5\n" << endl << "\n_____________________\nDelete all game files 0" << endl << endl;
	}
	switch (_getch()) {
	case '1':
		Start = true;
		break;
	case '2':
		Warning();
		break;
	case '3':
		Level();
		break;
	case '4':
		Developer();
		break;
	case '5':
		language();
		break;
	case '0':
		Delete();
		break;
	default:
		Main_Menu();
	}
}

//предупреждение
void Warning() {
	system("cls");
	cout << "          WW   WW   AAAA   RRRRR   NN  NN  IIIIII  NN  NN   GGGG\n          WW   WW  AA  AA  RR  RR  NNN NN    II    NNN NN  GG\n          WW W WW  AAAAAA  RRRRR   NN NNN    II    NN NNN  GG GGG\n          WWWWWWW  AA  AA  RR  RR  NN  NN    II    NN  NN  GG  GG\n           WW WW   AA  AA  RR  RR  NN  NN  IIIIII  NN  NN   GGGG" << endl << endl;
	if (!Language)
		cout << "В данной игре графика выполнена в виде символов и постоянно мерцает, в следствие чего может быть опасна для людей с эпилепсией.\nЕсли вы больны эпилепсией, я попрошу вас закрыть это приложение в целях вашей же безопастности. Спасибо" << endl;
	if (Language)
		cout << "In this game, the graphics are in the form of symbols and flicker constantly, as a result of which it can be dangerous for people with epilepsy.\nIf you have epilepsy, I ask you to close this application for your own safety. Thanks" << endl;
	system("pause");
	Main_Menu();
}

//настройки
void Level() {
	system("cls");
	if (Language) {
		cout << "Difficulty:\nEasy 1\nNormal 2\nHard 3\n_____________________\nExit 4\n_____________________" << endl;
		if (wall_killing)
			cout << "Walls kill: YES 5";
		if (!wall_killing)
			cout << "Walls kill: NO 5";
	}
	if (!Language) {
		cout << "Сложность:\nЛегко 1\nНормально 2\nСложно 3\n_____________________\nВыйти 4\n_____________________" << endl;
		if (wall_killing)
			cout << "Стены убивают: ДА 5";
		if (!wall_killing)
			cout << "Стены убивают: НЕТ 5";
	}
	cout << endl << endl;
	switch (_getch()) {
	case '1':
		level = 100;
		Level();
		break;
	case '2':
		level = 55;
		Level();
		break;
	case '3':
		level = 25;
		Level();
		break;
	case '4':
		Main_Menu();
		break;
	case '5':
		wall_killing = !wall_killing;
		Level();
		break;
	default:
		Level();
	}
}

//о разработчике
void Developer() {
	system("cls");
	if (!Language)
		cout << "Мои соц. сети:\n___________________________\nDiscord: Bubba#4211\nVK: @1blitz01\nTelegram: @an1onimes\n___________________________" << endl << endl;
	if (Language)
		cout << "My social networks:\n___________________________\nDiscord: Bubba#4211\nVK: @1blitz01\nTelegram: @an1onimes\n___________________________" << endl << endl;
	system("pause");
	Main_Menu();
}

//выбор языка
void language() {
	system("cls");
	Language = !Language;
	Main_Menu();
}

//удаление рекорда
void Delete() {
	char ye[5];
	system("cls");
	if (!Language) {
		cout << "Вы уверены что точно хотите удалить все игровые файлы? yes/no" << endl;
		cin >> ye;
		if (ye[0] == 'Y' || ye[0] == 'y') {
			if (remove("C:/Windows/Temp/Hight_Score.txt") != 0)
				cout << endl << endl << endl << ":3" << endl << endl << endl << endl;
			else
				cout << endl << endl << endl << ";-;" << endl << endl << endl << endl;
			Main_Menu();
		}
		else
			Main_Menu();
	}
	if (Language) {
		cout << "Are you sure you want to delete all game files? yes/no" << endl;
		cin >> ye;
		if (ye[0] == 'Y' || ye[0] == 'y') {
			if (remove("C:/Windows/Temp/Hight_Score.txt") != 0)
				cout << endl << endl << endl << "hfc" << endl << endl << endl << endl;
			else
				cout << endl << endl << endl << "cool dude" << endl << endl << endl << endl;
			Main_Menu();
		}
		else
			Main_Menu();
	}
}