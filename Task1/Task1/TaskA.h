#pragma once
#include <vector>

using namespace std;

struct Vertex {
	float x, y, z, r, g, b, u, v;
};

class TaskA
{
public:

	float function(float x);
	//vector<Vertex>interval(float a, float b, int numPoints);
	vector<Vertex>redOrGreen(float lower, float upper);


};

