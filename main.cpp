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

int getSuitOrder(Suit suit) { 
  if (suit == Suit::Clubs) { 
    return 0; 
  }
  if (suit == Suit::Diamonds) {
    return 1; 
  }
  if (suit == Suit::Hearts) { 
    return 2; 
  }
  return 3;
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
  cout << endl;


  cout << "Task 5: Print the cards in Suit Order" << endl; 

  vector<PlayingCard> suitSortedCards = cards; 

  sort(
    suitSortedCards.begin(), 
    suitSortedCards.end(), 
    [](const PlayingCard& a, const PlayingCard& b) { 
      return getSuitOrder(a.suit) < getSuitOrder(b.suit);
    }
  );


  for (const PlayingCard& card : suitSortedCards) { 
    cout << to_string(card) << " ";
  }

  cout << endl; 


  cout << "Task 6: Print the Unique Ranks" << endl; 
  set<int> uniqueRanks; 

  transform( 
    cards.begin(),
    cards.end(), 
    inserter(uniqueRanks, uniqueRanks.begin()), 
    [](const PlayingCard& card) { 
      return card.rank;
    }
  );

  for (int rank : uniqueRanks) { 
    cout << to_string(rank) << " "; 
  }

  cout << endl; 

  cout << "Task 7: Print the counts of each rank" << endl; 

  map<int, int> rankCounts; 

  for_each(
    cards.begin(),
    cards.end(),
    [&rankCounts](const PlayingCard& card) { 
      rankCounts[card.rank]++;
    }
  );

  

}





