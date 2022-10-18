/*
 * File: recursion-problems.cpp
 * --------------
 * Evana Pradhan
 *
 * Assignment 3 - Recursion Problems
 *
 */

#include <iostream>
#include "tigr.h"
#include "util.h"

using namespace std;

// globals
const TPixel black = tigrRGB(0, 0, 0);
const TPixel white = tigrRGB(255, 255, 255);
Tigr *window;

// function prototypes
string removeVowels(string s);
bool isVowel(char c);
void drawRulerWrapper(double x, double y, double w, double h);
void drawRuler(double x, double y, double w, double h);

// testing functions
void testRemoveVowels() {
    cout << "Armadillo--> " << removeVowels("Armadillo") << endl;
    cout << "AEIOU--> " << removeVowels("AEIOU") << endl;
    cout << "Universty --> " << removeVowels("University") << endl;
    cout << "ntr wqsdfgh--> " << removeVowels("ntr wqsdfgh") << endl;
}

void testRuler() {
    drawRulerWrapper(0, 0, 800, 400);
}

int main() {
    string yn;
    yn = getLine("test disemvowel? ");
    if (yn == "y")
        testRemoveVowels();

    yn = getLine("test ruler? ");
    if (yn == "y")
        testRuler();
}

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string removeVowels(string s) {
    // Base Case
    if (s.empty()) {
        return s;
    } 
    // Recursive Cases
    else if (isVowel(s[0])) {
        return removeVowels(s.substr(1));
    }
    return s[0] + removeVowels(s.substr(1));
}


// Wrapper function; do not modify
void drawRulerWrapper(double x, double y, double w, double h) {
    window = tigrWindow(w + 10, h + 10, "Ruler", TIGR_AUTO);
    tigrClear(window, white);
    tigrUpdate(window);
    drawRuler(x, y, w, h);
    while (!tigrClosed(window)) {
        tigrUpdate(window);
    }
    tigrFree(window);
}

void drawRuler(double x, double y, double w, double h) {
    // Base Case
    if (w < 5)
        return;

    // Drawing the base line
    tigrLine(window, x, y + h, x + w, y + h, black);

    // Drawing the ruler line
    tigrLine(window, x + w/2, y, x + w/2, y + h, black);

    // Recursive Cases
    drawRuler(x, y + h/2, w/2, h/2);
    drawRuler(x + w/2, y + h/2, w/2, h/2);
}
