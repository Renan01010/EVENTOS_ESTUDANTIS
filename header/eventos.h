#ifndef EVENTOS_ENCADEADO_H
#define EVENTOS_ENCADEADO_H
#include "participantes.h" 

// Declaração forward para ListaParticipante (definida em lista.h)
// Isso informa ao compilador que "ListaParticipante" é um struct.
typedef struct ListaParticipante ListaParticipante; 


//Estrutura do evento, Nó evento, como nome; codigo e data, lembrando que estamos utilizando lista dupla encadeada
typedef struct NoEvento {
    int codigo;                 
    char nome[100];
    char data[11]; // 
    struct NoEvento* anterior;  
    struct NoEvento* proximo;
    ListaParticipante* participantes;
}NoEvento;

//Aqui é a estrutura do nó da lista dupla 
typedef struct CadastroEvento {
    struct NoEvento* inicio;     //Inicio da lista
    struct NoEvento* fim;    //fim da lista
    int tamanho;    //tamaho da lista
}CadastroEvento;


// Função: Criar estrutura de lista de eventos vazia - Leticia
CadastroEvento* criarEvento(void);


// Função: Destruir a lista de eventos e liberar memória - Lucas
void destruirEvento(CadastroEvento* evento);


// Função: Inserir um novo evento no cadastro - Kauan
int inserirEvento(CadastroEvento* evento, int codigo, char *nome, char *data);


// Função: Buscar um evento pelo código - Renan
NoEvento* buscarEvento(CadastroEvento* evento, int codigo);


// Listar todos os eventos cadastrados - Renan
void listarEventos(CadastroEvento* evento);

#endif
