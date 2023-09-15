#include <iostream>
#include <random>
#include <Windows.h>
#include <cmath>
#include <Algorithm>

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

void db_Step(double a[], int size, double min, double max, int step){
	int h=size/step;
	for(int i=0; i<size;i++){
		a[i]=random(min, min + (max/step));
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


void Sinus(int a[], int size, int min, int max){
	FullOrder(a, size, min, max);
	for(int i=0; i<size; i++){
		a[i]=sin(a[i])*10;	
	}
};


void db_Sinus(double a[], int size, double min, double max){
	db_FullOrder(a, size, min, max);
	for(int i=0; i<size; i++){
		a[i]=sin(a[i]);	
	}
};


void Quas(int a[], int size, int min, int max, int step){
	
	for(int i=0; i<size; i++){
		a[i]=Randomize(min+i+step,max+i+step);
	}
};

void db_Quas(double a[], int size, double min, double max, double step){
	
	for(int i=0; i<size; i++){
		a[i]=random(min+i+step,max+i+step);
	}
	
};



int main(void){
	int const LENGTH = 6000;
	int size, min, max, step;
	double Min, Max;
	int *a= new int[LENGTH];
	double *arr = new double[LENGTH];
	int key;
	do
		{
			cout<<"Input the function:\n"<<" 1: FullRandom():\n 2: FullOrder():\n 3: ReverseOrder():\n 4: ChainSaw():\n 5: Step():\n 6: Sinus():\n 7: Quas():\n 8: db_FullRandom(): \n 9: db_FullOrder(): \n 10: db_ReverseOrder(): \n 11: db_ChainSaw():\n 12: db_Step():\n 13: db_Sinus():\n 14: db_Quas():\n 15: EXIT\n"<<endl;
			cin>>key;
			switch(key)
			{
				case 1:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>min;
					cout<<"Input the max of interval:"<<endl;
					cin>>max;
					cout<<"//////////////////////////"<<endl;
					FullRandom(a, size, min, max);
					print(a, size);
				break;
					
				case 2:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>min;
					cout<<"Input the max of interval:"<<endl;
					cin>>max;
					cout<<"//////////////////////////"<<endl;
					FullOrder(a, size, min, max);
					print(a, size);
				break;
				
				case 3:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>min;
					cout<<"Input the max of interval:"<<endl;
					cin>>max;
					cout<<"//////////////////////////"<<endl;
					ReverseOrder(a, size, min, max);
					print(a, size);
				break;
				
				case 4:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>min;
					cout<<"Input the max of interval:"<<endl;
					cin>>max;
					cout<<"Input the step of interval:"<<endl;
					cin>>step;
					cout<<"//////////////////////////"<<endl;
					ChainSaw(a, size, min, max, step);
					print(a, size);
				break;
				
				case 5:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>min;
					cout<<"Input the max of interval:"<<endl;
					cin>>max;
					cout<<"Input the step of interval:"<<endl;
					cin>>step;
					cout<<"//////////////////////////"<<endl;
					Step(a, size, min, max, step);
					print(a, size);
				break;
				
				case 6:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>min;
					cout<<"Input the max of interval:"<<endl;
					cin>>max;
					cout<<"//////////////////////////"<<endl;
					Sinus(a, size, min, max);
					print(a, size);
				break;
				
				case 7:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>min;
					cout<<"Input the max of interval:"<<endl;
					cin>>max;
					cout<<"Input the step of interval:"<<endl;
					cin>>step;
					cout<<"//////////////////////////"<<endl;
					Quas(a, size, min, max, step);
					print(a, size);
				break;
				
				case 8:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>Min;
					cout<<"Input the max of interval:"<<endl;
					cin>>Max;
					cout<<"//////////////////////////"<<endl;
					db_FullRandom(arr, size, Min, Max);
					print_db(arr, size);
				break;
				
				case 9:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>Min;
					cout<<"Input the max of interval:"<<endl;
					cin>>Max;
					cout<<"//////////////////////////"<<endl;
					db_FullOrder(arr, size, Min, Max);
					print_db(arr, size);
				break;
				
				case 10:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>Min;
					cout<<"Input the max of interval:"<<endl;
					cin>>Max;
					cout<<"//////////////////////////"<<endl;
					db_ReverseOrder(arr, size, Min, Max);
					print_db(arr, size);
				break;
				
				case 11:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>Min;
					cout<<"Input the max of interval:"<<endl;
					cin>>Max;
					cout<<"//////////////////////////"<<endl;
					db_ChainSaw(arr, size, Min, Max, step);
					print_db(arr, size);
				break;
				
				case 12:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the Min of interval:"<<endl;
					cin>>Min;
					cout<<"Input the Max of interval:"<<endl;
					cin>>Max;
					cout<<"Input the step of interval:"<<endl;
					cin>>step;
					cout<<"//////////////////////////"<<endl;
					db_Step(arr, size, Min, Max, step);
					print_db(arr, size);
				break;
				
				case 13:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>Min;
					cout<<"Input the max of interval:"<<endl;
					cin>>Max;
					cout<<"//////////////////////////"<<endl;
					db_Sinus(arr, size, Min, Max);
					print_db(arr, size);
				break;
				
				case 14:
					cout<<"Input the size:"<<endl;
					cin>>size;
					cout<<"Input the min of interval:"<<endl;
					cin>>Min;
					cout<<"Input the max of interval:"<<endl;
					cin>>Max;
					cout<<"Input the step of interval:"<<endl;
					cin>>step;
					cout<<"//////////////////////////"<<endl;
					db_Quas(arr, size, Min, Max, step);
					print_db(arr, size);
				break;
				
				case 15:
					cout<<"Welcome back"<<endl;
				break;
		
				}
		}
while(key!=15);
	
	
	/*Quas(a, size, 1, 32, 2);
	print(a, size);
	cout<<"///////"<<endl;
	db_Quas(arr, size, 0.1, 30.5, 0.5);
	print_db(arr, size);*/
	/*FullRandom(a,size, 1, 10);
	print(a, size);*/
	
	
	/*
	db_Sinus(arr, 10, 0.1, 0.9);
	print_db(arr, 10);
	cout<<"///////////////////"<<endl;
	Sinus(a, 10, 2, 10);
	print(a, 10);*/
	
	
	
	/*Step(a, 10, 1, 10, 2);
	print(a, 10);
	cout<<"//////////////"<<endl;
	db_Step(arr, 10, 0.1, 0.9, 2);
	print_db(arr, 10);*/
	
	
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
