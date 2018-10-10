/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MultiThreadPrimeCalculator.h
 * Author: Tobias Fischer
 *
 * Created on October 10, 2018, 2:23 PM
 */

#ifndef MULTITHREADPRIMECALCULATOR_H
#define MULTITHREADPRIMECALCULATOR_H

class MultiThreadPrimeCalculator {
public:
    static int calculateBruteForce(int amntPerThread, int threadCount, bool fileOut);
    static int calculateVectorized(int amntPerThread, int threadCount, bool fileOut);
private:

};

#endif /* MULTITHREADPRIMECALCULATOR_H */

