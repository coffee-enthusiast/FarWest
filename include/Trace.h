#pragma once
#define TRACES_FILENAME "traces/traces.txt"


#include <string>

extern bool isTracingActive;

const std::string currentDateTime();

void InitTracing();

void fTrace(std::string msg);