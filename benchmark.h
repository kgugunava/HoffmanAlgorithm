#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#ifndef BENCHMARK_H
#define BENCHMARK_H

#define Logs "Logs.txt"

void startTests(std::string files[5], int size, std::string logs);

int findAverageTimeForTXT(std::string files[5], int size, std::string logsFileName);

void startSpace(std::string fileName, std::string logs);

std::chrono::time_point<std::chrono::high_resolution_clock> startTime();

void duration(std::chrono::time_point<std::chrono::high_resolution_clock> start, std::string logs, std::string file);



#endif //BENCHMARK_H
