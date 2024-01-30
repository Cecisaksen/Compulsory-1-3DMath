#include <iostream>
#include <fstream>
#include "TaskA.h"

using namespace std;

double TaskA::function(double x)
{
	double number = x;
	double f = 2 * x + 2;

	cout << "f(" << number << ") = " << f << endl;
	return 0.0;
}

vector<float> TaskA::interval(float a, float b, int numPoints)
{
    vector<float> vertices;

    float step = (b - a) / numPoints;
    for (float i = a; i <= b; i += step) {
        double f = 2 * i + 2;
        cout << "Interval " << i << " is " << f << endl;
        vertices.push_back(i);
        vertices.push_back(static_cast<float>(f));
    }

	return vertices;
}

vector<float> TaskA::redOrGreen(int x)
{
    vector<float> colour;

    vector<float> functionValues;
    for (int i = 0; i < x; i++) {
        double f = 2 * i + 2;
        functionValues.push_back(static_cast<float>(f));
    }

    for (size_t i = 0; i < functionValues.size() - 1; i++) {
        if (functionValues[i] < functionValues[i + 1]) {
            cout << "Interval " << i << " is increasing (green)." << endl;
        }
        else {
            cout << "Interval " << i << " is decreasing (red)." << endl;
        }
    }

    return colour;
}
