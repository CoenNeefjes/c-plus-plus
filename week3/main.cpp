#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

mt19937 mersenne(static_cast<unsigned int>(time(nullptr)));
uniform_int_distribution<> generator(0,51);

enum Rank { two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, jack = 11, queen = 12, king = 13, ace = 14 };
enum Suit { club = 1, diamond = 2, heart = 3, spade = 4 };

struct Card {
    Rank rank;
    Suit suit;
};

void printCard(Card *card);
void printDeck(const vector<Card> *cardDeck);
void swapCards(Card *card1, Card *card2);
void shuffleDeck(vector<Card> *cardDeck_ptr);
int randomNumber();
int getCardValue(Card &card);
Card drawCard(vector<Card> &cardDeck);
void playBlackJack(vector<Card> &cardDeck);

int main() {

    vector<int> ranks(13);
    ranks.at(0) = Rank::two;
    ranks.at(1) = Rank::three;
    ranks.at(2) = Rank::four;
    ranks.at(3) = Rank::five;
    ranks.at(4) = Rank::six;
    ranks.at(5) = Rank::seven;
    ranks.at(6) = Rank::eight;
    ranks.at(7) = Rank::nine;
    ranks.at(8) = Rank::ten;
    ranks.at(9) = Rank::jack;
    ranks.at(10) = Rank::queen;
    ranks.at(11) = Rank::king;
    ranks.at(12) = Rank::ace;

    vector<int> suits(4);
    suits.at(0) = Suit::club;
    suits.at(1) = Suit::diamond;
    suits.at(2) = Suit::heart;
    suits.at(3) = Suit::spade;

    vector<Card> cardDeck(52);

    // Fill the deck with cards
    int counter = 0;
    for (int i = 0; i < suits.size(); i++) {
        for (int j = 0; j < ranks.size(); j++) {
            Card card;
            card.rank = (Rank) (j+2);
            card.suit = (Suit) (i+1);
            cardDeck.at(counter) = card;
            counter++;
        }
    }

    printDeck(&cardDeck);

    shuffleDeck(&cardDeck);
    printDeck(&cardDeck);

    playBlackJack(cardDeck);
    return 0;
}

void playBlackJack(vector<Card> &cardDeck) {
    int dealerValue = 0;
    int playerValue = 0;

    Card drawnCard = drawCard(cardDeck);
    dealerValue += getCardValue(drawnCard);

    for (int i = 0; i<2; i++) {
        drawnCard = drawCard(cardDeck);
        playerValue += getCardValue(drawnCard);
    }

    string input;
    while (input != "stand" && playerValue < 22) {
        cout << "dealerValue=" << dealerValue << " playervalue=" << playerValue << endl;
        cout << "Hit or stand" << endl;
        getline(cin, input);
        if (input == "hit") {
            drawnCard = drawCard(cardDeck);
            playerValue += getCardValue(drawnCard);
        }
    }
    if (playerValue > 21) {
        cout << "playerValue=" << playerValue << " so you deded" << endl;
    } else {
        while (dealerValue < 17) {
            drawnCard = drawCard(cardDeck);
            dealerValue += getCardValue(drawnCard);
        }
        cout << "dealerValue=" << dealerValue << " playervalue=" << playerValue << endl;
        if (dealerValue > 21) {
            cout << "The dealer is deded, you won" << endl;
        } else if (playerValue > dealerValue) {
            cout << "Player has won" << endl;
        } else {
            cout << "Dealer has won" << endl;
        }
    }
}

Card drawCard(vector<Card> &cardDeck) {
    Card c = cardDeck.back();
    cardDeck.pop_back();
    return c;
}

int getCardValue(Card &card) {
    int value = card.rank;
    if (value >= 10 && value < 14) {
        return 10;
    } else if (value == 14) {
        return 11;
    } else {
        return card.rank;
    }
}

void shuffleDeck(vector<Card> *cardDeck_ptr) {
    for (int i=0; i<cardDeck_ptr->size(); i++) {
        swapCards(&cardDeck_ptr->at(i), &cardDeck_ptr->at(randomNumber()));
    }
}

int randomNumber() {
    return generator(mersenne);
}

void swapCards(Card *card1, Card *card2) {
    Rank rank1 = card1->rank;
    Suit suit1 = card1->suit;

    card1->suit = card2->suit;
    card1->rank = card2->rank;
    card2->rank = rank1;
    card2->suit = suit1;
}

void printDeck(const vector<Card> *cardDeck_ptr) {
    vector<Card> cardDeck = *cardDeck_ptr;
    for (int i=0; i < cardDeck.size(); i++) {
        cout << i << ": ";
        printCard(&cardDeck.at(i));
    }
}

void printCard(Card *card) {
    string rank;
    switch (card->rank) {
        case 10:
            rank = "T";
            break;
        case 11:
            rank = "J";
            break;
        case 12:
            rank = "Q";
            break;
        case 13:
            rank = "K";
            break;
        case 14:
            rank = "A";
            break;
    }
    string suit;
    switch (card->suit) {
        case 1:
            suit = "C";
            break;
        case 2:
            suit = "D";
            break;
        case 3:
            suit = "H";
            break;
        case 4:
            suit = "S";
            break;
    }
    if (card->rank < 10) {
        cout << card->rank << suit << endl;
    } else {
        cout << rank << suit << endl;
    }
}
