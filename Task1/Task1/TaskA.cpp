#include <iostream>
#include <fstream>
#include "TaskA.h"

using namespace std;

float TaskA::function(float x)
{
	float number = x;
	float f = 2 * x + 2;

	return f;
}

float derivative(float x) {
    return 2;
}

vector<Vertex> TaskA::redOrGreen(float lower, float upper)
{
    vector < Vertex > Derivativedata;
    vector<Vertex> colour;

    ofstream outfile("RedOrGreen.txt");
    ofstream vertexData("VertexData.txt");

    int countlines = 0;

    float resolution = 1.f;
    float n = (upper - lower) / resolution;
    float h = (upper - lower) / n;

    vector<Vertex> functionValues;
    for (float i = lower; i < upper; i+=h)
    {
        float f = 2 * i + 2;
        functionValues.push_back(Vertex{ i, f, 0 });
        Derivativedata.push_back(Vertex{ i, derivative(i),0 });
    }

    for (float i = 0; i < functionValues.size() - 1; i++) {
        float f = 2 * i + 2;
        if (functionValues[i].y < functionValues[i + 1].y) {
            cout << "Interval " << i << " is increasing (green)." << endl;
            outfile << "Interval " << i << " is increasing (green)." << endl;
            colour.push_back(Vertex{ functionValues[i].x/10, functionValues[i].y/10, 0, 0, 1, 0 });
        }
        else {
            cout << "Interval " << i << " is decreasing (red)." << endl;
            outfile << "Interval " << i << " is decreasing (red)." << endl;
            colour.push_back(Vertex{ functionValues[i].x/10, functionValues[i].y/10, 0, 1, 0, 0});
        }

        vertexData << colour[i].x << " " << colour[i].y << " " << colour[i].z << " " << colour[i].r << " " << colour[i].g << " " << colour[i].b << endl;
        countlines++;

    }

    outfile.close();
    vertexData.close();

    ifstream tempfile("vertexData.txt");
    ofstream finalfile("Data.txt");

    finalfile << "Line count: " << countlines << endl;
    finalfile << tempfile.rdbuf();

    tempfile.close();
    finalfile.close();
    remove("vertexData.txt");

    return colour;
}
