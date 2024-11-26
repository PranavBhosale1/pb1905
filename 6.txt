#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include <vector>

using namespace std;

// Function to execute Prim's Algorithm and find the Minimum Spanning Tree (MST)
void executePrimsAlgorithm(vector<bool> &inMST, vector<int> &parent, vector<int> &minDistance, map<int, vector<pair<int, int>>> &graph, int numNodes)
{
    // Priority queue to select the edge with the smallest weight first (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  // Start from node 0 with weight 0
    minDistance[0] = 0;  // Set distance of starting node to 0

    while (!pq.empty())
    {
        // Extract the node with the smallest edge weight
        pair<int, int> currentNode = pq.top();
        pq.pop();
        int node = currentNode.second;
        int edgeWeight = currentNode.first;

        if (inMST[node]) continue;  // Skip if node is already in MST (Minimum Spanning Tree)

        inMST[node] = true;  // Include node in MST

        // Traverse all adjacent nodes (neighbors)
        for (auto &neighbor : graph[node])
        {
            int neighborNode = neighbor.first;
            int weight = neighbor.second;

            // If the neighbor node is not in MST and the edge weight is smaller than the current minimum distance
            if (!inMST[neighborNode] && weight < minDistance[neighborNode])
            {
                pq.push({weight, neighborNode});  // Add neighbor to priority queue with new edge weight
                parent[neighborNode] = node;  // Update the parent of the neighbor node
                minDistance[neighborNode] = weight;  // Update the minimum distance for the neighbor node
            }
        }
    }

    // Output the MST edges and calculate the total cost
    int totalCost = 0;
    for (int i = 1; i < numNodes; ++i)  // Start from node 1 (0 is the root)
    {
        cout << "Edge: " << parent[i] << " - " << i << " with weight " << minDistance[i] << endl;
        totalCost += minDistance[i];  // Accumulate the total cost of the MST
    }
    cout << "Total cost of MST: " << totalCost << endl;  // Output total cost of MST
}

// Function to display the menu and handle user input
void displayMenu()
{
    int choice, numNodes, numEdges, startNode, endNode, edgeWeight;
    map<int, vector<pair<int, int>>> graph;  // Map to store the graph (adjacency list)
    vector<bool> inMST;   // Vector to track nodes included in MST
    vector<int> parent;   // Vector to store the parent of each node in the MST
    vector<int> minDistance;  // Vector to store the minimum distance to each node from MST

    while (true)
    {
        // Display the main menu options
        cout << "\nMenu:\n";
        cout << "1. Input graph\n";
        cout << "2. Execute Prim's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Input graph (number of nodes, edges, and their weights)
            cout << "Enter the number of nodes: ";
            cin >> numNodes;

            // Initialize vectors for MST (inMST), parent, and minimum distance
            graph.clear();  // Clear any previous graph data
            inMST.resize(numNodes, false);  // Initialize all nodes as not in MST
            parent.resize(numNodes, -1);  // Initialize parent of each node to -1 (no parent)
            minDistance.resize(numNodes, INT_MAX);  // Initialize minimum distance to INF

            cout << "Enter the number of edges: ";
            cin >> numEdges;

            // Input edges (start node, end node, and edge weight)
            for (int i = 0; i < numEdges; i++)
            {
                cout << "Enter edge (startNode endNode weight): ";
                cin >> startNode >> endNode >> edgeWeight;
                graph[startNode].push_back({endNode, edgeWeight});  // Add edge to adjacency list
                graph[endNode].push_back({startNode, edgeWeight});  // Add reverse edge for undirected graph
            }
            break;

        case 2:
            // If no graph is available, prompt user to input a graph first
            if (graph.empty())
            {
                cout << "No graph is available. Please input a graph first.\n";
                break;
            }

            // Run Prim's Algorithm to find the MST
            minDistance[0] = 0;  // Start Prim's algorithm from node 0
            executePrimsAlgorithm(inMST, parent, minDistance, graph, numNodes);
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
