#include<iostream>
#include<algorithm>

using namespace std;

class Student{
public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // //shallow copy
    // Student(Student &obj){
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr;
    // }

    //deep copy
    Student(Student &obj){
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    ~Student(){
        cout << "Everything deleted from object" << endl;
        delete cgpaPtr;
        //name deleted just when this fucntion is called by compiler w/o even writing this
        //but for dyn. allocated cgpaPtr need to delete it
        //prevents memory leaks
    }
    
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main(){

    Student s1("ABCD", 9.6);
    Student s2(s1);

    s2.name = "XYZ";
    s1.getInfo();
    s2.getInfo();

    *s2.cgpaPtr = 9.75;
    s1.getInfo();
    s2.getInfo();

    return 0;
}