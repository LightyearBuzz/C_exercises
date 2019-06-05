//Упражнение, скопировать содержимое из одного файла в другой.
//Открываем два файла, создаем в памяти буфер, пишем из первого файла в буфер,
//затем из буфера во второй файл

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char * argv[])
{
	FILE * inputPointer = NULL;//указатель на фаил
	FILE * outputPointer = NULL;//указатель на фаил

	//если не удалость открыть файл, завершает программу
	if((inputPointer = fopen(argv[1], "rb")) == NULL)
	{
		printf("Can't open file input");
		exit(1);
	}

	//если не удалость открыть файл, завершает программу
	if((outputPointer = fopen(argv[2], "wb")) == NULL)
	{
		printf("Can't open file output");
		exit(2);
	}

	fseek(inputPointer, 0, SEEK_END);//устанавливает указатель в конец файла
	long sizeF = ftell(inputPointer);//измеряет размер файла
	rewind(inputPointer);//устанавливает указатель в начало файла

	char * buffer;//указатель на буфер

	//выделяет память размером с входящий фаил
	buffer = (char *) malloc(sizeof(char) * sizeF);
	if(buffer == NULL)//если не удалось выделить завершает программу
	{
		printf("Can't make a buffer");
		exit(3);
	}  

	long result = 0; //содержит количество прочитанных байт
	result = fread(buffer, 1, sizeF, inputPointer);//читает из файла в буфер
	if(result != sizeF)//если не удалось прочитать, завершает программу
	{
		printf("Can't read file");
		exit(5);
	}

	result = fwrite(buffer, 1, sizeF, outputPointer);//читает из буфера в файл
	if(result != sizeF)//если не удалось записать, завершает программу
	{
		printf("Can't write file");
		exit(6);
	}

	//закрываем файлы, освобождаем буфер
	fclose(inputPointer);
	fclose(outputPointer);
	free(buffer);

return 0;
} 