#include <iostream>
#include <vector>
#include <math.h>
#include <Windows.h>
using namespace std;

class Dot {
private:
    double x;
    double y;
public:
    Dot() {
        this->x = 0;
        this->y = 0;
    }
    Dot(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void enterDot() {
        cout << "Enter dot x: ";
        cin >> x;
        cout << "Enter dot y: ";
        cin >> y;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

};

class Figure {
private:
    vector<Dot> dots;
    int n;
public:
    Figure() {
        cout << "Please enter count of figure's sides: ";
        cin >> n;
    }

    Figure(int n) {
        this->n = n;
    }

    void appendDots() {
        for (int i = 0; i < n; i++) {
            Dot dot;
            dot.enterDot();
            dots.push_back(dot);
        }
    }

    double countLineLength(Dot d1, Dot d2) {
        return sqrt(pow(d1.getX() - d2.getX(), 2) + pow(d1.getY() - d2.getY(), 2));
    }

    double countP() {
        double p = 0;
        for (int i = 0; i < n - 1; i++) {
            p += this->countLineLength(dots[i], dots[i + 1]);
        }
        p += this->countLineLength(dots[0], dots[dots.size() - 1]);
        return p;
    }

    double countArea() {
        double area = 0.0;
        int j = n - 1;
        for (int i = 0; i < n; i++)
        {
            area += (dots[j].getX() + dots[i].getX()) * (dots[j].getY() - dots[i].getY());
            j = i;
        }
        return abs(area / 2.0);
    }


    double findAngle(Dot d1, Dot d2, Dot d3) {
        // a1x = x1 - x2, a2x = x3 - x1
        return ((d1.getX() - d2.getX()) * (d3.getX() - d2.getX()) + (d1.getY() - d2.getY()) * (d3.getY() - d2.getY())) / (this->countLineLength(d1, d2) * this->countLineLength(d2, d3));
    }

    double countSlope(Dot d1, Dot d2) {
        return (d2.getY() - d1.getY()) / (d2.getX() - d1.getX());
    }

    string checkType() {
        int type = 0;
        //1 - рівносторонній трикутник 
        //2 - прямокутний трикутник 
        //3 - рівнобедрений трикутник
        //4 - прямокутний рівнобедрений трикутник
        //5 - квадрат
        //6 - трапеція
        //7 - ромб
        //8 - паралелограм
        //9 - правильні пятикутник
        if (n == 3) {
            int a1 = countLineLength(dots[0], dots[1]), a2 = countLineLength(dots[1], dots[2]), a3 = countLineLength(dots[0], dots[2]);
            double angle1 = findAngle(dots[0], dots[1], dots[2]), angle2 = findAngle(dots[1], dots[2], dots[0]),
                angle3 = findAngle(dots[2], dots[0], dots[1]);
            if (a1 == a2 == a3) {
                type = 1;
            }
            else if (angle1 == 0 || angle2 == 0 || angle3 == 0) {
                if (a1 == a2 || a2 == a3 || a1 == a3) {
                    type = 4;
                }
                else {
                    type = 2;
                }
            }
            else if (a1 == a2 || a2 == a3 || a1 == a3) {
                type = 3;
            }

        }
        else if (n == 4) {
            int a1 = countLineLength(dots[0], dots[1]), a2 = countLineLength(dots[1], dots[2]),
                a3 = countLineLength(dots[2], dots[3]), a4 = countLineLength(dots[3], dots[0]);
            double angle1 = findAngle(dots[0], dots[1], dots[2]), angle2 = findAngle(dots[1], dots[2], dots[3]),
                angle3 = findAngle(dots[3], dots[0], dots[1]), angle4 = findAngle(dots[2], dots[3], dots[0]);
            double l1 = countSlope(dots[0], dots[1]), l2 = countSlope(dots[1], dots[2]),
                l3 = countSlope(dots[2], dots[3]), l4 = countSlope(dots[3], dots[0]);
            if (a1 == a2 && a2 == a3 && a3 == a4) {
                if (angle1 == 0 || angle2 == 0 || angle3 == 0 || angle4 == 0) {
                    type = 5;
                }
                else {
                    type = 7;
                }
            }
            else if (l1 == l3 && l2 == l4) {
                type = 8;
            }
            else if (l1 == l3 || l2 == l4) {
                type = 6;
            }
        }
        else if (n == 5) {
            int a1 = countLineLength(dots[0], dots[1]), a2 = countLineLength(dots[1], dots[2]),
                a3 = countLineLength(dots[2], dots[3]), a4 = countLineLength(dots[3], dots[4]), a5 = countLineLength(dots[4], dots[0]);
            double angle1 = findAngle(dots[0], dots[1], dots[2]), angle2 = findAngle(dots[1], dots[2], dots[3]),
                angle3 = findAngle(dots[2], dots[3], dots[4]), angle4 = findAngle(dots[3], dots[4], dots[0]),
                angle5 = findAngle(dots[4], dots[0], dots[1]);
            if (a1 == a2 && a2 == a3 && a3 == a4 && a4 == a5) {
                if (angle1 == -0.5 || angle2 == -0.5 || angle3 == -0.5 || angle4 == -0.5 || angle5 == -0.5) {
                    type = 9;
                }
            }
        }
        switch (type)
        {
        case 1:
            return "рівносторонній трикутник";
        case 2:
            return "прямокутний трикутник";
        case 3:
            return "рівнобедрений трикутник";
        case 4:
            return "прямокутний рівнобедрений трикутник";
        case 5:
            return "квадрат";
        case 6:
            return "трапеція";
        case 7:
            return "ромб";
        case 8:
            return "паралелограм";
        case 9:
            return "правильні пятикутник";
        case 0:
            return "щось інше";
        }
    }


    bool checkOPYK() {
        for (int i = 0; i < n; i++) {
            int j = i - 1, k = i + 1;
            if (i - 1 < 0) { j = n - 1; }
            if (i + 1 == n) { k = 0; }
            Dot ab =
            {
              dots[i].getX() - dots[j].getX(),
              dots[i].getY() - dots[j].getY()
            };
            Dot bc =
            {
              dots[k].getX() - dots[i].getX(),
              dots[k].getY() - dots[i].getY()
            };

            double product = ab.getX() * bc.getY() - ab.getY() * bc.getX();
            if (product < 0) { return false; }
        }
        return true;
    }

};


int main()
{
    SetConsoleOutputCP(1251);
    Figure f;
    f.appendDots();
    cout << f.countP() << endl;
    cout << f.countArea() << endl;
    if (f.checkOPYK() == true)
        cout << "OPYK" << endl;
    else
        cout << "NOT OPYK" << endl;
    cout << f.checkType() << endl;
}
