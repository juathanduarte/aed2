#define ADD_ARESTAS 1
#define LIST_GRAPH 2
#define EXIT 3

#define MAX_VERTICES 20

int main(int argc, char const *argv[]){
    int option = 0;
    int sizeGraph = 0;

    printf("Quantos vértices deseja adicionar?\n");
    scanf("%d", &sizeGraph);

    do{
        menu(&option);

        switch (option){
        case ADD_ARESTAS:
            printf("ADICIONA ARESTAS");
            break;
        case LIST_GRAPH:
            printf("LISTAR GRAFO");
            break;
        case EXIT:
            printf("SAIR");
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