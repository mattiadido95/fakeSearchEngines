//
// Created by MATTIA on 10/11/2022.
//

#ifndef BACKEND_AVAILABLEMEMORY_H
#define BACKEND_AVAILABLEMEMORY_H

#include <unistd.h>

unsigned long long getTotalSystemMemory();

int parseLine(char *line);

int getValue();

#endif //BACKEND_AVAILABLEMEMORY_H
