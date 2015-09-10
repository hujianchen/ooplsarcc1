// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    
    int max_cycle = 1;
    int current_cycle = 1;
    if (i > j) 
    {
        int temp = j;
        j = i;
        i = temp;
    }
    for(int k=i; k<=j; ++k)
    {
        current_cycle = 1;
        int temp = k;
        while (temp != 1)
        {
          if ( (temp & 1) == 0)

            temp = temp >> 1;
          else 
            temp = temp * 3 + 1;
          current_cycle += 1;
        }
        max_cycle = max_cycle < current_cycle ? current_cycle : max_cycle;
        
    }
    return max_cycle;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
