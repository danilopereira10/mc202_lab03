#include "livro.h"

void copiar_string_livro(char destino[], const char origem[]) {
	int i = 0;
	for (; origem[i] != '\0'; i++) {
		destino[i] = origem[i];
	}
	destino[i] = '\0';
}

Livro criar_livro(const char* titulo, Data emprestimo) //OK
{
	Livro livro;
	copiar_string_livro(livro.titulo, titulo);
	livro.emprestimo.dia = emprestimo.dia;
	livro.emprestimo.mes = emprestimo.mes;
	livro.emprestimo.ano = emprestimo.ano;
	return livro;
}

Data obter_data_emprestimo(const Livro* livro)
{
	return (*livro).emprestimo;
}

const char* obter_titulo(const Livro* livro)
{
	return livro->titulo;
}