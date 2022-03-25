#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD_ARESTAS 1
#define LIST_GRAPH 2
#define EXIT 3

#define MAX_VERTICES 20

void menu(int *option);
void clearGraph(int sizeGraph);
int addWeight(int sizeGraph);
void listGraph(int sizeGraph);

int graph[MAX_VERTICES][MAX_VERTICES];

int main(int argc, char const *argv[]){
    int option = 0;
    int sizeGraph = 0;

    while (sizeGraph  <= 0 || sizeGraph > MAX_VERTICES){
        system("clear || cls");
        printf("O número máximo de vértices é %d\n\n", MAX_VERTICES);
        printf("Quantos vértices deseja adicionar? ");
        scanf("%d", &sizeGraph);
    }

    clearGraph(sizeGraph);

    do{
        menu(&option);

        switch (option){
            case ADD_ARESTAS:
                addWeight(sizeGraph);
                break;
            case LIST_GRAPH:
                listGraph(sizeGraph);
                break;
            case EXIT:
                printf("Saindo do programa...\n");
                exit(0);
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (1);
    
    return 0;
}

void menu(int *option) {
    printf("\nLISTA 1 [GRAFOS] - JUATHAN COELHO DUARTE\n");
	printf("\n\t[%d] - ADICIONAR UMA ARESTA\n", ADD_ARESTAS);
	printf("\t[%d] - LISTAR GRAFO\n", LIST_GRAPH);
	printf("\t[%d] - SAIR\n", EXIT);

	printf("\n- Inserir opção: ");
	scanf("%d", option);
}

void clearGraph(int sizeGraph){
    int i, j;

    for (i = 0; i < sizeGraph; i++){
        for (j = 0; j < sizeGraph; j++){
            graph[i][j] = 0;
        }
    }
}

int addWeight(int sizeGraph){
    int v1, v2;
    int weight;
    char confirm[2];

    printf("\nOpção [%d] - ADICIONAR UMA ARESTA\n\n", ADD_ARESTAS);

    do{
        printf("Inserir vértice 1: ");
        scanf("%d", &v1);

        printf("Inserir vértice 2: ");
        scanf("%d", &v2);

        v1--;
        v2--;
    } while ((v1 < 0 || v1 >= sizeGraph) && (v2 < 0 || v2 >= sizeGraph));

    if (graph[v1][v2] != 0){
        printf("Já existe uma aresta entre os vértices [%d][%d], deseja alterar?. Y || N\n" , v1, v2);
        scanf("%s", &confirm);
        
        if  (strcmp(confirm, "Y") == 0 || strcmp(confirm, "y") == 0){
            printf("Inserir peso:");
            scanf("%d", &weight);
            graph[v1][v2] = weight;
        } else {
            printf("Aresta não alterada.\n");
        }
    } else {
        printf("Qual o peso da aresta?\n");
        scanf("%d", &weight);

        while (weight < 0){
            printf("Peso inválido.\n");
            printf("Qual o peso da aresta?\n");
            scanf("%d", &weight);
        }
        graph[v1][v2] = weight;
    }

    return graph;
}

void listGraph(int sizeGraph){
    int i, j;

    printf("\nOpção [%d] - LISTAR GRAFO\n\n", LIST_GRAPH);

    for (i = 0; i < sizeGraph; i++){
        for (j = 0; j < sizeGraph; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}