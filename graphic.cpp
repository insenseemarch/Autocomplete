#include "Header.h"

int comparison_count = 0;

void gotoyx(int y, int x)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

string borderHelloScreen(int y, int x, int max_y, int max_x)
{
	if (y == 0 && x == 0) {

		return "/";
	}
	else if (y == 0 && x == max_x - 1) {

		return "\\";
	}
	else if (y == max_y - 1 && x == 0) {

		return "\\";
	}
	else if (y == max_y - 1 && x == max_x - 1) {

		return "/";
	}
	else if (x == 0 || x == max_x - 1)
	{

		return "|";
	}
	else if (y == 0 || y == max_y - 1) {

		return "-";
	}
	else
	{

		return " ";
	}
}

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int getThingColor(string c)
{
	if (c == "/" || c == "\\")
		return 11;
	else if (c == "|")
		return 14;
	else if (c == "-")
		return 10;
	else
		return 15;
}

void drawFrame(int max_y, int max_x)
{

	for (int i = 0; i < max_y; i++)
	{
		gotoyx(i + 1, 38);

		for (int j = 0; j < max_x; j++)
		{

			string m = borderHelloScreen(i, j, max_y, max_x);
			color(getThingColor(m));
			cout << m;
		}
	}
}

void helloScreen() 
{
	int max_y = 18;
	int max_x = 46;

	for (int i = 0; i < max_y; i++) {
		gotoyx(i + 1, 38);

		for (int j = 0; j < max_x; j++) {

			string m = borderHelloScreen(i, j, max_y, max_x);
			color(getThingColor(m));
			cout << m;
		}
	}
	gotoyx(3, 56);
	cout << "Welcome to: " << endl;

	color(9);
	gotoyx(5, 46);
	cout << "TTTTTT RRRRR  IIIIII EEEEE " << endl;
	gotoyx(6, 45);
	cout << "   T    R   R    I    E     " << endl;
	gotoyx(7, 45);
	cout << "   T    RRRR     I    EEEE  " << endl;
	gotoyx(8, 45);
	cout << "   T    R  R     I    E     " << endl;
	gotoyx(9, 45);
	cout << "   T    R   R  IIIIII EEEEE " << endl;


	color(7);
	gotoyx(13, 45);
	cout << "This Trie program is created by " << endl;
	color(9);
	gotoyx(14, 41);
	cout << "[23CTT2 | 23120172 - Tran Thi Thuy Tien]" << endl;
	color(7);
	gotoyx(16, 46);
	cout << "Please press any key to start!" << endl;
	_getch(); // Waiting for user to press any key before starting to play game.
	system("cls");
}

void start()
{
	HWND hwnd = GetConsoleWindow();
	LONG cur_style = GetWindowLong(hwnd, GWL_EXSTYLE);
	SetWindowLong(hwnd, GWL_EXSTYLE, cur_style | WS_EX_TRANSPARENT | WS_EX_LAYERED);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hConsole, &dwMode);
	dwMode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hConsole, dwMode);
	helloScreen();
	gotoyx(7, 10);
	system("cls");
	menu();
}

void menu()
{
	int counter = 1;
	int Set[] = { 7, 7, 7, 7, 7 }; // Default colors
	char key;
	drawFrame(18, 46);
	for (int i = 0;;)
	{
		color(3);

		// Using ENGLISH
		gotoyx(3, 58);
		cout << "MENU" << endl;
		color(7);
		gotoyx(4, 48);
		cout << "+------------------------+";
		gotoyx(5, 48);
		color(Set[0]);
		cout << "|  1. Map                |" << endl;
		color(7);
		gotoyx(6, 48);
		cout << "+------------------------+";
		gotoyx(7, 48);
		color(Set[1]);
		cout << "|  2. Trie Tree          |" << endl;
		color(7);

		gotoyx(8, 48);
		cout << "+------------------------+";
		gotoyx(9, 48);
		color(Set[2]);
		cout << "|  3. Radix Tree         |" << endl;
		color(7);

		gotoyx(10, 48);
		cout << "+------------------------+";
		gotoyx(11, 48);
		color(Set[3]);
		cout << "|  4. How to use         |" << endl;
		color(7);

		gotoyx(12, 48);
		cout << "+------------------------+";
		gotoyx(13, 48);
		color(Set[4]);
		cout << "|  5. Exit               |" << endl;
		color(7);

		gotoyx(14, 48);
		cout << "+------------------------+";

		key = _getch();
		if (key == 72 && (counter >= 2 && counter <= 5)) // 72 = up arrow key
		{
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 4)) // 80 = down arrow key
		{
			counter++;
		}

		if (key == '\r') // 72 = up arrow key
		{
			if (counter == 1)
			{
				while (true)
				{
					system("cls");
					hashSetting();
					break;
				}
			}
			if (counter == 2)
			{
				while (true)
				{
					system("cls");
					trieSetting();
					break;
				}
			}
			if (counter == 3)
			{
				while (true)
				{
					system("cls");
					radixSetting();
					break;
				}
			}
			if (counter == 4)
			{
				while (true)
				{

					system("cls");
					int max_y = 22;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "HOW TO USE" << endl << endl;
					//Set[2] = 11;
					color(11);
					gotoyx(5, 31);
					cout << "1. Words suggestion.";
					gotoyx(6, 31);
					color(7);
					cout << "       User will put in a prefix, program will show k words" << endl;
					gotoyx(7, 31);
					cout << "       in the dictionary which are started with prefix." << endl;
					color(11);
					gotoyx(8, 31);
					cout << "2. Words adding." << endl;
					color(7);
					gotoyx(9, 31);
					cout << "       User will put in a word, program will add that word" << endl;
					gotoyx(10, 31);
					cout << "       in the dictionary." << endl;
					gotoyx(11, 31);
					color(11);
					cout << "3. Words removing" << endl;
					gotoyx(12, 31);
					color(7);
					cout << "       User will put in a word, program will remove that word" << endl;
					gotoyx(13, 31);
					cout << "       in the dictionary." << endl;
					gotoyx(14, 31);
					system("pause");
					gotoyx(15, 31);
					color(11);
					cout << "Back to the menu (Y: Yes / N: No)? " << endl;
					char choose = _getch();

					if (choose == 'Y' || choose == 'y')
					{
						system("cls");
						color(7);
						drawFrame(18, 46);
						break;
					}
					else if (choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n')
					{
						gotoyx(19, 31);
						color(12);
						cout << "Please choose again, this in not in our choice." << endl;
						gotoyx(20, 31);
						color(7);
						system("pause");
					}
				}
			}
			if (counter == 5)
			{
				color(7);
				system("cls");
				exit(0);
			}

		}
		else
		{
			Set[0] = 7; // Default white color
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			Set[4] = 7;

			if (counter == 1)
			{
				Set[0] = 14; // 12 is color red
			}
			if (counter == 2)
			{
				Set[1] = 14; // 12 is color red
			}
			if (counter == 3)
			{
				Set[2] = 14; // 12 is color red
			}
			if (counter == 4)
			{
				Set[3] = 14;
			}
			if (counter == 5)
			{
				Set[4] = 14;
			}
		}
	}
}

void hashSetting()
{
	int max_y = 18;
	int max_x = 46;

	for (int i = 0; i < max_y; i++) {
		gotoyx(i + 1, 38);

		for (int j = 0; j < max_x; j++) {

			string m = borderHelloScreen(i, j, max_y, max_x);
			color(getThingColor(m));
			cout << m;
		}
	}
	int Set[] = { 7, 7, 7, 7 }; // Default colors
	int counter = 1;
	char key;
	int option = 0;
	//system("cls");
	//drawFrame(18, 46);
	string filename = "words_alpha.txt"; // File chứa các từ khóa
	vector<string> words = readFromFile(filename);

	// Khởi tạo bảng băm
	HashTable hashTable;
	for (const auto& word : words)
	{
		hashInsert(hashTable, word);
	}
	string prefix;
	for (int i = 0;;)
	{
		gotoyx(3, 54);
		color(3);
		gotoyx(3, 54);
		cout << "MAP" << endl;

		color(7);
		gotoyx(4, 48);
		cout << "+------------------------+";
		gotoyx(5, 48);
		color(Set[0]);
		cout << "| 1. Words suggestion    |" << endl;

		color(7);
		gotoyx(6, 48);
		cout << "+------------------------+";
		gotoyx(7, 48);
		color(Set[1]);
		cout << "| 2. Add word            |" << endl;

		color(7);
		gotoyx(8, 48);
		cout << "+------------------------+";
		gotoyx(9, 48);
		color(Set[2]);
		cout << "| 3. Remove word         |" << endl;

		gotoyx(10, 48);
		color(7);
		cout << "+------------------------+";
		gotoyx(11, 48);
		color(Set[3]);
		cout << "| 4. Back to menu        |" << endl;

		gotoyx(12, 48);
		color(7);
		cout << "+------------------------+";

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 4)) // 72 = up arrow key
		{
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 3)) // 80 = down arrow key
		{
			counter++;
		}


		if (key == '\r') // 72 = up arrow key
		{
			system("cls");
			// Chèn các từ từ file vào bảng băm
			//break;
			if (counter == 1)
			{
			first_choice:
				while (true)
				{
					// Reset biến đếm trước khi gọi hàm suggest
					comparison_count = 0;

					int choice = 0;
					int k = 0;
					int max_y = 28;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "WORDS SUGGEST" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type your word: ";
					cin >> prefix;
					gotoyx(7, 31);
					cout << "Number of suggestion-keyword: ";
					cin >> k;
					int x_pos = 11;
					{
						auto start = chrono::high_resolution_clock::now(); // Bắt đầu đo thời gian
						vector<string> suggestions = hashSuggest(hashTable, prefix, k);
						auto end = chrono::high_resolution_clock::now(); // Kết thúc đo thời gian

						if (suggestions.empty())
						{
							gotoyx(9, 31);
							color(4);
							cout << "Incorrect input." << endl;
						}
						else
						{
							gotoyx(9, 31);
							color(11);
							cout << "Successfully looking your keyword up in the dictionary. ";
							gotoyx(10, 31);
							color(11);
							cout << "Here are your results: ";
							int i = 1;
							color(7);
							for (const string& s : suggestions)
							{
								gotoyx(x_pos++, 37);
								cout << i++ << ". " << s << "\n";
							}
							if (i < k)
							{
								x_pos++;
								gotoyx(x_pos++, 31);
								color(11);
								cout << "This is all words that appears in dictionary!" << endl;
							}
							//gotoyx(x_pos++, 31);
							//color(11);
							//chrono::duration<double, milli> duration = end - start; // Tính thời gian chạy
							//cout << "Time: " << duration.count() << " ms" << endl;
							//gotoyx(x_pos++, 31);
							//cout << "Count: " << comparison_count;

						}
					}
					//break;

					gotoyx(x_pos++, 31);
					system("pause");
					gotoyx(x_pos++, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / Else: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto first_choice;
						}
					} while (choose);
					break;
				}
			}
			if (counter == 2)
			{
			second_choice:
				while (true)
				{
					int max_y = 26;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "ADD WORD" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type a word needed to be added: ";
					cin >> prefix;
					hashInsert(hashTable, prefix);
					gotoyx(7, 31);
					color(11);
					cout << "Successfully adding it to the map.\n";
					color(7);
					gotoyx(8, 31);
					system("pause");
					gotoyx(9, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / N: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto second_choice;
						}
					} while (choose);
					break;
				}
			}
			else if (counter == 3)
			{
			third_choice:
				while (true)
				{
					int max_y = 26;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "REMOVE WORD" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type a word needed to be removed: ";
					cin >> prefix;
					hashRemove(hashTable, prefix);
					/*gotoyx(7, 31);
					color(11);
					cout << "Successfully removing it to the hash table.\n";*/
					color(7);
					color(7);
					gotoyx(9, 31);
					system("pause");
					gotoyx(11, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / N: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto third_choice;
						}
					} while (choose);
					break;
				}
			}
			else if (counter == 4)
			{
				system("cls");
				drawFrame(18, 46);
				break;
			}
		}
		else
		{
			Set[0] = 7; // Default white color
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			if (counter == 1)
			{
				Set[0] = 14; // 12 is color red
			}
			if (counter == 2)
			{
				Set[1] = 14; // 12 is color red
			}
			if (counter == 3)
			{
				Set[2] = 14; // 12 is color red
			}
			if (counter == 4)
			{
				Set[3] = 14; // 12 is color red
			}
		}
	}
}

void radixSetting()
{
	int max_y = 18;
	int max_x = 46;

	for (int i = 0; i < max_y; i++) {
		gotoyx(i + 1, 38);

		for (int j = 0; j < max_x; j++) {

			string m = borderHelloScreen(i, j, max_y, max_x);
			color(getThingColor(m));
			cout << m;
		}
	}
	int Set[] = { 7, 7, 7, 7 }; // Default colors
	int counter = 1;
	char key;
	int option = 0;
	RadixTreeNode* root = new RadixTreeNode();

	// Đọc từ file và xây dựng Radix Tree
	ifstream input("words_alpha.txt");
	string line;
	while (input >> line) {
		radixInsert(root, line);
	}
	input.close();
	string prefix;
	for (int i = 0;;)
	{
		gotoyx(3, 54);
		color(3);
		gotoyx(3, 54);
		cout << "RADIX TREE" << endl;

		color(7);
		gotoyx(4, 48);
		cout << "+------------------------+";
		gotoyx(5, 48);
		color(Set[0]);
		cout << "| 1. Words suggestion    |" << endl;

		color(7);
		gotoyx(6, 48);
		cout << "+------------------------+";
		gotoyx(7, 48);
		color(Set[1]);
		cout << "| 2. Add word            |" << endl;

		color(7);
		gotoyx(8, 48);
		cout << "+------------------------+";
		gotoyx(9, 48);
		color(Set[2]);
		cout << "| 3. Remove word         |" << endl;

		gotoyx(10, 48);
		color(7);
		cout << "+------------------------+";
		gotoyx(11, 48);
		color(Set[3]);
		cout << "| 4. Back to menu        |" << endl;

		gotoyx(12, 48);
		color(7);
		cout << "+------------------------+";

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 4)) // 72 = up arrow key
		{
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 3)) // 80 = down arrow key
		{
			counter++;
		}

		if (key == '\r') // 72 = up arrow key
		{
			system("cls");
			//drawFrame(18, 46);
			//break;
			if (counter == 1)
			{
			first_choice:
				while (true)
				{
					// Reset biến đếm trước khi gọi hàm suggest
					comparison_count = 0;

					int choice = 0;
					int k = 0;
					int max_y = 28;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "WORDS SUGGEST" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type your word: ";
					cin >> prefix;
					gotoyx(7, 31);
					cout << "Number of suggestion-keyword: ";
					cin >> k;
					int x_pos = 11;
					{
						auto start = chrono::high_resolution_clock::now(); // Bắt đầu đo thời gian
						vector<string> suggestions = radixSuggest(root, prefix, k);
						auto end = chrono::high_resolution_clock::now(); // Kết thúc đo thời gian

						if (suggestions.empty())
						{
							gotoyx(9, 31);
							color(4);
							cout << "Incorrect input." << endl;
						}
						else
						{
							gotoyx(9, 31);
							color(11);
							cout << "Successfully looking your keyword up in the dictionary. ";
							gotoyx(10, 31);
							color(11);
							cout << "Here are your results: ";
							int i = 1;
							color(7);
							for (const string& s : suggestions)
							{
								gotoyx(x_pos++, 37);
								cout << i++ << ". " << s << "\n";
							}
							if (i < k)
							{
								x_pos++;
								gotoyx(x_pos++, 31);
								color(11);
								cout << "This is all words that appears in dictionary!" << endl;
							}
							//gotoyx(x_pos++, 31);
							//color(11);
							//chrono::duration<double, milli> duration = end - start; // Tính thời gian chạy
							//cout << "Time: " << duration.count() << " ms" << endl;
							//gotoyx(x_pos++, 31);
							//cout << "Count: " << comparison_count;

						}
					}
					//break;

					gotoyx(x_pos++, 31);
					system("pause");
					gotoyx(x_pos++, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / Else: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto first_choice;
						}
					} while (choose);
					break;
				}
			}
			if (counter == 2)
			{
			second_choice:
				while (true)
				{
					int max_y = 26;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "ADD WORD" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type a word needed to be added: ";
					cin >> prefix;
					radixAddKeyword(root, prefix);
					gotoyx(7, 31);
					color(11);
					cout << "Successfully adding it to the radix tree.\n";
					color(7);
					gotoyx(8, 31);
					system("pause");
					gotoyx(9, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / N: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto second_choice;
						}
					} while (choose);
					break;
				}
			}
			else if (counter == 3)
			{
			third_choice:
				while (true)
				{
					int max_y = 26;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "REMOVE WORD" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type a word needed to be removed: ";
					cin >> prefix;
					deleteKeyword(root, prefix);
					/*gotoyx(7, 31);
					color(11);
					cout << "Successfully removing it to the hash table.\n";*/
					color(7);
					color(7);
					gotoyx(9, 31);
					system("pause");
					gotoyx(11, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / N: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto third_choice;
						}
					} while (choose);
					break;
				}
			}
			else if (counter == 4)
			{
				system("cls");
				drawFrame(18, 46);
				break;
			}
		}
		else
		{
			Set[0] = 7; // Default white color
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			if (counter == 1)
			{
				Set[0] = 14; // 12 is color red
			}
			if (counter == 2)
			{
				Set[1] = 14; // 12 is color red
			}
			if (counter == 3)
			{
				Set[2] = 14; // 12 is color red
			}
			if (counter == 4)
			{
				Set[3] = 14; // 12 is color red
			}
		}
	}
}

void trieSetting()
{
	int max_y = 18;
	int max_x = 46;

	for (int i = 0; i < max_y; i++) {
		gotoyx(i + 1, 38);

		for (int j = 0; j < max_x; j++) {

			string m = borderHelloScreen(i, j, max_y, max_x);
			color(getThingColor(m));
			cout << m;
		}
	}
	int Set[] = { 7, 7, 7, 7 }; // Default colors
	int counter = 1;
	char key;
	int option = 0;
	Trie trie;
	loadFromFile(trie, "words_alpha.txt"); // Nạp từ khóa từ file

	int choice;
	string prefix;
	int k;
	for (int i = 0;;)
	{
		gotoyx(3, 54);
		color(3);
		gotoyx(3, 54);
		cout << "TRIE TREE" << endl;

		color(7);
		gotoyx(4, 48);
		cout << "+------------------------+";
		gotoyx(5, 48);
		color(Set[0]);
		cout << "| 1. Words suggestion    |" << endl;

		color(7);
		gotoyx(6, 48);
		cout << "+------------------------+";
		gotoyx(7, 48);
		color(Set[1]);
		cout << "| 2. Add word            |" << endl;

		color(7);
		gotoyx(8, 48);
		cout << "+------------------------+";
		gotoyx(9, 48);
		color(Set[2]);
		cout << "| 3. Remove word         |" << endl;

		gotoyx(10, 48);
		color(7);
		cout << "+------------------------+";
		gotoyx(11, 48);
		color(Set[3]);
		cout << "| 4. Back to menu        |" << endl;

		gotoyx(12, 48);
		color(7);
		cout << "+------------------------+";

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 4)) // 72 = up arrow key
		{
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 3)) // 80 = down arrow key
		{
			counter++;
		}

		if (key == '\r') // 72 = up arrow key
		{
			system("cls");
			//drawFrame(18, 46);
			//break;
			if (counter == 1)
			{
			first_choice:
				while (true)
				{
					// Reset biến đếm trước khi gọi hàm suggest
					comparison_count = 0;

					int choice = 0;
					int k = 0;
					int max_y = 28;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "WORDS SUGGEST" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type your word: ";
					cin >> prefix;
					gotoyx(7, 31);
					cout << "Number of suggestion-keyword: ";
					cin >> k;
					int x_pos = 11;
					{
						auto start = chrono::high_resolution_clock::now(); // Bắt đầu đo thời gian
						vector<string> suggestions = trieSuggest(trie, prefix, k);
						auto end = chrono::high_resolution_clock::now(); // Kết thúc đo thời gian

						if (suggestions.empty())
						{
							gotoyx(9, 31);
							color(4);
							cout << "Incorrect input." << endl;
						}
						else
						{
							gotoyx(9, 31);
							color(11);
							cout << "Successfully looking your keyword up in the dictionary. ";
							gotoyx(10, 31);
							color(11);
							cout << "Here are your results: ";
							int i = 1;
							color(7);
							for (const string& s : suggestions)
							{
								gotoyx(x_pos++, 37);
								cout << i++ << ". " << s << "\n";
							}
							if (i < k)
							{
								x_pos++;
								gotoyx(x_pos++, 31);
								color(11);
								cout << "This is all words that appears in dictionary!" << endl;
							}
							//gotoyx(x_pos++, 31);
							//color(11);
							//chrono::duration<double, milli> duration = end - start; // Tính thời gian chạy
							//cout << "Time: " << duration.count() << " ms" << endl;
							//gotoyx(x_pos++, 31);
							//cout << "Count: " << comparison_count;

						}
					}
					//break;

					gotoyx(x_pos++, 31);
					system("pause");
					gotoyx(x_pos++, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / Else: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto first_choice;
						}
					} while (choose);
					break;
				}
			}
			if (counter == 2)
			{
			second_choice:
				while (true)
				{
					int max_y = 26;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "ADD WORD" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type a word needed to be added: ";
					cin >> prefix;
					trieInsert(trie, prefix);
					gotoyx(7, 31);
					color(11);
					cout << "Successfully adding it to the trie.\n";
					color(7);
					gotoyx(8, 31);
					system("pause");
					gotoyx(9, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / N: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto second_choice;
						}
					} while (choose);
					break;
				}
			}
			else if (counter == 3)
			{
			third_choice:
				while (true)
				{
					int max_y = 26;
					int max_x = 65;

					for (int i = 0; i < max_y; i++)
					{
						gotoyx(i + 1, 28);

						for (int j = 0; j < max_x; j++)
						{

							string m = borderHelloScreen(i, j, max_y, max_x);
							color(getThingColor(m));
							cout << m;
						}
					}
					gotoyx(3, 51);
					color(3);
					cout << "REMOVE WORD" << endl << endl;
					Set[2] = 7;
					color(Set[2]);
					gotoyx(5, 31);
					cout << "Type a word needed to be removed: ";
					cin >> prefix;
					trieRemove(trie, prefix);
					/*gotoyx(7, 31);
					color(11);
					cout << "Successfully removing it to the trie.\n";*/
					color(7);
					color(7);
					gotoyx(8, 31);
					system("pause");
					gotoyx(9, 31);
					color(7);
					cout << "Back to the menu (Y: Yes / N: No)? " << endl;
					char choose = _getch();

					do
					{
						if (choose == 'Y' || choose == 'y')
						{
							system("cls");
							drawFrame(18, 46);
							break;
						}
						else
						{
							system("cls");
							goto third_choice;
						}
					} while (choose);
					break;
				}
			}
			else if (counter == 4)
			{
				system("cls");
				drawFrame(18, 46);
				break;
			}
		}
		else
		{
			Set[0] = 7; // Default white color
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			if (counter == 1)
			{
				Set[0] = 14; // 12 is color red
			}
			if (counter == 2)
			{
				Set[1] = 14; // 12 is color red
			}
			if (counter == 3)
			{
				Set[2] = 14; // 12 is color red
			}
			if (counter == 4)
			{
				Set[3] = 14; // 12 is color red
			}
		}
	}
}