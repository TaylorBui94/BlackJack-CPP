//
//  player.cpp
//  final 282
//
//  Created by Taylor Bui on 12/3/18.
//  Copyright (c) 2018 Taylor Bui. All rights reserved.
//

#include "Player.h"
#include "Deck.h"
Player :: Player()
{
    betAmount = 0;
    accountNumber = 0;
    balance = 0;
    splitter = false;
    earning = 0;
}

Player :: Player(double accountNumber)
{
    (*this).accountNumber = accountNumber;
    betAmount = 0;
    balance=  0;
    splitter = false;
    earning = 0;
}

Player::Player( double betAmount, double accountNumber, double balance)
{
    (*this).betAmount = betAmount;
    (*this).accountNumber = accountNumber;
    (*this).balance = balance;
    splitter = false;
    earning = 0;
}

void Player::setBetAmount(double bet)
{
    betAmount = bet;
}

Player::Player( double betAmount, double accountNumber, double balance, bool splitter)
{
    (*this).betAmount = betAmount;
    (*this).accountNumber = accountNumber;
    (*this).balance = balance;
    splitter = true;
}




//Creates a new object for a new hand. Also checks if there is a duplicate

void  Player:: split(Deck d)
{
    //checks if its possible to split.
    int duplicateCheck = 0;
    duplicateCheck = d.sumHand(d.getPlayerCards())%2;
    if(balance  >= betAmount*2 &&  duplicateCheck == 0 && d.getPlayerHandSize() == 2 )
    {
        splitter = true;
        balance = betAmount + betAmount;
    }else
        cout << " Cannot split" << endl;
}


//print statement
void Player:: stand()
{
    cout << "You have picked to stand" << endl;
}

//function to call to get the result of the game
void Player :: result(Deck d)
{
    
    cout<< "Player total :"<<d.sumHand(d.getPlayerCards()) <<". Dealer total: " <<d.sumHand(d.getDealerCards())<< endl;
    //player loses
    if(d.sumHand(d.getPlayerCards()) >21 && d.sumHand(d.getPlayerCards()) < d.sumHand(d.getDealerCards()) &&  d.sumHand(d.getDealerCards()) <22 )
    {
        balance = balance - betAmount;
        cout << "You lost $" << betAmount<< ". Your new balance is " << balance << endl;
        earning = earning-betAmount;
    }else
        if( d.sumHand(d.getPlayerCards()) == d.sumHand(d.getDealerCards()) )
           {
               //tie
               balance = balance - (betAmount/2);
               cout << "You tied. You lost $" << .5*betAmount<< ". Your new balance is " << balance << endl;
               earning = earning - (betAmount/2);
           }else
               if(d.sumHand(d.getPlayerCards()) >21 )
               {
                   //lose above 21
                   balance = balance - betAmount;
                   cout << "You lost $" << betAmount<< ". Your new balance is $" << balance << endl;
                   earning = earning -betAmount;
               }
    else
        if(d.sumHand(d.getPlayerCards()) < d.sumHand(d.getDealerCards()) && d.sumHand(d.getDealerCards()) <= 21 )
           {
               //lose
               balance = balance - betAmount;
               cout << "You lost $" << betAmount<< ". Your new balance is $" << balance << endl;
               earning = earning -betAmount;
               
           }else
           {
               //win               
               balance = balance + betAmount;
               cout<< "You won $" << betAmount <<" .Your new balance is $" << balance << endl;
               earning = earning + betAmount;
           }
      betAmount = 0;
  
}


double Player::getBalance()
{
    return balance;
}

void Player::setBalance(double money)
{
    balance = money;
}


double Player::getEarning()
{
    return earning;
}