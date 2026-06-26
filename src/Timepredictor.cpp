#include "../include/TimePredictor.h"
#include <vector>
#include <iostream>
using namespace std;
TimePredictor::TimePredictor(double learingRate, int graditrate)
{
    bias = 0;
    this->graditrate=graditrate;
    this->learingRate=learingRate;
    weights.resize(FEATURECOUNT, 0.0);
}

vector<double> TimePredictor::getFeatures(Task &task, StudentProfile &student)
{
    vector<double> features;
    features.push_back(task.getDifficulty());
    features.push_back(task.getImportance());
    features.push_back(task.getStudentEstimatedTime());
    features.push_back(task.getPagesOrQuestions());
    features.push_back(task.getTaskTypeWeight());
    features.push_back(student.getFocusScore());
    features.push_back(student.getCompletionRate());
    return features;
}

double TimePredictor::dotProduct(vector<double>&weights, vector<double>&features )
{
    double ans = 0.0;
    for (int i = 0; i < FEATURECOUNT; i++)
    {
        ans += weights[i] * features[i];
    }
    return ans;
}

double TimePredictor::predict(vector<double> &features)
{
    double pred =dotProduct(weights,features)+bias;
    return pred;
}

void TimePredictor::train(vector<vector<double>>& X_train, vector<double>& y_train)
{
    int n = X_train.size();
    for(int i =1; i<=graditrate;i++)
    {
        vector<double>gradW(FEATURECOUNT);
        double gradBias =0.0; 
        for(int j = 0 ; j <n;j++)
        {
            double pred =predict(X_train[j]);
            double error =pred-y_train[j];
            for(int k =0; k <FEATURECOUNT;k++)
            {
                gradW[k]+=error*X_train[j][k];
            }
            gradBias +=error;   
        }
        for(int k =0; k <FEATURECOUNT;k++)
        {
            weights[k]-=gradW[k]*(learingRate/n);
        }
        bias-=gradBias*(learingRate/n);
    }
}
void TimePredictor::predictTime(Task& task,  StudentProfile& student)
{
vector<double> features = getFeatures(task, student);

    task.setPredictedDuration(predict(features));
}