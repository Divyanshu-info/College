#include <iostream>
#include <limits>
#include <ostream>
using namespace std;

#define MAXV 1000

class EdgeNode {
public:
  int key;
  int weight;
  EdgeNode *next;
  EdgeNode(int key, int weight) {
    this->key = key;
    this->weight = weight;
    this->next = NULL;
  }
};

class Graph {
  bool directed;

public:
  EdgeNode *edges[MAXV + 1];
  Graph(bool directed) {
    this->directed = directed;
    for (int i = 1; i < (MAXV + 1); i++) {
      this->edges[i] = NULL;
    }
  }
  ~Graph() {}
  void insert_edge(int x, int y, int weight, bool directed) {
    if (x > 0 && x < (MAXV + 1) && y > 0 && y < (MAXV + 1)) {
      EdgeNode *edge = new EdgeNode(y, weight);
      edge->next = this->edges[x];
      this->edges[x] = edge;
      if (!directed) {
        insert_edge(y, x, weight, true);
      }
    }
  }

  void print() {
    for (int v = 1; v < (MAXV + 1); v++) {
      if (this->edges[v] != NULL) {
        cout << "Vertex " << v << " has neighbors: " << endl;
        EdgeNode *curr = this->edges[v];
        while (curr != NULL) {
          cout << curr->key << endl;
          curr = curr->next;
        }
      }
    }
  }
};

void init_vars(bool discovered[], int distance[], int parent[]) {
  for (int i = 1; i < (MAXV + 1); i++) {
    discovered[i] = false;
    distance[i] = std::numeric_limits<int>::max();
    parent[i] = -1;
  }
}

void dijkstra_shortest_path(Graph *g, int parent[], int distance[], int start) {

  bool discovered[MAXV + 1];
  EdgeNode *curr;
  int v_curr;
  int v_neighbor;
  int weight;
  int smallest_dist;

  init_vars(discovered, distance, parent);

  distance[start] = 0;
  v_curr = start;

  while (discovered[v_curr] == false) {

    discovered[v_curr] = true;
    curr = g->edges[v_curr];

    while (curr != NULL) {

      v_neighbor = curr->key;
      weight = curr->weight;

      if ((distance[v_curr] + weight) < distance[v_neighbor]) {
        distance[v_neighbor] = distance[v_curr] + weight;
        parent[v_neighbor] = v_curr;
      }
      curr = curr->next;
    }

    smallest_dist = std::numeric_limits<int>::max();
    for (int i = 1; i < (MAXV + 1); i++) {
      if (!discovered[i] && (distance[i] < smallest_dist)) {
        v_curr = i;
        smallest_dist = distance[i];
      }
    }
  }
}

void print_shortest_path(int v, int parent[]) {
  if (v > 0 && v < (MAXV + 1) && parent[v] != -1) {
    cout << "->" << parent[v];
    print_shortest_path(parent[v], parent);
  }
}
void print_shortest_path_from(int v, int parent[]) {
  cout << "Shortest path from " << v << " to starting node is : ";
  cout << v;
  print_shortest_path(v, parent);
  cout << endl;
}

void print_distances(int start, int distance[]) {
  for (int i = 1; i < (MAXV + 1); i++) {
    if (distance[i] != std::numeric_limits<int>::max()) {
      cout << "Shortest distance from " << start << " to " << i
           << " is: " << distance[i] << endl;
    }
  }
}

int main() {

  Graph *g = new Graph(false);
  int n, tmp = 5;
  int parent[MAXV + 1];
  int distance[MAXV + 1];
  int start = 1;

  cout<<"Input No. of Nodes : ";
  cin >> n;
  cout << "Input Node Values :\n(parent_node(int) child_node(int) weight(int) directed(0/1)\n";
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a>>b>>c>>d;
    g->insert_edge(a, b, c, d);
  }
  cout<<"Input Starting Node : ";
  cin >> start;
  
  // g->insert_edge(1, 2, 4, false);
  // g->insert_edge(1, 3, 1, false);
  // g->insert_edge(3, 2, 1, false);
  // g->insert_edge(3, 4, 5, false);
  // g->insert_edge(2, 4, 3, false);
  // g->insert_edge(2, 5, 1, false);
  // g->insert_edge(4, 5, 2, false);

  dijkstra_shortest_path(g, parent, distance, start);

  //print shortest path from vertex 5 to 1
  cout << "Enter the node to find the shortest path from : ";
  cin >> tmp;
  cout<< endl;
  
  print_shortest_path_from(tmp, parent);
  print_distances(start, distance);

  delete g;
  return 0;
}
