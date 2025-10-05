#ifndef LISTA_H
#define LISTA_H

#include "participantes.h"

// Lista de participantes por evento
typedef struct ListaParticipante {
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
void removerParticipante(ListaParticipante* listaP, int RA);

// Buscar participante - Leticia
NoParticipante* buscaParticipante(ListaParticipante* listaP, int RA);

// Exibir lista de participantes - Lucas
void exibirLista(ListaParticipante* listaP);
#endif
