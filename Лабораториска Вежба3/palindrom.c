#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20

typedef struct element {
    char data;
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

void push (magacin* m, char data){
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

bool ePalindrom(char zbor[]){
    int length=strlen(zbor);
    magacin prevrten;
    init(&prevrten);
    int i;
    for (i = 0;i<length;i++){
        push(&prevrten,zbor[i]);
    }

    bool allMatch = 1;
    i = 0;
    while (!isEmpty(&prevrten)){
        element temp = pop(&prevrten);
        if (temp.data != zbor[i]){
            allMatch=0;
        }
        i++;
    }
    return allMatch;

}

int main () { 
    printf("Vnesete go brojot na zborovi: ");
    int brZborovi;
    scanf("%d",&brZborovi);

    int i;
    int brPalindromi;

    for (i=0;i<brZborovi;i++){
        char zbor[20];
        printf("Vnesete go %d-ot zbor\n",i);
        scanf("%s",zbor);
        if(ePalindrom(zbor)){
            printf("Toj e palindrom.\n");
        }
        else {
            printf("Zborot ne e palindrom.\n");
        }
    }
    return 0;

}

