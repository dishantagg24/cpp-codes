//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//*Simple Betting Game
// "Jack Queen King" - computer these cards
// player has to guess the position of queen.
// if he wins, he takes 3*bet 
// if he looses, he looses the bet amount.
// player has ₹100 initially

int cash = 100;

void Play (int bet){
    char C[3] ={'J','Q','K'};
    cout<<"Shuffling......."<<endl;

    srand(time(NULL));       // seeding random number generator

    for (int i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;        // swaps characters at position x and y
    }

    int playersGuess;
    cout<<"What's the position of queen -  1,2 or 3? ";
    cin>>playersGuess;

    if (C[playersGuess-1]=='Q') 
    {
        cash += 3*bet;
        cout<<"You win ! Result = "<<C[0]<<","<<C[1]<<","<<C[2]<<" Total Cash = "<<cash;
    }else{
        cash -= bet;
        cout<<"You loose ! Result = "<<C[0]<<","<<C[1]<<","<<C[2]<<" Total Cash = "<<cash;
    }
}

int main(){
    int bet;
    cout<<"Welcome to the Virtual Casino"<<endl;
    cout<<"Total cash = "<<cash<<endl;
    
    while (cash > 0)
    {
        cout<<"What's your bet? ";
        cin>>bet;
        if (bet == 0 || bet > cash)
        {
            break;
        }
        Play(bet);
        cout<<"\n***********************************************************\n";
    }
    
    return 0;
}