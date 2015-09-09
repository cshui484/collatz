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
	int max_cl = 1;
	int n, cl, tmp;
	int max_ix;

	if (i > j) {
		tmp = j;
		j = i;
		i = tmp;
	}
	for (int ix=i; ix<=j; ix++) {
		n = ix;
		cl = 1;
		while (n != 1) {
			if (n % 2 == 0) {
				n /= 2;
			} else {
				n = 3*n + 1;
			}
			cl++;
			
//printf("%d %d %d\n", ix, n, cl);			
		}
		if (cl > max_cl) {
			max_cl = cl;  
			max_ix = ix;
		}
	}
//	printf ("return %d %d\n", max_ix, max_cl);
	return max_cl;
}

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
