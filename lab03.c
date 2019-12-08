#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "leitor.h"

void imprimir_saida(Livro* livros, Leitor* leitores, int n, Data data_consulta) {
   for (int i = 0; i < n; i++) {
      printf("%s", obter_nome(&leitores[i]));
      printf("\n");

      const int* restituicoes = obter_restituicoes(&leitores[i]);
      for (int j = 0; j < obter_num_restituicoes(&leitores[i]); j++) {
         if (eh_menor_que(obter_data_emprestimo(&livros[restituicoes[j] - 1]), data_consulta) 
            && !eh_nula(obter_data_emprestimo(&livros[restituicoes[j] - 1]))) {
            printf("Restituição: ");
            printf("%s", obter_titulo(&livros[restituicoes[j] - 1]));
            printf("\n");
         }
      }

      const int* devolucoes = obter_devolucoes(&leitores[i]);
      for (int j = 0; j < obter_num_devolucoes(&leitores[i]); j++) {
         if (eh_menor_que(obter_data_emprestimo(&livros[devolucoes[j] - 1]), data_consulta) 
            && !eh_nula(obter_data_emprestimo(&livros[devolucoes[j] - 1]))) {
            printf("Devolução: ");
            printf("%s", obter_titulo(&livros[devolucoes[j] - 1]));
            printf("\n");
         }
      }
   }
}

int main()
{
   int m, n;
   scanf("%d %d", &m, &n);

   Livro* livros = NULL;        // ponteiro para o vetor de livros
   Leitor* leitores = NULL;     // ponteiro para o vetor de leitores

   livros = malloc(m * sizeof(Livro));
   leitores = malloc(n * sizeof(Leitor));

   
   for (int i = 0; i < m; i++) {
      char titulo[MAXCHAR_TITULO]; // string para a leitura do título
      int dia, mes, ano;
      scanf("%d-%d-%d", &dia, &mes, &ano);

      scanf(" %[^\n]", titulo);
      Data data = criar_data(dia, mes, ano);
      livros[i] = criar_livro(titulo, data);
   }

   for (int i = 0; i < n; i++) {
      char nome[MAXCHAR_LNOME];    // string para a leitura do nome
      int e;
      scanf("%s", nome);
      scanf("%d", &e);
      leitores[i] = criar_leitor(nome, e);
      
      int indice_livro;

      for (int j = 0; j < e; j++) {
         scanf("%d", &indice_livro);
         if (indice_livro > 0) {
            registrar_restituicao(&leitores[i], indice_livro);
         } else {
            registrar_devolucao(&leitores[i], -indice_livro);
         }
      }
   }

   Data data_atual;
   int dia, mes, ano;
   scanf("%d-%d-%d", &dia, &mes, &ano);

   data_atual = criar_data(dia, mes, ano);

   imprimir_saida(livros, leitores, n, data_atual);

   for (int i = 0; i < n; i++) {
      desalocar_memoria(&leitores[i]);
   }

   free(livros);
   free(leitores);

   return 0;
}


