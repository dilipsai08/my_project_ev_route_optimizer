#include "Graph.h"

Graph::Graph(int totalNodes)
    : totalNodes(totalNodes), adj(totalNodes) {}

// add
void Graph::addCity(int index, string name) {
    nodeNames[index] = name;
}
void Graph::addCS(int index, string name, double rate) {
    nodeNames[index] = name;
    chargingStations.insert(index);
    chargeRate[index] = rate;
}
void Graph::addEdge(int u, int v, int dist) {// bidirectional
    adj[u].push_back({v, dist});
    adj[v].push_back({u, dist});
}

//find
bool Graph::check_cs(int node) const {
    if(chargingStations.count(node)){
        return true;
    }
    return false;
}
string Graph::find_node(int node) const {
    auto name = nodeNames.find(node);
    if(name!=nodeNames.end()){
        return name->second;
    }
    return "-1";
}
double Graph::findChargeRate(int node) const {
    auto it = chargeRate.find(node);
    if (it != chargeRate.end()) return it->second;
    return 0.0;
}
int Graph::findTotalNodes() const {
    return totalNodes;
}
int Graph::findEdge_Wt(int u, int v) const {
    if (u < 0 || u >= totalNodes || v < 0 || v >= totalNodes) return -1;
    for (auto& edge : adj[u]) {
        if (edge.first == v) return edge.second;
    }
    return -1; // no direct edge
}
static const vector<pair<int,int>> empty_neighbors;
const vector<pair<int,int>>& Graph::getNeighbors(int node) const {
    if (node < 0 || node >= totalNodes) return empty_neighbors;
    return adj[node];
}