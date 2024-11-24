#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string subjects[5];
    double grades[5];
};

void print(Student s) {
    cout << "\tID: " << s.id << "\n\tName: " << s.name << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "\n\tSubject: " << s.subjects[i] << "\n\tGrade: " << s.grades[i] << endl;
    }
    cout << "\n\n\t ___________________________\n";
}

struct TempAc {
    char ch;
    Student st;
};

struct Node {
    TempAc data;
    Node* next;
};

class LinkedStack {
private:
    Node* topNode;

public:
    LinkedStack() : topNode(nullptr) {}

    void push(TempAc act) {
        Node* newNode = new Node{ act, topNode };
        topNode = newNode;
    }

    TempAc pop() {
        if (topNode == nullptr) {
            return TempAc{ ' ', {0, ""} };
        }
        Node* temp = topNode;
        TempAc poppedData = topNode->data;
        topNode = topNode->next;
        delete temp;
        return poppedData;
    }

    bool empty() {
        return topNode == nullptr;
    }
};

class StudentRecord {
private:
    Student* students;  
    int sCount;        
    LinkedStack unSt;  
    LinkedStack reSt;

public:
    StudentRecord() : sCount(0) {
        students = new Student[100]; 
    }

    void addStudent() {
        int id;
        string name, subjects[5];
        double grades[5];

        cout << "\t [-] Insert Data Student \n";
        cout << "ID : "; cin >> id;
        cout << "name : "; cin >> name;
        for (int i = 0; i < 5; i++) {
            cout << "subjects [" << i + 1 << "] : "; cin >> subjects[i];
            cout << "grades [" << i + 1 << "] : "; cin >> grades[i];
        }
        Student newStudent = { id, name };
        for (int i = 0; i < 5; ++i) {
            newStudent.subjects[i] = subjects[i];
            newStudent.grades[i] = grades[i];
        }
        students[sCount++] = newStudent;

        TempAc act = { 'a', newStudent };
        unSt.push(act);
    }

    void deleteStudent(int id) {
        for (int i = 0; i < sCount; ++i) {
            if (students[i].id == id) {
                TempAc act = { 'd', students[i] };
                unSt.push(act);
                students[i] = students[--sCount];
                cout << "Done";
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void modifyStudent(int id, string newName, string newSubjects[5], double newGrades[5]) {
        for (int i = 0; i < sCount; ++i) {
            if (students[i].id == id) {
                Student oldStudent = students[i];
                students[i].name = newName;
                for (int j = 0; j < 5; ++j) {
                    students[i].subjects[j] = newSubjects[j];
                    students[i].grades[j] = newGrades[j];
                }
                TempAc action = { 'm', oldStudent };
                unSt.push(action);
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    int searchStudent(int id) {
        for (int i = 0; i < sCount; i++) {
            if (students[i].id == id) {
                cout << "\n\t __________[" << students[i].id << "]_________\n\n";
                print(students[i]);
                return i;
            }
        }
        cout << "Student not found." << endl;
        return -1;
    }

    void undo() {
        if (unSt.empty()) {
            cout << "\n\n\t------------------------------\n\t[-] no action UNDO \n\n\t------------------------------\n";
            return;
        }

        TempAc act = unSt.pop();

        if (act.ch == 'a') {
            sCount--;
        }
        else if (act.ch == 'd') {
            students[sCount++] = act.st;
        }
        else if (act.ch == 'm') {
            for (int i = 0; i < sCount; ++i) {
                if (students[i].id == act.st.id) {
                    students[i] = act.st;
                    break;
                }
            }
        }
        reSt.push(act);
    }


    void redo() {
        if (reSt.empty()) {
            cout << "\n\n\t------------------------------\n\t[-] no action REDO \n\n\t------------------------------\n";
            return;
        }

        TempAc ac = reSt.pop();

        if (ac.ch == 'a') {
            students[sCount++] = ac.st;
        }
        else if (ac.ch == 'd') {
            deleteStudent(ac.st.id);
        }
        else if (ac.ch == 'm') {
            modifyStudent(ac.st.id, ac.st.name, ac.st.subjects, ac.st.grades);
        }
    }

    void displayAll() {
        cout << "\n\t ___________________________\n\n";
        for (int i = 0; i < sCount; ++i) {
            print(students[i]);
        }
    }

    void readKey() {

        char op = '#'; int id; string name, sub[5]; double gra[5];

        while (op != '$' || op!='0') 
        {
            cout << "\n\t_________________________________________________\n";
            cout << "|\t\t           Enter Option                       |\n";
            cout << "|\t\t  [a] - Add Student                           |\n";
            cout << "|\t\t  [s] - Search Student                        |\n";
            cout << "|\t\t  [d] - Delete Student                        |\n";
            cout << "|\t\t  [m] - Modify Student                        |\n";
            cout << "|\t\t  [r] - Redo                                  |\n";
            cout << "|\t\t  [u] - Undo                                  |\n";
            cout << "|\t\t  [p] - Display All Students                  |\n";
            cout << "|\t\t  [$] - Exit                                  |\n";
            cout << "\t_________________________________________________\n\n\n";
            cin >> op;
            switch (op) {
            case 'a':
            case 'A':
            case '1':
                addStudent();
                break;
            case 's':
            case 'S':
            case '2':
                cout << "\n\t[-] Enter ID Student : "; cin >> id;
                searchStudent(id);
                break;
            case 'd':
            case 'D':
            case '3':
                cout << "\n\t[-] Enter ID Student : "; cin >> id;
                deleteStudent(id);
                break;
            case 'm':
            case 'M':
            case '4':
                cout << "\n\t[-] Enter ID Student for Edit : "; cin >> id;
                cout << "\n\t[-] Enter name Student for Edit : "; cin >> name;
                for (int i = 0; i < 5; i++) {
                    cout << "subjects [" << i + 1 << "] : "; cin >> sub[i];
                    cout << "grades [" << i + 1 << "] : "; cin >> gra[i];
                }
                modifyStudent(id, name, sub, gra);
                break;
            case 'r':
            case 'R':
            case '5':
                redo();
                break;
            case 'u':
            case 'U':
            case '6':
                undo();
                break;
            case 'p':
            case 'P':
            case '7':
                displayAll();
                break;
            default:
            case '0':
                cout << "\tExit Enter 0 Or $";
                break;
            }
        }
    }
};

int main() {
    StudentRecord s;
    s.readKey();
    return 0;
}
