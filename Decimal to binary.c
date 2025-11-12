#include <stdio.h>
#define size 32

typedef struct stack {
    int top;
    int parcel[size];
} stack;

stack st;

int isFULL(){
	return (st.top==size-1);
}
int isEMPTY(){
	return (st.top==-1);
}
void push(int n) {
    if (isFULL()) {
        printf("Stack is FULL\n");
    } else {
        st.top++;
        st.parcel[st.top] = n;
    }
}

int pop() {
    if (isEMPTY()) {
        printf("Stack is EMPTY\n");
        return -1;
    } else {
        int val = st.parcel[st.top];
        st.top--;
        return val;
    }
}

void decimalToBinary(int num) {
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    st.top = -1;

    while (num > 0) {
        int rem = num % 2;
        push(rem);
        num /= 2;
    }

    printf("Binary: ");
    while (st.top != -1) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int decimal;

    st.top = -1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}

