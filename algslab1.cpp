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

int randint(int min, int max) 
{
	return (((rand())<<15)|rand())%(max-min) + min;
}

int order(int a[], int count, int min, int max){
	
	for(int i=0; i<count; i++){
		a[i]=rand();
	}
};

int part_order(){
	
};

int rand(){
	
};

int reverse_order(){
	
};

double db_reverse_order(){
		
};

double db_order(){
	
};

double db_part_order(){
	
};

double db_rand(){
	
};

int main(void){
	int *a= new int[10];
	order(a, 10, 0, 30);
	print(a, 10);
	system("pause");
	return 0;
}
