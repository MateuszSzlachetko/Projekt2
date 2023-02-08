#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <random>
#include <iomanip>
#include <bits/stdc++.h>

enum Print
{
    No_print,
    Print_on_screen,
    Print_to_file
};

int Random_int(int lower_bound, int upper_bound);

#endif // FUNCTIONS_H