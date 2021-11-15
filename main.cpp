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
    string days;
    int duration;
    public:
        Lecture_Class() = default;
        Lecture_Class(int sn, string instr, int te, int ts, string d, int dr, string cc, string cn, string icn, string dept) : Course(cc, cn, icn, dept), section_number{sn}, Instructor{instr}, total_enrollment{te}, current_enrollment{0}, time_slot{ts}, days{d}, duration{dr} {}
        void Insert_Class();
        friend ostream& operator<< (ostream &out, Lecture_Class const& data){
            out << "Course Code->"<< data.course_code << "\nCourse Name->"<<data.course_name<<"\nIC Name->"<< data.IC_name <<"\nDept->"<<data.department_name;
            out << "\nSection no.->"<< data.section_number<<"\nInstructor Name->"<<data.Instructor<<"\nTotal Enrollment->"<<data.total_enrollment<<"\nCurrent Enrollment->"<<data.current_enrollment<<"\nTime Slot->"<<data.time_slot;
            return out;
        }
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
        friend ostream& operator<< (ostream &out, Student const& data) {
            out << data.name << "-->" << data.id;
            // and so on... 
            return out;
        }
};
int main(){
    vector<Lecture_Class> admin_classes;
    vector<Student> students;
    while(true){
        int choice;
        cout << "Input 1 for Admin, 0 for student, -1 to exit" << endl;
        cin >> choice;
        if(choice == 1){
            // Admin
            int x;
            cout << "Input Choice of task:\n" << "0: Add Student\n1: Add Classes\n2: Display Students\n3: Display Classes" << endl;
            cin >> x;
            switch (x) {
                case 0:{
                    string name, id;
                    cout << "Enter Student FirstName, SecondName and ID\n";
                    string temp;
                    cin >> name;
                    cin >> temp;
                    name += temp;
                    cin >> id;
                    Student s{name, id};
                    students.push_back(s);
                    break;
                }
                case 1:{
                    string cc,cn,icn,deptn,in,d;
                    cout << "Input Class Details in order(Course Code, Course Name, IC Name, Department Name, Intrsuctor Name, Days)"<<endl;
                    cin >> cc>>cn>>icn>>deptn>>in>>d;
                    cout << "Enter section number, total enrollment, time slot, duration" << endl;
                    int sn, te, ts, dur;
                    cin >> sn>>te>>ts>>dur;
                    Lecture_Class c{sn, in, te, ts, d, dur, cc, cn, icn, deptn};
                    admin_classes.push_back(c);
                    break;
                }
                case 2:
                    for(auto i : students){
                        cout << i << endl << "----------------------------" << endl;
                    }
                    break;
                case 3:
                    for(auto i : admin_classes){
                        cout << i << endl << "-----------------------------" << endl;
                    }
                    break;
                
                default:
                    cout << "Invalid Choice" << endl;
                    break;
            }
        }
        else if(choice == 0){
            // Student
        }
        else if(choice == -1){
            break;
        }
        else{
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}