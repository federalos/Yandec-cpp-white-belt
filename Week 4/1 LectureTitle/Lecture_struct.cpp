#include <iostream>
#include <string>

using namespace std;

struct Specialization {
  explicit Specialization(const string& new_value) {
    value = new_value;
  }
  string value;
};

struct Course {
  explicit Course(const string& new_value) {
    value = new_value;
  }
  string value;
};

struct Week {
  explicit Week(const string& new_value) {
    value = new_value;
  }
  string value;
};

struct LectureTitle {
  LectureTitle(const Specialization& new_specialization,
               const Course& new_course,
               const Week& new_week) {
    specialization = new_specialization.value;
    course = new_course.value;
    week = new_week.value;
  }
  string specialization;
  string course;
  string week;
};


//int main (){

// Test 1 Must work
/*    LectureTitle title1(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

*/
// Test 2 shouldn't work
/*
    LectureTitle title("C++", "White belt", "4th");
*/

// Test 3 shouldn't work
/*
    LectureTitle title(string("C++"), string("White belt"), string("4th"));
*/

// Test 4 shouldn't work
/*
    LectureTitle title = {"C++", "White belt", "4th"};
*/

// Test 5 shouldn't work
/*
    LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
*/

// Test 6 shouldn't work
/*
    LectureTitle title(
        Course("White belt"),
        Specialization("C++"),
        Week("4th")
    );
*/

// Test 7 shouldn't work
/* //
    LectureTitle title(
        Specialization("C++"),
        Week("4th"),
        Course("White belt")
    );
*/


/*
(Wrong answer) Compile error: 
b'/tmp/tmpewrbnz4g.cpp:34:5: 
fatal error: unknown type name \'LectureTitle\'\n    
LectureTitle title(Specialization("C++"), Course("White belt"), Week("3rd"));\n    
^\n1 error generated.\n'
*/

// Test 8
/*
    LectureTitle title(Specialization("C++"), Course("White belt"), Week("3rd"));
*/

/*
(Wrong answer) 
Compile error: 
b"/tmp/tmpq_pla993.cpp:115:5: 
fatal error: 
redefinition of 'main'\nint main() {\n    
^\n/tmp/tmpq_pla993.cpp:41:5: 
note: previous definition is here\nint main (){\n    
^\n1 error generated.\n"
*/

//    return 0;
//}
