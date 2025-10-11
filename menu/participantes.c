#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participantes.h"
#include "lista.h"


// Função para gerar relatório de presença individual pelo RA
void relatorioParticipacao(ListaParticipante* listaP, int RA) {
    if (listaP == NULL) {
        printf("Lista inexistente!\n");
        return;
    }
    NoParticipante* p = listaP->inicio;
    while (p) {
        if (p->RA == RA) {
            printf("RA: %d | Nome: %s\n", p->RA, p->nome);
            return;
        }
        p = p->proximo;
    }
    printf("Participante com RA %d nao encontrado.\n", RA);
}

// Função: Emitir lista de presença de um evento - Leticia
void emitirListaPresenca(ListaParticipante* listaP, int codEvento)
{
    if (listaP == NULL || listaP->inicio == NULL) {
        printf("Nenhum participante cadastrado.\n");
        return;
    }

    printf("\n===== LISTA DE PRESENCA - EVENTO %d =====\n", codEvento);
    int encontrados = 0;

    NoParticipante* atual = listaP->inicio;
    while (atual != NULL) {
        if (atual->codEvento == codEvento) {
            printf("RA: %d | Nome: %s\n", atual->RA, atual->nome);
            encontrados++;
        }
        atual = atual->proximo;
    }

    if (encontrados == 0) {
        printf("Nenhum participante encontrado para este evento.\n");
    }

    printf("========================================\n");
}

