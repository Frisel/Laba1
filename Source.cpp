#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	char buff[50];
	vector <int> a;
	int r, num;
	cout << "������� ������������������ �����." << endl << " ��� ������ ������� q" << endl;
	while (cin >> num)
		a.push_back(num);
	cout << "���� ������������������" << endl;
	for (auto x : a)
		cout << x << " ";
	cout << "������ �������" << size(a) << endl;
	int k = size(a);
	//////////////////////////////////////
	srand(time(0)); // ��������� ��������� �����
	int  *ptrarray = new int[k]; // �������� ������������� �������
	for (int count = 0; count < k; count++)
		ptrarray[count] = count+1; //���������� �������
	for (int i = 0; i < k; i++)
	{
		srand(time(0));////////////////////////////////
		for (int i = 0; i < k; ++i)//////////////////// ������������ ��������� ��������� �������
			swap(ptrarray[i], ptrarray [rand() % k]);//
	}
	cout << "array = ";
	for (int count = 0; count < k; count++)
		cout << setprecision(2) << ptrarray[count] << "    ";
	delete[] ptrarray; // ������������� ������
	cout << endl;
	//////////////////////////////////////////
	ofstream fin("decode.txt");
	for (auto x : a)
		fin << x;
	fin.close();
	ifstream fon("decode.txt");
	if (!fon.is_open())
		cout << "���� �� ���������";
	else {
	fon >> buff;
		cout << buff << endl;
		fon.getline(buff, 50);
		fon.close();
		cout << buff << endl;
	}
	
	system("pause");
	return 0;
}