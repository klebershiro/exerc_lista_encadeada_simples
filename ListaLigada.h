#include <iostream>
#include <string.h>
#include "Celula.h"

using namespace std;

class ListaLigada {
	
	//= privado
	private:
	Celula * prim;
	int qtdCelulas;
	
	//= publico
	public:
	ListaLigada();
	bool vazia();
	int tamanho();
	void insereInicio(int i);
	string insereEmN(Celula * c, int pos);
	void imprime();
	void insereFinal(int i);
	string pos_mais_um(Celula * c, int pos);
	string pos_menos_um(Celula * c, int pos);
	void excluir_elem(int pos);
	void excluir_elem_mais_um(int pos);
	void excluir_elem_menos_um(int pos);
};
