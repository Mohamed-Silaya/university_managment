#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Department {
private:
    string department_name;
    int department_capacity;
    double required_gpa;

public:
    // Default constructor
    Department() {
        department_name = "";
        department_capacity = 0;
        required_gpa = 0.0;
    }

    // Parameterized constructor
    Department(string name, int capacity, double gpa) {
        department_name = name;
        department_capacity = capacity;
        required_gpa = gpa;
    }

    // Setters
    void set_department_name(string name) {
        department_name = name;
    }

    void set_department_capacity(int capacity) {
        department_capacity = capacity;
    }

    void set_required_gpa(double gpa) {
        required_gpa = gpa;
    }

    // Getters
    string get_department_name() {
        return department_name;
    }

    int get_department_capacity() {
        return department_capacity;
    }

    double get_required_gpa() {
        return required_gpa;
    }
};

class Person{
protected:
    int id, age;
    string name;
    char gender;

public:
    // Default Constructor
    Person()
    {
        id = 0;
        age = 0;
        name = "";
        gender = ' ';
    }

    // Parametrized Constructor
    Person(int personId, string personName, int personAge, char personGender)
    {

        id = personId;
        age = personAge;
        name = personName;
        gender = personGender;
    }
    // Setters
    void set_id(int personId)
    {
        id = personId;
    }
    void set_age(int personAge)
    {
        age = personAge;
    }
    void set_name(string personName)
    {
        name = personName;
    }
    void set_gender(char personGender)
    {
        gender = personGender;
    }
    // Getters
    int get_id()
    {
        return id;
    }
    int get_age()
    {
        return age;
    }
    string get_name()
    {
        return name;
    }
    char get_gender()
    {
        return gender;
    }
    virtual void attend()=0;
};

class Student : public Person {
private:
    int level;
    double gpa;
public:
 // constructors
    Student(){}                //default constructor
    Student(int i, string n, int a, char ge, int l, double g) :Person(i, n, a, ge), level(l), gpa(g){}    //parameterized constructor

    //setters
    void set_level(int l){
        level = l;
    }
    void set_gpa(double g){
        gpa = g;
    }

    //getters
    int get_level(){
        return level;
    }
    double get_gpa(){
        return gpa;
    }
    void attend(){}
};

class Professor : public Person {
private:
    Department* department;
    double salary;
    string degree;
public:
    //constructors
    Professor() : salary(0), degree(""){}                                                                //default constructor
    Professor(int i, string n, int a, char ge, Department* d, double s, string t) : Person(i, n, a, ge), department(d), salary(s), degree(t){}          //parameterized constructor

    //setters
    void set_department(Department* d){
        department = d;
    }
    void set_salary(double s){
        salary = s;
    }
    void set_degree(string t){
        degree = t;
    }

    //getters
    Department* get_department(){
        return department;
    }
    double get_salary(){
        return salary;
    }
    string get_degree(){
        return degree;
    }
    void attend(){}
};

class Course{
private:
    string course_name;
    string course_code;
    int course_hours;
    vector<Course*> prerequisites;
    Professor* professor;
    vector<Student*> students;

public:
    // Default constructor
    Course()
    {
        course_name = "";
        course_code = "";
        course_hours = 0;
    }

    // Parameterized constructor
    Course(string name, string code, int hours, vector<Course*> prereqs, Professor* prof, vector<Student*> studs)
    {
        course_name = name;
        course_code = code;
        course_hours = hours;
        prerequisites = prereqs;
        professor = prof;
        students = studs;
    }

    // Setters
    void set_course_name(string name)
    {
        course_name = name;
    }

    void set_course_code(string code)
    {
        course_code = code;
    }

    void set_course_hours(int hours)
    {
        course_hours = hours;
    }

    void set_prerequisites(vector<Course*> prereqs)
    {
        prerequisites = prereqs;
    }

    void set_professor(Professor* prof)
    {
        professor = prof;
    }

    void set_students(vector<Student*> studs)
    {
        students = studs;
    }

    // Getters
    string get_course_name()
    {
        return course_name;
    }

    string get_course_code()
    {
        return course_code;
    }

    int get_course_hours()
    {
        return course_hours;
    }

    vector<Course*> get_prerequisites()
    {
        return prerequisites;
    }

    Professor* get_professor()
    {
        return professor;
    }

    vector<Student*> get_students()
    {
        return students;
    }
};

class University{
private:
    vector<Department> departments;
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;
    static University *ptr;
    University(){addData();}
public:
    University( const University &op) = delete;
    static University* get_instance(){
        if(ptr == NULL){
            ptr = new University;
        }
        return ptr;
    }
    void add_department(string name, int capacity, double gpa) {
        Department* Ptr =new Department(name, capacity, gpa);
        departments.push_back(*Ptr);


    }

    void delete_department(string name) {
        for (int i =0; i<departments.size(); i++) {
            if (name == departments[i].get_department_name()) {
                departments.erase(departments.begin()+i);
                return;
            }
        }
    }
    void update_department(string name,int new_department_capacity) {
        for (int i =0; i<departments.size(); i++) {
            if (name == departments[i].get_department_name()) {
                departments[i].set_department_capacity(new_department_capacity);
                return;
            }
        }
    }
    void add_student(string Name, int Id, char Gender, int Age, int Level, double Gpa){
    Student *PTR = new Student(Id, Name, Age, Gender, Level, Gpa);
    students.push_back(*PTR);
    }
    void add_professor(string Name, int Id, char Gender, int Age, double Salary, string Degree, Department* D){
    Professor* PTR = new Professor(Id, Name, Age, Gender, D, Salary, Degree);
    professors.push_back(*PTR);
    }
    void update_student(int Id, int Level){
        for(int i = 0; i<students.size(); i++){
            if(students[i].get_id() == Id){
                students[i].set_level(Level);
                return;
            }
        }
    }
    void update_professor(int Id, double Salary){
        for(int i=0; i<professors.size(); i++){
            if(professors[i].get_id() == Id){
                professors[i].set_salary(Salary);
                return;
            }
        }
    }
    void delete_student(int Id){
        for(int i = 0; i<students.size(); i++){
            if(students[i].get_id() == Id){
                students.erase(students.begin()+i);
                return;
            }
        }
    }
    void delete_professor(int Id){
        for(int i = 0; i<professors.size(); i++){
            if(professors[i].get_id() == Id){
                professors.erase(professors.begin()+i);
                return;
            }
        }
    }
    void add_Course(string name, string code, int hours, vector<Course*> prereqs, Professor* prof, vector<Student*> studs){
    Course* PTR = new Course;
    PTR->set_course_name(name);
    PTR->set_course_code(code);
    PTR->set_course_hours(hours);
    PTR->set_prerequisites(prereqs);
    PTR->set_professor(prof);
    PTR->set_students(studs);
    courses.push_back(*PTR);
    }

    void update_courses(string code, int hours){
        for(int i=0; i<courses.size(); i++){
            if(courses[i].get_course_code() == code){
                courses[i].set_course_hours(hours);
                return;
            }
        }
    }

    void delete_courses(string code){
        for(int i = 0; i<courses.size(); i++){
            if(courses[i].get_course_code() == code){
                courses.erase(courses.begin()+i);
                return;
            }
        }
    }

    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2,"Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4,"Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5,"Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6,"Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8,"Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(1,"Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professors.push_back(p1);
        Professor p2(2,"Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professors.push_back(p2);
        Professor p3(3,"Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professors.push_back(p3);
        Professor p4(4,"Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professors.push_back(p4);
        Professor p5(5,"Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professors.push_back(p5);

        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i].get_department_name()<<endl;
        }
        for(int i=0; i<professors.size(); i++)
        {
            cout<<"Professor Name: "<<professors[i].get_name()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i].get_name()<<endl;
        }
       for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i].get_course_name()<<endl;
        }
    }
};
University* University::ptr = NULL;

int main() {
    University* PTR = University::get_instance();

    PTR->printAll();
    PTR->add_department("Electrec", 10, 2.5);
    PTR->delete_department("Cyber Security");
    PTR->delete_courses("HTML123");
    PTR->add_student("Hamada", 10, 'M', 22, 5, 3.1);
    //PTR->update_student(3, 4);
    PTR->delete_student(6);
    PTR->printAll();
    //PTR->add_student("Ma7moud", 302011, 'M', 22, 5, 3.1);

    return 0;
}
