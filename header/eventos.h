#ifndef EVENTOS_ENCADEADO_H
#define EVENTOS_ENCADEADO_H
#include <stdio.h>
#include <stdlib.h>


//Estrutura do evento, Nó evento, como nome; codigo e data, lembrando que estamos utilizando lista dupla encadeada
typedef struct NoEvento {
    int codigo;                 
    char nome[100];
    char data[10]; // 
    struct NoEvento* anterior;  
    struct NoEvento* proximo;
} NoEvento;

//Aqui é a estrutura do nó da lista dupla 
typedef struct CadastroEvento {
    No* inicio;     //Inicio da lista
    No* fim;    //fim da lista
    int tamanho;    //tamaho da lista
}CadastroEvento;


// Função: Criar estrutura de lista de eventos vazia - Leticia
CadastroEvento* criarEvento();


// Função: Destruir a lista de eventos e liberar memória - Lucas
void destruirEvento(CasdastroEvento* evento);


// Função: Inserir um novo evento no cadastro - Kauan
int inserirEvento(CadastroEvento* evento, int codigo, char *nome, char *data);


// Função: Buscar um evento pelo código - Renan
NoEvento* buscarEvento(CadastroEvento* evento, int codigo);


// Listar todos os eventos cadastrados - Renan
void listarEventos(CadastroEvento* evento);

#endif