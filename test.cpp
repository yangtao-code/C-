#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <string.h>

void swap(int& a, int& b)
{
	int tmp=a;
	a = b;
	b = tmp;
}


int main()
{
	int a = 10;
	int b = 20;

	swap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	int c = 20;
//	b = 100;
//	b = c;
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int* p = new int(20);
//	
//	cout << *p << endl;
//	delete p;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i <10; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			cout << setw(3) << left << i << "*" << j <<"="<< i * j << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
//			cout << "�����ӣ�" << endl;
//		else
//			cout << i << endl;
//		i++;
//	}
//	system("pause");
//	return 0;
//}

//��ӡˮ�ɻ���
//int main()
//{
//	int a, b, c;
//	int i = 100;
//	while (i < 1000)
//	{
//		a = i % 10;
//		b = i / 10 % 10;
//		c = i / 100;
//		if (a * a * a + b * b * b + c * c * c == i)
//			cout << i << endl;
//		i++;
//	}
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	do
//	{
//		cout << num << endl;
//		num++;
//	} while (num);
//
//
//}

//int main()
//{
//	char str[] = "baifgaiufhi";
//	int len = strlen(str);
//	cout<<"len= " <<len<<endl;
//	system("pause");
//
//}


//int main()
//{
//	int score = 0;
//	cout << "������߿�����" << endl;
//	cin >> score;
//	if (score > 600)
//	{
//		if (score > 700)
//		{
//			cout << "��ϲ�㿼���廪������" << endl;
//		}
//		else
//		{
//			cout << "��ϲ�㿼��һ��" << endl;
//		}
//	}
//	else if (score > 500)
//		cout << "��ϲ�㿼�϶�����" << endl;
//	else if (score > 400)
//		cout << "��ϲ�㿼��������" << endl;
//	else
//		cout << "���ź�����û���ϱ��ƣ�" << endl;
//	system("pause");
//	return 0;
//}



//int main()
//{
//	cout << "hello world" << endl;
//
//	int a = 0;
//	cout << "�����룺" << endl;
//	cin >> a;
//	cout << "a=" << a << endl;
//	string str;
//	cout << "�����룺" << endl;
//	cin >> str ;
//	cout << "str=" << str << endl;
//	system("pause");
//}
