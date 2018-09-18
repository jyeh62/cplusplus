//
//  main.cpp
//  Go
//
//  Created by Jaeyoung Choi on 2018. 9. 18..
//  Copyright © 2018년 Jaeyoung Choi. All rights reserved.
//

#include <iostream>
#include <memory>
using namespace std;

class Person {
private:
    string name_;
    int age_;
public:
    Person(const string& name, int age);
    Person(){
        cout << "Call contructor empty" << endl;
    };
    ~Person() {
        cout<< "Call Destructor name : " << name_ << endl;
    }
    void showPersonInfo();
    void setAge(int age) {
        age_ = age;
    }
    int getAge() {
        return age_;
    }
};

extern void classTest();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Person *p = new Person("Choi", 20);
    unique_ptr<Person> pPtr = make_unique<Person>("Jung", 20);
    
    auto aPtr = std::make_unique<Person>("Choiii", 10);
    auto aPtr2 = std::move(aPtr);
    
    unique_ptr<Person> pPtr2(p);
    pPtr->showPersonInfo();
    p->showPersonInfo();
    aPtr2->showPersonInfo();
    
    unique_ptr<Person[]> persons = make_unique<Person[]>(3);
        cout<<"array init---"<<endl;
    persons[0] = Person("Choi1", 1);
    persons[1] = Person("Choi2", 2);
    persons[2] = Person("Choi3", 3);

    cout<<"end---"<<endl;
    
    
    shared_ptr<Person>sPtr = make_shared<Person>("1Choi", 10);
    auto sPtr2 = sPtr;
    auto sPtr3(sPtr);
    sPtr->setAge(11);
    sPtr2->setAge(22);
    sPtr3->setAge(33);
    
    sPtr->showPersonInfo();
    sPtr2->showPersonInfo();
    sPtr3->showPersonInfo();
    
    
    cout<< "sPtr: " << sPtr.use_count() << endl;
    
    shared_ptr<Person> ssPtr = make_shared<Person>("2Choi", 22);
    weak_ptr<Person> wPtr = ssPtr;
    {
        cout << "weak ptr : " << wPtr.use_count() << endl;
        
    }
    ssPtr.reset();
    
    auto dataFromCache = wPtr.lock();
    if (dataFromCache)
    {
        cout << "dataFromCache ptr : " << dataFromCache.use_count() << endl;
    }
    
    if (wPtr.expired()) {
        cout << " wPtr expired" << endl;
    }
    
    classTest();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    int a = 5;
    int &b = a;
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}

Person :: Person(const string& name, int age) {
    name_ = name;
    age_ = age;
    cout << "Call contructor name = " << name << endl;
}

void Person :: showPersonInfo() {
    cout << "Name : " << name_ << ", age : " << age_ << endl;
}
