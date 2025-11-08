#include <iostream>
using namespace std;

class Lecture {
private:
    char lecturerName[50];
    char courseName[50];
    int numberOfLectures;
    int subjectCode;  
public:
    Lecture() { }

    void assignLectureDetails() {
        cout << "Enter Lecturer Name: ";
        cin >> lecturerName;
        cout << "Enter Subject Code (Number Only): ";
        cin >> subjectCode;
        cout << "Enter Course Name: ";
        cin >> courseName;
        cout << "Enter Number of Lectures: ";
        cin >> numberOfLectures;
    }

    void displayLectureDetails() {
        cout << "\nLecturer Name: " << lecturerName;
        cout << "\nSubject Code: " << subjectCode;
        cout << "\nCourse Name: " << courseName;
        cout << "\nNumber of Lectures: " << numberOfLectures << "\n";
    }

    int getSubjectCode() {
        return subjectCode;
    }
};

int main() {
    Lecture lecturers[5];

    for(int i = 0; i < 5; i++) {
        cout << "\nEnter Details for Lecturer " << i + 1 << "\n";
        lecturers[i].assignLectureDetails();
    }

    while(true) {
        int searchCode;
        int choice;

        cout << "\nPress 1 to Search by Subject Code or 0 to Exit: ";
        cin >> choice;

        if(choice == 0)
            break;

        cout << "Enter Subject Code: ";
        cin >> searchCode;

        for(int i = 0; i < 5; i++) {
            if(lecturers[i].getSubjectCode() == searchCode) {
                lecturers[i].displayLectureDetails();
            }
        }
    }

    return 0;
}
