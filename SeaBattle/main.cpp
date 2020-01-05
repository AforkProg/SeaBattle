#include <iostream>
#include <ctime>
using namespace std;
void shipsSet(int size, int field[10][10])
{
	bool check = 0;
	int dir;
	int str;
	int sto;
	while (check != 1)
	{
		str = rand() % 10;
		sto = rand() % 10;
		dir = rand() % 4;
		int cSize = 0;
		while(cSize != size)
		{
			if (str < 0 || str >= 10 || sto < 0 || sto >= 10)
			{
				check = 0;
				cSize = 0;
				break;
			}
			else if (field[str][sto] == 1 || field[str - 1][sto] == 1 || field[str - 1][sto + 1] == 1 || field[str][sto + 1] == 1 || field[str + 1][sto + 1]
				|| field[str + 1][sto] == 1 || field[str + 1][sto - 1] == 1 || field[str][sto - 1] == 1 || field[str - 1][sto - 1] == 1)
			{
				check = 0;
				cSize = 0;
				break;
			}
			else
			{
				if (dir == 0)
				{
					str++;
					cSize++;
				}
				else if (dir == 1)
				{
					str--;
					cSize++;
				}
				else if (dir == 2)
				{
					sto++;
					cSize++;
				}
				else if (dir == 3)
				{
					sto--;
					cSize++;
				}
				if (cSize == size)
				{
					for (int a = 0; a < size; a++)
					{
						if (size == 1)
						{
							if (dir == 0)
							{
								str--;
								field[str][sto] = 1;
							}
							else if (dir == 1)
							{
								str++;
								field[str][sto] = 1;
							}
							else if (dir == 2)
							{
								sto--;
								field[str][sto] = 1;
							}
							else if (dir == 3)
							{
								sto++;
								field[str][sto] = 1;
							}
						}
						else
						{
							if (dir == 0)
							{
								field[str][sto] = 1;
								str--;
							}
							else if (dir == 1)
							{
								field[str][sto] = 1;
								str++;
							}
							else if (dir == 2)
							{
								field[str][sto] = 1;
								sto--;
							}
							else if (dir == 3)
							{
								field[str][sto] = 1;
								sto++;
							}
						}
					}
					check = 1;
					break;
				}
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	int field[10][10];
	for (int a = 0; a < 10; a++)
	{
		for (int i = 0; i < 10; i++)
		{
			field[a][i] = 0;
		}
	}
	int size = 4;
	shipsSet(4, field);
	shipsSet(3, field);
	shipsSet(3, field);
	shipsSet(2, field);
	shipsSet(2, field);
	shipsSet(2, field);
	shipsSet(1, field);
	shipsSet(1, field);
	shipsSet(1, field);
	shipsSet(1, field);
	for (int a = 0; a < 10; a++)
	{
		cout << endl;
		for (int i = 0; i < 10; i++)
		{
			if (field[a][i] == 0)
			{
				cout << '.';
			}
			else if (field[a][i] == 1)
			{
				cout << 'X';
			}
		}
	}
	system("pause");
	return 0;
}