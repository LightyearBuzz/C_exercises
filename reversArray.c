//Упражнение, реверс массива.
#include <stdio.h>
#define ARRAYSIZE 5

int main (void)
{	
	//массив чисел, тип char используем для компактности
	char array[ARRAYSIZE] = {11, 54, 78, 96, 54}; 

	//одна кружка с кофе другая к молоком, как поменять содержимое местами?
	//нужна третья кружка.
	char thirdCap=0;

	//реверс массива реализуем так, меняем местами первый и последний элемент
	//и так до середины массива
	for(int i=0; i<ARRAYSIZE/2; i++)
	{
		thirdCap=array[i];
		array[i]=array[ARRAYSIZE-1-i];
		array[ARRAYSIZE-1-i]=thirdCap;
	}

	//вывод на консоль
	for(int i=0; i<=ARRAYSIZE-1; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}