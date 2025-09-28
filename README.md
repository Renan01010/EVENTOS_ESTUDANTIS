# Sistema de Gerenciamento de Eventos em C
Desenvolver uma aplicação em linguagem C que utilize listas encadeadas para armazenar, manipular e exibir dados de eventos e participantes.

# Funcionalidades
Cadastrar eventos (código, nome, data)

Inscrever participantes (RA, nome, evento) com verificação de duplicidade

Listar participantes por evento

Remover participante de um evento

Emitir relatório de participação individual (por RA)
    
Emitir lista de presença de um evento

# Estrutura do Projeto
main.c → menu principal
eventos.c / eventos.h → cadastro e gerenciamento de eventos
participantes.c / participantes.h → inscrições e remoções
lista.c / lista.h → implementação da lista encadeada
README.md → orientações gerais
