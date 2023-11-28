#pragma once
class IPlayer
{
public:

    virtual int     getPlayerAction()   = 0;
    virtual void    setPlayerAction(int action)   = 0;
    virtual bool    isPlayerAlive()     = 0;
    virtual void    setPlayerAlive(bool alive)     = 0;
    virtual void    printStats()        = 0;
    virtual void    simulateAction()    = 0;
    virtual void    goToSleep()         = 0;
    virtual int     getNumberOfGuns()   = 0;
    virtual void    addHealth(int healthAmount)         = 0;
    virtual int    getHealth()         = 0;
};