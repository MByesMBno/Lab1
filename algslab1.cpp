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

double random(double min, double max){
	return min+fmod(static_cast<double>(rand()), max-min);
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
		a[i] = random(min, max);
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




void db_FullOrder(double a[], int size, double min, double max){
	for(int i=0; i<size; i++){
		double diff= max - min;
		double multiplier= diff / size;
		a[i]= (multiplier * i) + min;
	}
};

void db_ReverseOrder(double a[], int size, double min, double max){
	db_FullOrder(a, size, max, min);
};

void ChainSaw(int a[], int size, int min, int max, int step){
	int h = size/step;
	for(int i=0; i<step; i++){
		FullOrder(&a[i*h], h, min, max);
	}
	int b=0;
	if((h*step)<size){
		double k = ((double(max-min))/h);
		for(int i= h*step; i<size; i++, b++){
			a[i]=h * b + min;
		}
	}	
};

void db_ChainSaw(double a[], int size, double min, double max, int step){
	double h = size/step;
	int H = size/step;
	for(int i=0; i<step; i++){
		db_FullOrder(&a[i*H], h, min, max);
	}
	int b=0;
	if((h*step)<size){
		double k = ((double(max-min))/h);
		for(int i= h*step; i<size; i++, b++){
			a[i]=h * b + min;
		}
	}	
};


void Sinus(int a[], int size, int min, int max){
	
};


void Step(int a[], int size, int min, int max, int step){
	int h=size/step;
	for(int i=0; i<size;i++){
		a[i]=Randomize(min, min + (max/step));
		if((i+1)%(size/step)==0){
			min += max / step;
		}
	}
	if((h*step)<size){
		double m= ((double(max-min))*step/(size));
		for(int i=h*step; i<size;i++){
			a[i]=m*(i-h*step)+min;
		}
	}
};

int main(void){
	int *a= new int[10];
	double *arr = new double[10];
	
	Step(a, 10, 1, 10, 2);
	print(a, 10);
	
	
	
	/*ChainSaw(a, 10, 1, 10, 2); //пилозубчатая
	print(a, 10);
	cout<<"//////////////"<<endl;
	db_ChainSaw(arr, 10, 0.1, 1.0, 2); //пилозубчатая дабл
	print_db(arr, 10);*/
	
	/*db_FullOrder(arr, 10, 0.1, 1.0);
	print_db(arr, 10);*/
	
	/*db_ReverseOrder(arr, 10, 0.1, 1.0);
	print_db(arr, 10);*/
	
	/*db_FullRandom(arr, 10, 0.1, 1.0);
	print_db(arr, 10);*///рандом double
	
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
