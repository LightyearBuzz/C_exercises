//Упражнение: память, массивы и указатели. Рассмотрим синтаксические детали Си
//указателей и массивов.
#include <stdio.h>


int main(void)
{
	char arr[3]={0,1,2};//одномерный массив

	char arrII[3][2]={{00,01},//двухмерный массив
					  {10,11},
					  {20,21}};	

	char * arrayPointer;//указатель на массив
	arrayPointer=arr;

	printf("                    content adress size\n");
	printf("arr                 %d %d %d\n",arr, &arr, sizeof(arr));//обращение к целому массиву.
	
	//обращение к [0] элементу массива, адрес такой же, но размер и содержание отличается.
	printf("arr[0]              %d       %d %d\n\n",arr[0], &arr[0], sizeof(arr[0]));

	//обращение к одному и тому же элементу разными способами
	printf("*(arr+1)            %d\n", *(arr+1) );
	printf("*(arrayPointer+1)   %d\n", *(arrayPointer+1) );
	printf("arr[1]              %d\n", arr[1] );
	printf("arrayPointer[1]     %d\n\n", arrayPointer[1] );

	//эти вызовы содержат один и тот же адрес, но элемент, содержание и размер отличаются
	printf("arrII               %d\n", arrII ); 
	printf("arrII[0]            %d\n", arrII[0] );  
	printf("&arrII[0][0]        %d\n", &arrII[0][0] );
	printf("*arrII              %d\n", *arrII );

	//обращение к элементу arrII[2][1] разными способами
	printf("*(*(arrII+2)+1)     %d\n", *(*(arrII+2)+1) );
	printf("*(*(arrII)+5)       %d\n", *(*(arrII)+5) );

	return 0;
}