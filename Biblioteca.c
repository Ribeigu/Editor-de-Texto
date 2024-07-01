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