#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to find the representative of a set (with path compression)
int findParent(int node, vector<int> &parent)
{
    if (parent[node] != node)
    {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

// Function to union two sets based on rank (union by rank)
void unionSets(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV)
    {
        // Union by rank: attach the smaller tree under the root of the larger tree
        if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Function to execute Kruskal's Algorithm and find the Minimum Spanning Tree (MST)
void executeKruskalAlgorithm(vector<vector<int>> &edges, int numNodes)
{
    vector<int> parent(numNodes);
    vector<int> rank(numNodes, 0);
    int mstCost = 0;

    // Initially, each node is its own parent
    for (int i = 0; i < numNodes; ++i)
    {
        parent[i] = i;
    }

    // Sort edges by their weight (ascending order)
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];  // Compare by edge weight
    });

    // Process each edge and include it in the MST if it doesn't form a cycle
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // If the nodes are not in the same set, include the edge in the MST
        if (findParent(u, parent) != findParent(v, parent))
        {
            unionSets(u, v, parent, rank);
            cout << "Edge: " << u << " - " << v << " with weight " << weight << endl;
            mstCost += weight;  // Accumulate the total cost of the MST
        }
    }

    cout << "Total cost of MST: " << mstCost << endl;
}

// Function to display the menu and handle user input
void displayMenu()
{
    int choice, numNodes, numEdges, startNode, endNode, edgeWeight;
    vector<vector<int>> edges;  // Vector to store the edges (startNode, endNode, weight)

    while (true)
    {
        // Display the main menu options
        cout << "\nMenu:\n";
        cout << "1. Input graph\n";
        cout << "2. Execute Kruskal's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Input graph (number of nodes, edges, and their weights)
            cout << "Enter the number of nodes: ";
            cin >> numNodes;

            cout << "Enter the number of edges: ";
            cin >> numEdges;

            // Input edges (start node, end node, and edge weight)
            edges.clear();  // Clear any previous edges data
            for (int i = 0; i < numEdges; i++)
            {
                cout << "Enter edge (startNode endNode weight): ";
                cin >> startNode >> endNode >> edgeWeight;
                edges.push_back({startNode, endNode, edgeWeight});  // Add edge to the list
            }
            break;

        case 2:
            // If no edges are available, prompt user to input a graph first
            if (edges.empty())
            {
                cout << "No graph is available. Please input a graph first.\n";
                break;
            }

            // Run Kruskal's Algorithm to find the MST
            executeKruskalAlgorithm(edges, numNodes);
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
