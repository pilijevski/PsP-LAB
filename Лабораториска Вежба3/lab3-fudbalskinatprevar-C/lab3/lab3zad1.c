#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20
typedef struct element
{
	char d;
	int nakogo;
}element;
typedef struct stack
{
	int array[MAX];
	int top;
}stack;
void init(stack *s)
{
	s->top=-1;
}
bool isEmpty(stack *s)
{
	return (s->top==-1);
}
bool isFull(stack *s)
{
	return(s->top==MAX-1);
}
void push(stack *s,int e)
{
	if(isFull(s))
	{
		printf("magacinot e poln");
		return;
	}
	s->array[++s->top]=e;
}
int pop(stack *s)
{
	if(isEmpty(s))
	{
		printf("magacinot e prazen");
		exit(-1);
	}
	return s->array[s->top--];
}
int peek(stack *s)
{
	if(isEmpty(s))
	{
		printf("prazen");
		exit(-1);
	}return s->array[s->top];
}
void kojSutira(element niza[],int n)
{
	stack topka;
	init(&topka);
	push(&topka,1);
	for(int i=0;i<n;i++)
	{
		if(niza[i].d=='v')
			pop(&topka);
		else if(niza[i].d=='d')
		{
			push(&topka,niza[i].nakogo);
		}
	}
	printf("igracot koj sto sutira e %d",pop(&topka));

}
int main()
{
	element niza[15];
	int n;
	printf("Vnesi broj na igraci.\n");
	fflush(stdout);
	scanf("%d",&n);
	print("Vnesi gi igracite: <broj><dodavanje> \n");
	for(int i=0;i<n;i++){
		scanf("%d %c",&niza[i].nakogo,&niza[i].d);
	}
	kojSutira(niza,n);
	return 0;
}
