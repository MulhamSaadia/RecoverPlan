#include "../include/StudySession.h"

using namespace std;

StudySession::StudySession(
    int sessionId,
    int taskId,
    string courseName,
    string taskName,
    int dayNumber,
    double plannedHours
)
{
    this->sessionId = sessionId;
    this->taskId = taskId;
    this->courseName = courseName;
    this->taskName = taskName;

    this->dayNumber=dayNumber>=1?dayNumber:1;
    
        this->plannedHours = plannedHours>=0?plannedHours:0;

    actualHours = 0;
    completed = 0;
    missed = 0;
}

int StudySession::getSessionId() const
{
    return sessionId;
}

int StudySession::getTaskId() const
{
    return taskId;
}

string StudySession::getCourseName() const
{
    return courseName;
}

string StudySession::getTaskName() const
{
    return taskName;
}

int StudySession::getDayNumber() const
{
    return dayNumber;
}

double StudySession::getPlannedHours() const
{
    return plannedHours;
}

double StudySession::getActualHours() const
{
    return actualHours;
}

bool StudySession::isCompleted() const
{
    return completed;
}

bool StudySession::isMissed() const
{
    return missed;
}

void StudySession::setSessionId(int sessionId)
{
    this->sessionId = sessionId;
}

void StudySession::setTaskId(int taskId)
{
    this->taskId = taskId;
}

void StudySession::setCourseName(const string& courseName)
{
    this->courseName = courseName;
}

void StudySession::setTaskName(const string& taskName)
{
    this->taskName = taskName;
}

void StudySession::setDayNumber(int dayNumber)
{
    if (dayNumber >= 1)
    {
        this->dayNumber = dayNumber;
    }
}

void StudySession::setPlannedHours(double plannedHours)
{
    if (plannedHours >= 0)
    {
        this->plannedHours = plannedHours;
    }
}

void StudySession::setActualHours(double actualHours)
{
    if (actualHours >= 0)
    {
        this->actualHours = actualHours;
    }
}

void StudySession::setCompleted(bool completed)
{
    this->completed = completed;

    if (completed)
    {
        missed = 0;
    }
}

void StudySession::setMissed(bool missed)
{
    this->missed = missed;

    if (missed)
    {
        completed = 0;
    }
}

bool StudySession::isDelayed() const
{
    return completed && actualHours > plannedHours;
}

double StudySession::getDelayHours() const
{
    if (actualHours > plannedHours)
    {
        return actualHours - plannedHours;
    }

    return 0;
}

void StudySession::printSession() const
{
    cout << "========== Study Session ==========" << endl;

    cout << "Session ID: " << sessionId << endl;
    cout << "Task ID: " << taskId << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Task Name: " << taskName << endl;
    cout << "Day Number: " << dayNumber << endl;
    cout << "Planned Hours: " << plannedHours << endl;
    cout << "Actual Hours: " << actualHours << endl;

    cout << "Status: ";

    if (missed)
    {
        cout << "Missed" << endl;
    }
    else if (completed)
    {
        if (isDelayed())
        {
            cout << "Completed with delay" << endl;
            cout << "Delay Hours: " << getDelayHours() << endl;
        }
        else
        {
            cout << "Completed on time" << endl;
        }
    }
    else
    {
        cout << "Not completed yet" << endl;
    }

    cout << "===================================" << endl;
}