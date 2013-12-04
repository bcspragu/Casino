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
#include "Deck.h"
#include "Gui.h"
#include "Hand.h"
#include "HumanPlayer.h"
#include "Player.h"
#include "PlayerList.h"
#include "SmallDeck.h"

Game::Game() {
	state = 0;
	centerPot = 0;
	minBet = 20;
	winner = NULL;
	commCards = new SmallDeck();
	dealer = new Dealer();
	playerList = new PlayerList();
}

Game::~Game() {

}

bool Game::startGame() {
	if (gui.startGui()) {

		state = 1;

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

void Game::playRound() {

	// update playerlist and gui
	playerList->purge(minBet);
	if (playerList->getSize() > 1) {
		gui.update();
		dealer->resetDeck();
		initialTurns();
		flop();
		////cout << "flop" << endl;
		turn();
		////cout << "turn" << endl;
		river();
		////cout << "river" << endl;
	} else {
		winner = playerList->getCurrentPlayer();
	}
	endRound();
}

void Game::initialTurns() {

	//make big and little
	big();
	playerList->next();
	little();
	playerList->next();

	givePlayerCards();
	initialBets();

}

void Game::givePlayerCards() {

	int i;
	for (i = 0; i < playerList->getSize() * 2; i++) {
		playerList->getCurrentPlayer()->giveCard(dealer->deal());
		playerList->next();
	}
	gui.update();
}

void Game::initialBets() {
	Bet bet;
	Player * player;
	do {
		player = playerList->getCurrentPlayer();
		bet = player->makeBet(*commCards, minBet);
		centerPot += bet.getAmount();
		gui.showTurn(player->getNum(), bet);
		gui.update();
		playerList->next();
	} while (playerList->getCurrentPlayer() != playerList->getButton());
	player = playerList->getCurrentPlayer();
	bet = player->makeBet(*commCards, minBet);
	centerPot += bet.getAmount();
	gui.showTurn(player->getNum(), bet);
	gui.update();
	playerList->next();
}

void Game::little() {
	////cout << "little" << endl;

	//Get current player and bet
	Player * current = playerList->getCurrentPlayer();
	Bet bet = current->makeLittle(minBet);

	//process bet
	centerPot += bet.getAmount();
	if (bet.getAction() == -1) {
		dealer->discard(current->fold());
	}
	gui.showTurn(current->getNum(), bet);
	////cout << "little" << endl;

}

void Game::big() {
	////cout << "Big" << endl;

//Get current player and bet
	Player * current = playerList->getCurrentPlayer();
	Bet bet = current->makeBig(minBet);

//process bet
	centerPot += bet.getAmount();
	if (bet.getAction() == -1) {
		dealer->discard(current->fold());
	}
	gui.showTurn(current->getNum(), bet);
}

void Game::flop() {
	dealer->burn();
	commCards->add(dealer->deal());
	commCards->add(dealer->deal());
	commCards->add(dealer->deal());
	gui.update();
	makeBets();
}

void Game::turn() {
	dealer->burn();
	commCards->add(dealer->deal());
	gui.update();

	makeBets();
}

void Game::river() {
	dealer->burn();
	commCards->add(dealer->deal());
	gui.update();
	makeBets();
}

void Game::makeBets() {
	Bet bet;
	Player * start = playerList->getCurrentPlayer();
	Player * player;
	do {
		player = playerList->getCurrentPlayer();
		bet = player->makeBet(*commCards, minBet);
		if (bet.getAction() == -1) {
			dealer->discard(player->fold());
		}
		centerPot += bet.getAmount();
		gui.showTurn(player->getNum(), bet);
		gui.update();
		playerList->next();
	} while (playerList->getCurrentPlayer() != start);
}

void Game::endRound() {

	Hand * winningHand = findBestHand();
	Player * winner = winningHand->getPlayer();
	winner->takePot(centerPot);
	delete winningHand;
	centerPot = 0;
	discardAll();
	gui.update();
}

Hand* Game::findBestHand() {
	Player * start = playerList->getCurrentPlayer();
	Player * player = start;

	//initialze best hand as first
	Hand * best = new Hand(start);
	SmallDeck d = *(start->getPocket());
	best->putInCards(d, *commCards);
	best->evaluateCards();
	playerList->next();

	//loop through other hands to check if they are better
	while (playerList->getCurrentPlayer() != start) {
		player = playerList->getCurrentPlayer();
		Hand *temp = new Hand(player);
		SmallDeck d = *(player->getPocket());
		temp->putInCards(d, *commCards);
		temp->evaluateCards();
		if ((*best > *temp) != 1) {
			best = temp;
		} else
			delete temp;
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

void Game::endGame() {
	int i;
	for (i = 0; i < playerList->getSize() - 1; i++) {
		dealer->discard(playerList->getCurrentPlayer()->fold());
		playerList->next();
	}
	////cout << "asdf" << endl;
	dealer->discard(commCards);
	dealer->deleteAll();
	////cout << "Cards deleted" << endl;
	playerList->removeAll();
	////cout << "Players deleted" << endl;
}

