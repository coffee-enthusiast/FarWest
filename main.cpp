#include <iostream>
#include <cstdlib>
#include <time.h>  
#include <fstream>
#include <chrono>
#include <string>

//  Built-in headers
#include "GameEngine.h"
#include "IOFunctions.h"
#include "Trace.h"

//  Global tracing boolean
bool isTracingActive;


int main(int argc, char* argv[])
{
    //  Activate tracing
    if (argc > 1 && std::string(argv[1]) == "-trace") 
    {
        isTracingActive = true;
        InitTracing();
    }
    else
    {
        isTracingActive = false;
    }
    GameEngine ge = GameEngine();
    return 0;
}