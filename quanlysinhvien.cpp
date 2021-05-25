#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Information {
    string name;
    string classes;
    string phone_number;
    string id;
    int age;
    int sex;
    Information() {}
    Information(const string& _name
                ,const string& _classes
                ,const string& _phone_number
                ,const string& _id
                ,const int& _age
                ,const int& _sex) : name(_name)
                                    ,classes(_classes) 
                                    ,phone_number(_phone_number)
                                    ,id(_id), age(_age)
                                    ,sex(_sex) {}
} Student;
bool compareStruct(Student* a, Student* b) {
        if ((a->name).compare(b->name) > 0) {
            return 0;
        } else {
            return 1;
        }
    }


class Classes {
public:
    Classes(int n, string _name) {
        this->size = 0;
        this->name = _name;
        students = new Student[n];
        pt = new Student*[n];
    }
    void printListStudent() {
        for (int i = 0; i < size; ++i) {
            cout << students[i].name         << " " 
                 << students[i].age          << " "
                 << students[i].phone_number << " "
                 << students[i].sex          << endl;
        }
        cout << endl;
    }
    void addStudent(const Student& student) {
        students[size] = student; 
        pt[size] = students + size;
        size++;
    }
    void Soft() {
        sort(pt, pt + size,compareStruct);
    }
    void printSortListStudent() {
        for (int i = 0; i < size; ++i) {
            cout << pt[i]->name         << " " 
                 << pt[i]->age          << " "
                 << pt[i]->phone_number << " "
                 << pt[i]->sex          << endl;
        }
    }
    ~Classes() {
        delete []students;
        delete []pt;
    }
private:
    Student* students;
    Student** pt;
    string name;
    int size;
    };

void ignoreLine()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Student InputStudent() {
     Student student;
     cout << "Enter student's name : ";
     ignoreLine();
     getline(cin,student.name);
     cout << "Enter student' age: ";
     cin >> student.age;

     cout << "Enter student's sex : ";
     cin >> student.sex;


     cout << "Enter student's phone_number : ";
     ignoreLine();
     cin.clear();
     getline(cin,student.phone_number);

     cout << "Enter student's id : ";
     ignoreLine();
     cin.clear();
     getline(cin,student.id);
     return student;
}

int main() {
    Classes ktlt(200, "KTLT");
    cout << "............................Welcome to Manage Service............................\n";
    cout << "Class : KTLT\n";
    int service;
    do {
        cout << "Chose your service: (1) addNewStudent ||  (2) printSortListStudent || (3) printListStudent() || (4) clearScreen\n";
        cin >> service;
        while(1) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<< "Chose your service: (1) addNewStudent ||  (2) printSortListStudent || (3) printListStudent() || (4) clearScreen --- again!!" <<endl;
                cin >> service;
            }
        if(!cin.fail())
            break;
        }
        switch (service) {
            case 1:
                {
                    cout << "Enter number of students want to add: ";
                    int k;
                    cin >> k;
                    while(1) {
                        if(cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout<< "Enter amount of students again: " <<endl;
                            cin >> k;
                        }
                        if(!cin.fail())
                            break;
                    }
                    for (int i = 0; i < k; ++i) {
                        ktlt.addStudent(InputStudent());
                    }             
                    break;
                }
            case 2:
                {
                    ktlt.Soft();
                    ktlt.printSortListStudent();
                    break;
                }
            case 3:
                {
                    ktlt.printListStudent();
                    break;
                }
            case 4:
                {
                    system("clear");
                    break;
                }
            default:
                cout << "Wrong syntax. Please choose again\n";
        }
    } while(1);
}
