#pragma once
#include "../../UF/include/EntitiesInterfaces.h"

#include <string>

extern int playerInput;

void prompt();
void InitUI();
void fInInt(int* storeInput);

void fOut(std::string message);
void fOutWarn(std::string message);
void fOutSucc(std::string message);

//  Dependency from CE component
void processInput(IPlayer* p);
