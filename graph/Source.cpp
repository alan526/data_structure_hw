#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct vertex{
	int data;
	struct vertex* next;
};

struct Graph {
	int numberVertex;
	struct vertex** adjList;
};

struct vertex* createV(int v);
struct Graph* createG(int num);

void addEdge(struct Graph* gra, int v1, int v2);

void BFS(struct Graph* gra, int start, int *display);

void DFS(struct Graph* gra, int *display, int currentV);

void printG(struct Graph* gra);

int main(void) {
	int number = 0, v1, v2, repeat = 0;
	char choose = 'y', discard;
	struct vertex* temp;
	printf("Enter the number of vertex => ");
	scanf("%d", &number);

	int* display1 = (int*)malloc(number * sizeof(int));
	int* display2 = (int*)malloc(number * sizeof(int));
	for (int i = 0; i < number; i++) {
		display1[i] = 0;
		display2[i] = 0;
	}

	struct Graph* gra = createG(number);
	do {
		printf("Enetr the v1 0f edge (0 ~ %d) => ", number-1);
		scanf("%d", &v1);
		if (v1 < 0 || v1 >= number) {
			printf("Data is wrong\n");
			system("pause");
			exit(1);
		}
		printf("Enetr the v2 0f edge (0 ~ %d) => ", number - 1);
		scanf("%d", &v2);
		if (v2 < 0 || v2 >= number) {
			printf("Data is wrong\n");
			system("pause");
			exit(1);
		}
		temp = gra->adjList[v1];
		while (temp) {
			if (temp->data == v2) {
				printf("The data is repeat \n");
				repeat = 1;
			}
			temp = temp->next;
		}

		if (repeat == 0) {
			addEdge(gra, v1, v2);
		}
		else {
			repeat = 0;
		}
		do {
			scanf("%c", &discard);
		} while (discard != '\n');

		printf("Do you want to add edge again (y or n) => ");
		scanf("%c", &choose);

	} while (choose == 'Y' || choose == 'y');
	
	printf("DFS: ");
	for (int i = 0; i < 4; i++) {
		DFS(gra, display1, i);
	}
	printf("\n");
	printf("BFS: ");
	for (int i = 0; i < 4; i++) {
		BFS(gra, i, display2);
	}
	printf("\n");

	printG(gra);
	system("pause");
	return(0);
}

struct vertex* createV(int v) {
	struct vertex* firstV = (vertex*)malloc(sizeof(struct vertex));
	firstV->data = v;
	firstV->next = NULL;
	return(firstV);
}

struct Graph* createG(int num) {
	
	struct Graph* graph = (Graph*)malloc(sizeof(struct Graph));
		graph->numberVertex = num;

		graph->adjList = (vertex**)malloc(num * sizeof(struct vertex*));

		for (int i = 0; i < num; i++)
			graph->adjList[i] = NULL;

		return graph;
	
}

void addEdge(struct Graph* gra, int v1, int v2)
{
	/* edge from v1 to v2 */
	struct vertex* temp = createV(v2);
	temp->next = gra->adjList[v1];
	gra->adjList[v1] = temp;

	/* edge from v2 to v1 */
	temp = createV(v1);
	temp->next = gra->adjList[v2];
	gra->adjList[v2] = temp;

}

void DFS(struct Graph* gra, int* display, int currentV) {
	if (display[currentV] == 1) {
		
	}
	else {
		struct vertex* temp = gra->adjList[currentV];
		printf("%d ", currentV);
		display[currentV] = 1;
			while (temp) {
				if (display[currentV] == 1) {
					temp = temp->next;
				}
				else {
					printf("%d ", currentV);
					display[currentV] = 1;
					currentV = temp->data;
					DFS(gra, display, currentV);
					temp = temp->next;
				}
			}
		
	}
}

void BFS(struct Graph* gra, int start, int* display) {
	int queue[40], front = 0, rear = 0;
	if (display[start] == 1) {

	}
	else {
		display[start] = 1;
		queue[rear++] = start;
		while (front!=rear&&rear!=-1)
		{
			printf("%d ", queue[front]);
			display[queue[front]] = 1;
			front++;
			struct vertex* temp = gra->adjList[queue[front-1]];
			while (temp)
			{
				if (display[temp->data]==0) {
					display[temp->data] = 1;
					queue[rear++] = temp->data;
				}
				temp = temp->next;
			}
		}
		
	}
}

void printG(struct Graph* gra) {

	for (int i = 0; i < gra->numberVertex; i++) {
		struct vertex* temp = gra->adjList[i];
		printf("adjacency list of vertex %d => ", i);
		while (temp) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

