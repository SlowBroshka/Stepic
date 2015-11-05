/*
Даны целые числа 1≤n≤1018 и 2≤m≤105, необходимо найти остаток от деления n-го числа Фибоначчи на m.

Sample Input:
16759108071127739 44408
Sample Output:
22937

*/

#include <iostream>
#include <conio.h>

unsigned int get_last_digit(long long n, unsigned long m) {
	unsigned int M[2];
	M[0] = 0;
	M[1] = 1;
	long *Pisano = new long [1000000];
	Pisano[0] = 0;
	Pisano[1] = 1;
	long k = n;
	long Ncount = 2;
	long i = 2;
	for (;n>0;n--){
		M[2] = (M[1] + M[0]) % m;
		M[0] = M[1] % m;
		M[1] = M[2] % m;
		if (M[2] == 0 && M[0] == 1)
            break;
			else{
                printf("%d ", M[2]); 
                Ncount++;
                Pisano[i++] = M[2]; 
           }
	}
	printf("\n n= %d Ncount= %d  nNcount= %d\n", k, Ncount, ((k) % Ncount));
	return Pisano[((k) % Ncount)];
  }
main() {
  int64_t n, m;
  std::cin >> n;
  std::cin >> m;
  printf("%d",get_last_digit(n, m));
  getch();
  return 0;
}
