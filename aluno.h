#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include <string.h>

#define MAX_ALUNOS 100

typedef struct{
    int id;
    char nome [50];
    int idade;
    float notas[3];
    float media;
    int ativo;
}Aluno; // 128 bytes

Aluno a;

Aluno lista[MAX_ALUNOS];

int criar_aluno(Aluno lista[], int* tamanho);

int listar_alunos(Aluno lista[], int tamanho);

int buscar_aluno(Aluno lista[], int tamanho);

int buscar(char* nome_buscado, Aluno lista[], int tamanho);

int buscar_id(int id, Aluno lista[], int tamanho);

int editar_dados(Aluno lista[],int tamanho);

int remover_aluno(Aluno lista[], int* tamanho);

int calcular_media(Aluno lista[], int tamanho);

#endif // ALUNO_H_INCLUDED
