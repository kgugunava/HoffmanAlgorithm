#include <chrono>
#include <iostream>

#ifndef BENCHMARK_H
#define BENCHMARK_H

#define Logs "Logs.txt"

void startTests(const char** files, int size, const char * logs = Logs);


void startSpace(std::string fileName, std::string logs = Logs);

std::chrono::time_point<std::chrono::high_resolution_clock> startTime();

void duration(std::chrono::time_point<std::chrono::high_resolution_clock> start, const char * logs = Logs);



#endif //BENCHMARK_H
