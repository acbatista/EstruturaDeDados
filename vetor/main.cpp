//Fillipe Lucas de Sousa
//Adriano Carvalho
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "vetor.h"

using namespace std;

int main(){
	int tamanho,opcao,opcao2,opcao3,opcao4;
	
	cout <<"==============================================================================="<<endl;
	cout <<"                                    VETOR                                      "<<endl;
	cout <<"==============================================================================="<<endl;
    
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    
    int vetorDeInteiros[tamanho]; 
    
    Vetor objVetor(tamanho, vetorDeInteiros); 
    
    cin.ignore ();
    system("cls");
    
    do {
    	system("cls");
    	objVetor.menu();
    	cout <<"<1> Carregar Vetor"<<endl;
    	cout <<"<2> Pesquisa"<<endl;
    	cout <<"<3> Ordenar:"<<endl;
    	cout <<"<4> Sair"<<endl;
    	cout <<"Opcao: ";
    	cin >>opcao;
    
    switch(opcao){
    	case 1:
    		system("cls");
    		objVetor.menu();
    		objVetor.atribuir();
    		break;
    	
    	case 2:
    		system("cls");
    		objVetor.menu();
    		cout <<"<1> Normal"<<endl;
    		cout <<"<2> Sequencial"<<endl;
    		cout <<"<3> Binario"<<endl;
    		cout <<"Opcao: ";
    		cin >>opcao2;
    		switch(opcao2){
    			case 1:
    				objVetor.mostrar();
    				getch();
    				break;
    				
    			case 2:
    				objVetor.sequencial();
    				getch();
    				break;
    			
    			case 3:
					objVetor.inbinario();
    				objVetor.binario();
    				getch();
    				break;
    		} 
			break;		
			    	
    	case 3:
    		system("cls");
    		objVetor.menu();
    		cout <<"<1> Insercao"<<endl;
    		cout <<"<2> Selecao"<<endl;
    		cout <<"<3> Bolha"<<endl;
    		cout <<"Opcao: ";
    		cin >>opcao3;
    		
    		switch(opcao3){
    			case 1:
    				objVetor.insercao();
    				getch();
    				break;
    				
    			case 2:
    				objVetor.selecao();
    				getch();
    				break;
    				
    			case 3:
    				objVetor.bolha();
    				getch();
    				break;
    		}
    		break;
    		
    	case 4:
    		return 0;
    		break;    	
    		
    }
    system("cls");
} while(opcao!=4);
//cin.ignore ();
system("pause");
}
