#pragma once

inline int sleepHealth = 1;
inline int sleepStamina = 3;

inline int workHealth  = -1;
inline int workStamina = -2;
inline int workMoney   = 2;

inline int gunCost = 5;

enum PlayerAction
{
    WORK,
    DRINK,
    EAT,
    BUY_GUN,
    SLEEP,
    EXIT,
    ACCESS_INVENTORY
};