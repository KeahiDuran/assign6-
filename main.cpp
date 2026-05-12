#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> 
#include <map> 
#include <set> 
#include <string> 
#include <numeric> 
#include "PlayingCard.h"

using namespace std;

vector<PlayingCard> parseCards(const string &input)
{
  vector<PlayingCard> cards;
  stringstream ss(input);
  string cardStr;
  while (ss >> cardStr)
  {
    cards.push_back(makeCard(cardStr));
  }
  return cards;
}

int main()
{
  std::cout << "Enter a list of playing cards (e.g. AS 10H 3D JC): ";
  string input;
  getline(cin, input);
  vector<PlayingCard> cards = parseCards(input);



  cout << "Task 1: Print the Hearts" << endl; 

  for_each( 
    cards.begin(),
    cards.end(), 
    [](const PlayingCard& card) {
      if (card.suit == Suit::Hearts) { 
        cout << to_string(card) << " "; 
      }
    }
  );


  cout << endl << "Task 2: Count the Spades" << endl; 

  int spadeCount = count_if( 
    cards.begin(), 
    cards.end(), 
    [](const PlayingCard& card) { 
      return card.suit == Suit::Spades; 
    }
  );

  cout << spadeCount << endl;

  cout << "Task 3: Print the Total Value of Diamonds" << endl; 

  int diamondTotal = accumulate( 
    cards.begin(), 
    cards.end(), 
    0,
    [](int total, const PlayingCard& card) { 
      if (card.suit == Suit::Diamonds) { 
        return total + card.rank;
      }
      return total;
    }

  );

  cout << diamondTotal << endl; 

  cout << "Task 4: Print the cards in rank order" << endl; 

  vector<PlayingCard> rankSortedCards = cards; 

  sort( 
    rankSortedCards.begin(), 
    rankSortedCards.end(), 
    [](const PlayingCard& a, const PlayingCard& b) { 
      return a.rank < b.rank;
    }
  );

  for (const PlayingCard& card : rankSortedCards) { 
    cout << to_string(card) << " "; 
  }
  cout << endl << endl;


  cout << "Task 5: Print the cards in Suit Order" << endl; 

  vector<PlayingCard? suitSortedCards = cards; 

  sort(
    suit
  )
}





