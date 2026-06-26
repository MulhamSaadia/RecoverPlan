#ifndef TIME_H
#define TIME_H
#include "Task.h"
#include "StudentProfile.h" 
#include <vector>

using namespace std;

class TimePredictor{
private: 
    static const int FEATURECOUNT =7;
    double bias ;
    vector<double>weights; 
    double learingRate;
    int graditrate;
    double dotProduct(vector<double>&weights, vector<double>& features);
    vector<double> getFeatures( Task& task,  StudentProfile& student);
    
public:
    TimePredictor(double learingRate, int graditrate);
    void predictTime(Task& task,  StudentProfile& student);
    double predict(vector<double>&features);
    void train(vector<vector<double>>& X_train, vector<double>& y_train);
};

#endif