#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
private:
    int totalNodes; // cities + charging stations
    vector<vector<pair<int,int>>> adj;// v, dist
    unordered_map<int, string> nodeNames;// key--> node id, value : city name or CS name
    unordered_set<int> chargingStations; //cs
    unordered_map<int, double> chargeRate;// CS_index -> km added per min

public:
    Graph(int totalNodes);
    void Default_graph();
    //add
    void addCity(int index, string name);
    void addCS(int index, string name, double rate);
    void addEdge(int u, int v, int dist); 

    //find
    bool check_cs(int node) const;
    string find_node(int node) const;
    double findChargeRate(int node) const;
    int findTotalNodes() const;
    int findEdge_Wt(int u, int v) const;
    const vector<pair<int,int>>& getNeighbors(int node) const;
};
