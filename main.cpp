/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tobias Fischer
 *
 * Created on October 9, 2018, 9:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <pthread.h>

#include "SingleThreadPrimeCalculator.h"
#include "MultiThreadPrimeCalculator.h"

#define MULTI_THREAD    false
#define FILE_OUT        true
#define FILE_NAME       "out.txt"

#define THREAD_COUNT        10
#define AMOUNT_PER_THREAD   1000000
#define STARTING_AMNT       1000000

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout << SingleThreadPrimeCalculator::calculateBruteForce(10000, FILE_OUT).size() << endl;
    
}

