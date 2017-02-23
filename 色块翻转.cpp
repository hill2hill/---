#include <iostream>
#include <cstdio>
#include <cmath>
#define N 200
using namespace std;

void OutPut(int a[][N], int n)
{
	for (int x = 0; x<n; x++)
	{
		for (int y = 0; y<n; y++)
		{
			if (a[x][y] == 1)
				cout << "X" << " ";
			else
				cout << "O" << " ";
		}
		cout << endl;
	}
}
void OneToZero(int  a[][N], int x, int y)
{
	if (a[x][y] == 1)
	{
		a[x][y] = 0;
	}
	else if (a[x][y] == 0)
	{
		a[x][y] = 1;
	}
}
void SetSwitchs(int  a[][N], int x, int y)
{
	if (x == 0 && y == 0)//影响3格
	{
		OneToZero(a, x, y);
		OneToZero(a, x + 1, y);
		OneToZero(a, x, y + 1);
	}
	else if ((x == 0) && (y != 0))//影响4格
	{
		OneToZero(a, x, y);
		OneToZero(a, x, y - 1);
		OneToZero(a, x, y + 1);
		OneToZero(a, x + 1, y);
	}
	else if ((x != 0) && (y == 0))//影响4格
	{
		OneToZero(a, x, y);
		OneToZero(a, x - 1, y);
		OneToZero(a, x + 1, y);
		OneToZero(a, x, y + 1);
	}

	else//影响5格
	{
		OneToZero(a, x, y);
		OneToZero(a, x - 1, y);
		OneToZero(a, x + 1, y);
		OneToZero(a, x, y - 1);
		OneToZero(a, x, y + 1);
	}
}

void refresh(int  a[][N])//全赋值为0
{
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			a[i][j] = 0;
		}
	}
}

int Initialize(int  a[N], int i, int n)//对第一行进行各种情况的赋值
{
	int p = i;
	for (int j = 0; j<n; j++)
	{
		a[n - j - 1] = p % 2;
		p = p / 2;
	}
	return 0;
}

int main()
{
	int n = 0;
	int a[N][N];
	int Changeposition[N][N];
	int t[N] = { 0 };
	while (cin >> n)
	{
		for (int i = 0; i <= pow( 2, n); i++)//若n=6：从000000枚举到000001再到111111，以此类推
		{
			refresh(a);
			refresh(Changeposition);
			int line, column;
			line = 0;
			Initialize(t, i, n);
			for (int p = 0; p < n; p++)
			{
				Changeposition[0][p] = t[p];
			}
			

			for (column = 0; column<n; column++)//第一行操作时也应该产生SetSwitchs效果；
			{
				if (t[column] == 1)
				{
					SetSwitchs(a, 0, column);
				}
			}


			for (line = 0; line<n - 1; line++)
			{
				for (column = 0; column<n; column++)
				{
					if (a[line][column] == 0)
					{
						SetSwitchs(a, (line + 1), column);
						Changeposition[line + 1][column] = 1;
					}
				}
			}


			for (column = 0; column<n; column++)
			{
				if (a[n - 1][column] == 0)
					break;
				else if (column == n - 1)
				{

					if (a[n - 1][column + 1] == 1)
					{
						OutPut(Changeposition, n);
						cout << endl;
					}
				}
			}
			

		}
		cout << endl;
	}
	return 0;
}