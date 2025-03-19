#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;


class Graph {
	unordered_map<string, vector<string>> graph;
	

public:
	void printGraph(const string& vertex) const {
		if (graph.empty()) {
			cout << "Graph is empty!\n";
			return;
		}
		
		
		if (graph.find(vertex) == graph.end()) {
			cout << "Vertex " << vertex << " doesn't exist!\n";
			return;
		}
		unordered_map<string, bool> visited;
		deque<string> queue;

		queue.push_back(vertex);
		visited[vertex] = true;

		while (!queue.empty()) {
			string current = queue.front();
			queue.pop_front();
			cout << current << " -> ";

			for (const string& neighbor : graph.at(current)) {
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					queue.push_back(neighbor);
					cout << neighbor << ' ';
				}
			}
			cout << '\n';
		}
	}


	void addVertex(string name, initializer_list<string> list) {

		if (name.empty()) {
			cout << "Vertex must have a name!\n";
			return;
		}
		if (list.begin() == list.end()) {
			cout << "Vertex must be connected!\n";
			return;
		}
		if (!(graph.find(name) == graph.end())) {
			cout << "Vertex" << name << "already exists! Updating connections...\n";
			graph[name] = list;
			return;
		}
		graph[name] = list;
	}
	void removeVertex(const string& name) {
		if (graph.find(name) == graph.end()) {
			cout << "Vertex " << name << " doesn't exist!\n";
			return;
		}

		graph.erase(name);

		for (auto& pair : graph) {
			auto& neighbors = pair.second;
			neighbors.erase(remove(neighbors.begin(), neighbors.end(), name), neighbors.end());
		}

		cout << "Vertex " << name << " removed.\n";
	}
};


int main() {
	Graph g;
	

	/*  .---------------------------------------------------- - .
		|  | > "We Don't Have To Dance" - Andy Black            |
		|  ---------------------------------------------------- |
		|  |█████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░|
		|  0:58 / 3:14                                          |
		'-------------------------------------------------------'
		
		We don't have to talk
		We don't have to dance
		We don't have to smile
		We don't have to make friends
		It's so nice to meet you
		Let's never meet again
		
		*/

	return 0;
}