#include <iostream>

using namespace std;

struct Subject
{
    char subject_id[10];
    char subject_name[10];
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
    list_subject subject;
};

struct StudentNode
{
    Student info;
    StudentNode* next;
};

typedef StudentNode* list_student;

