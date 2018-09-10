#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

class Graph {

    vector<int> vertices;
    int**       adjacency_matrix;
    int**       weighting_matrix;

public:
    Graph(const vector<int>& _vertices): vertices(_vertices) {
        
        adjacency_matrix = new int*[vertices.size()];
        for (int i = 0; i < vertices.size(); i++)
            adjacency_matrix[i] = new int[vertices.size()];

        for (int i = 0; i < vertices.size(); i++)
            for (int j = 0; j < vertices.size(); j++)
                adjacency_matrix[i][j] = 0;
    }
    
    ~Graph() {
    
        for (int i = 0; i < vertices.size(); i++)
            delete[] adjacency_matrix[i];
        delete[] adjacency_matrix;
    }
    
    void            addEdge(int from, int to) {
        
        adjacency_matrix[from][to] = adjacency_matrix[to][from] = 1;
    }
    
    void            deleteEdge(int from, int to) {
        
        adjacency_matrix[from][to] = adjacency_matrix[to][from] = 0;
    }
    
    list<int>     findShortestPath(int from, int to) const {
        
        queue<int>  queue;
        bool        visited[vertices.size()];
        int         parents[vertices.size()];
        
        for (int i = 0; i < vertices.size(); i++) {
            visited[i] = false;
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
        
        list<int>     shortest_path;
        
        if (parents[to] != -1)
            shortest_path.push_front(to);
        while (parents[to] != -1) {
            shortest_path.push_front(parents[to]);
            to = parents[to];
        }
        
        return shortest_path;
    }
    
    int   getPathNumber(int from, int to) {
        
        int         path_number = 0;
        queue<int>  deleted_from;
        queue<int>  deleted_to;
        
        while (true) {
            list<int>   tmp_path = findShortestPath(from, to);
            if (tmp_path.size()) {
                ++path_number;
                deleteEdge(*++tmp_path.rbegin(), *tmp_path.rbegin());
                deleted_from.push(*++tmp_path.rbegin());
                deleted_to.push(*tmp_path.rbegin());
            }
            else
                break;
        }
        
        while (!deleted_from.empty() && !deleted_to.empty()) {
            addEdge(deleted_from.front(), deleted_to.front());
            deleted_from.pop();
            deleted_to.pop();
        }
        
        return path_number;
    }
    
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
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
        graph.addEdge(N1, N2);
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
        
        for (auto gateway : gateways) {
            list<int> tmp_path = graph.findShortestPath(SI, gateway);
            if (tmp_path.size())
                paths.push_back(tmp_path);
        }
        
        const list<int>&   path = *min_element(paths.begin(), paths.end(),
            [](const list<int>& a, const list<int>& b){
                return a.size() < b.size();
            }
        );
        
        graph.deleteEdge(*++path.rbegin(), *path.rbegin());

        // list<int>   path;
        // int         max = 0;
        // for (auto gateway : gateways) {
        //     int tmp = graph.getPathNumber(SI, gateway);
        //     cerr << tmp << endl;
        //     if (tmp > max) {
        //         max = tmp;
        //         path = graph.findShortestPath(SI, gateway);
        //     }
        // }
        
        // graph.deleteEdge(*++path.rbegin(), *path.rbegin());
        
        cout << *++path.rbegin() << " " << *path.rbegin() << endl;
    }
}
