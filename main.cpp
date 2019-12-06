#include <cstdlib>
#include <iostream>
#include "ListaLigada.h"

using namespace std;

void ni();
void pausa();

int main() {

	ListaLigada lista;


	while (true) {

		cout << "\n0 - sair";
		cout << "\n1 - inserir no inicio";
		cout << "\n2 - inserir no final";
		cout << "\n3 - inserir na posicao 'n'";
		cout << "\n4 - inserir apos a posicao 'n'";
		cout << "\n5 - inserir antes da posicao 'n'";
		cout << "\n6 - excluir da posicao 'n'";
		cout << "\n7 - excluir apos a posicao 'n'";
		cout << "\n8 - excluir antes da posicao 'n'";
		cout << "\n9 - informar total de elementos na lista";
		cout << "\n10 - imprimir a lista";
		cout << "\n\nInforme sua opcao: ";
		int opc;
		cin >> opc;

		if (opc == 0) {
			break;
		} else if (opc == 1) {
			int opc1;
			cout << "Valor do elemento: ";
			cin >> opc1;
			lista.insereInicio(opc1);
		} else if (opc == 2) {
			int opc2;
			cout << "Valor do elemento para o final da lista: ";
			cin >> opc2;
			lista.insereFinal(opc2);
			pausa();
		} else if(opc == 3) {
			int opc3a;
			int opc3b;
			cout << "\nValor do elemento: ";
			cin >> opc3a;
			cout << "Posicao a ser inserido: ";
			cin >> opc3b;
			Celula * c = new Celula(opc3a);
			cout << lista.insereEmN(c, opc3b);
			pausa();
		} else if (opc == 4) {
			int opc4a;
			int opc4b;
			cout << "\nValor do elemento: ";
			cin >> opc4a;
			cout << "\nPosicao a ser inserida (o elemento sera inserido na posicao+1 da posicao escolhida): ";
			cin >> opc4b;
			Celula * c = new Celula(opc4a);
			cout << lista.pos_mais_um(c, opc4b);
			pausa();
		} else if (opc == 5) {
			int opc5a;
			int opc5b;
			cout << "\nValor do elemento: ";
			cin >> opc5a;
			cout << "\nPosicao a ser inserida (o elemento sera inserido na posicao-1 da posicao escolhida): ";
			cin >> opc5b;
			Celula * c = new Celula(opc5a);
			cout << lista.pos_menos_um(c, opc5b);
			pausa();
		} else if (opc == 6) {
			int opc6;
			cout << "Excluir elemento da posicao: ";
			cin >> opc6;
			lista.excluir_elem(opc6);
			pausa();
		} else if (opc == 7) {
			int opc7;
			cout << "Excluir o proximo elemento da posicao escolhida: ";
			cin >> opc7;
			lista.excluir_elem_mais_um(opc7);
			pausa();
		} else if (opc == 8) {
			int opc8;
			cout << "Excluir o elemento anterior da posicao escolhida: ";
			cin >> opc8;
			lista.excluir_elem_menos_um(opc8);
			pausa();
		} else if (opc == 9) {
			cout << "\n\nTamanho da lista = " << lista.tamanho() << " elemento(s)";
			pausa();
		} else if (opc == 10) {
			cout << "\n\nImpressao dos elemento da lista -> ";
			lista.imprime();
			pausa();
		}

	}

	return 0;
}


void ni() {
	cout << "\n\n\n\n\n          ***********************";
	cout << "\n\n          AINDA NAO IMPLEMENTADO.\n\n";
	cout << "          ***********************\n\n\n\n\n\n\n\n\n";
}


void pausa() {
	cout << "\n\n\n\n";
}



