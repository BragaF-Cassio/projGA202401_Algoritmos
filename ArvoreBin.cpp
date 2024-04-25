#include "ArvoreBin.h"

ArvoreBin::ArvoreBin()
{
	raiz = NULL;
}


ArvoreBin::~ArvoreBin()
{
}

void ArvoreBin::inserir(int valor)
{
	raiz = inserir(valor, raiz);
}

void ArvoreBin::preOrdem()
{
	preOrdem(raiz);
}

void ArvoreBin::central()
{
	central(raiz);
}

void ArvoreBin::posOrdem()
{
	posOrdem(raiz);
}

Nodo * ArvoreBin::buscar(int valor)
{
	return buscar(valor, raiz);
}

Nodo * ArvoreBin::alocarNodo(int valor)
{
	Nodo *novo = new Nodo;
	novo->info = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

Nodo* ArvoreBin::inserir(int valor, Nodo *raiz)
{
	if(raiz == NULL){
		return alocarNodo(valor);
	} else if(raiz->info < valor) {
		raiz->dir = inserir(valor, raiz->dir);
	} else if(raiz->info > valor) {
		raiz->esq = inserir(valor, raiz->esq);
	}
	return raiz;
}

void ArvoreBin::preOrdem(Nodo * raiz)
{
	// Implementação aqui
	if(raiz){
		cout << raiz->info;
		cout << " ";
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void ArvoreBin::central(Nodo * raiz)
{
	// Implementação aqui
	if(raiz){
		central(raiz->esq);
		cout << raiz->info;
		cout << " ";
		central(raiz->dir);
	}
}

void ArvoreBin::posOrdem(Nodo * raiz)
{
	// Implementação aqui
	if(raiz){
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		cout << raiz->info;
		cout << " ";
	}
}

Nodo * ArvoreBin::buscar(int valor, Nodo * raiz)
{
	// Implementação aqui
	if(raiz == NULL) {
		cout << "Não foi localizado um nodo com o valor ";
		cout << valor;
		cout << "\n";
		return raiz;
	} else if(raiz->info == valor) {
		cout << "Nodo com o valor ";
		cout << valor;
		cout << " foi localizado!\n";
		return raiz;
	} else if(raiz->info < valor) {
		return buscar(valor, raiz->dir);
	} else {
		return buscar(valor, raiz->esq);
	}

	//Não deve entrar	
	return NULL;
}

Nodo * ArvoreBin::buscarMin(Nodo * raiz)
{
	// Implementação aqui

	return NULL; //provisorio
}

void ArvoreBin::escreverPreOrdemDot(Nodo * raiz, ofstream &arqSaida)
{
	if (raiz != NULL)
	{
		if (raiz->esq)
			arqSaida << raiz->info << " -> " << raiz->esq->info << ";" << endl;
		if (raiz->dir)
			arqSaida << raiz->info << " -> " << raiz->dir->info << ";" << endl;
		escreverPreOrdemDot(raiz->esq, arqSaida);
		escreverPreOrdemDot(raiz->dir, arqSaida);
	}

}


void ArvoreBin::gerarArqDot(string folder, string filename)
{
	ofstream arqSaida;

	wstring temp = wstring(folder.begin(), folder.end());
	LPCWSTR wideStringFolder = temp.c_str();
	if (CreateDirectoryW(wideStringFolder, NULL) || ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Pasta criada ou localizada com sucesso!
	} else {
		cout << "Houve uma falha ao criar uma pasta DOT!\n";
	}

	arqSaida.open(folder+"\\"+filename,ios::out);
	if (arqSaida.is_open()) {
        cout << "Arquivo aberto com sucesso!\n";
        
        // Escreve no arquivo
        
		arqSaida << "digraph ArvoreBinaria {" << endl;
		arqSaida << "node [shape=circle, style=\"filled, radial\", fontname=\"Arial Black\", color=\"white:#770000\", fillcolor=\"white:#FF7700\", gradientangle=\"110\"];" << endl;
		arqSaida << "edge [style=dashed];" << endl;
		escreverPreOrdemDot(raiz,arqSaida);

		arqSaida << "}" << endl;

        
        // Fecha o arquivo
        arqSaida.close();
		cout << "Arquivo salvo com sucesso!\n";

		wideStringFolder = L"svgFiles";
		if (CreateDirectoryW(wideStringFolder, NULL) || ERROR_ALREADY_EXISTS == GetLastError())
		{
			// Pasta criada ou localizada com sucesso!
		} else {
			cout << "Houve uma falha ao criar uma pasta SVG!\n";
		}
		system("dot -Tsvg dotFiles\\ArvoreBinGerado.dot -o svgFiles\\ArvoreBinGerado.svg");
		cout << "SVG Gerado!\n"; 
    } else {
        cout << "Erro ao abrir o arquivo.\n";
    }
}

void ArvoreBin::remover(int valor)
{
	// Implementação aqui
	raiz = remover(raiz, valor);
	cout << "Operação de remoção finalizada\n";
}

Nodo *ArvoreBin::remover(Nodo *raiz, int valor)
{
	//Exclusão por fusão
	if(raiz == NULL) return raiz;

	if(valor < raiz->info){
		raiz->esq = remover(raiz->esq, valor);
	} else if(valor > raiz->info){
		raiz->dir = remover(raiz->dir, valor);
	} else {
		Nodo *nodoDir = raiz->dir;
		Nodo *nodoEsq = raiz->esq;
		//delete raiz;
		raiz = NULL;

		//Se possuir 2 filhos
		if(nodoEsq != NULL && nodoDir != NULL){
			
			raiz = nodoEsq;

			while(nodoEsq->dir != NULL) {
				nodoEsq = nodoEsq->dir;
			}

			nodoEsq->dir = nodoDir;
			
		} else if(nodoEsq != NULL) {
			raiz = nodoEsq;
		} else if(nodoDir != NULL) {
			raiz = nodoDir;
		}

		
		cout << "Valor ";
		cout << valor;
		cout << " removido!\n";
	}

	return raiz;
}
