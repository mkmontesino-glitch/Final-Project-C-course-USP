#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include "aluno.h"

int tamanho = 0;

int carregar_dados(char *nome_arq, Aluno lista[], int *tamanho);
int salvar_arquivo(char *nome_arq, Aluno lista[], int tamanho);

#endif // ARQUIVO_H_INCLUDED
