#include <stdlib.h>
#include "leitor.h"

void copiar_string_leitor(char str1[], const char str2[]) {
	int i = 0;
	for (; str2[i] != '\0'; i++) {
		str1[i] = str2[i];
	}
	str1[i] = '\0';
}

Leitor criar_leitor(const char* nome, int e) {
    Leitor novoLeitor;
    copiar_string_leitor(novoLeitor.nome, nome);
	novoLeitor.restituicoes = malloc(e * sizeof(int));
	novoLeitor.devolucoes = malloc(e * sizeof(int));
	novoLeitor.num_restituicoes = 0;
	novoLeitor.num_devolucoes = 0;
	return novoLeitor;
}

void desalocar_memoria(Leitor* leitor) {
	if (leitor->restituicoes != NULL) {
		free(leitor->restituicoes);
	}
	if (leitor->devolucoes != NULL) {
		free(leitor->devolucoes);
	}
}

const char* obter_nome(const Leitor* leitor) {
	return leitor->nome;
}

void registrar_restituicao(Leitor* leitor, int i) {
	leitor->restituicoes[leitor->num_restituicoes] = i;
	leitor->num_restituicoes += 1;
}

void registrar_devolucao(Leitor* leitor, int i) {
	leitor->devolucoes[leitor->num_devolucoes] = i;
	leitor->num_devolucoes += 1;				
}

const int* obter_restituicoes(const Leitor* leitor) {
    return leitor->restituicoes;
}

const int* obter_devolucoes(const Leitor* leitor) {
	return leitor->devolucoes;
}

int obter_num_restituicoes(const Leitor* leitor) {
	return (*leitor).num_restituicoes;
}

int obter_num_devolucoes(const Leitor* leitor)
{
   return (*leitor).num_devolucoes;
}
