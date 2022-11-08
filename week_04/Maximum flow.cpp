#include <iostream>
#include <vector>
#include <queue>

int Ford_Fulkerson(int source, int target, int n, std::vector<std::vector<int> >& graph);
void addEdge(std::vector<std::vector<int> >& graph, int u, int v, int w);
int main()
{
	// initialize
	// input line 1: The number of nodes/vertices V in the network
	int n_Ver;
	std::cin >> n_Ver;

	// input line 2: The number of edges of E in the network.
	int n_Edges;
	std::cin >> n_Edges;

	// input line3: (source, target, capacity)
	std::vector<std::vector<int> > Flow(n_Edges, std::vector<int>(3, 0));
	for (int i = 0; i < n_Edges; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> Flow[i][j];
		}
	}

	std::vector<std::vector<int> > graph(n_Ver, std::vector<int>(n_Ver, 0));

	// Adding edges weight in the graph
	for (int i = 0; i < n_Edges; i++)
	{
		addEdge(graph, Flow[i][0], Flow[i][1], Flow[i][2]);
	}

	// output
	std::cout << Ford_Fulkerson(0, 1, n_Ver, graph) << std::endl;

	return 0;

}

void addEdge(std::vector<std::vector<int> >& graph, int u, int v, int w)
{
	graph[u][v] = w;
}

int bfs(int source, int target, int n, std::vector<int>& parent, std::vector<std::vector<int>>& graph) {
	//Update the parent vector as each node value to be -1
	fill(parent.begin(), parent.end(), -1);
	//parent of source node to be -2
	parent[source] = -2;
	//Initializing queue for storing and min capacity so far
	std::queue<std::pair<int, int>> q;
	//Source node min capacity to be 1e9
	q.push({ source,1e9 });

	//Looping while queue is not empty 
	while (!q.empty()) {
		//storing top node and min capacity so far
		int u = q.front().first;
		int cap = q.front().second;
		//Removing top node from queue
		q.pop();
		//Looping all edges from u
		for (int v = 0; v < n; v++) {
			//finding v node has edge from u
			if (u != v && graph[u][v] != 0 && parent[v] == -1) {
				//storing parent v to be u
				parent[v] = u;
				//Updating the minimum capacity
				int min_cap = std::min(cap, graph[u][v]);
				//If v is the target node then return minimum capacity
				if (v == target) {
					return min_cap;
				}
				//if we didn't find target node
				//Insert the v node and minimum capacity so far in queue
				q.push({ v,min_cap });
			}
		}
	}
	//if we didn't find path between source to target return 0
	return 0;
}


int Ford_Fulkerson(int source, int target, int n, std::vector<std::vector<int> >& graph)
{
	// creater vector for finding the path from source to the target
	std::vector<int> parent(n, -1);
	int max_flow = 0;
	int min_cap = 0;

	while (min_cap = bfs(source, target, n, parent, graph))
	{
		// adding the min_cap from this path
		max_flow += min_cap;
		//sorting target node in v
		int v_target = target;

		while (v_target != source)
		{
			// finding parent of v_target node
			int u_source = parent[v_target];

			// substracting minimum capacity from u_source to v_target
			// and adding minimum capacity from v_target to u_source
			graph[u_source][v_target] -= min_cap;
			graph[v_target][u_source] += min_cap;

			// update
			v_target = u_source;
		}

	}
	return max_flow;

}
