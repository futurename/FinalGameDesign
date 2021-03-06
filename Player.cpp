#include "HelperFunctions/Game.h"
#include "Player.h"
#include <vector>

const vector<string> Player::DEFAULT_PLAYER_NAMES{vector<string>{"You", "Napoleon", "Trump", "Putin", "Modi"}};

Player::Player(int index, string name) {
    continentBonus = 0;
    playerIndex = index;
    if (name.empty()) {
        this->playerName = DEFAULT_PLAYER_NAMES.at(index);
    }
    cards = {};
}

string Player::getPlayerName() {
    return playerName;
}

void Player::addCard(CardType card) {
    cards.push_back(card);
}

void Player::addContinentBonus(int bonus) {
    continentBonus += bonus;
}

void Player::removeContinentBonus(int bonus) {
    continentBonus -= bonus;
}

void Player::setBgColor(tuple<int, int, int, int> color) {
    this->bgColour = color;
}

void Player::setTextColor(tuple<int, int, int, int> color) {
    this->textColour = color;
}

tuple<int, int, int, int> Player::getBgColor() {
    return bgColour;
}

tuple<int, int, int, int> Player::getTextColor() {
    return textColour;
}


int Player::getNumOfCapturedCountries() {
    return capturedCountries.size();
}

int Player::getPlayerIndex() const {
    return playerIndex;
}


int Player::getUndeployArmyNumber() const {
    return undeployArmyNumber;
}

void Player::setUndeployArmyNumber(int newUndeployArmyNumber) {
    undeployArmyNumber = newUndeployArmyNumber;
}

/*
 * check cards first: if player can / must exchange cards
   if can exchange: do multiplication.
   update undeployed army number of the player
*/
void Player::getCalUndeployArmyNumber() {
    int exchangeBonus = Card::exchangeCards(cards, exchangeTimes);
    exchangeTimes += exchangeBonus > 0 ? 1 : 0;
    int numOfCountries = Game::getPlayerCountries(playerIndex).size();
    int baseUndeployArmy =
            Game::DEFAULT_NUM_UNDEPLOY > numOfCountries / 3 ? Game::DEFAULT_NUM_UNDEPLOY : numOfCountries / 3;
    this->undeployArmyNumber = baseUndeployArmy + continentBonus + exchangeBonus;
}

void Player::removeUndeployArmy(int numOfArmy) {
    undeployArmyNumber -= numOfArmy;
}

int Player::getCardNumOfType(CardType type) {
    int result;
    for (CardType c: cards) {
        if (c == type) {
            result++;
        }
    }
    return result;
}

vector<Country> Player::getCapturedCountries(){
    return capturedCountries;
}

int Player::getContinentBonus(){
    return continentBonus;
}

int Player::getExchangeTimes(){
    return exchangeTimes;
}

vector<string> Player::getCapturedCountryNames() {
    vector <string> capturedCountryNames;

    for (size_t i = 0; i < capturedCountries.size(); i++) {
        capturedCountryNames.push_back(capturedCountries.at(i).getCountryName());
    }
    return capturedCountryNames;
}

void Player::setCapturedCountries(vector<Country>& newCapturedCountries){
    capturedCountries = newCapturedCountries;
}

void Player::setExchangeTimes(int newExchangeTimes){
    exchangeTimes = newExchangeTimes;
}

vector<CardType> &Player::getCards() {
    return this->cards;
}

void Player::setCards(vector<CardType>& cards) {
    this->cards = cards;
}
