//#ifndef __CELULA__
//#define __CELULA__

#ifndef CELULA_H
#define CELULA_H

class Celula {

	//= privado
	private:
	int info;
	Celula * prox;

	//= publico
	public:
	Celula(int);
	int  getInfo();
	void setInfo(int);
	Celula * getProx();
	void setProx(Celula * );
};
#endif

