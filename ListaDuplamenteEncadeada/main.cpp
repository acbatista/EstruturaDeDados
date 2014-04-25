#include <iostream>
#include "ListaD.h"

using namespace std;


int main(){
	ListaD lista;
	int num,i=1;
	
	cout << "\n Entre com os 20 primeiros numeros [0 para sair]: ";
	cout << "\n Digite os numeros "<< i<<" [0 para sair]: ";
	cin >> num;
	
	while(num != 0){
		++i;
		lista.adicionaTopo(num);
		cout << "\n Digite os numeros "<< i<<" [0 para sair]: ";
		cin >> num;
		
	}
	cout << endl;
	while(!lista.estaVazia()){
	cout << "O numero maior removido e: " << lista.removeMaior() << endl;
	}
	
	system("pause");
}
