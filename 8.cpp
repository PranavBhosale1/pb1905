#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include <vector>

using namespace std;

// Function to execute Dijkstra's Algorithm and find the shortest paths
void executeDijkstraAlgorithm(map<int, vector<pair<int, int>>> &graph, vector<int> &parent, vector<int> &distance, int startNode, int numNodes)
{
    // Priority queue to select the edge with the smallest weight first (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode});  // Start from the startNode with weight 0
    distance[startNode] = 0;  // Set distance of starting node to 0

    while (!pq.empty())
    {
        // Extract the node with the smallest edge weight
        pair<int, int> currentNode = pq.top();
        pq.pop();
        int node = currentNode.second;
        int edgeWeight = currentNode.first;

        // Traverse all adjacent nodes (neighbors)
        for (auto &neighbor : graph[node])
        {
            int neighborNode = neighbor.first;
            int weight = neighbor.second;

            // If the current path is shorter than the previously recorded one
            if (distance[node] + weight < distance[neighborNode])
            {
                distance[neighborNode] = distance[node] + weight;
                pq.push({distance[neighborNode], neighborNode});
                parent[neighborNode] = node;  // Update the parent of the neighbor node
            }
        }
    }

    // Output the shortest path for each node from the startNode
    for (int i = 0; i < numNodes; ++i)
    {
        if (distance[i] == INT_MAX)
            cout << "Node " << i << " is unreachable from node " << startNode << endl;
        else
            cout << "Distance from node " << startNode << " to node " << i << " is " << distance[i] << endl;
    }
}

// Function to display the menu and handle user input
void displayMenu()
{
    int choice, numNodes, numEdges, startNode, endNode, edgeWeight;
    map<int, vector<pair<int, int>>> graph;  // Map to store the graph (adjacency list)
    vector<int> parent;   // Vector to store the parent of each node in the shortest path tree
    vector<int> distance;  // Vector to store the shortest distance to each node

    while (true)
    {
        // Display the main menu options
        cout << "\nMenu:\n";
        cout << "1. Input graph\n";
        cout << "2. Execute Dijkstra's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Input graph (number of nodes, edges, and their weights)
            cout << "Enter the number of nodes: ";
            cin >> numNodes;

            // Initialize vectors for Dijkstra's algorithm
            graph.clear();  // Clear any previous graph data
            parent.assign(numNodes, -1);  // Initialize parent of each node to -1 (no parent)
            distance.assign(numNodes, INT_MAX);  // Initialize distance to INF

            cout << "Enter the number of edges: ";
            cin >> numEdges;

            // Input edges (start node, end node, and edge weight)
            for (int i = 0; i < numEdges; i++)
            {
                cout << "Enter edge (startNode endNode weight): ";
                cin >> startNode >> endNode >> edgeWeight;
                graph[startNode].push_back({endNode, edgeWeight});  // Add edge to adjacency list
                // No need for reverse edge as the graph is directed
            }
            break;

        case 2:
            // If no graph is available, prompt user to input a graph first
            if (graph.empty())
            {
                cout << "No graph is available. Please input a graph first.\n";
                break;
            }

            // Get the start node for Dijkstra's algorithm
            cout << "Enter the start node for Dijkstra's Algorithm: ";
            cin >> startNode;

            // Run Dijkstra's Algorithm to find the shortest paths
            executeDijkstraAlgorithm(graph, parent, distance, startNode, numNodes);
            break;

        case 3:
            // Exit the program
            cout << "Exiting the program.\n";
            return;

        default:
            // Handle invalid menu choice
            cout << "Invalid choice! Please try again.\n";
        }
    }
}

// Main function that starts the program
int main()
{
    displayMenu();  // Call the displayMenu function to begin the program
    return 0;
}
