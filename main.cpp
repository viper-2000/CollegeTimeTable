#include <bits/stdc++.h>
using namespace std;

class Course {
    protected:
        string course_code;
        string course_name;
        string IC_name;
        string department_name;
    public:
        // Course() = default;
        Course(string course, string coursen, string icn, string dept) : course_code{course}, course_name{coursen}, IC_name{icn}, department_name{dept}{};
};

class Lecture_Class : protected Course{
    int section_number;
    string Instructor;
    int total_enrollment;
    int current_enrollment;
    int time_slot;
    vector<string> days;
    int duration;
    public:
        Lecture_Class() = default;
        Lecture_Class(int sn, string instr, int te, int ts, vector<string> d, int dr, string cc, string cn, string icn, string dept) : Course(cc, cn, icn, dept), section_number{sn}, Instructor{instr}, total_enrollment{te}, current_enrollment{0}, time_slot{ts}, days{d}, duration{dr} {}
};

class Student {
    string name;
    string id;
    vector<Lecture_Class> class_taken;
    public:
        Student() = default;
        Student(string nm, string i) : name{nm}, id{i} {};
        bool Add_Class(){

        }
        bool delete_Class(){

        }
        bool verify_TimeTable(){

        }
        bool register_Class(){

        }
};
int main(){
    return 0;
}