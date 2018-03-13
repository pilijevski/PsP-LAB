#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#define MAX 50
#define MAX2 1000

struct Ucenik
{
	string ime;
	string pol;
	void pecati()
	{
		cout<<ime<<" "<<pol<<endl;
	}
};
struct Queue
{
	Ucenik array[MAX];
	int front,rear;
	void init(){
		front=0;rear=-1;
	}
	bool isEmpty(){
		return(rear==-1);
	}
	bool isFull()
	{
		return (rear==MAX-1);
	}
	void enqueue(Ucenik e){
		if(isFull())
		{
			cout<<"nema mesto";
			return;
		}
		array[++rear]=e;
	}
	Ucenik dequeue()
	{
		if(isEmpty())
		{
			cout<<"redot e prazen";
			exit(-1);
		}
		Ucenik pom=array[front];
		for(int i=front;i<rear;i++)
			array[i]=array[i+1];
		rear--;
		return pom;
	}
	Ucenik peek()
	{
		if(isEmpty())
		{
			cout<<"redot e prazen";
			exit(-1);
		}
	return array[front];
	}
};
Queue podeliMaski(Queue Ucenici)
{
	Queue maski;
	maski.init();
//	zenski.init();
	while(!Ucenici.isEmpty())
	{
		Ucenik pom=Ucenici.dequeue();
		if(pom.pol=="masko")
		{
			maski.enqueue(pom);
		}
	}
	return maski;
}
Queue podeliZenski(Queue Ucenici)
{
	Queue zenski;
	zenski.init();
	while(!Ucenici.isEmpty())
	{
		Ucenik pom=Ucenici.dequeue();
		if(pom.pol=="zensko")
		{
			zenski.enqueue(pom);
		}
	}
	return zenski;
}
int main()
{
	Queue ucenici;
	ucenici.init();
//	ucenici.enqueue();
	Ucenik u[5];
	for(int i=0;i<3;i++)
	{
		cin>>u[i].ime;
		cin>>u[i].pol;
		ucenici.enqueue(u[i]);
	}
	Queue maski=podeliMaski(ucenici);
	cout<<"Maski"<<endl;
	while(!maski.isEmpty())
	{
		Ucenik pom=maski.dequeue();
		pom.pecati();

	}	cout<<"Zenski"<<endl;
	Queue zenski=podeliZenski(ucenici);
	while(!zenski.isEmpty())
	{
		Ucenik pom=zenski.dequeue();
		pom.pecati();
	}
}
