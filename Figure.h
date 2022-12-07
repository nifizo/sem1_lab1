#pragma once
class Figure {
private:
    vector<Dot> dots;
    int n;
public:
    Figure() {}
    Figure(int n) {}
    void appendDots() {}
    double countLineLength(Dot d1, Dot d2) {}
    double countP() {}
    double countArea() {}
    double findAngle(Dot d1, Dot d2, Dot d3) {}
    double countSlope(Dot d1, Dot d2) {}
    string checkType() {}
    bool checkOPYK() {}
};
