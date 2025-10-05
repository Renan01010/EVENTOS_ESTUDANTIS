#include <stdio.h>
#include "eventos.h"
#include "participantes.h"
#include "lista.h"

int main(){
    int menu=-1;
    int codigo;
    char nome[100], data[10];
    CadastroEvento *eventos = criarEvento();
    ListaParticipante *participantes = criarListaParticipante();
    
    printf("Sistema de eventos escolares!\nSegue o menu abaixo\n");
    do
    {
        printf("=== MENU ===");
        printf("1. CADASTRAR EVENTO:\n2. BUSCAR EVENTO:\n3. LISTAR EVENTO:\n4.INSCREVER PARTICIPANTE:\n5.BUSCAR PARTICIPANTE:\n6. LISTAR PARTICIPANTE:\n7. REMOVER PARTICIPANTE:\n. ENCERRAR PROGRAMA:\n");
        scanf("%d",&menu);
        switch (menu)
        {
            case 1:
                printf("Digite o codigo do evento: \n");
                scanf("%d",&codigo);

                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Digite a data (dia/mes/ano): ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0;

                inserirEvento(eventos, codigo, nome, data);
                printf("Evento criado!!\n");
                break;
            case 2: 
            case 3:
            case 4:
                printf("Digite o codigo do evento para inscrição: \n");
                scanf("%d",&codigo);
                if(buscarEvento(eventos, codigo) == NULL){
                    printf("Erro: evento não encontrado!\n");
                    break;
                }
                printf("Digite o RA do participante para inscrição: \n");
                scanf("%d",&RA); 
            case 5:
            case 6:
            case 7:
            case 8:
            case 9: 
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Você digitou um numero invalido, por gentileza entre com numero valido!");
        }
    } while (menu!=0);  

    return 0;
}