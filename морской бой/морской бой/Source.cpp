#include <time.h>
#include <iostream>

using namespace std;

const int N = 12;

void createField(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void printField(int arr[N][N])
{
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 1; j < N-1; j++)
		{
			cout << arr[i][j]<<' ';
		}
		cout << endl;
	}
}

bool oobck(int x, int y, int l, int k, int N = 12)
{
	//rabotaet
	if ((l && y > N - k) || (!l && x > N - k) || x == 0 || y == 0 || x == 11 || y == 11)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void create_k_Ship(int arr[N][N],int k)
{
	int m = 2;
	int n = k + 1;
	int x, y, l;
	
	int stop = 1;
	while (stop)
	{
		do
		{
			x = rand() % 10;
			y = rand() % 10;
			l = rand() % 2;
		} while (!(oobck(x, y, l, k)));
		int flag = 1;
		if (l)
		{
			//checking the territory
			for (int i = -1; i < m; i++)
			{
				for (int j = -1; j < n; j++)
				{
					if (arr[y + i][x + j])
					{
						flag = 0;
						break;
					}
				}
				if (!flag)
				{
					break;
				}

			}
			if (!flag)
			{
				continue;
			}
			//creating a ship
			for (int i = 0; i < k; i++)
			{
				arr[y][x + i] = 1;
			}
			stop = 0;
		}
		else
		{
			//checking the territory
			for (int i = -1; i < n; i++)
			{
				for (int j = -1; j < m; j++)
				{
					if (arr[y + i][x + j])
					{
						flag = 0;
						break;
					}
				}
				if (!flag)
				{
					break;
				}

			}
			if (!flag)
			{
				continue;
			}
			//creating a ship
			for (int i = 0; i < k; i++)
			{
				arr[y + i][x] = 1;
			}
			stop = 0;
		}
	}
	
}

void print_empty(int arr[N][N])
{
	char brr[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			brr[i][j] = ' ';
		}
	}
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			if (arr[i][j])
			{
				brr[i][j] = 'S';
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << brr[i][j]<<' ';
		}
		cout << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	char t;
	
	while (true)
	{
		int arr[N][N];
		createField(arr);
		create_k_Ship(arr, 4);

		create_k_Ship(arr, 3);
		create_k_Ship(arr, 3);

		create_k_Ship(arr, 2);
		create_k_Ship(arr, 2);
		create_k_Ship(arr, 2);


		create_k_Ship(arr, 1);
		create_k_Ship(arr, 1);
		create_k_Ship(arr, 1);
		create_k_Ship(arr, 1);

		//printField(arr);

		print_empty(arr);

		
		cin >> t;
	}
	
}