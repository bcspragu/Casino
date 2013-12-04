/*
 * Game.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Eli
 */

#include "Game.h"

#include <iostream>

#include "Bet.h"
#include "ComputerPlayer.h"
#include "Dealer.h"
#include "Hand.h"
#include "HumanPlayer.h"
#include "PlayerList.h"
#include "SmallDeck.h"

Game::Game() {
	state = -1;
	centerPot = 0;
	minBet = 20;
	numFolded = 0;
	winner = NULL;
	commCards = new SmallDeck();
	dealer = new Dealer();
	playerList = new PlayerList();
	currentPlayer = -1;
	userInputState = 0;
}

Game::~Game() {

}

bool Game::startGame() {
	if (gui.startGui()) {

		//dealer populates the deck
		dealer->makeDeck();

		//add players to the playerlist
		HumanPlayer * human = new HumanPlayer(0);
		playerList->addPlayer(human);	//one human player
		int i;
		for (i = 1; i < 9; i++) {
			ComputerPlayer * computer = new ComputerPlayer(i);
			playerList->addPlayer(computer);
		}
		return true;
	}
	return false;
}

bool Game::playRound() {

	Player * roundWinner;

	// update playerlist and gui
		minBet= 20*pow(2,floor(float(roundNum)/float(5)));
	centerPot=playerList->purge(minBet);
	cout << "PURGE COMPLETE"<<endl;
	numFolded = 0;
	if (playerList->getSize() > 1) {
		state = 0;
		gui.update(0);
		dealer->resetDeck();
		initialTurns();
		if (flop()) {
			playerList->next();
			roundWinner = playerList->getCurrentPlayer();
		} else if (turn()) {
			playerList->next();
			roundWinner = playerList->getCurrentPlayer();

		} else if (river()) {
			playerList->next();
			roundWinner = playerList->getCurrentPlayer();
		} else {
			Hand * winningHand = findBestHand();
			roundWinner = winningHand->getPlayer();
			delete winningHand;
		}
		roundWinner->takePot(centerPot);
		endRound();
	} else {
		winner = playerList->getCurrentPlayer();
		return false;
	}
	return true;
}

void Game::initialTurns() {

//make big and little
	cout<< "INITIAL TURNNTTTTTTTTT" << endl;
	big();
	little();
	givePlayerCards();
	initialBets();

}

void Game::givePlayerCards() {

	int i;
	for (i = 0; i < playerList->getSize() * 2; i++) {
		playerList->getCurrentPlayer()->giveCard(dealer->deal());
		gui.update(1);
		playerList->next();
	}
}

void Game::initialBets() {
	makeBets();
	int i;
	for(i=0; i<playerList->getSize()-2; i++){
	playerList->iterate();
	}

}

void Game::little() {

//Get current player and bet
	Player * current = playerList->getCurrentPlayer();
	currentPlayer = current->getNum();
	Bet bet = current->makeLittle(minBet);
	processBet(bet, current);
	playerList->next();

}

void Game::big() {
//Get current player and bet

	Player * current = playerList->getCurrentPlayer();
	current->print();
	currentPlayer = current->getNum();
	Bet bet = current->makeBig(minBet);
	bet.print();
	processBet(bet, current);
	playerList->next();
}

bool Game::flop() {
	minBet = 0;
	dealer->burn();
	commCards->add(dealer->deal());
	commCards->add(dealer->deal());
	commCards->add(dealer->deal());
	state = 1;
	return makeBets();
}

bool Game::turn() {
	minBet = 0;
	dealer->burn();
	commCards->add(dealer->deal());
	state = 2;
	return makeBets();
}

bool Game::river() {
	minBet = 0;
	dealer->burn();
	commCards->add(dealer->deal());
	state = 3;
	return makeBets();
}

bool Game::makeBets() {
	Bet bet;
	Player * start = playerList->getCurrentPlayer();
	Player * player;
	do {
		if (numFolded > (playerList->getSize())-2)
			return true;
		player = playerList->getCurrentPlayer();
		if (player->inRound()) {
			currentPlayer = player->getNum();
			bet = player->makeBet(*commCards, minBet);
			processBet(bet, player);
		}
		playerList->iterate();
	} while (playerList->getCurrentPlayer() != start);
	return false;
}

void Game::processBet(Bet bet, Player * p) {
	centerPot += bet.getAmount();
	if (bet.getAction() == -1) {
		dealer->discard(p->fold());
		numFolded++;
	}
	minBet = minBet<bet.getAmount() ? bet.getAmount() : minBet;
	currentBet = bet;
	gui.update(2);
	currentPlayer = -1;
	currentBet = Bet();
	gui.update(0);
}

void Game::endRound() {
	centerPot = 0;
	discardAll();
	gui.update(0);
	state = -1;
}

Hand* Game::findBestHand() {
	playerList->next();
	Player * start = playerList->getCurrentPlayer();
	Player * player = start;

//initialze best hand as first
	Hand * best = new Hand(start);
	SmallDeck d = *(start->getPocket());
	best->putInCards(d, *commCards);
	best->evaluateCards();
	playerList->next();
	cout << best->getType() << endl;
//loop through other hands to check if they are better
	while (playerList->getCurrentPlayer() != start) {
		player = playerList->getCurrentPlayer();
		Hand *temp = new Hand(player);
		SmallDeck d = *(player->getPocket());
		d.print();
		commCards->print();
		temp->putInCards(d, *commCards);
		temp->evaluateCards();
		if ((*best > *temp) != 1) {
			best = temp;
		} else
			delete temp;
		cout << best->getType() << endl;
		playerList->next();
	}
	return best;
}

void Game::discardAll() {
	int i;
	for (i = 0; i < playerList->getSize(); i++) {
		dealer->discard(playerList->getCurrentPlayer()->getPocket());
		playerList->next();
	}
	dealer->discard(commCards);
}

Player * Game::getWinner() {
	return winner;
}

int Game::getButNum(){
	return playerList->getButton()->getNum();
}

void Game::endGame() {
	int i;
	for (i = 0; i < playerList->getSize() - 1; i++) {
		dealer->discard(playerList->getCurrentPlayer()->fold());
		playerList->next();
	}
	dealer->discard(commCards);
	dealer->deleteAll();
	playerList->removeAll();
}

