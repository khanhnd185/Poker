#ifndef DECK_H
#define DECK_H

#include "linklist.h"

typedef enum enSuit {
    enSpade,
    enClub,
    enDiamond,
    enHeart,
    enNumSuit
} Suit;

typedef enum enRank {
    en2,
    en3,
    en4,
    en5,
    en6,
    en7,
    en8,
    en9,
    en10,
    enJ,
    enQ,
    enK,
    enA,
    enNumRank
} Rank;

extern char *stringIcon[enNumSuit];
extern char *stringRank[enNumRank];

struct Node* create_deck();
void print_hand(struct Node* hand);

#endif /* DECK_H */