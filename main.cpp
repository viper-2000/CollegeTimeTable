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
        string getCourseCode(){
            return this->course_code;
        }
};

class Lecture_Class : public Course{
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
        string getCourseCode(){
            return course_code;
        }
        int getCurrentEnrollment(){
            return current_enrollment;
        }
        bool updateEnrollment(int val){
            if(current_enrollment + val <= total_enrollment){
                current_enrollment -= val;
                return true;
            }
            else{
                return false;
            }
        }
        bool isAvailable(){
            return (current_enrollment < total_enrollment);
        }
        int totalEnrollment(){
            return total_enrollment;
        }
        int getSectionNumber(){
            return section_number;
        }
        friend ostream& operator<< (ostream &out, Lecture_Class const& data){
            out << "Course Code->"<< data.course_code << "\nCourse Name->"<<data.course_name<<"\nIC Name->"<< data.IC_name <<"\nDept->"<<data.department_name;
            out << "\nSection no.->"<< data.section_number<<"\nInstructor Name->"<<data.Instructor<<"\nTotal Enrollment->"<<data.total_enrollment<<"\nCurrent Enrollment->"<<data.current_enrollment<<"\nTime Slot->"<<data.time_slot;
            return out;
        }
};

class Student {
    string name;
    string id;
    deque<Lecture_Class> class_taken;
    unordered_set<string> mp;
    public:
        Student() = default;
        Student(string nm, string i) : name{nm}, id{i} {};
        string getId(){
            return id;
        }
        void displayMyClasses(){
            for(auto i : class_taken){
                cout << i << "\n-----------------------------------------\n";
            }
        }
        bool Add_Class(Lecture_Class l){
            if(mp.find(l.getCourseCode()) == mp.end()){
                class_taken.push_back(l);
                mp.insert(l.getCourseCode());
                return true;
            }
            else{
                cout << "Class could not be registered\n";
                return false;
            }
            
        }
        bool delete_Class(Lecture_Class l){
            if(mp.find(l.getCourseCode()) == mp.end()){
                class_taken.erase(l);
                mp.erase(l.getCourseCode());
                return true;
            }
            else{
                cout << "Class could not be deleted\n";
                return false;
            }
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
    deque<Lecture_Class> admin_classes;
    deque<Student> students;
    while(true){
        int choice;
        cout << "Input 1 for Admin, 0 for student, -1 to exit" << endl;
        cin >> choice;
        if(choice == 1){
            // Admin
            int x;
            cout << "Input Choice of task:\n" << "0: Add Student\n1: Add Classes\n2: Display Students\n3: Display Classes\n4: Delete Class\n5: Delete Student" << endl;
            cin >> x;
            switch (x) {
                case 0:{
                    string name, id;
                    cout << "Enter Student FirstName, SecondName and ID\n";
                    string temp;
                    cin >> name;
                    cin >> temp;
                    name = name + " " + temp;
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
                    if(students.empty()){
                        cout << "Students list is empty\n";
                        break;
                    }
                    for(auto i : students){
                        cout << i << endl << "----------------------------" << endl;
                    }
                    break;
                case 3:
                    for(auto i : admin_classes){
                        cout << i << endl << "-----------------------------" << endl;
                    }
                    break;
                case 4:{
                    cout << "Enter Course Code\n";
                    string s;
                    bool flag = false;
                    cin >> s;
                    for(auto i = admin_classes.begin();i != admin_classes.end(); i++){
                        if(i->getCourseCode() == s){
                            flag = true;
                            admin_classes.erase(i);
                            break;
                        }
                    }
                    if(flag == false) cout << "No such entry found\n";
                    break;
                }
                case 5:{
                    cout << "Enter Student ID\n";
                    string s;
                    cin >> s;
                    bool flag = false;
                    if(students.size() == 0){
                        cout << "No students to delete\n";
                        break;
                    }
                    if(students.size() == 1){
                        if(students.begin()->getId() == s){
                            students.clear();
                        }
                        else{
                            cout << "No such entry found\n";
                        }
                        break;
                    }

                    for(auto i = students.begin(); i != students.end(); i++){
                        if(i->getId() == s){
                            flag = true;
                            students.erase(i);
                            break;
                        }
                    }
                    if(flag == false) cout << "No such entry found\n";
                    break;
                }
                
                default:
                    cout << "Invalid Choice" << endl;
                    break;
            }
        }
        else if(choice == 0){
            // Student
            cout << "Enter ID No.\n";
            string id;
            cin >> id;
            bool flag = false;
            Student current;
            for(auto i = students.begin(); i!=students.end(); i++){
                if(i->getId() == id){
                    flag = true;
                    current = *i;
                    break;
                }
            }
            if(flag == false){
                cout << "No such entry found\n";
                break;
            }
            cout << "Input Choice\n0: Add Class\n1: Delete Class\n2: Display my Classes";
            int x;
            cin >> x;
            switch(x){
                case 0:{
                    cout << "Enter Course Code and Section no.\n";
                    string courseCode;
                    int sectionNumber;
                    cin >> courseCode;
                    cin >> sectionNumber;
                    bool flag = false;
                    for(auto i=admin_classes.begin(); i!=admin_classes.end(); i++){
                        if(i->getCourseCode() == courseCode && i->getSectionNumber() == sectionNumber){
                            flag = true;
                            if(i->isAvailable()){
                                current.Add_Class(*i);
                                i->updateEnrollment(-1);
                            }
                            else{
                                cout << "Class Enrollment is full\n";
                            }
                            
                            // alter enrollment of class
                            break;
                        }
                    }
                    if(flag == false){
                        cout << "No such entry found\n";
                        break;
                    } 
                    break;
                }
                case 1:
                    break;
                case 2:
                    current.displayMyClasses();
                    break;
                default:
                    cout << "Invalid Choice\n";
                    break;
            }
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
