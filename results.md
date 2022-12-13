# Results

## Output and Correctness of Each Algorithm

### Breadth First Search 

Our BFS algorithm takes a start_id that the user can set. Our BFS takes the start_id then generates a possible path through the whole city using the breadth first search algorithm. It then returns a vector of ints which are road ids.  


### Dijkstra's

The user gets to set the source node’s index and the end node index in our set_start_end function provided. In the shortest_path_algo function this function uses the source node to finds all shortest paths and their distances from every other node to the the source node. In the print_shortest_path_distances this function prints the distance of the shortest path between every vertex and the source node. The print_short_path_dist_src_to_end function prints the shortest path distance from the source node to the end node. The print_shortest_paths prints out the actual paths as a visual representation from each node to the source node. Lastly the print_shortest_path() prints out the shortest path between the source node to the end node as a visual representation.

### Betweeness 

This function gets the shortest path from each pair of nodes in the graph and returns a vector with a count of how many times a node lies on one of these paths. The shortest paths are found by setting the start and end nodes and then calling Dijkstra's algorithm to get the shortest path between them as a vector. It marks that path as traveled, iterates through the path vector and increments the count for that node.

## Tests Performed
TEST SMALL BFS SIZE - test that BFS has the right size

TEST SMALL BFS TRAVERSAL - test that BFS has the right traversal for a small graph

TEST NORMAL BFS TRAVERSAL - test that BFS has the right traversal for a small graph

TEST LARGE BFS START NODE - test that the large BFS has the right start node

TEST LARGE BFS ADJACENT NODES - test that the large BFS has the right adjacent nodes to a node we were testing

TEST DIJKSTRA'S WITH ONE POSSIBLE PATH - Dijkstra's when only one path is possible

TEST DIJKSTRA'S BEST OF MULTIPLE PATHS - Dijkstra's when choosing between paths

TEST DIJKSTRA'S FULL - Dijkstra's specifics with full graph (test small parts)

TEST BETWEENNESS SMALL - gives proper scores for betweenness on a small graph

TEST BETWEENNESS SMALL SIZE - betweenness returns a vector of the right size

## Leading Question 

Our leading question we hoped to solve was, What is the best way to get around the city? We answered this question by creating 3 functions using 3 different algorithms. The first one uses Dijsktras to find the shortest path between any 2 given roads. Another one uses BFS to return a path through the whole city. Our last function uses the betweeness algorithm to find the busiest interesection. We discovered some creative ways to use our functions. For instance if a user wanted to go on a fun adventure through the city our BFS function could generate a path that they can go explore through the city. Our Dijkstra's algorithm generates all possible shortest paths from every road to the source node. So if you're ever lost or just want to plan ahead you could use our function to show you the shortest path to anywhere in the city from where you are. Our Betweenness algorithm helps the user plan ahead for their trip. By giving the user the busiest intersection the user can then plan to avoid that certain intersection on their trip.


## Presentation Link
https://docs.google.com/presentation/d/1pmrxRiKhYZx2S0FK9ypu37MYbXszisF8byV3sD3hXig/edit#slide=id.g1b0ea3e97fa_0_30






