#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;
#include "eventos.h";

// Função: Criar estrutura de lista de eventos vazia - Leticia
CadastroEvento* criarEvento()
{
    CadastroEvento* novoEvento = (CadastroEvento*)malloc(sizeof(CadastroEvento)); //faz a alocação de memoria necessaria
    
    // verifica se a alocação foi realizada com sucesso!
    if(novoEvento == NULL){
        printf("Erro na alocacao!!\n");
        return;
    }
    //coloca inio com null, pois a lista está vazia
    novoEvento->inicio=NULL; 
    //coloca o fim como nulo tambem
    novoEvento->fim=NULL;    
    //tamanho é igual a zero, lista criada agora.
    novoEvento->tamanho=0;
    //retorna a lista de evento retoina
    return novoEvento;    
}
// Função: Destruir a lista de eventos e liberar memória - Lucas
void destruirEvento(CasdastroEvento* evento)
{
    //verifica se a lista existe
    if (lista == NULL) {
        return;
    }

    //remover todos os nós da lista
    No* atual = evento->inicio;
    No* proximo;
    
    //libera memória ate o fim da lista
    while (atual != NULL){
        proximo = atual -> proximo;
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
    novoNo->proximo=NULL;
    novoNo->anterior=NULL;

    //caso especial: se for vazia a lista
    if(evento==NULL){
        evento->inicio=novoNo;
        evento->fim=novoNo;
    }else{
        NoEvento* atual =evento->inicio;
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
            novoNo->anterior = evento->ultimo;
            evento->ultimo->proximo = novoNo;
            evento->ultimo = novoNo;
        }
        else{
            novo->
        }
    }


    


}
//  Função: Buscar um evento pelo código - Renan
int NoEvento* buscarEvento()
{
 
}
// Listar todos os eventos cadastrados - Renan
void listarEventos()
{


}


//url misteriosa
//https://pbs.twimg.com/media/FwILuvgXgAAXNSH.jpg