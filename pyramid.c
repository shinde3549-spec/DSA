#include <stdio.h>

void rightAngleTriangleWithNumbers(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}

void diamondShapeWithNumbers(int n) {
    int i, j, space;
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
    for (i = n - 1; i >= 2; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

void diamondShapeStars(int n) {
    int i, j, space;
    for (i = 1; i <= n; i++) {
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--) {
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void pyramidWithAsterisk(int n) {
    int i, j, space;
    for (i = 1; i <= n; i++) {
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void alphabetPyramid(int n) {
    int i, j;
    char ch;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            ch = 'A' + j - 1;
            printf("%c ", ch);
        }
        printf("\n");
		}
}
void alphabetDiamond(int n) {
    int i, j;
    char ch;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            ch = 'A' + j - 1;
            printf("%c ", ch);
        }
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            ch = 'A' + j - 1;
            printf("%c ", ch);
        }
        printf("\n");
    }
}
int main() {
    int n;

    printf("\nPattern 1: Right-angle triangle with numbers\n");
    rightAngleTriangleWithNumbers(4);

    printf("\nPattern 2: Diamond shape with numbers\n");
    diamondShapeWithNumbers(4);

    printf("\nPattern 3: Diamond shape with stars\n");
    diamondShapeStars(3);

    printf("\nPattern 4: Pyramid with asterisk\n");
    pyramidWithAsterisk(5);

    printf("\nPattern 5: Alphabet pyramid\n");
    alphabetPyramid(5);
alphabetDiamond(5);
    return 0;
}

