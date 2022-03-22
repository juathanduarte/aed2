#define ADD_ARESTAS 1
#define LIST_GRAPH 2
#define EXIT 3

#define MAX_VERTICES 20

int main(int argc, char const *argv[]){
    int option = 0;
    int sizeGraph = 0;

    while (sizeGraph  <= 0 || sizeGraph > MAX_VERTICES){
        printf("O número máximo de vértices é %d\n\n", MAX_VERTICES);
        printf("Quantos vértices deseja adicionar?\n");
        scanf("%d", &sizeGraph);
    }

    int graph[sizeGraph][sizeGraph];

    for(int i = 0; i < sizeGraph; i++){
        for(int j = 0; j < sizeGraph; j++){
            graph[i][j] = 0;
        }
    }

    do{
        menu(&option);

        switch (option){
        case ADD_ARESTAS:
            addAresta(MAX_VERTICES, sizeGraph);
            break;
        case LIST_GRAPH:
            printf("LISTAR GRAFO");
            break;
        case EXIT:
            printf("SAIR");
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (1);
    
    return 0;
}

void menu(int *option) {
	printf("[%d] - ADICIONAR UMA ARESTA\n", ADD_ARESTAS);
	printf("[%d] - LISTAR GRAFO\n", LIST_GRAPH);
	printf("[%d] - SAIR\n", EXIT);

	printf("Inserir opçao:");
	scanf("%d", option);
}

void addAresta(int graph[][MAX_VERTICES], int sizeGraph){
    int v1, v2;

    printf("Inserir vértice 1:");
    scanf("%d", &v1);

    while(v1 < 0 || v1 >= sizeGraph){
        printf("Vértice inválido.\n");
        printf("Inserir vértice 1:");
        scanf("%d", &v1);
    }

    printf("Inserir vértice 2:");
    scanf("%d", &v2);

    while(v2 < 0 || v2 >= sizeGraph){
        printf("Vértice inválido.\n");
        printf("Inserir vértice 2:");
        scanf("%d", &v2);
    }

    if (graph[v1][v2] != 0){
        printf("Aresta já existe.\n");
    } else {
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}