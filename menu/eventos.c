#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eventos.h"
#include "lista.h"

// Função: Criar estrutura de lista de eventos vazia - Leticia
CadastroEvento* criarEvento()
{
    CadastroEvento* novoEvento = (CadastroEvento*)malloc(sizeof(CadastroEvento)); //faz a alocação de memoria necessaria
    
    // verifica se a alocação foi realizada com sucesso!
    if(novoEvento == NULL){
        printf("Erro na alocacao!!\n");
        return NULL;
    }
    //coloca inicio com null, pois a lista está vazia
    novoEvento->inicio=NULL; 
    //coloca o fim como nulo tambem
    novoEvento->fim=NULL;    
    //tamanho é igual a zero, lista criada agora.
    novoEvento->tamanho=0;
    //retorna a lista de evento retoina
    return novoEvento;    
}
// Função: Destruir a lista de eventos e liberar memória - Lucas
void destruirEvento(CadastroEvento* evento)
{
    //verifica se a lista existe
    if (evento->inicio == NULL) {
        return;
    }

    //remover todos os nós da lista
    NoEvento* atual = evento->inicio;
    NoEvento* proximo;
    
    //libera memória ate o fim da lista
    while (atual != NULL){
        proximo = atual -> proximo;
        destruirListaParticipante(atual->participantes);  // libera lista de participantes usando a função de lista.h
        free(atual);
        atual = proximo;
    }
    
    //libera a memoria da lista
    free(evento);  
}

// Função: Inserir um novo evento no cadastro - Kauan
int inserirEvento(CadastroEvento* evento, int codigo, char *nome, char *data)
{
    //Verifica se a lista existe
    if(evento==NULL){
        printf("Lista nao existe!");
        return 0;
    }

    //faz a alocação de memória
    NoEvento* novoNo = (NoEvento*)malloc(sizeof(NoEvento));
    //Verifica se alocação de memória foi realizada com sucesso.
    if(novoNo==NULL){
        printf("Erro na alocacao!");
        return 0;
    }
    novoNo->codigo=codigo;
    strcpy(novoNo->nome,nome);
    strcpy(novoNo->data,data);
    novoNo->participantes = criarListaParticipante();
    novoNo->proximo=NULL;
    novoNo->anterior=NULL;

    //caso especial: se for vazia a lista
    if(evento->inicio==NULL){
        evento->inicio=novoNo;
        evento->fim=novoNo;
    }else{
        NoEvento* atual = evento->inicio;
        //verificação para inserir em ordem alfabética
        while(atual != NULL && strcmp(nome, atual->nome)>0){
            atual = atual->proximo;
        }
        //caso inserção no inicio
        if(atual == evento->inicio){
            novoNo->proximo = evento->inicio;
            evento->inicio->anterior = novoNo;
            evento->inicio = novoNo;
        }
        //caso inserção na ultima posicao
        else if (atual == NULL){
            novoNo->anterior = evento->fim;
            evento->fim->proximo = novoNo;
            evento->fim = novoNo;
        }
        else{
            //caso inserção no meio
            novoNo->proximo = atual;
            novoNo->anterior = atual->anterior;
            atual->anterior->proximo = novoNo;
            atual->anterior = novoNo;
        }
       
    }
    evento->tamanho++;
    return 1;
}

//  Função: Buscar um evento pelo código - Lucas
NoEvento* buscarEvento(CadastroEvento* evento, int codigo)
{
 if (evento == NULL || evento->inicio == NULL) {
    printf("Lista eventos vazia\n");
    return NULL;
 }
// percorrer a lista ate encontrar o codigo ou até null
    NoEvento* atual = evento->inicio;
    while(atual != NULL){
        if(atual->codigo == codigo){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Listar todos os eventos cadastrados - Renan
void listarEventos(CadastroEvento* evento)
{
    if (evento == NULL || evento->inicio == NULL) {
        printf("Sem eventos!!\n");
        return;
    }

    NoEvento* atual= evento->inicio;
    printf("Eventos:");
    while(atual != NULL){
        printf("codigo: %d\nNome: %s\nData: %s \n\n\n", atual->codigo, atual->nome, atual->data);
        atual=atual->proximo;
    }
    return;

}



