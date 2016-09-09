#include <stdio.h>
#include <iostream>


class Peek{
private:
	int *a;
	size_t size;

private:
	void Copy(int *to, int *from){
//		printf("\n--Start Copy--\n");
		for (int i = 1; i <= size; i++){
			to[i] = from[i];
	//		printf("%d ", to[i]);
		}
	//	printf("\n--End Copy--\n");
	}
	void swap(int &a, int &b){
		int buff = a;
		a = b;
		b = buff;
	}
	void siftup(int index){
		while ((index > 1) && (a[index] > a[index / 2])){
			swap(a[index], a[index / 2]);
			index = index / 2;
		}
	}
	void siftdown(int index){
		int min;
		while(2 * index <= size){
			min = index;
			if (a[2*index] > a[min]){
				min = 2*index;
			}
			if ((a[2*index + 1] > a[2*index]) && (2*index + 1 <= size)){
				min = 2*index + 1;
			}
			if (min == index){
				return;
			}
			swap(a[index], a[min]);
			index = min;
		}
		return;
	}
public:
	Peek(){
		size = 0;
		a = new int[size + 1];
	}

	void Insert(int elm){
		int *buff = new int[++size + 1];
		Copy(buff, a);
		delete a;
		a = buff;
		a[size] = elm;
		siftup(size);
	}
	int Extract(){
		if (size < 1){
			return -1;
		}
		int ExMin = a[1];
		a[1] = a[size];
		int *buff = new int[--size + 1];
		Copy(buff, a);
		delete a;
		a = buff;
		siftdown(1);
		return ExMin;

	}
	void PeekPrint(){
		for(int i = 1; i <= size; i++){
			std::cout<<a[i] <<  " ";
		}
		std::cout<<std::endl;
	}
	~Peek(){
		delete a;
	}
};

int main(){

	Peek P;
	int Number;
	int N;
	std::string inp;
	std::cin >> N;

	for(int i=0; i < N; i++){
		std::cin >> inp;

		if (inp == "In"){//Insert
			std::cin >>Number;
			P.Insert(Number);
		}else if(inp == "Ex"){//ExtractMax
			std::cout<<P.Extract()<<std::endl;
		}else{
			std::cout<<"Input Error"<<std::endl;
			return 1;
		}
	}
	return 0;
} 
