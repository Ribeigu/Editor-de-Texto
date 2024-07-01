#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct no{
    char letra;
    struct no *ant;
    struct no *prox;
}NO;
typedef struct pilha{
    struct no *topo;
}PILHA;

NO* criarNo(){
        NO *novoNo = (NO*)malloc(sizeof(NO));
        novoNo->letra=NULL;
        novoNo->ant=NULL;
        return novoNo;
}
int pilhaVazia(PILHA *p){
    if(p->topo==NULL) return TRUE;
    return FALSE;
}
void lerCaractere(PILHA *p){
    NO *no=criarNO();
    no->letra=getchar();
    if(pilhaVazia(p)){
        p->topo=no;
    }
    switch(no->letra){
        case 8:
        deleteCaractere(p, 8);
            break;
        case 127:
            deleteCaracter(p,9);
            break;
        
    }
    no->ant=p;
    p->topo->prox=no;
    p->topo=no;
}
void deleteCaractere(PILHA *p, int caso){
    if(!pilhaVazia(p)){
        //fazer voltar pra linha anterior. Exclui a linha
        if(caso==8){

        }
        if(caso==9){

        }
    }
    NO *aux=p->topo;
    p->topo= aux->ant;
    p->topo->prox=NULL;
    free(aux);
}
void criarArquivo() {
    char nome[20], c;//VAR PARA O NOME DO ARQUIVO E PARA OS CARACTERES
    FILE *file1, *file2;//VAR PARA OS ARQUIVOS
    file1 = fopen("temp.txt", "w");//INICIALIZA O ARQUIVO TEMPOR�RIO
    if (file1 == NULL) {
        printf("\nERRO AO ABRIR ARQUIVO");//ABRE UM ARQUIVO TEMPOR�RIO CASO N�O D� ERRO
        return;
    }

    printf("\nINSIRA O TEXTO E APERTE '.' PARA SALVAR\n");
    while ((c = getchar()) != '.') {
        fputc(c, file1);//L� O CARACTER E SALVA NO ARQUIVO
    }
    fputc(c, file1);//SALVA O PONTO NO ARQUIVO
    fclose(file1);//FECHA O ARQUIVO TEMPOR�RIO

    printf("\nINSIRA O NOME DO ARQUIVO: ");
    scanf("%s", nome);
    fflush(stdin);//L� O NOME E LIMPA O BUFFER

    file1 = fopen("temp.txt", "r");
    file2 = fopen(nome, "w");//ABRE OS DOIS ARQUIVOS
    if (file1 == NULL || file2 == NULL) {
        printf("\nERRO AO ABRIR ARQUIVO");//PRINTA ERRO CASO D� ERRO
        return;
    }

    while ((c = getc(file1)) != EOF) {
        putc(c, file2);//PASSA O QUE FOI ESCRITO DO ARQUIVO TEMPOR�RIO PARA O FINAL
    }
    fclose(file1);
    fclose(file2);
    remove("temp.txt");//FECHA OS ARQUIVOS E APAGA O TEMPOR�RIO
}

void mostrarArquivo() {
    char nome[20], c;//VARI�VEIS DO ARQUIVO
    FILE *file1;//INICIALIZA O ARQUIVO
    printf("\nINSIRA O NOME DO ARQUIVO: ");
    scanf("%s", nome);//NOME DO ARQUIVO QUE SER� BUSCADO
    fflush(stdin);//LIMPA O BUFFER

    file1 = fopen(nome, "r");//ABRE O ARQUIVO
    if (file1 == NULL) {
        printf("\nERRO AO BUSCAR ARQUIVO");//ERRO SE N�O ACHAR O ARQUIVO
    } else {
        while ((c = getc(file1)) != EOF) {
            printf("%c", c);//PRINTA O CONTE�DO DO ARQUIVO
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
