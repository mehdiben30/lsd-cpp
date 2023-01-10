#include <iostream>

using namespace std;

class Shape
{
protected :
    int width;
    int height;
public : 
    void construct(int wvalue, int hvalue) { 
        width=wvalue;
        height=hvalue;
    }
};

class Rectangle : public Shape
{
public : 
    float area()
    {
        return width*height;
    }
};

class Triangle : public Shape
{
public :
    float area()
    {
        return (width*height)/2;
    }
    
};

int main()
{
    Triangle T;
    Rectangle R;
    R.construct(5,2);
    int a=R.area();
    cout <<a;
}