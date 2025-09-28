#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "participantes.h"

// Criar lista de participantes - Lucas
ListaParticipante* criarListaParticipante() {

    //alocar uma nova lista dinamicamente
    ListaParticipante* novalistaP = (ListaParticipante*)malloc(sizeof(ListaParticipante));
    
    //se a lista não existe retorna um erro
    if(novalistaP == NULL){
        printf("Erro na alocacao!!\n");
        return NULL;
    }

    //inicialização das variaveis
    novalistaP->inicio = NULL;
    novalistaP->fim = NULL;
    novalistaP->tamanho = 0;
    return novalistaP; 
}

// Destruir a lista de participantes e liberar memória - Leticia
void destruirListaParticipante(ListaParticipante* listaP){

    //verificar se a lista existe 
    if(listaP == NULL){
        printf("Lista não encontrada!!\n");
        return;
    }

    //atribui um ponteiro para o participante do inicio da lista e um para o proximo
    NoParticipante* atual = listaP->inicio;
    NoParticipante* proximo;

    //O ponteiro aponta para o participante atual e o elimina então parte para o próximo enquanto atual não for NULL
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    //elimina a memória da lista de participante 
    free(listaP);
}

// Inserir participante na lista em uma posição específica - Kauan
int inserirParticipante(ListaParticipante* listaP, int RA, const char* nome, int codEvento){

    NoParticipante* novoParticipante = (NoParticipante*)malloc(sizeof(Noparticipante));

    if(novoParticipante == NULL){
        printf("erro ao adicionar participante!");
        return 0;
    }
    
    novoParticipante->RA=RA;
    strcpy(novoParticipante->nome,nome);
    novoParticipante->codEvento=codEvento; 
    novoParticipante->anterior=NULL;
    novoParticipante->proximo=NULL;

    if(ListaP == NULL){
        ListaP->inicio = novoParticipante;
        ListaP->proximo = novoParticipante;
    } else {

    }
}

// Remover participante da lista - Renan
void removerParticipante(ListaParticipante* listaP, NoParticipante* participante);

// Buscar participante - Leticia
NoParticipante* buscaParticipante(ListaParticipante* listaP, int RA);

// Exibir lista de participantes - Lucas
void exibirLista(ListaParticipante* listaP);