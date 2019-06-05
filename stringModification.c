//Упражнение, преобразовать строку введенную пользователем в верхний, 
//нижний или обратный регистр. Использовать для этого
//указатель на функцию 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//описываем сигнатуры функции
char ShowMenu(void); 
void EatLine(void); 
void ShowString(void (* fp) (char *), char * str);
void ToUpperCase(char *); 
void ToLowerCase(char *); 
void Transpose(char *);
void Original(char *);

int main(void)
{
	char line[256]; //оригинал строки
	char copy_line[256];//копия строки
	char chosen_variant = 0;//выбранный вариант меню
	void (*function_pointer) (char *);//указатель на функцию

	puts("Enter line (empty line - exit) :");

	//реалезует работу меню
	while (gets(line) != NULL && line[0] != '\0')//проверка ввода на символ конца строки
	{
		while((chosen_variant = ShowMenu()) != 'n')//проверка варианта ответа на 'n'
		{
			switch(chosen_variant)//проверка варианта ответа на 'u' , 'l', 't', 'o'
			{
				case 'u' : 
					//в случае u , установить указатель функции на ToUpperCase
					function_pointer = ToUpperCase;
					break; 
				case 'l' : 
					//в случае l, установить указатель функции на ToLowerCase
					function_pointer = ToLowerCase;
					break;
				case 't' :
					//в случае t, установить указатель функции на Transpose
					function_pointer = Transpose;
					break;
				case 'o' :
					//в случае o, установить указатель функции на Original
					function_pointer = Original;
					break;
			}

			strcpy(copy_line, line); //копирует строку

			//вызывает функцию показа строки, которая принимает указатель на функцию обработки
			// и строку для отображения
			ShowString(function_pointer, copy_line); 
		}

		puts("Enter line (empty line - exit) :");
	}
	puts("Good bye!" );
	return 0;
}

/*отображает меню пользователя, принимает вариант пользователя
и проверяет ввод на соответствие, возвращает выбранный вариант пользователя*/
char ShowMenu(void)
{
	char ans = 0;

	printf("%c", '\n');
	puts("Enter number of element menu :");
	puts("u) ToUpper l) ToLower" );
	puts("t) Trance  o) Original");
	puts("n) next line");

	ans = getchar();
	ans = tolower(ans);//приводит к нижнему регистру


	//вынимает из потока символ \n который остался после ввода пользователя
	EatLine();

	while (strchr("ulton", ans) == NULL)//strchr проверяет соответствует ли ответ вариантам меню 
	{
		puts(" Enter please u, l, t, o or n:");
		ans = tolower(getchar());
		EatLine();
	}
	return ans;
}

//вынимает из потока символ \n который остался после ввода пользователя
void EatLine(void)
{
	while(getchar() != '\n')
	continue;
}

//принимает адрес строки, затем меняет содержимое строки на верхний регистр
void ToUpperCase(char * str)
{
	while (* str)
	{
		* str = toupper(* str);
		str++;
	}
}

//принимает адрес строки, затем меняет содержимое строки на нижний регистр
void ToLowerCase(char * str)
{
	while (* str)
	{
		* str = tolower(* str);
		str++;
	}
}

//принимает адрес строки, затем меняет содержимое строки на обратный регистр
void Transpose(char * str)
{
	while (* str)
	{
		if (islower(* str))
		{
			*str = toupper(* str);
		}else if(isupper(* str))
		{
			*str = tolower(* str);
		}
		str++;
	}
}


void Original(char * str)
{
}

//принимает указатель на функцию, и указатель на строку, затем применяет функцию к строке
void ShowString(void (* fp)(char *), char * str)
{
	(* fp)(str);
	puts(str);
}