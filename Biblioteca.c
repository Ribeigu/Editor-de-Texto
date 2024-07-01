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
void lerCaractere(PILHA *p[], int pos){
    NO *no=criarNO();
    no->letra=getchar();
    if(pilhaVazia(p[pos])){
        p[pos]->topo=no;
    }
    switch(no->letra){
        case 8: //backspace
        deleteCaractere(p, 8, pos);
            break;
        case 127: //delete
            deleteCaracter(p,9,pos);
            break;
        
    }
    no->ant=p;
    p[pos]->topo->prox=no;
    p[pos]->topo=no;
}
void deleteCaractere(PILHA *p[], int caso, int pos){
    if(!pilhaVazia(p[pos])){
        //fazer voltar pra linha anterior. Exclui a linha
        if(caso==8){
            if(p[pos-1]->topo!=NULL){
                free(p[pos]);
                return p[pos-1]->topo;
            }
        }
        if(caso==9){
            if(p[pos+1]->topo!=NULL){
                free(p[pos]);
                return p[pos+1]->topo;
            }
        }
    }
    NO *aux=p[pos]->topo;
    p[pos]->topo= aux->ant;
    p[pos]->topo->prox=NULL;
    free(aux);
    return p[pos];
}

void navegar(PILHA *p[],int direcao, int pos){
    switch(direcao){
        case esquerda:
        if(p[pos]->topo->prox!=NULL) return p[pos]->topo->prox;
        if(p[pos+1]->topo!=NULL) return p[pos+1]->topo;
            break;
        case direita:
            if(p[pos]->topo->ant!=NULL) return p[pos]->topo->ant;
            if(p[pos-1]->topo!=NULL) return p[pos-1]->topo;
            break;
        case cima:
            break;
        case baixo;
            break;
    }
}