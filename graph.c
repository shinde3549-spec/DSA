#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int a[MAX][MAX], visited[MAX], rear = -1, front = 0, queue[MAX];
char vertices[MAX][20]; 
int n = 0;

void bfs(int, int);
void dfs(int, int);
void add(int);
int delet();
int getIndex(char*);


int main() {
    int i, j, option, choice;
    char vertex1[200], vertex2[200];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter names of %d vertices:\n", n);
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%s", vertices[i]);
    }

   
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Press 1 if there is an edge from %s to %s, else 0: ", vertices[i], vertices[j]);
            scanf("%d", &a[i][j]);
        }
    }

   
    printf("\nAdjacency Matrix:\n   ");
    for (i = 0; i < n; i++) {
        printf("%s\t", vertices[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%s\t", vertices[i]);
        for (j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    do {int v = getIndex(vertex1);
        printf("\nOPTIONS:\n1 - BFS\n2 - DFS\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("Enter vertex name: ");
        scanf("%s", vertex1);
        

        if (v == -1) {
            printf("Vertex not found!\n");
            continue;
        }

       
        for (i = 0; i < MAX; i++) {
            visited[i] = 0;
            queue[i] = 0;
        }
        front = 0;
        rear = -1;

        switch (choice) {
            case 1:
                printf("BFS Traversal starting from %s: ", vertex1);
                bfs(v, n);
                break;

            case 2:
                printf("DFS Traversal starting from %s: ", vertex1);
                dfs(v, n);
                break;


            default:
                printf("Invalid choice!\n");
        }

        printf("\nDo you want to continue? (Yes=1 / No=0): ");
        scanf("%d", &option);

    } while (option == 1);

    return 0;
}

int getIndex(char* name) {
	int i;
    for ( i = 0; i < n; i++) {
        if (strcmp(vertices[i], name) == 0)
            return i;
    }
    return -1;  
}

void bfs(int vertex, int n) {
    int i;
    visited[vertex] = 1;
    printf("%s\t", vertices[vertex]);

    for (i = 0; i < n; i++) {
        if (a[vertex][i] != 0 && visited[i] == 0) {
            add(i);
            visited[i] = 1;
        }
    }

    vertex = delet();
    if (vertex != -9)
        bfs(vertex, n);
}

void dfs(int vertex, int n) {
    int i;
    visited[vertex] = 1;
    printf("%s\t", vertices[vertex]);

    for (i = 0; i < n; i++) {
        if (a[vertex][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

void add(int no) {
    if (rear == MAX - 1) {
        printf("Queue is full!!!\n");
    } else {
        rear++;
        queue[rear] = no;
    }
}

int delet() {
    int k;
    if (front > rear)
        return -9;
    else {
        k = queue[front];
        front++;
        return k;
    }
}

/*Enter number of vertices: 5
Enter names of 5 vertices:
Vertex 1: main_building
Vertex 2: boys_hostel
Vertex 3: playground
Vertex 4: workshop
Vertex 5: parking
Press 1 if there is an edge from main_building to main_building, else 0: 0
Press 1 if there is an edge from main_building to boys_hostel, else 0: 1
Press 1 if there is an edge from main_building to playground, else 0: 1
Press 1 if there is an edge from main_building to workshop, else 0: 1
Press 1 if there is an edge from main_building to parking, else 0: 1
Press 1 if there is an edge from boys_hostel to main_building, else 0: 1
Press 1 if there is an edge from boys_hostel to boys_hostel, else 0: 0
Press 1 if there is an edge from boys_hostel to playground, else 0: 1
Press 1 if there is an edge from boys_hostel to workshop, else 0: 1
Press 1 if there is an edge from boys_hostel to parking, else 0: 1
Press 1 if there is an edge from playground to main_building, else 0: 1
Press 1 if there is an edge from playground to boys_hostel, else 0: 1
Press 1 if there is an edge from playground to playground, else 0: 0
Press 1 if there is an edge from playground to workshop, else 0: 1
Press 1 if there is an edge from playground to parking, else 0: 1
Press 1 if there is an edge from workshop to main_building, else 0: 1
Press 1 if there is an edge from workshop to boys_hostel, else 0: 1
Press 1 if there is an edge from workshop to playground, else 0: 1
Press 1 if there is an edge from workshop to workshop, else 0: 0
Press 1 if there is an edge from workshop to parking, else 0: 1
Press 1 if there is an edge from parking to main_building, else 0: 1
Press 1 if there is an edge from parking to boys_hostel, else 0: 1
Press 1 if there is an edge from parking to playground, else 0: 1
Press 1 if there is an edge from parking to workshop, else 0: 1
Press 1 if there is an edge from parking to parking, else 0: 0

Adjacency Matrix:
                       main_building        boys_hostel     playground      workshop        parking
main_building                0                   1              1              1               1
boys_hostel                  1                   0              1              1               1
playground                   1       			 1      	    0              1               1
workshop        			 1   			     1		        1		       0		       1
parking 				 	 1			         1		        1 		       1		       0

OPTIONS:
1 - BFS
2 - DFS
Enter your choice: 1
Enter vertex name: workshop
BFS Traversal starting from workshop: workshop  main_building   boys_hostel     playground      parking
Do you want to continue? (Yes=1 / No=0): 1

OPTIONS:
1 - BFS
2 - DFS
Enter your choice: 2
Enter vertex name: workshop
DFS Traversal starting from workshop: workshop  main_building   boys_hostel     playground      parking
Do you want to continue? (Yes=1 / No=0): 0

