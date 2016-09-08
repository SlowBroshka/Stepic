/*По данной непустой строке s длины не более 104, состоящей из строчных букв латинского алфавита, 
постройте оптимальный беспрефиксный код. В первой строке выведите количество различных букв k, 
встречающихся в строке, и размер получившейся закодированной строки. В следующих k строках запишите коды букв 
в формате "letter: code". В последней строке выведите закодированную строку.*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

class Haffm{
private:
	char Letter;
	char *pHafm;
	size_t size;

private:
	void StrCpy(char *str1, std::string str2){
		for(int i = 0; i < size; i++){
			str1[i] = str2[i];
		}
	}
public:
	Haffm(){
		Letter = 0;
		pHafm = NULL;
		size = 0;
	}
	Haffm(char Let, std::string *pSt, size_t s){
		Letter = Let;
		size  = s;
		pHafm = new char[size + 1];
		StrCpy(pHafm, *pSt);
		pHafm[s] = '\0';
	}
	Haffm(const Haffm & buf){
		Letter = buf.Letter;
		size = buf.size;
		pHafm = new char[size + 1];
		StrCpy(pHafm, buf.pHafm);
		pHafm[size] = '\0';
	}
	Haffm & operator=(const Haffm& buf){
		if (this != &buf){
			delete[] this->pHafm;
			this->pHafm = new char[buf.size + 1];
			this->Letter = buf.Letter;
			this->size = buf.size;
			StrCpy(this->pHafm, buf.pHafm);
			pHafm[size] = '\0';
		}
		return *this;
	}
	void operator()(char Let, std::string *pSt, size_t s){
		Letter = Let;
		size  = s;
		pHafm = new char[size + 1];
		StrCpy(pHafm, *pSt);
		pHafm[s] = '\0';
	}
	void HafPr(){
		std::cout << Letter << ": " << pHafm << "  size=" << size <<std::endl;
	}
	char GetLet(){
		return Letter;
	}
	char *GetpHafm(){
		return pHafm;
	}
	size_t GetSize(){
		return size;
	}
	~Haffm(){
		delete pHafm;
	}
};
bool InHaf(std::vector<Haffm> v, std::string str){
	for (int k = 0; k < v.size(); k++){
		if(str == v[k].GetpHafm()){
			std::cout << v[k].GetLet();
			return 1;
		}
	}
	return 0;
}
int main(){

	int N;
	int Nrange;
	std::vector<Haffm> H;
	Haffm buf;
	std::string *inp1 = new std::string;
	std::string *inp2 = new std::string;
	std::string buff;

	if (scanf("%d %d", &Nrange, &N) == 1){
		printf("Input error\n");
		return 1;
	}
	
	for (int i = 0; i < Nrange; i++){
		std::cin >> *inp1;
		std::cin >> *inp2;
		buf((*inp1)[0], inp2, (*inp2).length());
		H.push_back(buf);
	}
	(*inp1).clear();
	std::cin >> *inp1;
	for (int i = 0; i < (*inp1).length(); i++){
		for (int j = 1; j+i <= (*inp1).length(); j++){
			if (InHaf(H, (*inp1).substr(i,j)) == 1){
				i += j-1;		
				break;
			}
		}
	}
	std::cout<<std::endl;
	delete inp1;
	delete inp2;

	return 0;
}
