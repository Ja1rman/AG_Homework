/*
�������� ���������, ��������� ����������� ����� ���������
2020X +2021Y=78487894
����������� ���������. � ������������ ��������, ������ ������� - �����������
*/
#include <iostream>

using namespace std;

int main() {
	int y = 38834;
	int x;
	for (;;)
	{
		if (((78487894 - 2021 * y) % 2020) == 0)
        {
			x = (78487894 - 2021 * y) / 2020;
			break;
		}
		y -= 10;
	}

	while (y > 0)
    {
		cout << x << " " << y << endl;
		y -= 2020;
		x += 2021;
	}
	return 0;
}
/*
��� ��� �� ����� ����� 4, �� ���� ����������� ������� Y � ������ 4 �� �����(����� ����������� ��� ��������� �����), � ����� ���� ������ ��� �����,
�������� �� 10, ��� ��� �� ����� ��� ����� �������� 4, ����� ���������� ������������� ����� ��������� Y �� 2020, � X ����������� �� 2021,
����� �������� ��� ��������� ���� �����
*/