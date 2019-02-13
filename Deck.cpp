#include "Deck.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<Card> dealerCards;
vector<Card> playerCards;

Deck::Deck(){
	playerHandSize = 0;
	dealHandSize = 0;
	deckSize = 52;
    char suits[] = {'H','D','C','S'};
    char cards[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    for (int j=0; j<13; j++)
        for (int i=0; i<4; i++)
        	data.push_back(Card(cards[j],suits[i], false));
}

void Deck::shuffle(){
	int randomIndex;
	int randomNum = (rand() % 27);
	srand(time(0));
	for (int c = 0; c < 200; c++) {
	    for (int i = 0; i < 52; i++) {
			randomIndex = (rand() % 52);
			Card temp = data[randomIndex];
			data[randomIndex] = data[i];
			data[i] = temp;
	    }
	}
}

void Deck::display() {
	int c = 0;
	cout << "\n\t\t";
	for (int counter = 0; counter < 52; counter++){
	    if (c == 13) {
			cout << "\n\t\t";
			data[counter].display();
			c = 1;
	    } else {
			data[counter].display();
			c++;
	    }
	}
}

bool Deck::isEmpty(){
	if (deckSize > 0) return 0;
	return 1;
}

int Deck::sumHand(vector<Card> c){
	int sum = 0;
	int aces = 0;
	for (int i = 0; i<c.size() ; i++){
		if ( c[i].getRank() != 'A')
			sum += c[i].getValue();
		else aces++;
	}
	for (int i =1;i<aces;i++)
        sum++;{
		if (aces > 0){
			if(sum + 11 <= 21)
                sum+=11;
			else sum++;
		}
	}
	return sum;
}

Card Deck::deal(){
	Card c;
	if(! this->isEmpty()){
		c = data[data.size()-1];
		data.pop_back();
		return c;
	}
	else return c;
}

void Deck::dealToPlayer(Card c){
	playerCards.push_back(c);
	playerHandSize++;
	deckSize--;
}

void Deck::dealToDealer(Card c){
	dealerCards.push_back(c);
	dealHandSize++;
	deckSize--;
}

vector<Card>& Deck::getDealerCards(){
	return dealerCards;
}

vector<Card>& Deck::getPlayerCards(){
	return playerCards;
}

int Deck::getPlayerHandSize() const{
	return playerHandSize;
}

int Deck::getDealHandSize() const{
	return dealHandSize;
}

int Deck::getDeckSize() const{
	return deckSize;
}

void Deck::dealerTurn()
{
    cout << endl;
    while(sumHand(getDealerCards()) <= 15)
    {
        cout << "Dealer drew: ";
        getDealerCards()[getDealerCards().size()-1].faceUp();
        dealToDealer(deal());
        getDealerCards()[getDealerCards().size()-1].faceUp();
        getDealerCards()[getDealerCards().size()-1].display();
    }
    cout << endl;
}

void Deck::reset()
{
    dealerCards.clear();
    playerCards.clear();
    playerHandSize = 0;
    dealHandSize = 0;
}


//draw a card/deal
void Deck::hit()
{

    cout << endl << "Drawing a card: " << endl;
    dealToPlayer(deal());
    getPlayerCards()[getPlayerHandSize()-1].faceUp();
    cout << "You drew: ";
    getPlayerCards()[getPlayerHandSize()-1].display();
    cout << endl;
    
    cout<<"Your hand is: ";
    for(int i = 1; i< getPlayerHandSize()+1 ; i++)
    {
        getPlayerCards()[getPlayerHandSize()-i].display();
    }
    cout << " = " << sumHand(getPlayerCards()) ;
    cout << endl;
}
