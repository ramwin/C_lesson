#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Class {
  public:
    int id;
    Class(int id): id(id) {};
};


class Student {
  public:
    int id;
    Class &myclass;
    Student(int id, Class& myclass): id(id), myclass(myclass) {
    }
};


class StudentWithScore {
  public:
    int id;
    vector<vector<int>> &scores;
    StudentWithScore(int id, vector<vector<int>> &scores): id(id), scores(scores) {
    };
};


class Parent {
  public:
    StudentWithScore student_with_score;
};



int main() {
  // 基础使用没问题
  Class myclass(3);
  Student student(1, myclass);
  cout << "学生: " << student.id << " 所在的班级是: " << student.myclass.id << endl;
  vector<vector<int>> scores;
  vector<int> scores_grade1;
  scores_grade1.push_back(100);
  scores_grade1.push_back(99);
  vector<int> scores_grade2;
  scores_grade2.push_back(90);
  scores_grade2.push_back(89);
  scores.push_back(scores_grade1);
  scores.push_back(scores_grade2);
  StudentWithScore student2(2, scores);
  cout << "学生：" << student2.id << " 2年级最后一次考试成绩是: " << student2.scores[1][1] << endl;
};
