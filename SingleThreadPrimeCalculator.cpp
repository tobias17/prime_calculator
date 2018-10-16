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

using namespace std;

vector<int> SingleThreadPrimeCalculator::calculateBruteForce(int amntToCalculate, bool fileOut) {
    // create a vector to hold the primes
    vector<int> primes;
    
    // create a file for file output
    ofstream file;
    if (fileOut) {
        // try to open the file for file output
        file.open("out.txt");
        // check to see if file open properly
        if (!file.is_open()) {
            // if file was not opened, tell the user
            cout << "Error opening file" << endl;
            // and exit the program
            exit(-1);
        }
    }
    
    // loop through all possible prime candidates in our range
    for (int num = 2; num < amntToCalculate; num++) {
        // create a failed tag to see if any cases failed
        bool failed = false;
        // loop through all possible numbers from 2 to sqrt(num)
        for (int div = 2; div <= sqrt(num); div++) {
            // check to see if num can be divided into anything
            if (num % div == 0) {
                // if so set the failed flag
                failed = true;
                // break out of the for loop
                break;
            }
        }
        // check to see if the failed flag was not set
        if (!failed) {
            // add the prime to the prime storage vector
            primes.push_back(num);
            if (fileOut) {
                // feed the prime number to the file
                file << num << endl;
            }
        }
    }
    
    if (fileOut) {
        // check to see if file is still open
        if (file.is_open()) {
            // close the file
            file.close();
        } else {
            // if file was closed prematurely, tell the user
            cout << "Error closing file" << endl;
            // and exit the program
            exit(-1);
        }
    }
    
    // return back the prime storage vector
    return primes;
}

vector<int> SingleThreadPrimeCalculator::calculateVectorized(int amntToCalculate, bool fileOut) {
    // create a vector to hold the primes
    vector<int> primes;
    
    // create a file for file output
    ofstream file;
    if (fileOut) {
        // try to open the file for file output
        file.open("out.txt");
        // check to see if file open properly
        if (!file.is_open()) {
            // if file was not opened, tell the user
            cout << "Error opening file" << endl;
            // and exit the program
            exit(-1);
        }
    }
    
    // check to see if we are in range
    if (amntToCalculate >= 2) {
        // add 2 if in range to jump start the checking process
        primes.push_back(2);
    }
    // loop though all the numbers in our range
    for (int num = 3; num < amntToCalculate; num += 2) {
        // create a failed tag to see if any cases failed
        bool failed = false;
        // loop through all indexes of our vector up until the div <= sqrt(num)
        for (int divIndex = 0; primes.at(divIndex) <= sqrt(num); divIndex++) {
            // check to see if num can be divided into anything
            if (num % primes.at(divIndex) == 0) {
                // if so set the failed flag
                failed = true;
                // break out of the for loop
                break;
            }
        }
        // check to see if the failed flag was not set
        if (!failed) {
            // add the prime to the prime storage vector
            primes.push_back(num);
            if (fileOut) {
                // feed the prime number to the file
                file << num << endl;
            }
        }
    }
    
    if (fileOut) {
        // check to see if file is still open
        if (file.is_open()) {
            // close the file
            file.close();
        } else {
            // if file was closed prematurely, tell the user
            cout << "Error closing file" << endl;
            // and exit the program
            exit(-1);
        }
    }
    
    // return back the prime storage vector
    return primes;
}
