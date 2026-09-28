#include <stdio.h>

#include "arquivo.h"
#include "aluno.h"

int criar_aluno(Aluno lista[],int *tamanho){
    Aluno a;
    a.id = *tamanho + 1;
    a.ativo = 1;

    printf("Nome: ");
    scanf("%s", a.nome);

    printf("Idade: ");
    scanf("%d", &a.idade);

    printf("Notas: ");
    scanf("%f", &a.notas[0]);
    scanf("%f", &a.notas[1]);
    scanf("%f", &a.notas[2]);
    a.media = (a.notas[0] + a.notas[1] + a.notas[2]) / 3.0;

    lista[*tamanho] = a;
    printf("%s", lista[*tamanho].nome);
    printf("%d", lista[*tamanho].idade);
    printf("%f, %f, %f", lista[*tamanho].notas[0], lista[*tamanho].notas[1], lista[*tamanho].notas[2]);
    printf("%d", *tamanho);
    (*tamanho)++;
    printf("%d", *tamanho);

    return 0;
}

int listar_alunos(Aluno lista[],int tamanho){

    printf("=== Listagem de Alunos ===\n");

    if (tamanho == 0){
        printf("A lista de alunos esta vazia");
    } else {
        for (int i = 0; i < tamanho; i++){
        printf("%s\n", lista[i].nome);
        printf("%d\n", lista[i].idade);
        printf("%f, %f, %f\n\n", lista[i].notas[0], lista[i].notas[1], lista[i].notas[2]);
        }
    }

    printf("==========================\n");
    return 0;

}

int buscar_aluno(Aluno lista[],int tamanho){
    int id;

    printf("\nDigite o id do aluno: ");
    scanf("%d", &id);

    int pos = buscar_id(id, lista, tamanho);

    if (pos != -1){
        Aluno a = lista[pos];
        printf("%s\n", a.nome);
        printf("%d\n", a.idade);
        printf("%f, %f, %f\n\n", a.notas[0], a.notas[1], a.notas[2]);
        return 0;
    } else {
        printf("Aluno nao encontrado");
    }
    return 0;
}

int buscar(char *nome_buscado, Aluno lista[], int tamanho){
   int pos = -1;
    //for i de 0 ate tamanho
    //strcmp(nome, lista[i.nome) == 0 -> achou
    //se achou pos = posição do numero
    for (int i = 0; i < tamanho;i++){
        if (strcmp(nome_buscado, lista[i].nome) == 0){
            pos = i;
        }
    }

    return pos;
}

int buscar_id(int id, Aluno lista[], int tamanho){
   int pos = -1;
    //for i de 0 ate tamanho
    //strcmp(nome, lista[i.nome) == 0 -> achou
    //se achou pos = numero posição
    for (int i = 0; i < tamanho;i++){
        if (lista[i].ativo != 0){
            if (id == lista[i].id){
                pos = i;
            }
        }
    }

    return pos;
}

int editar_dados(Aluno lista[],int tamanho){
    char nome_buscado[100];

    printf("Digite o nome do aluno: ");
    scanf("%s", nome_buscado);

    int pos = buscar(nome_buscado, lista, tamanho);

    //se achou edita
    //senao erro
    if (pos != -1){
        printf("Novo nome: ");
        scanf("%s", lista[pos].nome);
        printf("Nova idade: ");
        scanf("%d", &lista[pos].idade);
        printf("Nova notas: ");
        scanf("%f %f %f", &lista[pos].notas[0], &lista[pos].notas[1], &lista[pos].notas[2]);
        printf("Aluno atualizado com sucesso!\n");
    } else{
        printf("Aluno nao encontrado, tente novamente.");
    }

    return 0;
}

int remover_aluno(Aluno lista[], int* tamanho){
    char nome_buscado[100];
    int tamanho2 = *tamanho;

    printf("Digite o nome do aluno que sera removido: ");
    scanf("%s", nome_buscado);

    //verificar se existe
    int pos = buscar(nome_buscado, lista, tamanho2);

    //se existir mover a lista
    if (pos != -1){
        //Se o item for o ultimo da lista:
        if (pos == *tamanho){
            *tamanho--;
        } else {
            for (pos = pos; pos < *tamanho; pos++){
                strcpy(lista[pos].nome, lista[pos+1].nome);
                lista[pos].id = lista[pos+1].id;
                lista[pos].idade = lista[pos+1].idade;
                lista[pos].notas[0] = lista[pos+1].notas[0];
                lista[pos].notas[1] = lista[pos+1].notas[1];
                lista[pos].notas[2] = lista[pos+1].notas[2];
                lista[pos].media = lista[pos+1].media;
                (*tamanho)--;
            }
        }
    } else {
        printf("Aluno nao encontrado, tente novamente");
    }

    return pos;
}

