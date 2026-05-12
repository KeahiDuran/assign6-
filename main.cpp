#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> 
#include <map> 
#include <set> 
#include <string> 
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
    cards.begin()
  )


}




