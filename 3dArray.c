//Упражнение, вывод на консоль 3х мерного массива. 
//Для удобства восприятия, представим его в виде трехмерной фигуры(куба),
//каждый for обрабатывает массив по своей оси (i, j, k).


#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main (void)
{
	char arr[SIZE][SIZE][SIZE] = {	
		{ {1, 2, 5, 4, 7}, {6, 1, 4, 7, 8}, {8, 9, 7, 5, 6}, {3, 4, 8, 9, 6}, {7, 7, 9, 4, 6} },
		{ {6, 1, 4, 7, 8}, {3, 4, 8, 9, 6}, {3, 4, 8, 9, 6}, {8, 9, 7, 5, 6}, {8, 9, 7, 5, 6} },
		{ {3, 4, 8, 9, 6}, {8, 9, 7, 5, 6}, {6, 1, 4, 7, 8}, {1, 2, 5, 4, 7}, {1, 2, 5, 4, 7} },
		{ {8, 9, 7, 5, 6}, {1, 2, 5, 4, 7}, {3, 4, 8, 9, 6}, {6, 1, 4, 7, 8}, {6, 1, 4, 7, 8} },
		{ {1, 2, 5, 4, 7}, {6, 1, 4, 7, 8}, {1, 2, 5, 4, 7}, {8, 9, 7, 5, 6}, {3, 4, 8, 9, 6} }	   
	};
						 																						
	for (int i = 0; i < SIZE; ++i)//обрабатывает по оси i 
	{
		for (int j = 0; j < SIZE; ++j)//обрабатывает по оси j
		{
		    for (int k = 0; k < SIZE; ++k)//обрабатывает по оси k
		    {
		        printf("%d", arr[i][j][k]); //вывод на консоль
		    }
		    printf("\n");
		}
		printf("\n");
	}

	return 0;	
}