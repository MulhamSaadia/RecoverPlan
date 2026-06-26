#include "../include/Task.h"

using namespace std;


Task::Task(int id,
           string sub,
           string name,
           TaskType type,
           int diff,
           int imp,
           double estTime,
           int pages,
           int days)
{
    taskId = id;
    subjectName = sub;
    taskName = name;
    taskType = type;

    difficulty = (diff >= 1 && diff <= 10) ? diff : 1;
    importance = (imp >= 1 && imp <= 10) ? imp : 1;

    studentEstimatedTime = estTime;

    pagesOrQuestions = pages;
    daysRemaining = days;

    predictedDuration = 0;
    delayProbability = -1;

    isCompleted = false;
}



int Task::getTaskId() const
{
    return taskId;
}

string Task::getSubjectName() const
{
    return subjectName;
}

string Task::getTaskName() const
{
    return taskName;
}

TaskType Task::getTaskType() const
{
    return taskType;
}

int Task::getDifficulty() const
{
    return difficulty;
}

int Task::getImportance() const
{
    return importance;
}

double Task::getStudentEstimatedTime() const
{
    return studentEstimatedTime;
}

int Task::getPagesOrQuestions() const
{
    return pagesOrQuestions;
}

int Task::getDaysRemaining() const
{
    return daysRemaining;
}

double Task::getPredictedDuration() const
{
    return predictedDuration;
}

double Task::getDelayProbability() const
{
    return delayProbability;
}

bool Task::getIsCompleted() const
{
    return isCompleted;
}



void Task::setSubjectName(string sub)
{
    subjectName = sub;
}

void Task::setTaskName(string name)
{
    taskName = name;
}

void Task::setTaskType(TaskType type)
{
    taskType = type;
}

void Task::setDifficulty(int diff)
{
    if (diff >= 1 && diff <= 10)
        difficulty = diff;
}

void Task::setImportance(int imp)
{
    if (imp >= 1 && imp <= 10)
        importance = imp;
}

void Task::setStudentEstimatedTime(double time)
{
    if (time > 0)
        studentEstimatedTime = time;
}

void Task::setPagesOrQuestions(int pages)
{
    if (pages >= 0)
        pagesOrQuestions = pages;
}

void Task::setDaysRemaining(int days)
{
    if (days >= 0)
        daysRemaining = days;
}

void Task::setPredictedDuration(double pred)
{
    predictedDuration = pred;
}

void Task::setDelayProbability(double prob)
{
    delayProbability = prob;
}

void Task::markAsCompleted()
{
    isCompleted = true;
}

string Task::getTaskTypeString() const
{
    switch (taskType)
    {
        case Study:
            return "Study";

        case Homework:
            return "Homework";

        case Project:
            return "Project";

        case Revision:
            return "Revision";
        case Exam: 
            return "Exam";

        default:
            return "Unknown";
    }
}


void Task::displayTaskRow() const
{
    cout << fixed << setprecision(2);

    cout << left
    << setw(5)  << taskId
    << setw(15) << subjectName
    << setw(20) << taskName
    << setw(12) << getTaskTypeString()
    << setw(8)  << difficulty
    << setw(8)  << importance
    << setw(10) << studentEstimatedTime
    << setw(10) << pagesOrQuestions
    << setw(10) << daysRemaining;

    if (predictedDuration == 0)
        cout << setw(12) << "N/A";
    else
        cout << setw(12) << predictedDuration;

    if (delayProbability == -1)
        cout << setw(12) << "N/A";
    else
        cout << setw(12) << delayProbability;

    cout << setw(10)
    << (isCompleted ? "Completed" : "Pending")
    << endl;
}
int Task::getTaskTypeWeight() const
{
switch (taskType)
{
case Revision:
    return 3;
case Study:
    return 5;
case Homework:
    return 6;
case Project:
    return 8;
case Exam:
    return 9;
    break;

default:return 5; 
    break;
}
}

void Task::displayHeader()
{
    cout << left
    << setw(5)  << "ID"
    << setw(15) << "Subject"
    << setw(20) << "Task Name"
    << setw(12) << "Type"
    << setw(8)  << "Diff"
    << setw(8)  << "Imp"
    << setw(10) << "EstTime"
    << setw(10) << "Pages"
    << setw(10) << "Days"
    << setw(12) << "PredTime"
    << setw(12) << "DelayProb"
    << setw(10) << "Status"
    << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
}
