#include <iostream>
#include <string>
#include <stdlib.h>
#define MAX 50
using namespace std;

struct Covek {
    string ime;
    int vreme_opsluzuvanje;
    int ima_potrebni_dokumenti;
};

struct Queue {
    Covek luge[MAX];
    int front,rear;
    void init();
    bool isEmpty();
    bool isFull();
    void enqueue(Covek c);
    Covek dequeue();
    Covek peek();
};

void Queue::init(){
    front = 0;
    rear=-1;
}

bool Queue::isEmpty(){
    return rear==-1;
}
bool Queue::isFull(){
    return rear==MAX-1;
}

void Queue::enqueue(Covek c){
    if (isFull()){
        cout<<"Nema mesto"<<endl;
        return;
    }
    luge[++rear]=c;
}

Covek Queue::dequeue(){
    if(isEmpty()){
        cout<<"Redot e prazen."<<endl;
        exit(-1);
    }
    Covek temp=luge[front];
    for (int i=front;i<rear;i++){
        luge[i]=luge[i+1];
    }
    rear--;
    return temp;
}

Covek Queue::peek(){
    if(isEmpty()){
        cout<<"Redot e prazen"<<endl;
        exit(-1);
    }
    return luge[front];
}

/*
void presmetajVreme(Queue* redica){
    int time=0;
    while (!redica->isEmpty()){
        Covek temp = redica->dequeue();
        time+=temp.vreme_opsluzuvanje;
        if (!temp.ima_potrebni_dokumenti){
            temp.ima_potrebni_dokumenti=1;
            redica->enqueue(temp);
        }
    }
    cout<<"Potrebnoto vreme e: "<<time<<" minuti"<<endl;
}
*/



int main () { 
    Covek luge_cekaat[MAX];
    cout<<"Vnesi go brojot na luge koi cekaat vo redicata."<<endl;
    int brLuge;
    cin>>brLuge;
    for (int i=0;i<brLuge;i++){
        cout<<"Vnesi go imeto na "<<i<<"-ot covek:";
        cin>>luge_cekaat[i].ime;
        cout<<"Kolkavo e vremeto na opsluzuvanje na "<<i<<"-ot covek?"<<endl;
        cin>>luge_cekaat[i].vreme_opsluzuvanje;
        cout<<"Dali gi ima site potrebni dokumenti"<<endl;
        cin>>luge_cekaat[i].ima_potrebni_dokumenti;
    }
    cout<<"--------------------------"<<endl;


    Queue redica;
    redica.init();

    for (int i=0;i<brLuge;i++){
        redica.enqueue(luge_cekaat[i]);
    }

    //presmetajVreme(&redica);
}