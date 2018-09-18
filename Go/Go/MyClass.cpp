//
//  MyClass.cpp
//  Go
//
//  Created by jaeyoung on 2018. 9. 18..
//  Copyright © 2018년 Jaeyoung Choi. All rights reserved.
//

#include <iostream>
using namespace std;

class Contained0 {
public:
    Contained0() {
        cout << "Contained 0 is call" << endl;
    }
};

class Contained1 {
public:
    Contained1() {
        cout << "Contained1 is call" << endl;
    }
private:
    Contained0 contained0;
};

class Contained2 {
public:
    Contained2() {
        cout << "Contained2 is call" << endl;
    }
    
};

class Contained3 {
public:
    Contained3() {
        cout << "Contained3 is call" << endl;
    }
};

class BaseContainer {
public:
    BaseContainer() {
        cout << "BaseContainer is call" << endl;
    }
private:
    Contained1 contained1;
    Contained2 contained2;
};

class DerivedContainer : public BaseContainer {
public:
    DerivedContainer() : BaseContainer() {
        cout << "DerivedContainer is call" << endl;
    }
private:
    Contained3 container;
};



class Box {
public:
    Box(int width, int length, int height)
    : m_width(width), m_length(length), m_height(height) // member init list
    {}
    Box(int size) : m_width(size), m_length(size), m_height(size) {}
    Box(const Box& b) : m_width(b.m_width), m_height(b.m_height), m_length(b.m_length){
        cout << "deep copy contructor" << endl;
    }
    int volume() {return m_width * m_length * m_height; }
private:
    int m_width;
    int m_length;
    int m_height;
    
};

Box func (Box& b) {
    cout << "call func b = "<< b.volume() <<endl;
    return b;
}
void classTest() {
    DerivedContainer d;
    Box b = 10;
    cout << "box volume = " << b.volume() << endl;
    Box a = Box(1,2,3);
    Box bb = a;
    cout << endl;
    func(bb);
//    Box bArrayb[3] = {{1,2,3}, {2,3,4}, {3,4,5}};
//    for (Box b : bArrayb) {
//        cout << "box in array = " <<b.volume() << endl;
//    }
}

class Point
{
public:
    Point &operator=(const Point & );  // Right side is the argument.
    int _x, _y;
};




Point &Point::operator=( Point const  &ptRHS )
{
    _x = ptRHS._x;
    _y = ptRHS._y;
    
    return *this;  // Assignment operator returns left side.
}


