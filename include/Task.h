#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

enum TaskType
{
    Study,
    Homework,
    Project,
    Revision,
    Exam
};

class Task
{
private:
    int taskId;
    string subjectName;
    string taskName;
    TaskType taskType;

    int difficulty;
    int importance;

    double studentEstimatedTime;

    int pagesOrQuestions;
    int daysRemaining;

    double predictedDuration;
    double delayProbability;

    bool isCompleted;

public:
    Task(int id,
         string sub,
         string name,
         TaskType type,
         int diff,
         int imp,
         double estTime,
         int pages,
         int days);

    static void displayHeader();

    int getTaskId() const;
    string getSubjectName() const;
    string getTaskName() const;
    TaskType getTaskType() const;
    int getTaskTypeWeight() const;
    int getDifficulty() const;
    int getImportance() const;

    double getStudentEstimatedTime() const;

    int getPagesOrQuestions() const;
    int getDaysRemaining() const;

    double getPredictedDuration() const;
    double getDelayProbability() const;

    bool getIsCompleted() const;

    void setSubjectName(string sub);
    void setTaskName(string name);
    void setTaskType(TaskType type);

    void setDifficulty(int diff);
    void setImportance(int imp);

    void setStudentEstimatedTime(double time);

    void setPagesOrQuestions(int pages);
    void setDaysRemaining(int days);

    void setPredictedDuration(double pred);
    void setDelayProbability(double prob);

    void markAsCompleted();

    string getTaskTypeString() const;

    void displayTaskRow() const;
};

#endif
