#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eventos.h"
#include "participantes.h"
#include "lista.h"

int main(){
    int menu=-1;
    int codigo;
    char nome[100], data[11];
    int RA;
    CadastroEvento *eventos = criarEvento();

    printf("\nSistema de eventos escolares!\nSegue o menu abaixo\n");

    //Inicializa o menu com as opções para o usuario
    do
    {
        printf("\n=== MENU ===\n");
        printf("1. CADASTRAR EVENTO:\n2. LISTAR EVENTOS:\n3. INSCREVER PARTICIPANTE: \n4. REMOVER PARTICIPANTE:\n5. EMITIR RELATORIO DE PARTICIPACAO INDIVIDUAL: \n6. EMITIR LISTA DE PARTICIPACAO DE UM EVENTO: \n0. ENCERRAR PROGRAMA:\n");
        scanf("%d",&menu);


        switch (menu)
        {
            //caso 1: cadastrar evento
            case 1:
                printf("Digite o codigo do evento: \n");
                scanf("%d",&codigo);
                getchar();

                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Digite a data (dia/mes/ano): ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0;

                inserirEvento(eventos, codigo, nome, data);
                printf("Evento criado!!\n");
                break;

            //caso 2: listar eventos
            case 2:
                printf("Aqui estao todos os eventos listados:\n");
                listarEventos(eventos);
                break;
            
            //caso 3: inscrever participante no evento
            case 3: {
                printf("Digite o codigo do evento para inscricao: ");
                scanf("%d", &codigo);

                NoEvento* eventoAtual = buscarEvento(eventos, codigo);
                if (eventoAtual == NULL) {
                    printf("Erro: evento nao encontrado!\n");
                    break;
                }

                printf("Digite o RA do participante: ");
                scanf("%d", &RA);
                getchar(); 

                printf("Digite o nome do participante: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

               int resultado = inserirParticipante(eventoAtual->participantes, RA, nome, codigo);
                if ( resultado != 0)
                {
                    printf("Participante inscrito com sucesso no evento %s!\n", eventoAtual->nome);
                }
                break;
            }
             
            //caso 4: remover participante de um evento
            case 4: {
                printf("Digite o codigo do evento: ");
                scanf("%d", &codigo);

                NoEvento* eventoAtual = buscarEvento(eventos, codigo);
                if (eventoAtual == NULL) {
                    printf("Erro: evento nao encontrado!\n");
                    break;
                }

                printf("Digite o RA do participante: ");
                scanf("%d", &RA);

                removerParticipante(eventoAtual->participantes, RA);
                break;
            }

            //caso 5: emitir relatorio de participacao individual
            case 5: {
                printf("Digite o RA do participante: ");
                scanf("%d", &RA);

                NoEvento* eventoAtual = eventos->inicio;
                int encontrado = 0;

                while (eventoAtual != NULL) {
                    printf("\n=== Verificando evento: %s ===\n", eventoAtual->nome);
                    relatorioParticipacao(eventoAtual->participantes, RA);
                    eventoAtual = eventoAtual->proximo;
                    encontrado = 1;
                }

                if (!encontrado) {
                    printf("Nenhum evento cadastrado!\n");
                }
                break;
            }

            //caso 6: emitir lista de participacao em um evento
            case 6: {
                 printf("Digite o codigo do evento: ");
                 scanf("%d", &codigo);
                 NoEvento* eventoAtual = buscarEvento(eventos, codigo);
                 if (eventoAtual == NULL) {
                    printf("Erro: evento nao encontrado!\n");
                    break;
                }
                emitirListaPresenca(eventoAtual->participantes, codigo); 
                break;
            }
            
            //caso 0: encerrar o programa
            case 0:
                printf("Encerrando...\n");
                break;                
            default:
                printf("Voce digitou um numero invalido, por gentileza entre com numero valido!\n");
        }
    } while (menu!=0);  

    return 0;
}