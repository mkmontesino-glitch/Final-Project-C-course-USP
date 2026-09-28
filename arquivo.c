#include <stdio.h>

#include "arquivo.h"
#include "aluno.h"

int carregar_dados(char* nome_arq, Aluno lista[], int *tamanho){
    int i = 0;
    printf("%d/", sizeof(Aluno));


    FILE* arq = fopen("alunos.bin", "rb");
    if (arq == NULL) {
        printf("Erro: Não foi possível abrir o arquivo!\n");
        exit(1);
    }

    while (fread(&lista, sizeof(Aluno), 1, arq) == 1){
        printf("%d", &lista[i].idade);
        printf("ok\n");
        *tamanho++;
        i++;
    }

    printf("%d/", sizeof(lista));


    //printf("%d\n", *tamanho);

    printf("Okkkk");

    //while(fread(&lista, sizeof (Aluno), 100, arq) != EOF){
    //}

    fclose(arq);

    //*tamanho = sizeof(lista[0]) / sizeof(Aluno);
}

int salvar_arquivo(char* nome_arq, Aluno lista[], int tamanho){
    FILE* arq = fopen("alunos.bin", "wb");
    if (arq == NULL) {
        printf("Erro: Sem espaco no disco!\n");
        exit(1);
    }
    int i = 0;

    while(i < tamanho){
        fwrite(lista, sizeof (Aluno), 1, arq);
        printf("ok");
        i++;
    }

    printf("Numero de elemntos escritos: %d", i);

    //size_t written = fwrite(lista, sizeof (Aluno), tamanho, arq);
    //printf("alunos: %d\n", sizeof(Aluno));
    //printf("Numero de elementos escritos: %zu\n", written);

    return 0;
}
