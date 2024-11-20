#include <iostream>
#include <cstring>
using namespace std;

struct Subject
{
    char subject_id[50];
    char subject_name[50];
    int  unit;
    float weight_mid;
    float weight_final;
};

struct SubjectNode {
    Subject info;
    SubjectNode* next;
    float mid_score, final_score;
};

typedef SubjectNode* list_subject;

struct Student
{
    long student_id;
    char student_name[50];
    char class_name[50];
    list_subject subjectList;
};

struct StudentNode
{
    Student info;
    StudentNode* next;
};

typedef StudentNode* list_student;

void Init(list_student &list){
    list = NULL;
}

//Add a new student to the first of list
void InsertStudentBegin(list_student &studentList, Student newstudent){
    StudentNode* newStudentNode = new StudentNode;
    newStudentNode->info = newstudent;
    newStudentNode->next = NULL;
    if (studentList == NULL){
        studentList = newStudentNode;
    }
    else {
    studentList = newStudentNode;
    newStudentNode->next = studentList;
    }
}

//Find student by ID
StudentNode* SearchStudent(list_student &studentList, int id){
    StudentNode* newStudentNode = new StudentNode;
    newStudentNode = studentList;
    while(newStudentNode != NULL){
        if(newStudentNode->info.student_id == id) return newStudentNode;
        else newStudentNode = newStudentNode->next;
    }
    return NULL;
}

//Add a new student after a given student ID 
void InsertStudentAfter(list_student &stuList, Student newstudent, int id){
    StudentNode* givenStu = SearchStudent(stuList, id);
    StudentNode* newStudentNode = new StudentNode;
    newStudentNode->info = newstudent;
    newStudentNode->next = NULL;
    if(stuList == NULL){
        stuList = newStudentNode;
    }
    else{
        if(givenStu == NULL) return;
        else{
            newStudentNode->next = givenStu->next;
            givenStu->next = newStudentNode;
        }
    }

}

//find subject by ID
SubjectNode* SearchSubject(list_subject &subjectList, char id[50]){
    SubjectNode* newSubjectNode = new SubjectNode;
    newSubjectNode = subjectList;
    while(newSubjectNode != NULL){
        if(newSubjectNode->info.subject_id == id) return newSubjectNode;
        else newSubjectNode = newSubjectNode->next;
    }
    return NULL;
}

//Add a new subject to the first of the list
void InsertSubjectBegin(list_subject& subjectList, Subject newSubject, float mid, float final) {
    SubjectNode* newSubjectNode = new SubjectNode;
    newSubjectNode->info = newSubject;
    newSubjectNode->mid_score = mid;
    newSubjectNode->final_score = final;
    newSubjectNode->next = NULL;
    if (subjectList == NULL){
        subjectList = newSubjectNode;
    }
    else {
        subjectList = newSubjectNode;
        newSubjectNode->next = subjectList;
    }
}

//Add a new subject after a given subject
void InsertSubjectAfter(list_subject& subjectList, Subject newSubject, float mid, float final, char subID[50]){
    SubjectNode* givenSubj = SearchSubject(subjectList, subID);
    SubjectNode* newSubjectNode = new SubjectNode;
    newSubjectNode->info = newSubject;
    newSubjectNode->mid_score = mid;
    newSubjectNode->final_score = final;
    newSubjectNode->next = NULL;
    if (subjectList == NULL){
        subjectList = newSubjectNode;
    }
    else {
        if(givenSubj == NULL) return;
        else {
            newSubjectNode->next = givenSubj->next;
            givenSubj->next = newSubjectNode;
        }
    }
}

//Display student list
void displayStudentList(list_student studentList) {
    StudentNode* current = studentList;
    while (current != NULL) {
        cout << "ID:" << current->info.student_id << " Name:" << current->info.student_name << " Class:" << current->info.class_name << endl;
        current = current->next;
    }
}

//print student node
void printStudent(StudentNode* current){
    cout << "ID:" << current->info.student_id << " Name:" << current->info.student_name << " Class:" << current->info.class_name << endl;
    // SubjectNode* currentSubject = current->info.subjectList;
    SubjectNode* currentSubject = current->info.subjectList;
    cout << "Subject: " << endl;
    // cout << "Name:"<< currentSubject->info.subject_name << "Mid:" << currentSubject->mid_score << "Final:"<<currentSubject->final_score << endl ;
    
    // cout << "Name:"<< currentSubject->info.subject_name << "Mid:" << currentSubject->mid_score << "Final:"<<currentSubject->final_score << endl ;
    cout << "Name: " << currentSubject->info.subject_id;
    currentSubject = currentSubject->next;
}

int main() {
    Student stu1 = {1,"Nguyen Van A","DT1",NULL};
    Student stu2 = {2,"Nguyen Van B","DT1",NULL};

    Subject GT1 = {"MI1111","GT1", 4, 0.3, 0.7};
    Subject GT2 = {"MI1121","GT2", 3, 0.3, 0.7};
    Subject GT3 = {"MI1131","GT3", 3, 0.3, 0.7};
    Subject LSD = {"SSH1141","LSD", 2, 0.5, 0.5};

    list_student S;
    Init(S);
    InsertStudentBegin(S,stu1);
    InsertSubjectBegin(stu1.subjectList, GT1, 5, 6);
    //InsertSubjectBegin(stu1.subjectList,LSD);
    InsertStudentAfter(S,stu2,1);
    displayStudentList(S);
    //printStudent(s2);
    return 0;
}