/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MultiThreadPrimeCalculator.cpp
 * Author: Tobias Fischer
 * 
 * Created on October 10, 2018, 2:23 PM
 */

#include "MultiThreadPrimeCalculator.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <thread>

using namespace std;

void thread_calculateBruteForce(int amntPerThread, int depth, bool fileOut) {
    if (depth <= 0) {
        cout << "hit bottom" << endl;
        return;
    }
    
    cout << "start: " << depth << endl;
    
    thread child(thread_calculateBruteForce, amntPerThread, depth-1, fileOut);
    
    // do stuff
    vector<int> primes;
    int startPoint = amntPerThread * (depth - 1);
    if (startPoint < 2) startPoint = 2;
    int endPoint = amntPerThread * (depth);
    for (int num = startPoint; num < endPoint; num++) {
        bool worked = true;
        for (int div = 2; div <= sqrt(num); div++) {
            if (num % div == 0) {
                worked = false;
                break;
            }
        }
        if (worked) {
            primes.push_back(num);
        }
    }
    
    child.join();
    
    // do other stuff
    if (fileOut) {
        ofstream file("out.txt", fstream::app);
        if (file.is_open()) {
            for (int i = 0; i < primes.size(); i++) {
                file << primes.at(i) << endl;
            }
            file.close();
        } else {
            cout << "Error opening file" << endl;
            exit(-1);
        }
    }
    
    cout << "end: " << depth << endl;
}

int MultiThreadPrimeCalculator::calculateBruteForce(int amntPerThread, int threadCount, bool fileOut) {
    ofstream file("out.txt");
    if (file.is_open()) {
        file << "Multi Threaded Brute Force - threads: " << threadCount << ", amntPerThread: " << amntPerThread << endl;;
        file.close();
    } else {
        cout << "Error opening file" << endl;
        exit(-1);
    }
    
    thread_calculateBruteForce(amntPerThread, threadCount, fileOut);
    return 1;
}



void thread_calculateVectorized(vector<int> origPrimes, int amntPerThread, int depth, bool fileOut) {
    if (depth <= 0) {
        cout << "hit bottom" << endl;
        return;
    }
    
    cout << "start: " << depth << endl;
    
    thread child(thread_calculateBruteForce, amntPerThread, depth-1, fileOut);
    
    // do stuff
    vector<int> primes;
    int startPoint = amntPerThread * (depth - 1);
    if (startPoint < 2) startPoint = 2;
    int endPoint = amntPerThread * (depth);
    for (int num = startPoint; num < endPoint; num++) {
        bool worked = true;
        for (int divIndex = 0; origPrimes.at(divIndex) <= sqrt(num); divIndex++) {
            if (num % origPrimes.at(divIndex) == 0) {
                worked = false;
                break;
            }
        }
        if (worked) {
            primes.push_back(num);
        }
    }
    
    child.join();
    
    // do other stuff
    if (fileOut) {
        ofstream file("out.txt", fstream::app);
        if (file.is_open()) {
            for (int i = 0; i < primes.size(); i++) {
                file << primes.at(i) << endl;
            }
            file.close();
        } else {
            cout << "Error opening file" << endl;
            exit(-1);
        }
    }
    
    cout << "end: " << depth << endl;
}

int MultiThreadPrimeCalculator::calculateVectorized(int amntPerThread, int threadCount, bool fileOut) {
    
    vector<int> origPrimes;
    origPrimes.push_back(2);
    bool wentOver = false;
    for (int num = 3; num <= sqrt(amntPerThread * threadCount) || !wentOver; num += 2) {
        bool worked = true;
        for (int divIndex = 0; origPrimes.at(divIndex) <= sqrt(num); divIndex++) {
            if (num % origPrimes.at(divIndex) == 0) {
                worked = false;
                break;
            }
        }
        if (worked) {
            origPrimes.push_back(num);
            if (num > sqrt(amntPerThread * threadCount)) {
                wentOver = true;
            }
        }
    }
    
    ofstream file("out.txt");
    if (file.is_open()) {
        file << "Multi Threaded Vectorized - threads: " << threadCount << ", amntPerThread: " << amntPerThread << endl;;
        file.close();
    } else {
        cout << "Error opening file" << endl;
        exit(-1);
    }
    
    thread_calculateVectorized(origPrimes, amntPerThread, threadCount, fileOut);
    return 1;
}
