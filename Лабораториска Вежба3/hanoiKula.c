#include <stdio.h>
#include <stdbool.h>

#define MAX 20

typedef struct element {
    int data;
} element;

typedef struct magacin {
    element elementi[MAX];
    int vrv;
} magacin;

void init (magacin *m){
    m->vrv=-1;
}

bool isEmpty(magacin* m){
    return (m->vrv==-1);
}

bool isFull (magacin* m){
    return (m->vrv==MAX-1);
}

void push (magacin* m, int data){
    if (isFull(m)){
        printf("Magacinot e poln.\n");
        fflush(stdout);
        return;
    }
    else {
        m->elementi[++m->vrv].data=data;
    }
}

element pop(magacin* m){
    if (isEmpty(m)){
        printf ("Magacinot e prazen.\n");
        fflush(stdout);
        return;
    }
    else {
        return m->elementi[m->vrv--];
    }
}

void printState(magacin* m) { // ovaa funkcija go pecati magacinot od negovoto DNO do negoviot VRV, shto znaci deka posledniot element koj ke go vidite ispecaten e onoj na koj mozete da mu napravite pop.
    int numElem = m->vrv+1;

    int i;

    printf("Sostojbata na magacinot e slednata:\n");
    fflush(stdout);

    for (int i=0;i<numElem;i++){
        printf("|");
        printf("%d",m->elementi[i].data);
    }

    printf("\n");
}

/*
void solveHanoi(magacin* A,magacin* C){


}
*/


int main () {

    magacin kulaA;

    init(&kulaA);


    // sega ke ja inicijalizirame sostojbata na kulata A.
    push(&kulaA,5);
    push(&kulaA,4);
    push(&kulaA,3);
    push(&kulaA,2);
    push(&kulaA,1);

    magacin kulaC;
    
    init(&kulaC);

    //solveHanoi(&kulaA,&kulaC);

    return 0;
}


