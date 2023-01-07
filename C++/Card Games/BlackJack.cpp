#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;

struct Card{
    int Value;
    string Suite;
    bool drawn;
};
struct Hand{
    vector<Card> hand;
    int total;
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
             allCards.at(p).Value = i;
            ++p;
        }
    }
    return allCards;
}
int GenerateCardValue(const vector<Card> &Deck){
    int v=rand()%52;
    return Deck[v].Value;
}
string GenerateCardSuite(const vector <Card> &Deck,int V){
    return Deck[V].Suite;
}
void HitHum(){}
void HitAi(){}
void Ai(Hand &handP){}
void CreatInHands(Hand &handP,Hand &handC,const vector<Card> &Deck){
    handP.total=0;
    handC.total=0;
    for(int i=0; i<2;++i){
        Card card;
        card.Value=GenerateCardValue(Deck);
        card.Suite=GenerateCardSuite(Deck,card.Value);
        handP.hand.push_back(card);
        if(card.Value<11){
            handP.total+=card.Value;
        }
        else if(card.Suite!="Ace"){
            handP.total+=10;
        }
        else{
            handP.total+=1;
        }
    }
    for(int i=0;i<2;++i){
        Card card;
        card.Value=GenerateCardValue(Deck);
        card.Suite=GenerateCardSuite(Deck,card.Value);
        handC.hand.push_back(card);
        handC.total+=card.Value;
    }
}
string handConvert(Hand &h,int i){
    string val=" ";
    if(h.hand[i].Value==2){
        val="2";
        return val;
    }
    if(h.hand[i].Value==3){
        val="3";
        return val;
    }
    if(h.hand[i].Value==4){
        val="4";
        return val;
    }
    if(h.hand[i].Value==5){
        val="5";
        return val;
    }
    if(h.hand[i].Value==6){
        val="6";
        return val;
    }
    if(h.hand[i].Value==7){
        val="7";
        return val;
    }
    if(h.hand[i].Value==8){
        val="8";
        return val;
    }
    if(h.hand[i].Value==9){
        val="9";
        return val;
    }
    if(h.hand[i].Value==10){
        val="10";
        return val;
    }
    if(h.hand[i].Value==11){
        val="Jack";
        return val;
    }
    if(h.hand[i].Value==12){
        val="Queen";
        return val;
    }
    if(h.hand[i].Value==13){
        val="King";
        return val;
    }
    if(h.hand[i].Value==14){
        val="Ace";
        return val;
    }
    else{
        return val;
    }
}
void announceHand(Hand &handP){
    cout<<endl;
    for(int i=0; i<handP.hand.size();++i){
        string val=handConvert(handP,i);
        cout<<"Card "<<i+1<<" is the "<<val<<" of "<<handP.hand[i].Suite<<endl;
    }
    cout<<"The total value of the hand is "<<handP.total<<endl;
        if(handP.hand[0].Suite=="Ace"||handP.hand[0].Suite=="Ace"){
        cout<<"Do you want the Ace to count as 1 or 11? ";
        int ans;
        cin>>ans;
        if(ans==11){
            handP.total+=10;
            cout<<"The new total is: "<<handP.total<<endl;
        }
    }
}
void redraw(char ans,Hand &handP, Hand handC, vector<Card> deck){
    handP.hand.clear();
    CreatInHands(handP,handC,deck);
    announceHand(handP);
}
void Hit(Hand &hand){}
int main(){
    srand(time(0));
    vector<Card> deck;
    ifstream in("cards.txt");
    deck=ReadCards(in);
    for(int i=0;i<deck.size();++i){
        deck[i].drawn=false;
    }
    Hand handC,handP;
    CreatInHands(handP,handC,deck);
    announceHand(handP);
    cout<<"Redraw? (y or n) "<<endl;
    char ans;
    cin>>ans;
    if(ans=='y'){redraw(ans,handP,handC,deck);}
    return 0;
}
