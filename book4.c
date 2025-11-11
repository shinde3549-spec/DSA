#include <stdio.h>
#include <string.h>

struct store {
    char name[100];
    float price;
    int book_id;
    char section[50];
} books[10];

void selectionSort(int n) {
    int i, j, minIndex, choice,k=0;
    struct store temp;

    printf("choose from below order\n");
    printf("1. ascending\n2. descending\n");
    printf("your choice is:");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        for (i = 0; i < n - 1; i++) {
		++k;
		printf("number of pass:%d\n",k);
            minIndex = i;
            for (j = i + 1; j < n; j++) {
                if (books[j].price < books[minIndex].price) {
                    minIndex = j;
                }
            }
            temp = books[minIndex];
            books[minIndex] = books[i];
            books[i] = temp;
        }
        break;
    case 2:
        for (i = 0; i < n - 1; i++) {
		++k;
		printf("number of pass:%d\n",k);
            minIndex = i;
            for (j = i + 1; j < n; j++) {
                if (books[j].price > books[minIndex].price) {
                    minIndex = j;
                }
            }
            temp = books[minIndex];
            books[minIndex] = books[i];
            books[i] = temp;
        }
        break;
    }

    printf("\nSorted Book List by Price:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Price", "Book ID", "Section");
    for (i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-10d %-10s\n",
               books[i].name,
               books[i].price,
               books[i].book_id,
               books[i].section);
    }
}

void insertionSort(int n) {
    int i, j, choice,k=0;
    struct store key;

    printf("choose from below order\n");
    printf("1. ascending\n2. descending\n");
    printf("your choice is:");
    scanf("%d", &choice);

    switch (choice) {
    case 1: 
        for (i = 1; i < n; i++) {
		++k;
		printf("number of pass:%d\n",k);
            key = books[i];
            j = i - 1;
            while (j >= 0 && books[j].price > key.price) {
                books[j + 1] = books[j];
                j--;
            }
            books[j + 1] = key;
        }
        break;
    case 2:
        for (i = 1; i < n; i++) {
		++k;
		printf("number of pass:%d\n",k);
            key = books[i];
            j = i - 1;
            while (j >= 0 && books[j].price < key.price) {
                books[j + 1] = books[j];
                j--;
            }
            books[j + 1] = key;
        }
        break;
    }

    printf("\nSorted Book List by Price (Insertion Sort):\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Price", "Book ID", "Section");
    for (i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-10d %-10s\n",
               books[i].name,
               books[i].price,
               books[i].book_id,
               books[i].section);
    }
}
void bubble_sort(int n) {
    struct store temp;
    int i, j, choice,k=0;
    printf("choose from below order\n");
    printf("1. ascending\n2. descending\n");
    printf("your choice is:");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        for (i = 0; i < n - 1; i++) {
		k++;
		printf("number of pass:%d\n",k);
            for (j = 0; j < n - i - 1; j++) {
                if (books[j].price > books[j + 1].price) {
                    temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        break;
    case 2:
        for (i = 0; i < n - 1; i++) {
		++k;
		printf("number of pass:%d\n",k);
            for (j = 0; j < n - i - 1; j++) {
                if (books[j].price < books[j + 1].price) {
                    temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        break;
    }

    printf("\nSorted Book List by Price:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Price", "Book ID", "Section");
    for (i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-10d %-10s\n",
               books[i].name,
               books[i].price,
               books[i].book_id,
               books[i].section);
    }
}

int main() {
    int n, i, choice;
    printf("How many books to save? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nGive info for book %d:\n", i + 1);
        printf("Enter name of book: ");
        scanf("%s", books[i].name);
        printf("Enter price of book: ");
        scanf("%f", &books[i].price);
        printf("Enter ID of book: ");
        scanf("%d", &books[i].book_id);
        printf("Enter section of book: ");
        scanf("%s", books[i].section);
    }

    printf("\nUnsorted Book List:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Price", "Book ID", "Section");
    for (i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-10d %-10s\n",
               books[i].name,
               books[i].price,
               books[i].book_id,
               books[i].section);
    }

    while (1) {
	    printf("Enter your choice\n");
	    printf("Choices are:\n 1. selection sort \n 2. bubble sort \n 3. insertionSort");
	    printf("Your choice is: ");
	    scanf("%d", &choice);
		switch (choice) {
	    case 1:
	        selectionSort(n);
	        break;
	    case 2:
	        bubble_sort(n);
	        break;
	    case 3:
	        insertionSort(n);
	        break;
	    default:
	        printf("Invalid choice.\n");
       }
	}

    return 0;
}

