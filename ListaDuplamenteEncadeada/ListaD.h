
/*
  Classe que implementa o Nó para uma Lista
  Duplamente Encadeada.
  Apresenta três informações:
  - info  : guarda a informação de interesse
  - *ant  : aponta para o nó anterior
  - *prox : aponta para o próximo nó
*/

#include <iostream>
#include <cstdlib>

using namespace std;
class Node {
  public:

    int info;
    Node *ant, *prox;

    Node()    // Método Construtor
    {
      prox = ant = 0;
    }

    Node (int _info, Node* _ant = 0, Node* _prox = 0) // Método Construtor
    {
      info = _info;
      ant  = _ant;
      prox = _prox;
    }
};


/*
  Classe que implementa as ligações para os Nós de uma Lista Duplamente Ligada.
  Apresenta duas informações:
  - *topo  : aponta para o endereço do primeiro nó
  - *resto : aponta para o endereço do último nó
*/


class ListaD {
  private:
    Node *topo, *resto;

  public:

    ListaD() {
      topo = resto = 0;
    }

/* Protótipos dos métodos */

    bool estaVazia();
    void adicionaTopo(int);
    void adicionaResto(int);
    int consultaTopo();
    int consultaResto();
    int removeTopo();
    int removeResto();
    int removeMaior();
    void remove(int);
};
/*
  Implementação das funções membro (métodos)
  */

/* Método que informa se a lista esta vazia */

bool ListaD::estaVazia() {
      return (topo == 0);
}

/* Método que adiciona elementos no topo da lista */

void ListaD::adicionaTopo(int el) {
  Node *tmp = new Node(el,0,topo);
  if (resto != 0) {
      topo = topo->ant = tmp;
  } else {
    resto = topo = tmp;
  }
}

/* Método que adiciona elementos no fim da lista */

void ListaD::adicionaResto(int el) {
  Node *tmp = new Node(el, resto);
  if (resto!=0) {
    resto = resto->prox = tmp;
  } else {
    topo = resto = tmp;
  }
}

/* Método que consulta elementos a partir do topo da lista */

int ListaD::consultaTopo() {
  if (topo != 0) {
    return (topo->info);
  } else {
      cout << "Erro: lista vazia!!" << endl;
  }
}

/* Método que consulta elementos a partir do fim da lista */

int ListaD::consultaResto() {
  if (resto != 0) {
    return (resto->info);
  } else {
      cout << "Erro: lista vazia!!" << endl;
  }
}

/* Método que remove elementos a partir do topo da lista */

int ListaD::removeTopo() {
  if (topo == 0) {
      cout << "Erro: lista vazia!!" << endl;
  } else {
    int el = topo->info;
    Node *tmp = topo;
    if (topo == resto) {
        topo = resto = 0;
    } else {
        topo = topo->prox;
        topo->ant = 0;
    }
    delete tmp;
    return (el);
  }
}

/* Método que remove elementos a partir do fim da lista */

int ListaD::removeResto() {
  if (resto == 0){
      cout << "Erro: lista vazia!!" << endl;
  } else {
    int el = resto->info;
    Node *tmp = resto;
    if (topo == resto) {
      topo = resto = 0;
    } else {
      resto = resto->ant;
      resto->prox = 0;
    }
    delete tmp;
    return (el);
  }
}

/* Método que remove elementos em qualquer lugar da lista */

void ListaD::remove(int el) {
  if (topo == 0){
      cout << "Erro: lista vazia!!" << endl;
  } else {
    Node *p, *a, *d;
    for (p = topo; p != 0 && !(p->info == el); p = p->prox){};
    if (p != 0 ) {
       if (p == resto && p == topo) {
           resto = topo = 0;
       } else {
           if (p == resto) {
               p->ant->prox = 0;
               resto = p->ant;
           } else {
               if (p == topo) {
                   p->prox->ant = 0;
                   topo = p->prox;
               } else {
                   p->ant->prox = p->prox;
		           p->prox->ant = p->ant;
               }
           }
       }
       delete p;
    } else {
      cout << "Erro: elemento nao encontrado na lista!!" << endl;
    }
  }
}

int ListaD::removeMaior(){
    int maior = topo ->info;

    Node *p, *m = topo;
    if (topo == 0) {
        cout << "Lista vazia";
    } else {
    for (p=topo; p !=0; p = p->prox) {
            if (p -> info > maior) {
                maior = p -> info;
                m = p;
            }
        }
    }
	if(m == topo && m == resto){
		topo = resto = 0;
	}else{
	
    if (m == resto) {
        m->ant->prox = 0;
        resto = m->ant;
    }
	else {
        if (m == topo) {
            m->prox->ant = 0;
            topo = m->prox;
        } else {
            m->ant->prox = m->prox;
            m->prox->ant = m->ant;
        }
    }
	}
    delete m;
    return maior;
};

