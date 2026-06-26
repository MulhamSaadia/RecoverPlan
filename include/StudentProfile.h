#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct SubjectRecord
{
    string subjectName;
    double grade;
};

class StudentProfile
{
private:
    string name;
    double availableHours;
    double completionRate;
    int numberOfMissedSessions;
    int focusScore;

    vector<SubjectRecord> pastRecord;
    vector<string> sessionLog;

public:
    StudentProfile();
    StudentProfile(const string& name, double availableHours);

    string getName() const;
    double getAvailableHours() const;
    double getCompletionRate() const;
    int getNumberOfMissedSessions() const;
    int getFocusScore() const;

    const vector<SubjectRecord>& getPastRecord() const;
    const vector<string>& getSessionLog() const;

    void setName(const string& name);
    void setAvailableHours(double hours);
    void setCompletionRate(double rate);
    void setNumberOfMissedSessions(int missed);
    void setFocusScore(int score);

    void addSubjectRecord(const string& subject, double grade);
    void addSessionLog(const string& session);

    void printProfile() const;
};

#endif