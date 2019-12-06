#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Celula.h"
#include "ListaLigada.h"

using namespace std;


ListaLigada::ListaLigada() {
	prim = NULL;
	qtdCelulas = 0;
}


bool ListaLigada::vazia() {
	return prim == NULL;
}


int ListaLigada::tamanho() {
	return this->qtdCelulas;
}


void ListaLigada::insereInicio(int i) {
	Celula * c = new Celula(i);
	c->setProx(prim);
	prim = c;
	qtdCelulas++;
}


string ListaLigada::insereEmN(Celula * c, int pos) {
	stringstream ss;

	while (true) {
		if (pos < 1) {
			ss << "A posicao deve ser maior ou igual a 1";
			break;
		}

		if (pos > qtdCelulas + 1) {
			ss << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

		if (pos == 1) {
			insereInicio(c->getInfo()); // o metodo insereInicio ja' estava implementado; aqui foi feita uma adaptacao.
			ss << "Inserido no inicio";
			break;
		}

		Celula * cursor = this->prim;
			for (int i = 1; i < pos - 1; i++) {
				cursor = cursor->getProx();
		}

		c->setProx(cursor->getProx());
		cursor->setProx(c);
		
		qtdCelulas++;

		ss << "Inserido na posicao " << pos;

		break;
	}
	return ss.str();
}


void ListaLigada::imprime() {
	Celula * cursor = prim;
	cout << "[ ";
	while (cursor != NULL) {
		cout << cursor->getInfo() << " ";
		cursor = cursor->getProx();
	}
	cout << "]\n";
}


void ListaLigada::insereFinal(int i){
	Celula * c = new Celula(i); // elemento novo
	Celula * cursor = this->prim;
	for (int i = 1; i <= qtdCelulas - 1; i++) {
		cursor = cursor->getProx();
	}
	cursor->setProx(c);
	qtdCelulas++;
}


string ListaLigada::pos_mais_um(Celula * c, int pos){
	stringstream ss;

	while (true){
		if (pos < 1){
			ss << "A posicao deve ser maior ou igual a 1";
			break;
		}

		if (pos > qtdCelulas + 1){
			ss << "Nao existe essa posicao. A fila esta com " << qtdCelulas << " elemento(s)";
			break;
		}

		Celula * cursor = this->prim;
		for (int i = 1; i < pos; i++){
			cursor = cursor->getProx();
		}

		c->setProx(cursor->getProx());
		cursor->setProx(c);
		
		qtdCelulas++;

		ss << "Inserido na posicao " << pos+1;

		break;
	}
	return ss.str();
}


string ListaLigada::pos_menos_um(Celula * c, int pos){
	stringstream ss;

	while (true){
		if (pos <= 1){
			ss << "Nesse caso, posicao deve ser maior que 1";
			break;
		}

		if (pos > qtdCelulas + 1){
			ss << "Nao existe essa posicao. A fila esta com " << qtdCelulas << " elemento(s)";
			break;
		}

		Celula * cursor = this->prim;
		for(int i = 1; i < (pos-2); i++){
			cursor = cursor->getProx();
		}

		if (pos == 2){
			c->setProx(prim);
			prim = c;
			ss << "Inserido na posicao " << (pos - 1);
			break;
		}

		c->setProx(cursor->getProx());
		cursor->setProx(c);

		qtdCelulas++;
		
		ss << "Inserido na posicao " << (pos-1);
		break;
	}
	return ss.str();
}


void ListaLigada::excluir_elem(int pos){
	while(true){
		Celula * cursor = prim;
		Celula * c = prim;

		if (pos < 0) {
			cout << "A posicao deve ser maior que 0";
			break;
		}

		if (pos > qtdCelulas + 1) {
			cout << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

		if (pos == 1){
			c = cursor->getProx();
			prim = c;
			qtdCelulas--;
			cout << "Excluido o elemento da posicao " << pos;
			break;
		}

		for(int i = 1; i < pos; i++){
			cursor = cursor->getProx();
		}
		
		for(int i = 1; i < pos-1; i++){
			c = c->getProx();
		}

		cursor->getProx();
		c->setProx(cursor->getProx());
			
		qtdCelulas--;
		cout << "Excluido o elemento da posicao " << pos; 
		break;
	}
}


void ListaLigada::excluir_elem_mais_um(int pos){
	while(true){
		if (pos <= 0) {
			cout << "A posicao deve ser maior que 0";
			break;
		}

		if (pos > qtdCelulas + 1) {
			cout << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

		Celula * cursor = prim;
		Celula * c = prim;

		for(int i = 1; i < pos+1; i++){
			cursor = cursor->getProx();
		}
		
		for(int i = 1; i < pos; i++){
			c = c->getProx();
		}

		cursor->getProx();
		c->setProx(cursor->getProx());

		qtdCelulas--;
		cout << "Excluido o elemento da posicao " << (pos+1);
		break;		
	}
}


void ListaLigada::excluir_elem_menos_um(int pos){
	while(true){
		Celula * cursor = prim;
		Celula * c = prim;

		if (pos <= 1) {
			cout << "A posicao deve ser maior que 1";
			break;
		}

		if (pos > qtdCelulas + 1) {
			cout << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

		if (pos == 2){
			c = cursor->getProx();
			prim = c;
			qtdCelulas--;
			cout << "Excluido o elemento da posicao " << pos-1;
			break;
		}

		for(int i = 1; i < pos-1; i++){
			cursor = cursor->getProx();
		}
		
		for(int i = 1; i < pos-2; i++){
			c = c->getProx();
		}

		cursor->getProx();
		c->setProx(cursor->getProx());

		qtdCelulas--;
		cout << "Excluido o elemento da posicao " << (pos-1);
		break;
	}
}
