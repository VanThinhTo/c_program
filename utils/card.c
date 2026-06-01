typedef struct {
    char value[6];
    char suit[10];
} Card; //should put outside any function

#define DECK_SIZE 52
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int size; // logical current size of the deck

// typedef struct{
    
// } DECK;

void createDeck(Card deck[]){
    char *values[] = {
        "Ace","2","3","4","5","6","7",
        "8","9","10","Jack","Queen","King"
    };

    char *suits[] = {
        "Hearts","Diamonds","Clubs","Spades"
    };

    int index = 0;

    for (int s = 0; s < 4; s++) {
        for (int v = 0; v < 13; v++) {
            strcpy(deck[index].value, values[v]);
            strcpy(deck[index].suit, suits[s]);
            index++;
        }
    }

    size = DECK_SIZE;
}

void shuffleDeck(Card deck[]) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;

        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(Card c){
    printf("%s of %s\n", c.value, c.suit);
}

void printDeck(Card deck[]){
    printf("%d ", size);
    for (int i=0; i<size; i++){
        printCard(deck[i]);
    }
}

int decrease(int deck_size){
    return deck_size--;
}

Card * getCard(Card deck[]){
    Card *pc = NULL;
    if (size > 0){
        pc = &deck[size-1];
        size--;
    }
    return pc;
}

_Bool putCard(Card c, Card deck[]){
    if (size < DECK_SIZE){
        deck[size] = c;
        size ++;
        return 1;
    }
    return 0;
}

int main(){
    Card deck[DECK_SIZE];
    //initialize, shuffle and print deck
    createDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);

    //remove the first two cards from the deck
    Card c1,c2;
    c1=*getCard(deck);
    c2=*getCard(deck);
    //print the deck
    printf("*** Deck after getting two cards\n");
    printDeck(deck);
    //puts the removed cards on the deck
    putCard(c2, deck);
    putCard(c1, deck);
    //print the deck
    printf("*** Deck after restoring two cards\n");
    printDeck(deck);
    //simulation of blackjack
}