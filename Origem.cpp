#include <cstdio>

#include <iostream>
#include "ArvoreBin.h"
#include "ArvoreBin.cpp"

using namespace std;

int main()
{
	freopen("output.log", "w", stdout);

	ArvoreBin arvore;
	
	/*
	arvore.inserir(10);
	//cout << arvore.getRaiz()->info;
	arvore.inserir(5);
	arvore.inserir(20);
	arvore.inserir(3);
	arvore.inserir(7);

	arvore.inserir(4);
	arvore.inserir(2);
	arvore.inserir(6);
	arvore.inserir(1);
	arvore.inserir(3);
	arvore.inserir(5);
	arvore.inserir(7);
	*/
	
	/*
	arvore.inserir(8);
	arvore.inserir(4);
	arvore.inserir(18);
	arvore.inserir(2);
	arvore.inserir(6);
	arvore.inserir(12);
	arvore.inserir(20);
	arvore.inserir(10);
	arvore.inserir(16);
	arvore.inserir(14);
	*/

	/*
	arvore.inserir(0);
	arvore.inserir(1);
	arvore.inserir(2);
	arvore.inserir(4);
	arvore.inserir(6);
	arvore.inserir(8);
	arvore.inserir(9);
	arvore.inserir(27);
	arvore.inserir(42);
	arvore.inserir(54);
	*/
	
	arvore.inserir(10);
	arvore.inserir(20);
	arvore.inserir(18);
	//arvore.inserir(30);
	arvore.inserir(5);
	arvore.inserir(9);
	arvore.inserir(1);
	arvore.inserir(18);
	arvore.inserir(1);
	arvore.inserir(16);
	arvore.inserir(-1);
	arvore.inserir(27);

	cout << "Caminhamento pre-ordem: ";
	arvore.preOrdem();
	cout << "\n--------------------------\n";

	cout << "Caminhamento central: ";
	arvore.central();
	cout << "\n--------------------------\n";

	cout << "Caminhamento pos-ordem: ";
	arvore.posOrdem();
	cout << "\n--------------------------\n";

	arvore.remover(18);

	arvore.buscar(10);

	arvore.gerarArqDot();


	//system("pause");
	cout << "Finalizando a aplicação...\n";

	cout << "\n";
	return 0;
}