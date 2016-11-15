/*Разработать программу solution, которая по заданному pid, осуществляет поиск всех потомков процесса с этим идентификатором и выводит их количество (включая процесс с заданным pid).

Пример вызова


./solution 1233
76
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>


pid_t GetPPid(pid_t p){
	pid_t ppid;
	char *filename = malloc(strlen("/proc/") + 5 + strlen("/stat") +1);
	sprintf(filename, "/proc/%d/stat", p);
	FILE *fd = fopen(filename, "r");
	if (fd){
		fscanf(fd, "%*d\t%*s\t%*c\t%d", &ppid);
	}else{
		printf("ERROR FILE INPUT\n");
		return -1;
	}
	fclose(fd);
	free(filename);
	return ppid;
}
size_t GetNumofProcs(){
	DIR *dir = opendir("/proc/");
	size_t Count = 0;
	if (dir){
		struct dirent *ent;
		while((ent = readdir(dir)) != NULL){
			if (atoi(ent->d_name)){
				Count++;
			}
		}
	}else{
		printf("ERROR OPENDIR\n");
	}
	return Count;
}
void PutPidPPid(pid_t *proc, pid_t *Pproc){
	size_t ProcCount = 0;

	DIR *dir = opendir("/proc/");
	if (dir){
		struct dirent *ent;
		while((ent = readdir(dir)) != NULL){
			if (atoi(ent->d_name)){
				proc[ProcCount] = (atoi(ent->d_name));
				Pproc[ProcCount] = GetPPid(atoi(ent->d_name));
				ProcCount++;
			}
		}
	}else{
		printf("ERROR OPENDIR\n");
	}
	return ;
}

size_t GetSonNums(pid_t pid, pid_t *proc, pid_t *Pproc, size_t Nums){
	size_t Count = 0;
	for(size_t i = 0; i < Nums; i++){
		if (Pproc[i] == pid){
			Count++;
			Count += GetSonNums(proc[i], proc, Pproc, Nums);
		}
	}
	return Count;
}

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("ERROR argc, please enter number of proc\n");
		return -1;
	}
	size_t ProcNum = GetNumofProcs();
	
	pid_t IskPid = atoi(argv[1]);
	
	pid_t *proc = (pid_t*)malloc((ProcNum + 8) * sizeof(pid_t));
	pid_t *Pproc = (pid_t*)malloc((ProcNum + 8) * sizeof(pid_t));
	
	PutPidPPid(proc, Pproc);

	printf("%d\n", GetSonNums(IskPid, proc, Pproc, ProcNum) + 1);
	free(proc);
	free(Pproc);
	return 0;
}
