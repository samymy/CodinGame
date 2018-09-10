#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
class Graph {
    
    vector<int> vertices;
    int**       adjacency_matrix;

public:
    Graph(vector<int> _vertices) {
        
        vertices = _vertices;
        
        adjacency_matrix = new int*[vertices.size()];
        
        for (int i = 0; i < vertices.size(); i++)
            adjacency_matrix[i] = new int[vertices.size()];
            
        for (int i = 0; i < vertices.size(); i++)
            for (int j = 0; j < vertices.size(); j++)
                adjacency_matrix[i][j] = 0;
    }
    
    ~Graph() {
        
        for (int i = 0; i < vertices.size(); i++)
            delete [] adjacency_matrix[i];
        delete [] adjacency_matrix;
    }
    
    void        addLink(int from, int to) {
        
        adjacency_matrix[from][to] = adjacency_matrix[to][from] = 1;
    }
    
    list<int>   BFS(int from, int to) {
        
        queue<int>  queue;
        bool        visited[vertices.size()];
        int         parents[vertices.size()];
        
        for (int i = 0; i < vertices.size(); i++) {
            visited[i] = 0;
            parents[i] = -1;
        }
            
        queue.push(from);
        visited[from] = true;
        
        while (!queue.empty()) {
            
            int     curr = queue.front();
            queue.pop();
            
            for (int i = 0; i < vertices.size(); i++)
                if (adjacency_matrix[curr][i] && !visited[i]) {
                    queue.push(i);
                    visited[i] = true;
                    parents[i] = curr;
                }
        }
        
        list<int>   path;
        path.push_front(to);
        while (parents[to] != -1) {
            path.push_front(parents[to]);
            to = parents[to];
        }
        
        return path;
    }
    
    
};
 
int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    
    vector<int>     vertices;
    
    for (int i = 0; i < N; i++)
        vertices.push_back(i);
        
    Graph   graph(vertices);
    
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        
        graph.addLink(N1, N2);
    }
    
    vector<int>     gateways;
    
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        
        gateways.push_back(EI);
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        vector<list<int>>   paths;
        
        for (auto gateway : gateways)
            paths.push_back(graph.BFS(SI, gateway));
            
        list<int>   min_path = *min_element(paths.begin(), paths.end(),
            [](const list<int>& a, const list<int>& b) {
                return a.size() < b.size();
            }
        );
    
        cout << *min_path.begin() << " " << *++min_path.begin() << endl;

        // Example: 0 1 are the indices of the nodes you wish to sever the link between
    }
}
