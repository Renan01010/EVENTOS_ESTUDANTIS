#ifndef PARTICIPANTES_ENCADEADO_H
#define PARTICIPANTES_ENCADEADO_H


// Estrutura do nó do participante com os dados e ponteiro para o nó anterior e próximo
typedef struct NoParticipante {
    int RA;
    char nome[50];
    int codEvento;
    struct NoParticipante* proximo;
    struct NoParticipante* anterior;
} NoParticipante;

typedef struct ListaParticipante ListaParticipante;
void relatorioParticipacao(ListaParticipante* listaP, int RA);
void emitirListaPresenca(ListaParticipante* listaP, int codEvento);
#endif
