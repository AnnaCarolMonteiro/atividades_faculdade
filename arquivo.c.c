#include <stdio.h>

struct Aluno {
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

struct Aluno cadastrarAluno() {
    struct Aluno aluno;
    printf("Nome: ");
    scanf("%s", aluno.nome);
    printf("Nota 1: ");
    scanf("%f", &aluno.nota1);
    printf("Nota 2: ");
    scanf("%f", &aluno.nota2);
    printf("\n");
    return aluno;
}

void calcularMedia(struct Aluno *aluno) {
    aluno->media = (aluno->nota1 + aluno->nota2) / 2.0;
}

void escreverArquivo(struct Aluno alunos[], int quantidade) {
    FILE *arquivo = fopen("teste.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Nome: %s, Nota1: %.2f, Nota2: %.2f, Media: %.2f\n",
                alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
    }

    fclose(arquivo);

    printf("Dados dos alunos foram escritos no arquivo 'teste.txt'.\n");
}

int main() {
    struct Aluno alunos[10];
    int quantidadeAlunos = 10;

    for (int i = 0; i < quantidadeAlunos; i++) {
        alunos[i] = cadastrarAluno();
        calcularMedia(&alunos[i]);
    }

    escreverArquivo(alunos, quantidadeAlunos);

    return 0;
}
