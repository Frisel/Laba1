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
	cout << "Введите последовательность чисел." << endl << " Для выхода нажмитн q" << endl;
	while (cin >> num)
		a.push_back(num);
	cout << "Ваша последовательность" << endl;
	for (auto x : a)
		cout << x << " ";
	cout << "Длинна массива" << size(a) << endl;
	int k = size(a);
	//////////////////////////////////////
	srand(time(0)); // генерация случайных чисел
	int  *ptrarray = new int[k]; // создание динамического массива
	for (int count = 0; count < k; count++)
		ptrarray[count] = count+1; //заполнение массива
	for (int i = 0; i < k; i++)
	{
		srand(time(0));////////////////////////////////
		for (int i = 0; i < k; ++i)//////////////////// Перестановка случайных элементов массива
			swap(ptrarray[i], ptrarray [rand() % k]);//
	}
	cout << "array = ";
	for (int count = 0; count < k; count++)
		cout << setprecision(2) << ptrarray[count] << "    ";
	delete[] ptrarray; // высвобождение памяти
	cout << endl;
	//////////////////////////////////////////
	ofstream fin("decode.txt");
	for (auto x : a)
		fin << x;
	fin.close();
	ifstream fon("decode.txt");
	if (!fon.is_open())
		cout << "Файл не обнаружен";
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