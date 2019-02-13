//
//  Game.cpp
//  blackjack
//
//  Created by Taylor Bui on 12/10/18.
//  Copyright (c) 2018 Taylor Bui. All rights reserved.
//

#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include <string.h>

Game::Game ()
{}

void Game:: Menu()
{
    double accountNum;
    double bet = 0;
    int input = 0;
    char playAgain ;
    bool repeat = true;
    double money;
    int counter= 0;
    
    cout << "Welcome to blackjack program by Taylor Bui" << endl;
    cout << "Enter account number: ";
    cin >> accountNum;
    Player p (accountNum);
    Deck d;
    d.shuffle();
    cout << endl;
    
    do
    {
        cout << "Your account balance is currently: $" << p.getBalance() << endl;
        if(p.getBalance()  == 0)
        {
            cout << "Input how much money you want to insert: $";
            cin >> money;
            money = p.getBalance() + money;
            p.setBalance(money);
        
            cout << "New balance is: $" << p.getBalance() << endl;
        }
        cout << "Enter how much you want to bet: $" ;
        cin >> bet;
        p.setBetAmount(bet);
        while(bet > p.getBalance())
        {
            cout << "You do not have enough money. Your balance is: $" << p.getBalance()<<". Enter how much you want to bet: $" ;
            cin >> bet;
            p.setBetAmount(bet);
        }
        
        cout << endl << "Blackjack started: " << endl;
        
        
        
        //Player card 1 draw + flip up
        d.dealToPlayer(d.deal());
        d.getPlayerCards()[d.getPlayerCards().size()-1].faceUp();
        
        //Dealer card 1 draw + flip up
        d.dealToDealer(d.deal());
        d.getDealerCards()[d.getDealerCards().size()-1].faceUp();
        
        //Player card 2 draw + flip up
        d.dealToPlayer(d.deal());
        d.getPlayerCards()[d.getPlayerCards().size()-1].faceUp();
        
        //Daeler card 2 draw + left unflipped
        d.dealToDealer(d.deal());
        
        //Display player cards
        cout << "Your cards: ";
        for(int i = 1; i< d.getPlayerCards().size()+1; i++)
        {
            d.getPlayerCards()[d.getPlayerCards().size()-i].display();
        }
        //display value of hand
        cout << " = " << d.sumHand(d.getPlayerCards()) ;
        cout << endl;
        
        //display  all dealer cards
        cout << "Dealer cards: ";
        
        for(int i = 1; i< d.getDealerCards().size()+1; i++)
        {
            d.getDealerCards()[d.getDealerCards().size()-i].display();
        }
        cout << endl;
        //Hit stand or split
        do
        {
            cout << "Do you want to 1)hit, 2)stand: ";
            cin >>input;
            switch(input)
            {
                case 1: d.hit();
                    break;
                case 2: p.stand();
                    break;
              //  case 3: p.split(d);
                //    break;
            }
            }while(input != 2);
            //flip up first dealer card
            d.getDealerCards()[d.getDealerCards().size()-1].faceUp();
            d.dealerTurn();
            
            //display  all dealer cards
            cout << "Dealer cards: ";
            
            for(int i = 1; i< d.getDealerCards().size()+1; i++)
            {
                d.getDealerCards()[d.getDealerCards().size()-i].display();
            }
            cout << " = " << d.sumHand(d.getDealerCards()) ;
            cout << endl;
            
            p.result(d);
            cout << endl <<"Would you like to play again Y/N? : ";
            cin  >> playAgain;
            playAgain = tolower(playAgain);
            if( playAgain == 'n')
            {
                repeat = false;
            }
        
        counter++;
        if(counter == 5)
        {
            d.shuffle();
            counter = 0;
        }
        d.reset();
       
    }while(repeat == true);
        cout << "Thank you for playing" << endl;
    if(p.getBalance() > 0)
    {
        cout << "Your balance is: $" << p.getBalance() <<". Go to the cashier to get your money. " <<endl;
    }
    cout << "Your total earning is: $" << p.getEarning();
    
        
        
    
}

