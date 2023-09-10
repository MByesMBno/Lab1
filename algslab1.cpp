#include <iostream>
#include <random>
#include <Windows.h>
#include <cmath>

using namespace std;
void print(int a[], int count)
{
	for (int i = 0; i < count; i++){
		cout << a[i] <<endl;
	}
}

void print_db(double a[], int count)
{
	for (int i = 0; i < count; i++){
		cout << a[i] <<endl;
	}
}

int Randomize(int min, int max) //функция необходима для усоверщенствования функции rand(), расширение диапозона получаемых значений 
{
	int newbye=(((rand())<<15)|rand())%(max-min) + min ;
	//cout << "bulling ="<<newbye <<endl;	
	return newbye;
}


void FullRandom(int a[], int size, int min, int max) //случайные последовательности
{
	for(int i =0;i<size;i++){
		a[i] = Randomize(min, max);
	}
}
void db_FullRandom(double a[], int size, double min, double max)
{
	for(int i =0;i<size;i++){
		a[i] = Randomize(min, max);
	}
}



void FullOrder(int a[], int size, int min, int max){
	for(int i=0; i<size; i++){
		double diff= max - min;
		double multiplier= diff / size;
		a[i]= (multiplier * i) + min;
	}
};

void ReverseOrder(int a[], int size, int min, int max){
	FullOrder(a, size, max, min);
};



int main(void){
	int *a= new int[10];
	double *arr = new double[10];
	
	db_FullRandom(arr, 10, 0.1, 1.0); //додумать randomize, ошибка массив с 0 из-за Randomize
	print_db(arr, 10);
	
	/*FullRandom(a, 10, 1, 10);
	print(a, 10);*/ //рандомная int
	
	/*FullOrder(a, 10, 1, 10);
	print(a, 10); // упорядоченная int
	cout<< "/////////////////////////////////" <<endl;
	ReverseOrder(a, 10, 1, 10);
	print(a, 10);*/ //обратная упорядоченная 
	 
	system("pause");
	return 0;
}
