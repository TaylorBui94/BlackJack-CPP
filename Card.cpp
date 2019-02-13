#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(){
	rank = '\0';
	suit = '\0';
	facedUp = false;
}

Card::Card(char rnk, char st, bool fup){
	rank = rnk;
	suit = st;
	facedUp = fup;
}

void Card:: display(){
	if(!facedUp){
		cout << "|* *|";
		return;
	}
	if (rank == 'T') cout << "|10" << suit << "|";
	else cout << "|" << (*this).rank << " " << (*this).suit << "|";
}

int Card::getValue(){
	if (rank == 'A') return 10;
	else if (rank == 'T' || rank == 'K' || rank == 'Q' || rank =='J')return 10;
	else return rank-'0';
}

char Card::getRank() const{
	return rank;
}

char Card::getSuit() const{
	return suit;
}

void Card::faceUp(){
	facedUp = true;
}
