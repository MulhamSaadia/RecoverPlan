#include "../include/StudentProfile.h"
#include <iomanip>

using namespace std;
StudentProfile::StudentProfile(const string& name, double availableHours)
{
    this->name = name;
    this->availableHours = availableHours>=0 ? availableHours :0;
    completionRate = 0;
    numberOfMissedSessions = 0;
    focusScore = 5;
}

string StudentProfile::getName() const
{
    return name;
}

double StudentProfile::getAvailableHours() const
{
    return availableHours;
}

double StudentProfile::getCompletionRate() const
{
    return completionRate;
}

int StudentProfile::getNumberOfMissedSessions() const
{
    return numberOfMissedSessions;
}

int StudentProfile::getFocusScore() const
{
    return focusScore;
}

const vector<SubjectRecord>& StudentProfile::getPastRecord() const
{
    return pastRecord;
}

const vector<string>& StudentProfile::getSessionLog() const
{
    return sessionLog;
}

void StudentProfile::setName(const string& name)
{
    this->name = name;
}

void StudentProfile::setAvailableHours(double hours)
{
   availableHours=hours>=0?hours:0;
}

void StudentProfile::setCompletionRate(double rate)
{
    if (rate >= 0.0 && rate <= 1.0)
    {
        completionRate = rate;
    }
}

void StudentProfile::setNumberOfMissedSessions(int missed)
{
    if (missed >= 0)
    {
        numberOfMissedSessions = missed;
    }
}

void StudentProfile::setFocusScore(int score)
{
    if (score >= 1 && score <= 10)
    {
        focusScore = score;
    }
}

void StudentProfile::addSubjectRecord(const string& subject, double grade)
{
    SubjectRecord record;
    record.subjectName = subject;
    record.grade = grade;

    pastRecord.push_back(record);
}

void StudentProfile::addSessionLog(const string& session)
{
    sessionLog.push_back(session);
}

void StudentProfile::printProfile() const
{
    cout << "========== Student Profile ==========" << endl;

    cout << "Student Name: " << name << endl;
    cout << "Available Hours per Day: " << availableHours << endl;

    cout << "Completion Rate: "
         << fixed << setprecision(2)
         << completionRate * 100 << "%" << endl;

    cout << "Number of Missed Sessions: "
         << numberOfMissedSessions << endl;

    cout << "Focus Score: " << focusScore << "/10" << endl;

    cout << endl;
    cout << "Past Records:" << endl;

    if (pastRecord.empty())
    {
        cout << "No past records available." << endl;
    }
    else
    {
        for (const auto& record : pastRecord)
        {
            cout << "- Subject: " << record.subjectName
                 << ", Grade: " << record.grade << endl;
        }
    }

    cout << endl;
    cout << "Session Log:" << endl;

    if (sessionLog.empty())
    {
        cout << "No study sessions recorded yet." << endl;
    }
    else
    {
        for (const auto& session : sessionLog)
        {
            cout << "- " << session << endl;
        }
    }

    cout << "=====================================" << endl;
}