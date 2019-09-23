#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "leitor.h"

void imprime_saida(int quantidadeDeLeitoresAtivos, Leitor* leitores) {
	for (int contador = 0; contador < quantidadeDeLeitoresAtivos; contador = contador + 1) {

		//leitorParaEnviar criado para poder invocar a função obter_nome, que requere ponteiro como parâmetro
		Leitor* leitorParaEnviar = &(leitores[contador]);
		printf(obter_nome(leitorParaEnviar));
		printf("\n");
		int num_rest = obter_num_restituicoes(leitorParaEnviar);	
		for (int contadorDeLivros = 0; contador < num_rest; contadorDeLivros = contadorDeLivros + 1) {
			//nothing yet
		}
	}
	//imprimeLeitorNaOrdemEmQueLeu();
	//imprimeLivrosDoLeitor();
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

void lerDadosDosLeitores(int quantidadeLeitoresAtivos, char nomeDoLeitor[], Leitor* leitores, Leitor* leitorAtual) {
	for (int contador = 0; contador < quantidadeLeitoresAtivos; contador = contador + 1) {
		scanf(" %[^\n]", nomeDoLeitor);
		
		int numeroDeEmprestimosDevolucoes;
		scanf("%d", &numeroDeEmprestimosDevolucoes);
		leitores[quantidadeLeitoresAtivos] = criar_leitor(nomeDoLeitor, numeroDeEmprestimosDevolucoes);
		registrarRestituicoesDevolucoes(leitorAtual, numeroDeEmprestimosDevolucoes);
	}
}

void lerEntrada(Livro* livros, Leitor* leitores, char titulo[]) {
	//declara variáveis
	int quantidadeLivrosRegistrados;
	int quantidadeLeitoresAtivos;

	//recebe entrada
	scanf("%d", &quantidadeLivrosRegistrados);
	scanf("%d", &quantidadeLeitoresAtivos);
	
	livros = malloc(quantidadeLivrosRegistrados * sizeof(Livro*));
	leitores = malloc(quantidadeLeitoresAtivos * sizeof(Leitor*));

	lerDadosDosLivros(quantidadeLivrosRegistrados, titulo, livros);
	lerDadosDosLeitores(quantidadeLeitoresAtivos, leitores, leitorAtual);

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

	lerEntrada(Livro* livros, Leitor* leitores, titulo);
	imprime_saida(quantidadeLeitoresAtivos, leitores);

	desalocar_memoria(leitores);
	free(livros);

	return 0;
}


void copiar_string(char destino[], const char origem[]) {
	int i = 0;
	for (; origem[i] != '\0'; i = i + 1) {
		destino[i] = origem[i];
	}
	destino[i] = '\0';
}


void imprimeSaida(Leitor* leitores, Livro* livros, int contadorLeitores, int contadorLivros, Data dataConsulta) {
	printf(obter_nome(leitores[contadorLeitores]));
	printf("\n");
	Leitor* leitorAtual = &(leitores[contadorLeitores]);
	int* restituicao = obter_restituicoes(leitorAtual);
	int num_rest = obter_num_restituicoes(leitorAtual);
	for (int contador = 0; contador < num_rest; contador = contador + 1) {
		Livro* livroAtual = livros[restituicao[contador]];
		Data dataDeEmprestimo = obter_data_emprestimo(livroAtual);
		if (eh_menor_que(dataDeEmprestimo < dataConsulta)) {
			printf(restituicao[contador]);	
		}
	}
	
}
