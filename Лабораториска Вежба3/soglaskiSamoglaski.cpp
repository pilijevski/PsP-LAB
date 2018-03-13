#include <iostream>
#include <string>
#include <stdlib.h>
#define MAX 50
using namespace std;

struct Zbor
{
    string data;
};

struct Queue
{
    Zbor zborovi[MAX];
    int front, rear;
    void init();
    bool isEmpty();
    bool isFull();
    void enqueue(Zbor z);
    Zbor dequeue();
    Zbor peek();
    void printQueue();
};

void Queue::init()
{
    front = 0;
    rear = -1;
}

bool Queue::isEmpty()
{
    return rear == -1;
}
bool Queue::isFull()
{
    return rear == MAX - 1;
}

void Queue::enqueue(Zbor c)
{
    if (isFull())
    {
        cout << "Nema mesto" << endl;
        return;
    }
    zborovi[++rear] = c;
}

Zbor Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Redot e prazen." << endl;
        exit(-1);
    }
    Zbor temp = zborovi[front];
    for (int i = front; i < rear; i++)
    {
        zborovi[i] = zborovi[i + 1];
    }
    rear--;
    return temp;
}

Zbor Queue::peek()
{
    if (isEmpty())
    {
        cout << "Redot e prazen" << endl;
        exit(-1);
    }
    return zborovi[front];
}

void Queue::printQueue(){
    for (int i=front;i<=rear;i++){
        cout<<zborovi[i].data<<"->";
    }
    cout<<"/"<<endl;
}

/*
Queue izvadi_Samoglaski(Queue *red_zborovi)
{
    Zbor prv;
    Queue pomosen;
    pomosen.init();

    prv.data = red_zborovi->peek().data;

    if (red_zborovi->peek().data[0] == 'a' || red_zborovi->peek().data[0] == 'e' ||
        red_zborovi->peek().data[0] == 'i' || red_zborovi->peek().data[0] == 'o' || red_zborovi->peek().data[0] == 'u')
    {
        pomosen.enqueue(red_zborovi->dequeue());
    }
    else
    {
        red_zborovi->enqueue(red_zborovi->dequeue());
    }

    while (red_zborovi->peek().data != prv.data)
    {
        if (red_zborovi->peek().data[0] == 'a' || red_zborovi->peek().data[0] == 'e' ||
            red_zborovi->peek().data[0] == 'i' || red_zborovi->peek().data[0] == 'o' || red_zborovi->peek().data[0] == 'u')
        {
            pomosen.enqueue(red_zborovi->dequeue());
        }
        else
        {
            red_zborovi->enqueue(red_zborovi->dequeue());
        }
    }

    return pomosen;
}

Queue izvadi_Soglaski(Queue* red_zborovi){
    Queue pomosen;
    pomosen.init();
    while (!red_zborovi->isEmpty()){
        pomosen.enqueue(red_zborovi->dequeue());
    }
    return pomosen;
}
*/

int main()
{
    cout << "Vnesete go brojot na zborovi vo redot: ";

    int brZborovi;

    cin >> brZborovi;

    Queue red_zborovi;
    red_zborovi.init();
    Zbor temp;

    for (int i = 0; i < brZborovi; i++)
    {
        cout << "Vnesete go " << i << "-ot zbor: ";
        cin >> temp.data;
        red_zborovi.enqueue(temp);
    }

    Queue red_samoglaski = izvadi_Samoglaski(&red_zborovi);
    Queue red_soglaski = izvadi_Soglaski(&red_zborovi);

    red_samoglaski.printQueue();
    red_soglaski.printQueue();
}