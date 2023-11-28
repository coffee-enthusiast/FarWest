#pragma once
#include "../../UF/include/EntitiesInterfaces.h"

#include <string>

extern int playerInput;

void prompt();

int readInput();

void fOut(std::string message);
void fOutWarn(std::string message);

//  Dependency from CE component
void processInput(IPlayer* p);
