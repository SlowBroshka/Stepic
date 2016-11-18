/*
Некоторая утилита генерирует довольно большой вывод, а вам требуется всего-лишь посчитать количество символов '0' в этом выводе. Утилита при запуске принимает 1 параметр. Вам требуется разработать программу, которая вызывает указанную утилиту, с заданным параметром и подсчитывает количество символов '0' в ее выводе. Ваша программа принимает на вход 2 параметра -- имя утилиты, в текущем каталоге и ее параметр. Ваша программа должна после подсчета вывести найденное число '0' в отдельной строке, заканчивающейся символом конца строки.

Пример вызова


./solution someprog param
234222
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	if(argc != 3){
		printf("ERROR: no argc, argc = %d", argc);
		return 1;
	}

	char buf;
	int Count = 0;
	char *filename = (char*)malloc((strlen(argv[1]) + strlen(argv[2]) + 1 + 1) * sizeof(*filename));
	sprintf(filename, "%s %s",argv[1], argv[2]);
	
	FILE *fd = popen(filename, "r");
		while( (buf = fgetc(fd)) != EOF){
			if (buf == '0'){
				Count++;
			}
		}
		printf("%d\n", Count);
		pclose(fd);
		free(filename);
		return 0;
}
