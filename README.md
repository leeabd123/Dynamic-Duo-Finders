** Leading Question ** 
Some of the most important problems are the ones we face every day.  For the residents of Oldenburg, this includes driving around the city to get from place to place. The overarching question is, what is the best way to get around the city? This is a very broad question, but we can split it into sub-questions that we can answer with our graph algorithms. Namely:
What is the shortest way from one place to another?
What is likely to be the busiest intersection?
What is one way to explore the city and drive through the entire city?
We have data with Nodes for different points in Oldenburg.  Each node contains an ID and an x and y coordinate. We also have data for the edges (roads) connecting them, each of which has a starting node id, ending node id, and distance between. The distance between can be used to determine the weights of the edges. With that, we can solve the first question using Dijkstra’s Algorithm, we can solve the second using the betweenness centrality algorithm, and we can use DFS for the third.

** Dataset Acquisition **

** Data Format **
We used the City of Oldenburg Road Network from the Real Datasets for Spatial Databases: Road Networks and Points of Interest (https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm). Our dataset has 2 CSV’s one for Oldenburgs Network's Nodes that is 6105 lines long with a line for each node, made up of Node ID, Normalized X Coordinate, Normalized Y Coordinate, the other is 7034 lines long for Oldenburg’s Road Network’s Edges (one edge per line) made up of Edge ID, Start Node ID, End Node ID, L2 Distance. We plan to use all of the data since the dataset is a manageable size.  Because we have a start and end node for each edge, this is a directed graph.

** Data Correction **
All of our Node IDs are integers and they range from 0 to 6104. While parsing through the Node Ids we can make sure that all of the Node IDs we receive are in that range or they’re invalid. We can also ensure that no node is accounted for twice and we don’t want any issues with the edges between our nodes. Finally, we have to ensure that each row contains two distinct node IDs. If we come across an edge that doesn't represent a meaningful relationship (one with a distance between two valid nodes) then we can disregard it entirely.

** Data Storage **
To store our data will be creating a graph with a Graph Class. We will also have a Node Class. Each node will have a key, a value, and a vector of pairs that stores each outgoing node and the distance to that node. However, instead of storing the distance as it is, we plan on storing 100/distance, so that the smaller distances will be weighted more. In our graph class, we will store all of the nodes of our graph in a vector of Nodes. The index of the vector will match with the Node ID, which works because our Node IDs are exactly the integers from 0 to 6104. The value stored at each index will be the Node with the matching ID.  The storage cost for the vector of Nodes is O(N), and the combined complexity for the edges between them is O(E), where N is the number of nodes and E is the number of edges. Overall, the sum of those two would be O(E+N).

** Algorithm **

** Function Inputs **
We have 2 CSV files with Nodes and edges as our input. In order to get the distances between 2 nodes we would have to go through the first CSV file of Node IDs or intersections and create nodes for each intersection and the edges of our graph would be using the 2nd CSV file of Edges to create the edges or roads of our graph. After we build our graph we would then use algorithms. Then we would create 3 functions that take an input of 2 nodes. One function would calculate the shortest way from one place to another using Dijkstra’s algorithm. The 2nd function would calculate was is more likely to be the busiest intersection using the betweenness centrality algorithm. The third function would give the user a way to drive through the entire city and we would be using DFS to compute this.

** Function Outputs **
For our first function, we want to output the shortest place from one place to another. So we want to output a vector that stores every node visited along the path from the first node to the destination.  For the busiest intersection function, we want to output the node or the intersection that is the busiest. For our last function, we would also like to output a vector of nodes or road intersections that shows a way to explore the city. 

** Function Efficency **
We are using 3 algorithms. Dijkstra’s algorithm, BFS, and the Betweenness algorithm. Dijkstra's algorithm shortest path algorithm has a time complexity of O(ElogV) where V is the number of vertices and e is the number of edges and the space complexity is O(V^2).  Breadth-first Search or (BFS) is O(V+E) time complexity and the space complexity is O(|V|). The betweenness algorithm’s time complexity is O(V+E) and the space complexity is O(V+E).  


** Timeline **

** Week of: **

Nov 14 (this week):
Finish project proposal
parse through csv

Nov 21:
Implement BFS and Closest Node algorithms with test cases

Nov 28:
Implement Betweenness Algorithm for busiest intersection with test cases

Dec 5:
If anything is left or didn't get done, finish it.
