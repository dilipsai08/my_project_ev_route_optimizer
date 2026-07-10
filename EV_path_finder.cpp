#include "Graph.h"
#include "Dijkstra.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int numCities = 36;
    int numChargingStations = 28;
    int totalNodes = 64;
    Graph g(totalNodes);
    bool default_map = false;
    cout << "Do you want to use the default graph (map)? (y/n): ";
    string response;
    getline(cin, response);

    if (response == "y" || response == "Y")
    {
        default_map = true;
    }
    else if (response == "n" || response == "N")
    {
        default_map = false;
    }
    else
    {
        cout << "invalid input, assuming your comfortable with the current graph " << endl;
        default_map = true;
    }

    if (default_map)
    {
        g.Default_graph();
    }
    else
    {
        // new graph;
        cout << "Enter number of cities: " << endl;
        cin >> numCities;
        cout << "Enter number of charging stations: " << endl;
        cin >> numChargingStations;
        totalNodes = numCities + numChargingStations;
        g = Graph(totalNodes);

        cout << "Enter city names (from index 0 to " << numCities - 1 << "):" << endl;
        for (int i = 0; i < numCities; i++)
        {
            string name;
            cout << " City " << i << ": ";
            getline(cin, name);
            g.addCity(i, name);
        }

        cout << "Enter charging station info (index " << numCities
             << " to " << totalNodes - 1 << "):" << endl;
        for (int i = numCities; i < totalNodes; i++)
        {
            string name;
            double rate;
            cout << "  CS " << i << " name & rate (km added per min): ";
            getline(cin, name);
            cin >> rate;
            cin.ignore();
            g.addCS(i, name, rate);
        }
        int numEdges;
        cout << "\nNumber of edges: ";
        cin >> numEdges;
        cout << "Enter edges (u v distance_km):" << endl;
        for (int i = 0; i < numEdges; i++)
        {
            int u, v, d;
            cin >> u >> v >> d;
            g.addEdge(u, v, d);
        }
    }

    cout << "\n \a Cities" << endl;
    for (int i = 0; i < numCities; i++)
        cout << i << ". " << g.find_node(i) << endl;
    cout << endl;
    cout << "Charging Stations" << endl;
    for (int i = numCities; i < totalNodes; i++)
        cout << i << ". " << g.find_node(i)
             << "  (" << g.findChargeRate(i) << " km/min)" << endl;
    cout << endl;
    int src = -1, dst = -1;
    cout << "Enter the starting city node number from above list ";
    cin >> src;
    cout << "\nEnter the destination city node number from the above list ";
    cin >> dst;
    if (src == -1 || dst == -1)
    {
        cout << "\nCity not found! Please enter exact city node number ." << endl;
        return 1;
    }
    int full_range, current_range;
    double charge_pct;
    cout << "\nEnter full charge range(km) of your EV ";
    cin >> full_range;
    cout << endl;
    cout << "Current battery %% ";
    cin >> charge_pct;
    cout << endl;
    current_range = (int)(charge_pct / 100.0 * full_range);
    if (current_range > full_range)
        current_range = full_range;
    cout << "estimated range " << current_range << " km" << endl;

    double avg_speed = 60.0; // assumed avg speed;
    Dijkstra solver;
    Ans result = solver.modified_dijkstra(g, src, dst, full_range, current_range, avg_speed);

    if (result.path.empty())
    {
        cout << "No route found.";
        return 1;
    }
    vector<int> &path = result.path;
    int totalDist = result.totalDist;
    double totalDriveMin = result.travelTime;
    double totalChargeMin = result.chargeTime;
    double totalTimeMin = totalDriveMin + totalChargeMin;

    // route
    cout << "  Route:\n    ";
    for (int i = 0; i < (int)path.size(); i++)
    {
        if (i > 0 && path[i] == path[i - 1])
            continue;
        if (i > 0)
            cout << " --> ";
        cout << g.find_node(path[i]);
        if (g.check_cs(path[i]))
            cout << " [Charged]";
    }
    cout << "\a" << endl;

    // stats
    cout << fixed << setprecision(1);
    cout << "Driving time: " << totalDriveMin << " min ";
    cout << "Charging time: " << totalChargeMin << " min ";
    cout << "Total journey time: " << totalTimeMin << " min ";
    cout << "Journey distance: " << totalDist << " km ";
    return 0;
}