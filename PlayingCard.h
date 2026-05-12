#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <string>

enum class Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

struct PlayingCard
{
    Suit suit;
    int rank; // rank: 1-13 representing Ace to King
};

/** 
 * Create a PlayingCard from its string representation (e.g. "AS" for Ace of Spades)
 * @param cardString The string representation of the card
 * @return The corresponding PlayingCard object
 */
PlayingCard makeCard(const std::string &cardString);

/**
 * @brief Convert a PlayingCard to its string representation (e.g. "AS" for Ace of Spades)
 * 
 * @param card The PlayingCard object to convert
 * @return std::string The string representation of the card
 */
std::string to_string(const PlayingCard &card);

#endif
