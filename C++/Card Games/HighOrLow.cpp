#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <random>

using namespace std;

struct Card{
    int Value;
    string Suite;
};
vector <Card> ReadCards(istream &in){
    vector <Card> allCards;
    int currentValue;
    int i=0;
    while(in){
         Card card;
        in>>card.Suite;
        allCards.push_back(card);
    }
    int p=0;
    for(int i=2;i<=14;++i){
        for(int k=0;k<4;++k){
            allCards[p].Value = i;
            ++p;
        }
    }
    return allCards;
}
int GenerateCardValue(const vector<Card> &Deck){
    srand((unsigned)time(0));
    int V = rand() % 52;
    return Deck[V].Value;
}
string GenerateCardSuite(vector <Card> Deck,int V){
    return Deck[V].Suite;
}
void GiveCurrentCard(int CCVal,string CCSuite){
    if(CCVal == 11){
        cout<<"Your current card is: "<<"The Jack of "<<CCSuite<<endl;
    }
    else if(CCVal==12){
        cout<<"Your current card is: "<<"The Queen of "<<CCSuite<<endl;
    }
    else if(CCVal==13){
        cout<<"Your current card is: "<<"The King of "<<CCSuite<<endl;
    }
    else if(CCVal==14){
        cout<<"Your current card is: "<<"The Ace of "<<CCSuite<<endl;
    }
    else{
        cout<<"Your current card is: "<<"The "<<CCVal<<" of "<<CCSuite<<endl;
    }
}


int main(){
    cout<<"Starting game..."<<endl;;
    ifstream in("cards.txt");
    vector <Card> CardDeck = ReadCards(in);
    int score=0;
    int startCardVal = GenerateCardValue(CardDeck);
    string startCardSuite = GenerateCardSuite(CardDeck,startCardVal);
    if(startCardVal == 11){
        cout<<"Your starting card is: "<<"The Jack of "<<startCardSuite<<endl;
    }
    else if(startCardVal==12){
        cout<<"Your starting card is: "<<"The Queen of "<<startCardSuite<<endl;
    }
    else if(startCardVal==13){
        cout<<"Your starting card is: "<<"The King of "<<startCardSuite<<endl;
    }
    else if(startCardVal==14){
        cout<<"Your starting card is: "<<"The Ace of "<<startCardSuite<<endl;
    }
    else{
        cout<<"Your starting card is: "<<"The "<<startCardVal<<" of "<<startCardSuite<<endl;
    }
    cout<<"Do you think that the next card is higher or lower? (h or l) ";
    char ans;
    int i =0;
    int LastCVal = startCardVal;
    string LastCSuite = startCardSuite;
    while(cin>>ans){ // starting the actual game section, player puts in guesses of higher or lower
        cout<<endl;
        int CCVal = GenerateCardValue(CardDeck);
        string CCSuite = GenerateCardSuite(CardDeck,CCVal);
            
            if(ans== 'h'&& CCVal == LastCVal){
            GiveCurrentCard(CCVal,CCSuite);
            break;
        }
        if(ans== 'l'&& CCVal == LastCVal){
            GiveCurrentCard(CCVal,CCSuite);
            cout<<"You don't get points for pairs, not in this game "<<endl;
            break;
        }
        if(ans == 'h' && CCVal > LastCVal){ //guessed higher and the player is right 
            GiveCurrentCard(CCVal,CCSuite);
            ++ score; 
            LastCVal = CCVal;
            LastCSuite = CCSuite;
            cout<<"Do you think that the next card is higher or lower? (h or l) " ;
        }
        if(ans == 'h' && CCVal < LastCVal){ //Guessed high incorrectly
            GiveCurrentCard(CCVal,CCSuite);
            break;
        }
        if(ans == 'l' && CCVal < LastCVal){
            GiveCurrentCard(CCVal,CCSuite);
            ++ score; 
            LastCVal = CCVal;
            LastCSuite = CCSuite;
            cout<<"Do you think that the next card is higher or lower? (h or l) ";   
        }
        if(ans == 'l' && CCVal > LastCVal){
            GiveCurrentCard(CCVal,CCSuite);
            break;
        }

    ++i;
    }

    cout<<"GAME OVER"<<endl;
    cout<<"Your Score was: "<<score<<endl;

}