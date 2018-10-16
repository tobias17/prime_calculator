/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SingleThreadPrimeCalculator.h
 * Author: Tobias Fischer
 *
 * Created on October 10, 2018, 1:10 AM
 */

#ifndef SINGLE_THREAD_PRIME_CALCULATOR_H
#define SINGLE_THREAD_PRIME_CALCULATOR_H

#include <vector>

using namespace std;

class SingleThreadPrimeCalculator {
public:
    static vector<int> calculateBruteForce(int amntToCalculate, bool fileOut);
    static vector<int> calculateVectorized(int amntToCalculate, bool fileOut);
private:
};

#endif /* SINGLE_THREAD_PRIME_CALCULATOR_H */

