#include "PlayingCard.h"

#include <map>

using namespace std;

const map<char, Suit> suitMap = {
    {'H', Suit::Hearts},
    {'D', Suit::Diamonds},
    {'C', Suit::Clubs},
    {'S', Suit::Spades}};

const map<string, int> rankMap = {
    {"A", 1},
    {"J", 11},
    {"Q", 12},
    {"K", 13}};

PlayingCard makeCard(const string &cardString)
{
  PlayingCard card;
  // Last character represents the suit
  char suitChar = cardString.back();

  card.suit = suitMap.at(suitChar);

  // The rest represents the rank
  string rankStr = cardString.substr(0, cardString.size() - 1);
  // Check for face cards and Ace
  if (rankMap.find(rankStr) != rankMap.end())
  {
    card.rank = rankMap.at(rankStr);
  }
  else
  {
    // Convert numeric rank directly
    card.rank = stoi(rankStr);
  }
  return card;
}

string to_string(const PlayingCard &card)
{
  string rankStr;
  switch (card.rank)
  {
  case 1:
    rankStr = "A";
    break;
  case 11:
    rankStr = "J";
    break;
  case 12:
    rankStr = "Q";
    break;
  case 13:
    rankStr = "K";
    break;
  default:
    rankStr = to_string(card.rank);
    break;
  }

  char suitChar;
  switch (card.suit)
  {
  case Suit::Hearts:
    suitChar = 'H';
    break;
  case Suit::Diamonds:
    suitChar = 'D';
    break;
  case Suit::Clubs:
    suitChar = 'C';
    break;
  case Suit::Spades:
    suitChar = 'S';
    break;
  }

  return rankStr + suitChar;
}
