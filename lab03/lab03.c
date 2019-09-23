#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "leitor.h"

int quantidadeLeitoresAtivos;
Data dataConsulta;

void copiar_string(char destino[], const char origem[]) {
	int i = 0;
	for (; origem[i] != '\0'; i = i + 1) {
		destino[i] = origem[i];
	}
	destino[i] = '\0';
}

void imprimeSaida(Leitor* leitores, Livro* livros) {
	int contadorLeitores = 0;;
	//int contadorLivros; 
	Leitor* leitorParaSerImpresso = &leitores[contadorLeitores];
	printf(obter_nome(leitorParaSerImpresso));
	printf("\n");
	Leitor* leitorAtual = &(leitores[contadorLeitores]);
	const int* restituicao = obter_restituicoes(leitorAtual);
	int num_rest = obter_num_restituicoes(leitorAtual);
	for (int contador = 0; contador < num_rest; contador = contador + 1) {
		Livro* livroAtual = &livros[restituicao[contador]];
		Data dataDeEmprestimo = obter_data_emprestimo(livroAtual);
		if (eh_menor_que(dataDeEmprestimo, dataConsulta)) {
			printf("%d", restituicao[contador]);	
		}
	}
	
}

void lerDadosDosLivros(int quantidadeLivrosRegistrados, char titulo[], Livro* livros) {
	int dia;
	int mes;
	int ano;
	for (int contador = 0; contador < quantidadeLivrosRegistrados; contador = contador + 1) {
		scanf("%d-%d-%d", &dia, &mes, &ano);
		scanf(" %[^\n]", titulo);
		
		Data data = criar_data(dia, mes, ano);
		livros[contador] = criar_livro(titulo, data);
	}
}

void registrarRestituicoesDevolucoes(Leitor* leitorAtual, int numeroDeEmprestimosDevolucoes) {
	for (int contadorDeLivros = 0; contadorDeLivros < numeroDeEmprestimosDevolucoes; contadorDeLivros = contadorDeLivros + 1) {
		int i;
		scanf("%d", &i);
		if (i > 0) {
			registrar_restituicao(leitorAtual, i);
		} else if (i < 0) {
			registrar_devolucao(leitorAtual, i);
		}
	}
}

void lerDadosDosLeitores(int quantidadeLeitoresAtivos, Leitor* leitores, char nome[]) {
	for (int contador = 0; contador < quantidadeLeitoresAtivos; contador = contador + 1) {
		scanf(" %[^\n]", nome);
		
		int numeroDeEmprestimosDevolucoes;
		scanf("%d", &numeroDeEmprestimosDevolucoes);
		leitores[quantidadeLeitoresAtivos] = criar_leitor(nome, numeroDeEmprestimosDevolucoes);
		Leitor* leitorAtual = &leitores[quantidadeLeitoresAtivos];
		registrarRestituicoesDevolucoes(leitorAtual, numeroDeEmprestimosDevolucoes);
	}
}

void lerEntrada(Livro* livros, Leitor* leitores, char titulo[], char nome[]) {
	//declara variáveis
	int quantidadeLivrosRegistrados;

	//recebe entrada
	scanf("%d", &quantidadeLivrosRegistrados);
	scanf("%d", &quantidadeLeitoresAtivos);
	
	livros = malloc(quantidadeLivrosRegistrados * sizeof(Livro*));
	leitores = malloc(quantidadeLeitoresAtivos * sizeof(Leitor*));

	lerDadosDosLivros(quantidadeLivrosRegistrados, titulo, livros);
	lerDadosDosLeitores(quantidadeLeitoresAtivos, leitores, nome);

	int dia;
	int mes;
	int ano;
	
	scanf("%d-%d-%d", &dia, &mes, &ano);
	//Data consulta = criar_data(dia, mes, ano);
}


int main()
{
	
	char titulo[MAXCHAR_TITULO]; // string para a leitura do título
	char nome[MAXCHAR_LNOME];    // string para a leitura do nome

	Livro* livros = NULL;        // ponteiro para o vetor de livros
	Leitor* leitores = NULL;     // ponteiro para o vetor de leitores

	lerEntrada(livros, leitores, titulo, nome);
	imprimeSaida(leitores, livros);

	desalocar_memoria(leitores);
	free(livros);

	return 0;
}

