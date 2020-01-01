#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

template <typename T>
class Graph{

	unordered_map<T,list<T> > AdjList;
public:
	Graph(){}

	void addEdge(T u,T v,bool birdir = true){

		AdjList[u].push_back(v);

		if(birdir){
			AdjList[v].push_back(u);
		}
	}

	void display(){
		for(auto node:AdjList){
			cout<<node.first<<" -> ";

			for(T vertex:node.second){
				cout<<vertex<<", ";
			}
			cout<<endl;
		}
	}

	void bfs(T src){
		queue<T> q;
		unordered_map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){

			T node = q.front();
			q.pop();

			cout<<node<<" ";

			for(T neighbor:AdjList[node]){
				if(!visited[neighbor]){
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}

		}

		cout<<endl;
	}

	void dfs_Helper(T node,unordered_map<T,bool> &visited){

		cout<<node<<" ";
		visited[node] = true;

		for(T neighbor:AdjList[node]){
			if(!visited[neighbor]){
				dfs_Helper(neighbor,visited);
			}
		}

	}

	void dfs(T src){

		unordered_map<T,bool> visited;
		// visited[src] = true;

		int component = 0;

		for(auto node:AdjList){
			if(!visited[node.first]){
				dfs_Helper(node.first,visited);
				cout<<endl;
				component++;
			}
		}
		
		cout<<"Number of component "<<component<<endl;
	}

	void dfsTopologicalSortHelper(T node,unordered_map<T,bool> &visited,list<T> &order){

		visited[node] = true;

		for(T neighbor:AdjList[node]){
			if(!visited[neighbor]){
				dfsTopologicalSortHelper(neighbor,visited,order);
			}
		}

		order.push_front(node);
	}

	void dfsTopologicalSort(T src){
		unordered_map<T,bool> visited;
		list<T> order;

		dfsTopologicalSortHelper(src,visited,order);

		for(auto node:AdjList){
			if(!visited[node.first]){
				dfsTopologicalSortHelper(node.first,visited,order);
			}
		}

		for(T node:order){
			cout<<node<<" ";
		}
		cout<<endl;
	}

	// int No_of_pair_Not_connected(){
	// 	unordered_map<T, bool> visited;
	// 	int countALL = 0;
	// 	vector<int> seperate;
	// 	for(auto node: AdjList){
			
	// 	}

	// }

};

int main(){

	// Graph<int> g;

	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(3,2);
	// // g.addEdge(3,2);

	// g.addEdge(4,5);
	// g.addEdge(6,5);
	// g.addEdge(7,5);


	// g.display();

	// // g.bfs(1);
	// g.dfs(1);

	// Graph<string> g;

	// g.addEdge("Coding Blocks","C++");
	// g.addEdge("C++","Java");
	// g.addEdge("Java","Python");
	// g.addEdge("Python","Coding Blocks");

	// g.display();

	Graph<string> g;

	g.addEdge("Maths","Programming",false);
	g.addEdge("English","Programming",false);
	g.addEdge("Programming","Python",false);
	g.addEdge("Programming","Java",false);
	g.addEdge("Java","Web",false);
	g.addEdge("Python","Web",false);

	g.dfsTopologicalSort("Maths");
	return 0;
}