#include "Dijkstra.h"

Ans Dijkstra::modified_dijkstra(Graph &graph, int src, int dst,
                                        int full_range, int current_range,
                                        double avg_speed)
{
    int n = graph.findTotalNodes();
    vector<vector<bool>> visited(n, vector<bool>(full_range + 1, false));
    auto cmp = [](const State &a, State &b)
    {
        return a.total_time > b.total_time;
    };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp); // min heap
    pq.push({0, 0, 0, 0, src, current_range, {src}});

    while (!pq.empty())
    {
        State cur = pq.top();
        pq.pop();
        if (cur.node == dst)
        {
            return {cur.path, cur.travelTime, cur.chargeTime, cur.totalDist};
        }
        if (cur.range < 0 || cur.range > full_range)
            continue;
        if (visited[cur.node][cur.range])
            continue;
        visited[cur.node][cur.range] = true;

        for (auto &edge : graph.getNeighbors(cur.node))
        {
            int next = edge.first;
            int dist = edge.second;

            if (cur.range >= dist)
            {
                double drive_min = (dist * 60.0) / avg_speed;
                vector<int> new_path = cur.path;
                new_path.push_back(next);

                pq.push({cur.total_time + drive_min, cur.travelTime + drive_min, cur.chargeTime, cur.totalDist + dist, next, cur.range - dist, new_path});
            }
        }
        if (graph.check_cs(cur.node) && cur.range < full_range)
        {
            int need = full_range - cur.range;
            double charge_mins = need / graph.findChargeRate(cur.node);
            pq.push({cur.total_time + charge_mins, cur.travelTime, cur.chargeTime + charge_mins, cur.totalDist, cur.node, full_range, cur.path});
        }
    }
    return {{}, 0.0, 0.0, 0}; // worst case, no route found :-(
}