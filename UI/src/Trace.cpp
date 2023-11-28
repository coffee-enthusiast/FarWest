#include "Trace.h"

#include <fstream>
#include <filesystem>
#include <iostream>

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void InitTracing()
{
    std::filesystem::path cwd = std::filesystem::current_path();
    std::cout << cwd.string() <<std::endl;
    // Open the file in truncate mode to delete existing content
    std::ofstream file(TRACES_FILENAME, std::ios::out | std::ios::trunc);

    if (file.is_open()) {
        // File is opened in truncate mode, existing content is deleted
        file << "=====FAR WEST TRACING=====" << std::endl;

        // Perform operations with the file as needed

        file.close();
    } else {
        std::cout << "Unable to open file for truncation!" << std::endl;
    }
}

void fTrace(std::string msg)
{
    if(!isTracingActive)
    {
        return;
    }

    std::filesystem::path p(__FILE__);
    std::ofstream outfile;
    outfile.open(TRACES_FILENAME, std::ios::out | std::ios::app );
    //  Unable to open file for tracing
    if(!outfile.is_open())
    {
        return;
    }
    outfile << currentDateTime() << " ["  << p.filename() << "] > " << msg << std::endl;
    outfile.close();
}