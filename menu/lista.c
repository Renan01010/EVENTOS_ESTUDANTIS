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

// Buscar participante - Leticia
NoParticipante* buscaParticipante(ListaParticipante* listaP, int RA){

    //verificar se a lista existe
    if(listaP == NULL){
        printf("Erro: lista não existe!");
        return NULL;
    }

    //percorre a lista procurando o participante
    NoParticipante* atual = listaP->inicio;
    while(atual != NULL){
        if (atual->RA == RA){
            return atual;
        }
        atual = atual->proximo;
    }

    //se não encontrou
    return NULL;
}

// Inserir participante na lista em uma posição específica - Kauan
int inserirParticipante(ListaParticipante* listaP, int RA, const char* nome, int codEvento){

    //Verifica se a lista existe
    if (listaP == NULL) {
        printf("Lista de participantes não existe!\n");
        return 0;
    }

    //verifica se o participante já existe
    if(buscaParticipante(listaP, RA) != NULL){
        printf("Erro: participante já cadastrado\n");
        return 0;
    }

    //aloca participante dinâmicamente na memória
    NoParticipante* novoParticipante = (NoParticipante*)malloc(sizeof(NoParticipante));
    if(novoParticipante == NULL) {
        printf("Erro ao adicionar participante!\n");
        return 0;
    }
    
    //preenche os dados do novo participante
    novoParticipante->RA=RA;
    strcpy(novoParticipante->nome,nome);
    novoParticipante->codEvento=codEvento; 
    novoParticipante->anterior=NULL;
    novoParticipante->proximo=NULL;

    //se a lista estiver vazia
    if(listaP->inicio == NULL){
        listaP->inicio = novoParticipante;
        listaP->fim = novoParticipante;
        } else {
        NoParticipante* atual = listaP->inicio;
        //insere em ordem alfabética
        while(atual != NULL && strcmp(nome, atual->nome)>0){
            atual = atual->proximo;
        }
        //caso inserção no inicio
        if(atual == listaP->inicio) {
            novoParticipante->proximo = listaP->inicio;
            listaP->inicio->anterior = novoParticipante;
            listaP->inicio = novoParticipante;
        }
        //caso inserção na ultima posição
        else if(atual == NULL){
            novoParticipante->anterior = listaP->fim;
            listaP->fim->proximo = novoParticipante;
            listaP->fim = novoParticipante;
        }
        //caso inserção no meio
        else{
            novoParticipante->proximo = atual;
            novoParticipante->anterior = atual->anterior;
            atual->anterior->proximo = novoParticipante;
            atual->anterior = novoParticipante;
        }
    }

    //aumenta o tamanho da lista
    listaP->tamanho++;
    return 1;
}

// Remover participante da lista - Renan
void removerParticipante(ListaParticipante* listaP, int RA){
    
    //verifica se listaParticipante existe
    if(listaP == NULL){
        printf("Erro: Lista não existe!\n");
        return;
    }

    //verifica se o participante existe
    NoParticipante* participante = buscaParticipante(listaP, RA);
    if(participante == NULL) {
        printf("Erro: participante não encontrado!\n");
        return;
    }

    //ajusta o ponteiro do participante anterior
    if (participante->anterior != NULL){
        participante->anterior->proximo = participante->proximo;
    } 
    //se for o primeiro participante
    else {
        listaP->inicio = participante->proximo;
    }

    //ajusta o ponteiro do participante posterior
    if(participante->proximo != NULL){
        participante->proximo->anterior = participante->anterior;
    } //se for o ultimo participante
    else {
        listaP->fim = participante->anterior;
    }

    //exclui o participante
    free(participante);
    listaP->tamanho--;
}

// Exibir lista de participantes - Lucas
void exibirLista(ListaParticipante* listaP){
    
    //verificar se a listaP existe
    if(listaP == NULL || listaP->inicio == NULL){
        printf("Erro: lista inexistente!\n");
        return;
    }

    //imprime a lista
    NoParticipante* atual = listaP->inicio;
    printf("Participantes:\n");
    while(atual != NULL){
        printf("RA: %d  Nome: %s\n", atual->RA, atual->nome);
        atual = atual->proximo;
    }
    return;
}
