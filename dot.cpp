#include <iostream>
#include <vector>
#include <math.h>
#include <Windows.h>
#include "Dot.h"
using namespace std;

Dot::Dot() {
    this->x = 0;
    this->y = 0;
}
Dot::Dot(double x, double y) {
    this->x = x;
    this->y = y;
}
void Dot::enterDot() {
    cout << "Enter dot x: ";
    cin >> x;
    cout << "Enter dot y: ";
    cin >> y;
}
double Dot::getX() {
    return x;
}
double Dot::getY() {
    return y;
}
