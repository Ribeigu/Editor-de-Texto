//PROJETO DE EDITOR DE TEXTO POR GUSTAVO RIBEIRO E HENRIQUE FINCO
#include <stdio.h>
#include <stdlib.h>//BIBLIOTECAS USADAS
#include <conio.h>

void criarArquivo() {
    char nome[20], c;//VAR PARA O NOME DO ARQUIVO E PARA OS CARACTERES
    FILE *file1, *file2;//VAR PARA OS ARQUIVOS
    file1 = fopen("temp.txt", "w");//INICIALIZA O ARQUIVO TEMPORÁRIO
    if (file1 == NULL) {
        printf("\nERRO AO ABRIR ARQUIVO");//ABRE UM ARQUIVO TEMPORÁRIO CASO NÃO DÊ ERRO
        return;
    }

    printf("\nINSIRA O TEXTO E APERTE '.' PARA SALVAR\n");
    while ((c = getchar()) != '.') {
        fputc(c, file1);//LÊ O CARACTER E SALVA NO ARQUIVO
    }
    fputc(c, file1);//SALVA O PONTO NO ARQUIVO
    fclose(file1);//FECHA O ARQUIVO TEMPORÁRIO

    printf("\nINSIRA O NOME DO ARQUIVO: ");
    scanf("%s", nome);
    fflush(stdin);//LÊ O NOME E LIMPA O BUFFER

    file1 = fopen("temp.txt", "r");
    file2 = fopen(nome, "w");//ABRE OS DOIS ARQUIVOS
    if (file1 == NULL || file2 == NULL) {
        printf("\nERRO AO ABRIR ARQUIVO");//PRINTA ERRO CASO DÊ ERRO
        return;
    }

    while ((c = getc(file1)) != EOF) {
        putc(c, file2);//PASSA O QUE FOI ESCRITO DO ARQUIVO TEMPORÁRIO PARA O FINAL
    }
    fclose(file1);
    fclose(file2);
    remove("temp.txt");//FECHA OS ARQUIVOS E APAGA O TEMPORÁRIO
}

void mostrarArquivo() {
    char nome[20], c;//VARIÁVEIS DO ARQUIVO
    FILE *file1;//INICIALIZA O ARQUIVO
    printf("\nINSIRA O NOME DO ARQUIVO: ");
    scanf("%s", nome);//NOME DO ARQUIVO QUE SERÁ BUSCADO
    fflush(stdin);//LIMPA O BUFFER

    file1 = fopen(nome, "r");//ABRE O ARQUIVO
    if (file1 == NULL) {
        printf("\nERRO AO BUSCAR ARQUIVO");//ERRO SE NÃO ACHAR O ARQUIVO
    } else {
        while ((c = getc(file1)) != EOF) {
            printf("%c", c);//PRINTA O CONTEÚDO DO ARQUIVO
        }
        fclose(file1);//FECHA O ARQUIVO
    }

    printf("\nAPERTE QUALQUER TECLA PARA CONTINUAR");
    getch();
}

void apagarArquivo() {
    char nome[20];
    printf("\nINSIRA O NOME DO ARQUIVO: ");
    scanf("%s", nome);
    fflush(stdin);//LIMPA O BUFFER

    if (remove(nome) == 0) {
        printf("\nARQUIVO DELETADO");
    } else {
        printf("\nERRO AO DELETAR ARQUIVO");
    }

    printf("\nAPERTE QUALQUER TECLA PARA CONTINUAR");
    getch();
}

void adicionarTexto() {
    char nome[20], c;
    FILE *file1;
    printf("\nINSIRA O NOME DO ARQUIVO: ");
    scanf("%s", nome);
    fflush(stdin);//LIMPA O BUFFER

    file1 = fopen(nome, "a");
    if (file1 == NULL) {
        printf("\nERRO AO ENCONTRAR ARQUIVO");
    } else {
        printf("\nINSIRA O TEXTO E APERTE 'CTRL+S' PARA SALVAR\n");
        while (1) {
            c = getch();
            if (c == 19) {//19 É O CÓDIGO ASCII PARA CTRL+S
                break;
            }
            if (c == 13) {//13 É O CÓDIGO ASCII PARA ENTER
                c = '\n';
                printf("\n");
            } else {
                printf("%c", c);
            }
            fputc(c, file1);//REGISTRA O CARACTER DIGITADO
        }
        fclose(file1);//FECHA O ARQUIVO
    }

    printf("\nINSIRA QUALQUER TECLA PARA CONTINUAR");
    getch();
}

int main() {
    int opcao;
    do {
        system("cls");//LIMPA A TELA
        printf("\n-//-//-EDITOR DE TEXTO-//-//-");//MENU COM AS OPÇÕES
        printf("\n-//-MENU-//-");
        printf("\n[1] CRIAR NOVO ARQUIVO\n[2] MOSTRAR ARQUIVO\n[3] ADICIONAR TEXTO\n[4] APAGAR ARQUIVO\n[5] SAIR\n");
        printf("\nINSIRA O QUE FAZER: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao) {
            case 1:
                criarArquivo();
                break;
            case 2:
                mostrarArquivo();
                break;
            case 3:
                adicionarTexto();
                break;
            case 4:
                apagarArquivo();
                break;
            case 5:
                exit(0);
            default:
                printf("\nERRO NA ENTRADA, TENTE NOVAMENTE: ");
                getch();
        }
    } while (1);
    return 0;
}
