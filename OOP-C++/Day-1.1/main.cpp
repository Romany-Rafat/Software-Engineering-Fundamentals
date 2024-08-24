#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
    int real, img;

public:
    Complex(int real = 0, int img = 0)
    {
        this->real = real;
        this->img = img;
    }

    inline void SetReal(int real)
    {
        this->real = real;
    }

    inline void SetImg(int img)
    {
        this->img = img;
    }

    inline int GetReal()
    {
        return real;
    }

    inline int GetImg()
    {
        return img;
    }

    void print()
    {
        if (real == 0 && img == 0)
        {
            cout << "Expression complex is: 0" << endl;
        }
        else if (real == 0)
        {
            cout << "Expression complex is: " << img << "i" << endl;
        }
        else if (img == 0)
        {
            cout << "Expression complex is: " << real << endl;
        }
        else
        {
            cout << "Expression complex is: " << real;
            if (img > 0)
            {
                cout << "+" << img << "i" << endl;
            }
            else
            {
                cout << img << "i" << endl;
            }
        }
    }

    Complex sum(Complex c1)
    {
        Complex c3;
        c3.SetReal(real + c1.GetReal());
        c3.SetImg(img + c1.GetImg());
        return c3;
    }
};
Complex sub(Complex c1, Complex c2)
{
    Complex c3;
    c3.SetImg(c1.GetImg() - c2.GetImg());
    c3.SetReal(c1.GetReal() - c2.GetReal());
    return c3;
}
Complex multi (Complex c1, Complex c2)
{
    //. (a×c−b×d)+(a×d+b×c)i,a+bi ,c+di
    //. real*real +img*img ==>real
    //. real*img2 +real2*img1 ==>real
    Complex c3;
    c3.SetImg(c1.GetReal()*c2.GetImg()+c1.GetImg()*c2.GetReal());
    c3.SetReal(c1.GetReal()*c2.GetReal()-c1.GetImg()*c2.GetImg());
    return c3;
}
int main()
{
    Complex c1(-1,5), c2(3,-2);
    c1.print();
    c2.print();
    Complex c3=sub(c1,c2);
    c3.print();
    return 0;
}
