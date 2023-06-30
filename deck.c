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

struct Node* overhand_shuffle(struct Node* deck, int pos)
{
    struct Node* cards = ll_split(deck, pos);
    ll_merge(cards, deck);
    return cards;
}

struct Node* riffle_shuffle(struct Node* deck)
{
    int len = ll_length(deck);
    int pos = (len >> 1) | (len & 1);

    struct Node* first = deck;
    struct Node* second = ll_split(first, pos);
    struct Node* tmp;

    while (second != NULL) {
        tmp = second->next;
        second->next = first->next;
        first->next = second;
        first = second->next;
        second = tmp;
    }

    return deck;
}

struct Node* deal_cards(struct Node* deck, struct Node** hands, int num_hands, int num_cards)
{
    struct Node *card, *remain;
    int len = ll_length(deck);

    len = len - 1;
    remain = deck;
    for (int i = 0; i < num_cards; i++) {
        for (int j = 0; j < num_hands; j++) {
            card = ll_split(remain, len);
            len--;
            card->next = hands[j];
            hands[j] = card;
        }
    }
    return remain;
}

void int2card(int in, struct Card* out)
{
    out->rank = (in >> 4) % enNumRank;
    out->suit = (in & 15) % enNumSuit;
}
