#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DECK_SIZE 52
int size;

typedef struct
{
    char value[6];
    char suit[10];
} Card;

void createDeck(Card deck[]){
    char *values[] = {
        "Ace","2","3","4","5","6","7",
        "8","9","10","Jack","Queen","King"
    };

    char *suits[] = {
        "Hearts","Diamonds","Clubs","Spades"
    };

    int index=0;

    for (int i=0; i<4; i++){
        for (int j=0; j<13; j++){
            strcpy(deck[index].value, values[i]);
            strcpy(deck[index].suit, suits[j]);
            index++;
        }   
    }

    size=DECK_SIZE;
}

void printCard(Card c){
    printf("%s of %s\n", c.value, c.suit);
}

void printDeck(Card deck[]){
    printf("%d\n", size);
    for (int i=0; i<size; i++){
        printCard(deck[i]);
    }
}

void shuffleDeck(Card deck[]){
    for (int i=0; i<size; i++){
        int j=rand()%52;

        Card temp=deck[i];
        deck[i]=deck[j];
        deck[j]=temp;
    }
}

int decrease(int *deck_size){
    return *deck_size--;
}

Card *getCard(Card deck[]){
    if (size==0){
        return NULL;
    }
    Card *card = &deck[size-1];
    size--;
    return card;
}

_Bool putCard(Card c, Card deck[]){
    if (size<DECK_SIZE){
        deck[size] = c;
        size++;
        return 1;
    }
    return 0;
}




int main() {
    
    Card deck[DECK_SIZE];

    createDeck(deck);
    printDeck(deck);
    // printf("---");
    // shuffleDeck(deck);
    // printDeck(deck);
    Card *c1=getCard(deck);
    Card *c2=getCard(deck);
    printCard(*c1);
    printCard(*c2);
    putCard(*c2, deck);
    putCard(*c1, deck);
    printDeck(deck);


    return 0;
}
