/*Первая строка содержит число 1≤n≤105, вторая — массив A[1…n], содержащий натуральные числа, не превосходящие 109. 
Необходимо посчитать число пар индексов 1≤i<j≤n, для которых A[i]>A[j]. 
(Такая пара элементов называется инверсией массива. Количество инверсий в массиве 
является в некотором смысле его мерой неупорядоченности: например, в упорядоченном по неубыванию массиве инверсий нет вообще, 
а в массиве, упорядоченном по убыванию, инверсию образуют каждые два элемента.)
Sample Input:
5
2 3 9 2 9
Sample Output:
2
*/

#include <stdio.h>
#include <iostream>

long long Count = 0;

void Merge(long long *Arr1, long long e, long long m, long long r){
	long long *Res = new long long[r - e + 1];
	long long pos1 = e, pos2 = m+1, re = 0;

	while(pos1 <= m && pos2 <= r){
		if (Arr1[pos1] > Arr1[pos2]){

			Count += (r+1 - pos2);
			//prlong longf("[%d] > [%d] | Count=  %d, pos1 = %d, m = %d ,r = %d, pos2 = %d\n", Arr1[pos1], Arr1[pos2], Count, pos1, m, r, pos2);
			Res[re++] = Arr1[pos1++];
		}else{
			Res[re++] = Arr1[pos2++];
		}
	}

	while(pos2 <= r){
		Res[re++] = Arr1[pos2++];
	}
	while(pos1 <= m){

		Res[re++] = Arr1[pos1++]; 
	}
	for(re = 0; re < r-e + 1; re++){
		Arr1[e + re] = Res[re];
	}
	
	delete Res;

}

void MegreSort(long long *Arr, long long e, long long r){
	long long m;
	if (r > e){
		m = (e + r) / 2;
		MegreSort(Arr, e, m);
		MegreSort(Arr, m+1, r);
		Merge(Arr, e, m, r);
	}
}

int main(){

	long long N;
	std::cin>> N;

	long long *Array = new long long [N];

	for (long long i = 0;i < N; i++){
		std::cin>>Array[i];
	}
	MegreSort(Array, 0, N-1);

	std::cout<<Count<<std::endl;

	delete Array;
	return 0;
}
