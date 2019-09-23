#include <stdlib.h>
#include "leitor.h"

void copiar_string_leitor(char str1[], const char str2[]) {
	int i = 0;
	for (; str2[i] != '\0'; i++) {
		str1[i] = str2[i];
	}
	str1[i] = '\0';
}

Leitor criar_leitor(const char* nome, int e)//OK
{
	Leitor novoLeitor;
	copiar_string_leitor(novoLeitor.nome, nome);
	novoLeitor.num_restituicoes = 0;
	novoLeitor.num_devolucoes = 0;
	return novoLeitor;
}

void desalocar_memoria(Leitor* leitor)
{
  	free(leitor);
}

const char* obter_nome(const Leitor* leitor)
{
	return leitor->nome;
}

void registrar_restituicao(Leitor* leitor, int i) //OK
{
	for(int contador = 0; contador < obter_num_restituicoes(leitor); contador++) {
		if(obter_restituicoes(leitor)[contador] == i) {
			leitor->num_restituicoes += 1;
			leitor->restituicoes[leitor->num_restituicoes] = i;		
		}	
	}
}

void registrar_devolucao(Leitor* leitor, int i) //OK
{
	for(int contador = 0; contador < obter_num_devolucoes(leitor); contador++) {
		if(obter_devolucoes(leitor)[contador] == i) {
			leitor->num_devolucoes += 1;
			leitor->devolucoes[leitor->num_devolucoes] = i;			
		}	
	}
}

const int* obter_restituicoes(const Leitor* leitor) //OK
{
	return leitor->restituicoes;
}

const int* obter_devolucoes(const Leitor* leitor) //OK
{
	return leitor->devolucoes;
}

int obter_num_restituicoes(const Leitor* leitor) //OK
{
	return (*leitor).num_restituicoes;
}

int obter_num_devolucoes(const Leitor* leitor) //OK
{
	return (*leitor).num_devolucoes;
}
