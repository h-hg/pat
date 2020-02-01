#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
struct Stu {
    string name, id;
    int grade;
    Stu(const string &_name, const string &_id, int _grade):name(_name), id(_id), grade(_grade){}
    bool operator<(const Stu &rhs)const {
        return grade < rhs.grade;
    }
};
int main() {
    int n;
    cin >> n;
    vector<Stu> men, women;
    while(n--) {
        string name,id; 
        char gender;
        int grade;
        cin >> name >> gender >> id >> grade;
        (gender == 'M' ? men : women).push_back(Stu(name, id, grade));
    }

    if(men.empty()) {
        auto &woman = *max_element(women.begin(), women.end());
        cout << woman.name << ' ' << woman.id << endl << "Absent\nNA";
    } else if(women.empty()) {
        auto &man = *min_element(men.begin(), men.end());
        cout << "Absent\n" << man.name << ' ' << man.id << endl << "NA";
    } else {
        auto &woman = *max_element(women.begin(), women.end());
        auto &man = *min_element(men.begin(), men.end());
        cout << woman.name << ' ' << woman.id << endl
             << man.name << ' ' << man.id << endl
             << (woman.grade - man.grade);
    }
    return 0;
}*/

//optimize the space
int main() {
    int n;
    cin >> n;
    string female, male;
    int f_grade = -1, m_grade = 101;
    while(n--) {
        string name, id;
        char gender;
        int grade;
        cin >> name >> gender >> id >> grade;
        if(gender == 'F') {
            if( f_grade < grade) {
                f_grade = grade;
                female = name + " " + id;
            }
        } else if(m_grade > grade) {
            m_grade = grade;
            male = name + " " + id;
        }
    }

    cout << (f_grade != -1 ? female : "Absent") << endl
         << (m_grade != 101 ? male  : "Absent") << endl
         << ( (f_grade != -1 && m_grade != 101) ? to_string(f_grade - m_grade) : "NA");
    return 0;
}
