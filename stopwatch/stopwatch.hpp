#pragma once
#include <chrono>
#include <thread>
#include <stdlib.h>

void stopwatch();
std::string formatted_time(
    std::chrono::time_point<std::chrono::system_clock> tp1=std::chrono::high_resolution_clock::now(), 
    std::chrono::time_point<std::chrono::system_clock> tp2={}
    );