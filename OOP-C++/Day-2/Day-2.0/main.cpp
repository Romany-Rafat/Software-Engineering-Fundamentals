#include <iostream>

using namespace std;

int area(int);
float area(float, int);
double area(float);
double area(float, float);

int main()
{
    cout << "Area of square: " << area(3) << endl;
    cout << "Area of rectangle: " << area((float)3, 3) << endl;  // استخدم 3.0f لتمرير float
    cout << "Area of circle: " << area(3.0f) << endl;
    cout << "Area of triangle: " << area(3.0f, 3.0f) << endl;

    return 0;
}

int area(int side)
{
    return side * side;
}

float area(float width, int height)
{
    return width * height;
}

double area(float radius)
{
    return radius * radius * 3.14159;
}

double area(float base, float height)
{
    return 0.5 * base * height;
}
