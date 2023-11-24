#pragma once

#include "Player.h"
extern int playerInput;

void prompt();

int readInput();

void processInput(Player* p);
