#pragma once
#include <iostream>
#include <array>
#include <vector>
#include "die.h"
#include "player.h"


class Table {

    // Checking for !cin and end of line for string
    void ClearInput();
    int GetInput();
	//VOID FUNCTIONS FOR CLEAN MESSAGES
    void Congratulate(Player& player);
    void FinalRound(Player& player);
    void ShowKeptDice(array<int, 6>& keptDice);
    void ShowRolls(vector<int>& dicePool);
    void WelcomePlayers(vector<Player>& players);
    // SETS UP PLAYERS AND PROMPTS GAME
	void PromptNumPlayers();
    void SetupPlayerNames(vector<Player>& players);
	//STARTS THE DIE AND KEEPS SCORE AND BOOL FOR WINNER
    array<int, 6> CountDice(vector<int>& dicePool);
    bool CheckFor5k(int score);
    bool IsValid(unsigned int& selection, vector<int>& dicePool);
    bool ScoringDice(array<int, 6>& diceCount);
    int ScoreDice(vector<int>& dicePool, int die, array<int, 6>& diceCount, array<int, 6>& keptDice);
    void RollDice(vector<int>& dicePool);
    Player GetWinner(vector<Player> players);
    int Turn(Player& player);
    Player Play();

public:
    void GameLoop();
};
