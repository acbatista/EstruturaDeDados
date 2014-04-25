#include <iostream>
#include <cstdlib>

using namespace std;
 
class Vetor
{
    int *vetor, tamanho, x, i,achou; 
    
    
public:
    Vetor(int t, int *v) 
    {
        vetor = v;
        tamanho = t;
    }
    
    void atribuir(){
        for (int i = 0; i < tamanho; i++){
            cout << "Digite um numero: ";
            cin >> vetor[i];
        }
    }
    
    void mostrar(void){
        for (int i = 0; i < tamanho; i++) {
            cout << "O numero " << i + 1 << " inserido foi: " << vetor[i] <<endl;
        }
    }
    
    void sequencial(void){
    	cout << "\nEntre com o elemento a ser pesquisado:";
		cin >> x;
		
		for (i=0; i<tamanho; i++){
			if(vetor[i]==x){
				cout <<"Valor encontrado na posicao: "<< i <<endl;
			}				
		}
	}	
	
	void binario(void){
		int direita, esquerda, meio, valor, encontrado;
		
		meio=0;
		encontrado = 0;
		esquerda = 0;
		direita = tamanho - 1;
		
		cout << "\nEntre com o elemento a ser pesquisado: ";
		cin >> valor;
		while (esquerda <= direita && !encontrado) {
			meio = (direita + esquerda) / 2;
				if (vetor[meio] == valor)
					encontrado = 1; 
				else if (valor < vetor[meio])
				direita = meio - 1;
				else
				esquerda = meio + 1;
		}
			if (encontrado) {
				cout <<"Encontrado na posicao: " << meio <<endl;
			} else {
				cout <<"Nao encontrado" <<endl;
			}
	}
	
	void bolha()
    {
    	int i,j,aux;
        cout << "Elementos do Vetor com bolha: " << endl;
        for (int i = 0; i < tamanho; i++) {
            cout << "O numero " << i + 1 << " inserido foi: " << vetor[i] <<endl;
        }
        for (i=0; i < tamanho; i++) {
            for (j=0; j < tamanho -i-1; j++) {
                if (vetor[j]> vetor[j+1]) {
                    aux = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = aux;
                }
            }
        }
        cout << "Elementos ordenados usando BubbleSort(Bolha): "<< endl;
        for (i=0; i< tamanho; i++) {
            cout << vetor[i] << " ";
        }
        
        cout << "\n" << endl;
    }
    
    void selecao(){
    	int i, j, aux, minimo;
    	
    	for(i=0;i<tamanho-1;i++) {
			minimo=i;
			for(j=i+1;j<tamanho;j++) {
				if (vetor[j] < vetor[minimo]) {
					minimo=j;
				}
			}
			aux=vetor[i];
			vetor[i]=vetor[minimo];
			vetor[minimo]=aux;
		}
		cout << "\n\nElementos ordenados " <<endl;
		for (i = 0; i < tamanho; i++) {
			cout << vetor[i] << " ";
		}
    }
    
    void insercao(){
        int i, j, aux;
        cout << "Elementos do Vetor " << endl;
        for (i=0; i < tamanho; i++) {
            cout << vetor[i] << " ";
        }
        
        for(i = 1; i < tamanho; i++) {
            aux = vetor[i];
            for(j = i-1; (j >= 0) && (aux < vetor[j]); j--) {
                vetor[j + 1] = vetor[j];
            }
            vetor[j + 1] = aux;
        }
        
        cout << "\n\nElementos ordenados " << endl;
        for (i = 0; i < tamanho; i++) {
            cout << vetor[i] << " ";
        }
        cout << "\n" << endl;
        system ("pause");
    
    }
    
    void inbinario(){
    	int i, j, aux;
        
        for(i = 1; i < tamanho; i++) {
            aux = vetor[i];
            for(j = i-1; (j >= 0) && (aux < vetor[j]); j--) {
                vetor[j + 1] = vetor[j];
            }
            vetor[j + 1] = aux;
        }
    }
    
    void menu(){
    	cout <<"==============================================================================="<<endl;
		cout <<"                                    VETOR                                      "<<endl;
		cout <<"==============================================================================="<<endl;
    }
};
 

