#include "deck.h"
#include <algorithm>
Deck::Deck() {
	Generate();
}

void Deck::Generate() {
	vector<Card> generated_deck; // ~ A temp vector to set the deck to
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"}; // ~ Suits of the cards
    vector<string> word_faces = {"Ace", "Jack", "Queen", "King"}; // ~ Cards that aren't referenced by numerical value
    for (int i = 0; i < 4; i++) { // ~ For every suit...
        for (int j = 0; j < 13; j++) { // ~ For every value...
            if (!j) generated_deck.emplace_back(suits.at(i), word_faces.at(i), j + 1); // ~ Construct Ace
            else if (j > 9) generated_deck.emplace_back(suits.at(i), word_faces.at(j - 9), 10); // ~ Construct Jack -> King
            else generated_deck.emplace_back(suits.at(i), to_string(j + 1), j + 1); // ~ Construct 1 -> 10
        }
    }
    class_deck = generated_deck; // ~ Set temp to deck
}

void Deck::Shuffle() {
	if (!class_deck.size()) Generate(); // ~ If no cards in the deck, regenerate the deck
	random_shuffle(class_deck.begin(), class_deck.end()); // ~ Shuffle the deck
}

Card Deck::Deal() {
	if (!class_deck.size()) Shuffle(); // ~ If no cards in the deck, shuffle (Which leads to regenerating and shuffling)
    Card temp = class_deck.at(0);
    class_deck.erase(class_deck.begin()); // ~ Erase top card of the deck
    return temp;
}
