#include <stdio.h>
#include <stdlib.h>

#include "deck.h"
void main()
{
    struct Node* deck = create_deck();
    print_hand(deck);
    printf("There are %d cards.\n", ll_length(deck));
    ll_delete(&deck);

    print_hand(deck);
    printf("There are %d cards.\n", ll_length(deck));
}
