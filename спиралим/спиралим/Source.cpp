#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int tmp;
	string pvd;
	int l;
	int k = 1;

	/*
	int** matr = new int* [10];
	for (int i = 0; i < 10; i++)
		matr[i] = new int[10];
	*/

	while (true)
	{
		tmp = _getch();

		if (tmp == 13)
		{
			l = pvd.length();
			int t = ceil(sqrt(l));
			int N = t;
			//�������� ��������� ������������������ �� ��������
			for (int i = l; i < t*t; i++)
			{
				pvd = pvd + ' ';
			}
			//������� ������������ ������
			char** matr = new char* [N];
			for (int i = 0; i < N; i++)
			{
				matr[i] = new char[N];
			}
			//�������� �����������
			int mid = ceil(N / 2);
			if (N % 2 == 0)
			{
				mid = mid - 1;
			}
			//������ ������ ��������
			int x = mid;
			int y = mid;
			int m = 0;
			matr[y][x] = char(pvd[m]);
			m++;
			while (mid < N)
			{
				//������ ��� ������(���������, ����� �� ��� �������)
				for (int j = 0; j < k; j++)
				{
					x++;
					if (x >= N)
					{
						break;
					}
					matr[y][x] = char(pvd[m]);
					m++;
				}

				if (x >= N)
				{
					break;
				}
				//������ ��� ����
				for (int j = 0; j < k; j++)
				{
					y++;
					matr[y][x] = char(pvd[m]);
					m++;
				}
				//����������� ����� ���� ���������� ����������� � � ��� ������ ������ ��� ��������
				k++;
				//������ ��� �����
				for (int j = 0; j < k; j++)
				{
					x--;
					if (x < 0)
					{
						break;
					}
					matr[y][x] = char(pvd[m]);
					m++;
				}
				if (x < 0)
				{
					break;
				}
				//������ ��� �����
				for (int j = 0; j < k; j++)
				{
					y--;
					matr[y][x] = char(pvd[m]);
					m++;
				}
				k++;
				mid++;
			}
			// ������� ������������������
			for (int i = 0; i < t; i++)
			{
				for (int j = 0; j < t; j++)
				{
					cout << matr[i][j] << '\t';
				}
				cout << '\n';
			}
			
			break;
		}
		
		if (tmp < 13 || (tmp > 13 && tmp < 33) || (tmp > 127))
		{
			cout << "�������� ������\n";
			break;
		}

		pvd = pvd + char(tmp);

	}

	return 0;
}