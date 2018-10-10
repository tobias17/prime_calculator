/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SingleThreadPrimeCalculator.cpp
 * Author: Tobias Fischer
 * 
 * Created on October 10, 2018, 1:10 AM
 */

#include "SingleThreadPrimeCalculator.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int SingleThreadPrimeCalculator::calculateBruteForce(int amntToCalculate, bool fileOut) {
    int cntr = 0;
    
    ofstream file("out.txt");
    if (fileOut) {
        if (!file.is_open()) {
            cout << "Error opening file" << endl;
            exit(-1);
        }
    }
    for (int num = 2; num < amntToCalculate; num++) {
        bool worked = true;
        for (int div = 2; div <= sqrt(num); div++) {
            if (num % div == 0) {
                worked = false;
                break;
            }
        }
        if (worked) {
            cntr++;
            if (fileOut) {
                file << num << endl;
            }
        }
    }
    if (fileOut) {
        if (file.is_open()) {
            file.close();
        } else {
            cout << "Error closing file" << endl;
            exit(-1);
        }
    }
    
    return cntr;
}

int SingleThreadPrimeCalculator::calculateVectorized(int amntToCalculate, bool fileOut) {
    ofstream file("out.txt");
    if (fileOut) {
        if (!file.is_open()) {
            cout << "Error opening file" << endl;
            exit(-1);
        }
    }
    vector<int> primes;
    if (amntToCalculate >= 2) {
        primes.push_back(2);
    }
    for (int num = 3; num < amntToCalculate; num += 2) {
        bool worked = true;
        for (int divIndex = 0; primes.at(divIndex) <= sqrt(num); divIndex++) {
            if (num % primes.at(divIndex) == 0) {
                worked = false;
                break;
            }
        }
        if (worked) {
            primes.push_back(num);
            if (fileOut) {
                file << num << endl;
            }
        }
    }
    if (fileOut) {
        if (file.is_open()) {
            file.close();
        } else {
            cout << "Error closing file" << endl;
            exit(-1);
        }
    }
    
    return primes.size();
}
