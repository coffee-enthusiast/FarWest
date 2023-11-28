#pragma once
#include "../../UF/include/EntitiesInterfaces.h"

extern int playerInput;

void prompt();

int readInput();

//  Dependency from CE component
void processInput(IPlayer* p);
