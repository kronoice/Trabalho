

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 10

struct exemplares {
	int codigo;
	char titulo[100];
	char autor[41];
	char area[7];
};

typedef struct exemplares Acervo;
typedef Acervo* Hash[tam];


void inicializa_Esp(Hash tab) {
	int i = 0;
	while (i < tam) {
		tab[i] = NULL;
		i++;
	}
}
int funcao_Esp(int codigo) {
	return (codigo % tam);
}

Acervo* insere_Esp(Hash tab, int codigo, char* titulo, char*autor, char* area) {
	int h = funcao_Esp(codigo);
	tab[h] = (Acervo*) malloc(sizeof(Acervo));
	tab[h]->codigo = codigo;
	strcpy(tab[h]->titulo, titulo);
	strcpy(tab[h]->autor, autor);
	strcpy(tab[h]->area, area);
	return tab[h];
}
void remove_Esp(Hash tab, int codigo) {
	int h = funcao_Esp(codigo);
		if (tab[h]->codigo == codigo) {
			tab[h] = NULL;
			printf("\nExemplar excluido!");
		}
		else {
			printf("\nExemplar nao encontrado");
		}
}
Acervo* busca_Esp(Hash tab, int codigo) {
	int h = funcao_Esp(codigo);
	while (tab[h] != NULL) {
		if (tab[h]->codigo == codigo)
			return tab[h];
		h = (h + 1) % tam;
	}
	return NULL;
}
int tamanho_Esp(Hash tab)
{
	int contador = 0;
	int total = 0;

	while (contador >= tam)
	{
		if (tab[contador] != NULL)
		{
			total++;
		}
		contador++;
	}
	return total;
}

void imprime_Esp(Hash tab) {
	int i = 0;
	while (i < tam) {
		printf("Posição %d:\n", i);
		if (tab[i] == NULL) {
			printf("- disponível\n\n");
		}
		else {
			printf("Codigo....: %d\n", tab[i]->codigo);
			printf("Titulo..: %s\n", tab[i]->titulo);
			printf("Autor: %s\n", tab[i]->autor);
			printf("Area.: %c\n\n", tab[i]->area);
		}

		i++;
	}
}

int main(){
	Acervo* Livro;
	Hash hashLivros;

	inicializa_Esp(hashLivros);
	//E0167
	insere_Esp(hashLivros, 000001, "Pato branco", "Rodrigo", "5");
	insere_Esp(hashLivros, 000002, "A volta dos que nao foram", "Almeida", "2");
	insere_Esp(hashLivros, 000004, "Poeira em alto Mar", "Renato", "4");
	insere_Esp(hashLivros, 000016, "As arvores somos nozes", "Julio", "7");
	//E0167
	Livro = busca_Esp(hashLivros, 000005);
	if (Livro == NULL)
	{
		printf("Não foi encontrado o codigo informado.\n\n");
	}
	else {
		printf("Codigo....: %d\n", Livro->codigo);
		printf("Titulo..: %s\n", Livro->titulo);
		printf("Autor: %s\n", Livro->autor);
		printf("Area.: %c\n\n", Livro->area);
	}

	imprime_Esp(hashLivros);

	remove_Esp(hashLivros, 000003);

	imprime_Esp(hashLivros);

}

