#ifndef PARTICIPANTES_ENCADEADO_H
#define PARTICIPANTES_ENCADEADO_H

#include <stdio.h>
#include <stdlib.h>
#include "eventos.h"

// Estrutura do nó do participante com os dados e ponteiro para o nó anterior e próximo
typedef struct noParticipante {
    int RA;
    char nome[50];
    int codEvento;
    struct noParticipante* proximo;
    struct noParticipante* anterior;
} NoParticipante;

// Estrutura da lista encadeada dos participantes, declara os ponteiros de inicio e fim da lista, além do contador de elementos
typedef struct {
    NoParticipante* inicio;
    NoParticipante* fim;
    int tamanho;
} ListaParticipante;

// Criar lista de participantes - Lucas
ListaParticipante* criarListaParticipante();

// Destruir a lista de participantes e liberar memória - Leticia
void destruirListaParticipante(ListaParticipante* listaP);

// Inserir participante na lista em uma posição específica - Kauan
int inserirParticipante(ListaParticipante* listaP, int RA, const char* nome, int codEvento);

// Remover participante da lista - Renan
void removerParticipante(ListaParticipante* listaP, NoParticipante* participante);

// Buscar participante - Leticia
NoParticipante* buscaParticipante(ListaParticipante* listaP, int RA);

// Exibir lista de participantes - Lucas
void exibirLista(ListaParticipante* listaP);

#endif