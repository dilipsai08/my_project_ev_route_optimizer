#pragma once
#include "Graph.h"
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Ans {
    vector<int> path;
    double travelTime;
    double chargeTime;
    int totalDist;
};
struct State {
    double total_time;// travel + charging in min
    double travelTime; // in min
    double chargeTime; // in min
    int totalDist;     // in km
    int node; // current node
    int range; // rem range in km
    vector<int> path; // travelled path
};

class Dijkstra {
public:
    Ans modified_dijkstra(Graph& graph, int src, int dst,
                                   int full_range, int current_range,
                                   double avg_speed);
};