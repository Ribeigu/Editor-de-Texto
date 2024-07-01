//PROJETO DE EDITOR DE TEXTO POR GUSTAVO RIBEIRO E HENRIQUE FINCO
#include <stdio.h>
#include <stdlib.h>//BIBLIOTECAS USADAS
#include <conio.h>


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
            if (c == 19) {//19 � O C�DIGO ASCII PARA CTRL+S
                break;
            }
            if (c == 13) {//13 � O C�DIGO ASCII PARA ENTER
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
        printf("\n-//-//-EDITOR DE TEXTO-//-//-");//MENU COM AS OP��ES
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
