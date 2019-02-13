//
//  player.h
//  final 282
//
//  Created by Taylor Bui on 12/3/18.
//  Copyright (c) 2018 Taylor Bui. All rights reserved.
//

#ifndef __final_282__player__
#define __final_282__player__

#include "Deck.h"
#include <iostream>
using namespace std;


class Player {
	public:
	    Player();
        Player (double betAmount, double accountNumber, double balance);
        Player(double accountNumber);
	    Player (double betAmount, double accountNumber, double balance, bool splitter);
	   // void hit(Deck d) ;
        void stand(); 
	    void split(Deck d);
        void result(Deck d);
        void setBetAmount(double bet);
        double getBalance();
        void setBalance(double money);
        double getEarning();
    
		
	private:
        double betAmount ;
        double accountNumber ;
        double balance;
        bool splitter;// if this object was created by split then do this instead
        double earning;
		
};
#endif /* defined(__final_282__player__) */
