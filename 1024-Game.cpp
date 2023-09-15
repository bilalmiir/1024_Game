#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void intro();
void newgame();
void display(int block[4][4]);
void each_move(int& first_row, int& first_col, int block[4][4]);
void inp(int block[4][4], char& move);
void help();
void exit();

int main()
{
	intro();
}

void intro()
{
	char option, m;

	cout << "\n\n\n";
	cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\t\t\t ** WELCOME TO 1024 **" << endl << endl;
	cout << "\t\t\t 1.New game" << endl;
	cout << "\t\t\t 2.Help" << endl;
	cout << "\t\t\t 3.Exit" << endl;
	cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	option = _getch();



	if (option == '1')
	{
		system("cls");
		newgame();
	}


	else if (option == '2')
	{
		system("cls");

		help();

	}

	else if (option == '3')
	{

		exit();
	}
	else
	{
		system("cls");

		intro();
	}

}

void help()
{
	cout << endl;
	cout << "1024 Game is Logic & Problem Solving game." << endl;
	cout << "The object of the game is to combine the numbers displayed on the tiles until you reach 1024." << endl << endl;
	cout << "How to play :\n\nUse your arrow keys or W S D A to move the tiles." << endl;
	cout << "When two tiles with the same number touch, they merge into one tile with same number they summed to one." << endl;
	cout << "\n\nPress M to return to main menu." << endl;

	char m;
	m = _getch();

	if (m == 'm' || m == 'M')
	{
		system("cls");

		intro();
	}
	else
	{
		system("cls");

		help();
	}

}
void exit()
{
	char option;

	system("cls");
	cout << "Are you sure want to exit? \n";

	cout << "1.Yes\t\t2.No\n";
	option = _getch();

	while (option != 1)
	{
		if (option == '1')
		{
			system("cls");
			cout << "***Thank you***" << endl;
			break;
		}
		else if (option == '2')
		{
			system("cls");
			intro();
			break;
		}
	}
}



void newgame()
{
	int block[4][4];
	char move;
	int m;

	srand(time(NULL));

	int first_row, first_col;

	first_row = rand() % 4;

	first_col = rand() % 4;

	block[first_row][first_col] = 1;

	int sec_row, sec_col;

	sec_row = rand() % 4;

	sec_col = rand() % 4;

	block[sec_row][sec_col] = 1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((i == first_row && j == first_col) || (i == sec_row && j == sec_col))
			{

			}

			else
			{
				block[i][j] = 0;
			}
		}
	}


	display(block);

	int i = 0, j = 0;


	while (block[i][j] != 1024)
	{
		inp(block, move);

		each_move(first_row, first_col, block);
	}
}

void display(int block[4][4])
{
	cout << "Press q any time to return to main menu." << endl;

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			cout << "\n\n\n";

			cout << "\t\t\t ______________________________" << endl;
		}
		cout << "\t\t\t ";

		for (int j = 0; j < 4; j++)
		{
			if (block[i][j] == 0)
			{
				cout << "|   ";

			}

			else
			{
				cout << "|  " << block[i][j];
			}
			if (j == 3)
			{
				cout << "  |";
			}
			else
			{
				cout << "\t";
			}
		}

		cout << endl;

		cout << "\t\t\t ______________________________" << endl;
	}

}

void each_move(int& first_row, int& first_col, int block[4][4])
{
	system("cls");

	bool check = true;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[i][j] == 0)
			{
				check = false;
				break;
			}
		}
	}

	if (check == true)
	{
		cout << "You Lose";
	}

	while (true)
	{
		first_row = rand() % 4;

		first_col = rand() % 4;

		if (block[first_row][first_col] == 0)
		{
			block[first_row][first_col] = 1;

			break;
		}
	}

	cout << "Press q any time to return to main menu." << endl;

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			cout << "\n\n\n";

			cout << "\t\t\t ______________________________" << endl;
		}
		cout << "\t\t\t ";

		for (int j = 0; j < 4; j++)
		{
			if (block[i][j] == 0)
			{
				cout << "|   ";
			}
			else
			{
				cout << "|  " << block[i][j];
			}

			if (j == 3)
			{
				cout << "  |";
			}
			else
			{
				cout << "\t";
			}
		}

		cout << endl;

		cout << "\t\t\t ______________________________" << endl;
	}
}

void inp(int block[4][4], char& move)
{
	int i = 0, j = 0;
	int m, k;

	move = _getch();
	system("cls");

	if (move == 'w' || move == 'W')
	{
		for (j = 0; j < 4; j++)
		{
			m = 0;
			k = j;

			for (i = 1; i < 4; i++)
			{
				if (block[i][j] > 0)
				{
					if ((block[i - 1][j] == block[i][j] || (block[i - 1][j] == 0)) && (block[m][k] == block[i][j]))
					{
						block[m][k] = block[i][j] + block[m][k];

						block[i][j] = 0;
					}

					else if ((block[i - 1][j] == block[i][j] || block[i - 1][j] == 0) && (block[m][k] == 0))
					{
						block[m][k] = block[i][j];

						block[i][j] = 0;
					}

					else if ((block[i - 1][j] == block[i][j] || (block[i - 1][j] == 0)) && (block[m][k] > 0))
					{
						m = m + 1;

						block[m][k] = block[i][j];

						block[i][j] = 0;
					}

					else
					{
						m++;
					}
				}

			}
		}
	}


	else if (move == 'a' || move == 'A')
	{
		for (i = 0; i < 4; i++)
		{
			m = i;
			k = 0;

			for (j = 1; j < 4; j++)
			{
				if (block[i][j] > 0)
				{
					if ((block[i][j - 1] == block[i][j] || block[i][j - 1] == 0) && block[m][k] == block[i][j])
					{
						block[m][k] = block[i][j] + block[m][k];
						block[i][j] = 0;
					}

					else if ((block[i][j - 1] == block[i][j] || block[i][j - 1] == 0) && block[m][k] == 0)
					{
						block[m][k] = block[i][j];
						block[i][j] = 0;
					}
					else if ((block[i][j - 1] == block[i][j] || block[i][j - 1] == 0) && block[m][k] > 0)
					{
						k = k + 1;
						block[m][k] = block[i][j];
						block[i][j] = 0;
					}
					else
					{
						k++;
					}
				}
			}
		}

	}

	else if (move == 's' || move == 'S')
	{
		for (j = 0; j < 4; j++)
		{
			m = 3;
			k = j;

			for (i = 2; i >= 0; i--)
			{
				if (block[i][j] > 0)
				{
					if ((block[i + 1][j] == block[i][j] || (block[i + 1][j] == 0)) && (block[m][k] == block[i][j]))
					{
						block[m][k] = block[i][j] + block[m][k];

						block[i][j] = 0;
					}

					else if ((block[i + 1][j] == block[i][j] || block[i + 1][j] == 0) && (block[m][k] == 0))
					{
						block[m][k] = block[i][j];

						block[i][j] = 0;
					}

					else if ((block[i + 1][j] == block[i][j] || (block[i + 1][j] == 0)) && (block[m][k] > 0))
					{
						m = m - 1;

						block[m][k] = block[i][j];

						block[i][j] = 0;
					}

					else
					{
						m--;
					}
				}

			}
		}

	}

	else if (move == 'd' || move == 'D')
	{
		for (i = 0; i < 4; i++)
		{
			m = i;
			k = 3;

			for (j = 2; j >= 0; j--)
			{
				if (block[i][j] > 0)
				{
					if ((block[i][j + 1] == block[i][j] || block[i][j + 1] == 0) && block[m][k] == block[i][j])
					{
						block[m][k] = block[i][j] + block[m][k];
						block[i][j] = 0;
					}

					else if ((block[i][j + 1] == block[i][j] || block[i][j + 1] == 0) && block[m][k] == 0)
					{
						block[m][k] = block[i][j];
						block[i][j] = 0;
					}
					else if ((block[i][j + 1] == block[i][j] || block[i][j + 1] == 0) && block[m][k] > 0)
					{
						k = k - 1;
						block[m][k] = block[i][j];
						block[i][j] = 0;
					}
					else
					{
						k--;
					}
				}
			}
		}

	}


	else if (move == 'q' || move == 'Q')
	{
		while (move == 'q')
		{
			system("cls");
			intro();
			break;
		}
	}

}