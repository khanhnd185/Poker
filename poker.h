#ifndef POKER_H
#define POKER_H

#include "deck.h"

int is_straight_flush(struct Card* cards);
int is_four(struct Card* cards);
int is_full_house(struct Card* cards);
int is_flush(struct Card* cards);
int is_straight(struct Card* cards);
int is_three(struct Card* cards);
int is_two_pairs(struct Card* cards);
int is_pair(struct Card* cards);

#endif /* POKER_H */
