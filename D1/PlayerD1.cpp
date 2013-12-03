#include <string>
#include "displayD1.h"
#include "CardD1.h"
#include "HandD1.h"
#include "PlayerD1.h"

using namespace std;

PlayerD1::PlayerD1(int displayPos, int initialMoney, string name) :
	displayPosition(displayPos),
	money(initialMoney),
	moneyInPot(0),
	hasFolded(false),
	playerName(name)
	{
}

PlayerD1::~PlayerD1() {

}

HandD1* PlayerD1::getHand() {
    return hand;
}

void PlayerD1::setHand(HandD1 *newHand) {
    hand = newHand;
}

int PlayerD1::getMoney() {
    return money;
}

int PlayerD1::getMoneyInPot() {
    return moneyInPot;
}

void PlayerD1::setMoneyInPot(int amount) {
    moneyInPot = amount;
}

int PlayerD1::giveMoney(int amount) {
    money += amount;
    return money;
}

void PlayerD1::setMoney(int amount) {
    money = amount;
}

void PlayerD1::setFrame(Frame* newFrame) {
    frame = newFrame;
}

Frame* PlayerD1::getFrame() {
    return frame;
}
bool PlayerD1::folded() {
    return hasFolded;
}

void PlayerD1::setFolded(bool fold) {
    hasFolded = fold;
}

void PlayerD1::setDisplayPosition(int position) {
    displayPosition = position;
}

int PlayerD1::getDisplayPosition() {
    return displayPosition;
}

int PlayerD1::ante(int anteAmount, displayD1 gameDisplay) {
    int ante = (money > anteAmount) ? anteAmount : money;
    money -= ante;
    moneyInPot += ante;
    return ante;
}

string PlayerD1::getName() {
	return playerName;
}
