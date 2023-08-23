#include <iostream>
#include <string>
using namespace std;
class University{
  private:
   
     
  static University*is_Ptr;
  University()
  {
  }
   
  public:
     University(const University& obj)= delete;
 
  
  static University* getInstance()
  { 
    if (is_Ptr == NULL)
    {
   
      is_Ptr = new University();
             return is_Ptr;
    }
    else
    {
      return is_Ptr;
    }
  }
 
   };// end of class university
     University * University::is_Ptr= NULL;

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

