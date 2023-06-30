#include <stdio.h>
#include <stdlib.h>

#include "deck.h"
void main()
{
    struct Node* deck = create_deck();
    print_hand(deck);
    printf("There are %d cards.\n\n", ll_length(deck));

    struct Node* new_deck = riffle_shuffle(deck);
    print_hand(new_deck);
    printf("There are %d cards.\n\n", ll_length(new_deck));

    struct Node* hands[4];
    for (int i = 0; i < 4; i++) {
        hands[i] = NULL;
    }

    struct Node* remain = deal_cards(new_deck, hands, 4, 2);
    for (int i = 0; i < 4; i++) {
        print_hand(hands[i]);
        printf("[%d] There are %d cards.\n\n", i, ll_length(hands[i]));
    }

    struct Node *flop = NULL, *turn = NULL, *river = NULL;

    remain = deal_cards(remain, &flop, 1, 3);
    remain = deal_cards(remain, &turn, 1, 1);
    remain = deal_cards(remain, &river, 1, 1);
    print_hand(flop);
    printf("Flop %d cards.\n\n", ll_length(flop));
    print_hand(turn);
    printf("Turn %d cards.\n\n", ll_length(turn));
    print_hand(river);
    printf("River %d cards.\n\n", ll_length(river));
    print_hand(remain);
    printf("Remain %d cards.\n\n", ll_length(remain));

    ll_delete(&hands[0]);
    ll_delete(&hands[1]);
    ll_delete(&hands[2]);
    ll_delete(&hands[3]);
    ll_delete(&flop);
    ll_delete(&turn);
    ll_delete(&river);
    ll_delete(&remain);
}
