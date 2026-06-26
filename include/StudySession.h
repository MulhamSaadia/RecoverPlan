#ifndef STUDYSESSION_H
#define STUDYSESSION_H

#include <iostream>
#include <string>

using namespace std;

class StudySession
{
private:
    int sessionId;
    int taskId;

    string courseName;
    string taskName;

    int dayNumber;

    double plannedHours;
    double actualHours;

    bool completed;
    bool missed;

public:
    StudySession();

    StudySession(
        int sessionId,
        int taskId,
        string courseName,
        string taskName,
        int dayNumber,
        double plannedHours
    );

    int getSessionId() const;
    int getTaskId() const;
    string getCourseName() const;
    string getTaskName() const;
    int getDayNumber() const;
    double getPlannedHours() const;
    double getActualHours() const;
    bool isCompleted() const;
    bool isMissed() const;

    void setSessionId(int sessionId);
    void setTaskId(int taskId);
    void setCourseName(const string& courseName);
    void setTaskName(const string& taskName);
    void setDayNumber(int dayNumber);
    void setPlannedHours(double plannedHours);
    void setActualHours(double actualHours);
    void setCompleted(bool completed);
    void setMissed(bool missed);

    bool isDelayed() const;
    double getDelayHours() const;

    void printSession() const;
};

#endif