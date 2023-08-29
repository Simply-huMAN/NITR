// Uniform Cost Search
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
map<pair<int, int>, int> cost;

vector<int> uniform_cost_search(vector<int> goal, int start){
	vector<int> answer;
	priority_queue<pair<int, int> > queue;

	for (int i = 0; i < goal.size(); i++) answer.push_back(INT_MAX);

	queue.push(make_pair(0, start));
	map<int, int> visited;
	int count = 0;

	while (queue.size() > 0) {
		pair<int, int> p = queue.top();
		queue.pop();
		// get the original value
		p.first *= -1;
		// check if the element is part of the goal list
		if (find(goal.begin(), goal.end(), p.second) != goal.end()) {
			int index = find(goal.begin(), goal.end(),p.second) - goal.begin();

			// if a new goal is reached
			if (answer[index] == INT_MAX) count++;

			// if the cost is less
			if (answer[index] > p.first) answer[index] = p.first;
			queue.pop();

			if (count == goal.size()) return answer;
		}

		// check for the adjacent non visited nodes
		if (visited[p.second] == 0)
			for (int i = 0; i < graph[p.second].size(); i++) {
				queue.push(make_pair((p.first + cost[make_pair(p.second, graph[p.second][i])]) * -1,graph[p.second][i]));
			}
		visited[p.second] = 1;
	}
	return answer;
}

// main function
int main(){
	// create the graph
	graph.resize(7);
    // A B C D E F G H  -> GOAL IS G
    // 0 1 2 3 4 5 6 7
    // 0 - 1 5
    // 0 - 3 6
    // 1 - 2 1
    // 1 - 4 2
    // 2 - 5 3
    // 3 - 4 5
    // 4 - 5 4
    // 3 - 6 5
    // 4 - 6 3
    // 5 - 6 7
    // 5 - 7 1
    // 7 - 6 1
	graph[0].push_back(1);
	graph[0].push_back(3);
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(5);
	graph[3].push_back(4);
	graph[3].push_back(6);
	graph[4].push_back(5);
	graph[4].push_back(6);
	graph[5].push_back(6);
	graph[5].push_back(7);
	graph[7].push_back(6);

	// add the cost
    cost[{0, 1}] = 5;
	cost[{0, 3}] = 6;
	cost[{1, 2}] = 1;
	cost[{1, 4}] = 2;
	cost[{2, 5}] = 3;
	cost[{3, 4}] = 5;
	cost[{3, 6}] = 5;
	cost[{4, 5}] = 4;
	cost[{4, 6}] = 3;
	cost[{5, 6}] = 7;
	cost[{5, 7}] = 1;
	cost[{7, 6}] = 1;

	// goal state
	vector<int> goal;
	goal.push_back(6);

	vector<int> answer = uniform_cost_search(goal, 0);
	cout << "Minimum cost from 0 to 6 is = " << answer[0] << endl;
	return 0;
}
