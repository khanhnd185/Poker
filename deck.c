#include <stdio.h>
#include "deck.h"

char *stringSuit[enNumSuit] = {
    "<)",
    "C8",
    "<>",
    "<3",
};

char *stringRank[enNumRank] = {
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "J",
    "Q",
    "K",
    "A",
};

struct Node* create_deck()
{
    struct Node* head = NULL;

    for (int i = 0; i < enNumRank; i++) {
        for (int j = 0; j < enNumSuit; j++) {
            i = i & 0xf;
            j = j & 0xf;
            int value = (j << 4) | i;
            ll_push(&head, value);
        }
    }
    return head;
}

void print_hand(struct Node* hand)
{
    struct Node* card = hand;
    char rank, suit;
    
    if (card == NULL) {
        printf("No card.\n");
        return;
    }

    do {
        rank = (card->data) & 0xf;
        suit = (card->data >> 4) & 0xf;
        printf("%s-%s | ", stringRank[rank], stringSuit[suit]);

        card = card->next;
    } while (card != NULL);

    printf("\n");
}
