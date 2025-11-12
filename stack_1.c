#include<stdio.h>
#include<string.h>
struct patient
{char name[20];
int code;
}patient;

struct stack
{ struct patient[10];
 int top;
 };

void isfull() {
if(top == MAXSIZE)
return 1;
else
return 0;
}

int peek() {
return stack[top];
}

int pop() {
int data;
if(!isempty()) {
data = stack[top];
top = top - 1;
return data;
}else {
printf("Could not retrieve data, Stack is empty.\n");
}
}
int push(int data) {

if(!isfull()) {
top = top + 1;
stack[top] =
data; }else {
printf("Could not insert data, Stack is full.\n");
}
}

void main()
{
 int i,data;
 printf("how many patient information you have to save");
 scanf("%d",&data);
 for(i=0;i<data;i++)
  {
 printf("information of patient %d:",i+1);
 printf("name of patient:");
 scanf("%s",patient[].name);
 printf("special code %s is:",patient[].name);
 scanf("%d",&patient[].code);

}
  for(

