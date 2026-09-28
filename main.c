#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "arquivo.h"
#include "aluno.c"
#include "arquivo.c"

typedef enum{
    ADICIONAR = 1,
    LISTAR,
    BUSCAR,
    EDITAR,
    REMOVER,
    SAIR
} Opcao;
Opcao opcao;


void boas_vindas(){
    int i;

    printf("=== SISTEMA DE GESTAO DE ALUNOS ===\n1. Adicionar alunos\n2. Listar todos os alunos\n3. Buscar um aluno por ID\n4. Editar dado de um aluno\n5. Remover aluno\n6. Sair\n");
    i = scanf("%d", &opcao);
    getchar();

    if(i != 1){
        printf("Opcao invalida! Tente novamente.\n");
        while (getchar()!='\n');
        boas_vindas();
    }
}

int main(){
    Aluno lista[MAX_ALUNOS];
    carregar_dados("alunos.bin", lista, &tamanho);

    do{
        boas_vindas();

        switch (opcao){
        case ADICIONAR:
            criar_aluno(lista, &tamanho);
            break;
        case LISTAR:
            listar_alunos(lista, tamanho);
            break;
        case BUSCAR:
            buscar_aluno(lista, tamanho);
            break;
        case EDITAR:
            editar_dados (lista, tamanho);
            break;
        case REMOVER:
            remover_aluno(lista, &tamanho);
            break;
        case SAIR:
            printf("Saindo do programa...\n");
            break;
        default:
            if(scanf("%d", &opcao) != 1){
                printf("Opcao invalida! Tente novamente.\n\n");
                system("cls");
                while (getchar()!='\n');
            } else {
                printf("Erro: Opcao invalida! Tente novamente.\n");
                system("cls");
            }
            break;
        }

    } while (opcao != SAIR);

    salvar_arquivo("alunos.bin", lista, tamanho);

    return 0;
}
