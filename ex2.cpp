#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual double Area() = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
    double a, b;
public:
    Rectangle(double a, double b) {
        this->a = a;
        this->b = b;
    }

    double Area() override {
        return a * b;
    }
};

class Circle : public Figure {
    double r;
public:
    Circle(double r) {
        this->r = r;
    }

    double Area() override {
        return M_PI * r * r;
    }
};

class RightTriangle : public Figure {
    double a, b;
public:
    RightTriangle(double a, double b) {
        this->a = a;
        this->b = b;
    }

    double Area() override {
        return a * b / 2.0;
    }
};

class Trapezoid : public Figure {
    double a, b, h;
public:
    Trapezoid(double a, double b, double h) {
        this->a = a;
        this->b = b;
        this->h = h;
    }

    double Area() override {
        return (a + b) * h / 2.0;
    }
};

int main() {
    Figure* figures[4];

    figures[0] = new Rectangle(5, 4);
    figures[1] = new Circle(3);
    figures[2] = new RightTriangle(6, 8);
    figures[3] = new Trapezoid(5, 9, 4);

    for (int i = 0; i < 4; i++) {
        cout << "Ploshcha figury " << i + 1 << " = "
             << figures[i]->Area() << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete figures[i];
    }

    return 0;
}