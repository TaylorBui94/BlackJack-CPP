#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
using namespace std;

class Card
{
public:
    Card();
    Card(char rnk, char st, bool fup);
    char getRank() const;
    char getSuit() const;
    void faceUp();
    void display();
    int getValue();
private:
    char rank;
    char suit;
    bool facedUp;
};
#endif

