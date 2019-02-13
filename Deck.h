#ifndef DECK_H
#define DECK_H
#include <string>
#include <iostream>
#include "Card.h" 
using namespace std;
#include <vector>

class Deck{
public:
    Deck();
    void display();
    void shuffle();
    Card deal();
    bool isEmpty();
    int sumHand(vector<Card> c);
    vector<Card>& getDealerCards();
    vector<Card>& getPlayerCards();
    void dealToPlayer(Card c);
    void dealToDealer(Card c);
    int getPlayerHandSize() const;
    int getDealHandSize() const;
    int getDeckSize() const;
    void dealerTurn();
    void reset();
    void hit() ;
    friend class Player;
private:
    vector<Card> dealerCards;
    vector<Card> playerCards;
    vector<Card> data;
    int playerHandSize;
    int dealHandSize;
    int deckSize;
};
#endif
