#include<iostream>
#include<fstream>

using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	char buff[50];
	ofstream fin("decode.txt");
	fin << "������ �������";
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