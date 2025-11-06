#include <iostream>
using namespace std;

class Lecture {
private:
    char lecturerName[50];
    char subjectName[50];
    char courseName[50];
    int numberOfLectures;

public:
    Lecture() { }

    void assignLectureDetails() {
        cout << "Enter Lecturer Name: ";
        cin >> lecturerName;
        cout << "Enter Subject Name: ";
        cin >> subjectName;
        cout << "Enter Course Name: ";
        cin >> courseName;
        cout << "Enter Number of Lectures: ";
        cin >> numberOfLectures;
    }

    void displayLectureDetails() {
        cout << "\nLecturer Name: " << lecturerName;
        cout << "\nSubject Name: " << subjectName;
        cout << "\nCourse Name: " << courseName;
        cout << "\nNumber of Lectures: " << numberOfLectures << "\n";
    }

    char* getSubjectName() {
        return subjectName;
    }
};

int compareStrings(char a[], char b[]) {
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0') {
        if(a[i] != b[i])
            return 0;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

int main() {
    Lecture lecturers[5];

    for(int i = 0; i < 5; i++) {
        cout << "\nEnter Details for Lecturer " << i + 1 << "\n";
        lecturers[i].assignLectureDetails();
    }

    while(true) {
        char searchSubject[50];
        int found = 0;
        int choice;

        cout << "\nPress 1 to Search by Subject or 0 to Exit: ";
        cin >> choice;

        if(choice == 0)
            break;

        cout << "Enter Subject Name: ";
        cin >> searchSubject;

        for(int i = 0; i < 5; i++) {
            if(compareStrings(lecturers[i].getSubjectName(), searchSubject)) {
                lecturers[i].displayLectureDetails();
                found = 1;
            }
        }

        if(found == 0)
            cout << "\nNo lecturer found for this subject.\n";
    }

    return 0;
}
