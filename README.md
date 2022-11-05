# Dynamic-Duo-Finders

**Leading Question**
Given a dataset composed of Github users’ mutual friendships, how can we identify promising collaborations between developers with similar interests? 
The basis of this is that friendships on github are based on shared interests. Therefore, having a mutual friend with another user is a promising indication that there is potential shared interest. 
So, what potential friendships between two users/groups are possible based on their mutual friends?

**Dataset Acquisition**
We are using the GitHub Social Network dataset (http://snap.stanford.edu/data/github-social.html) that was given. It contains data for 37,000 users, and the friendships between them. Specifically, it lists in each row of its csv two user IDs for two users that have a mutual friendship. The IDs are integers from 0 to 37,699, with the entire range being full.  Each user can be viewed as a node, and each friendship, of which there are 289,003, can be viewed as an edge between those two nodes. This data only includes mutual friendships and it does not include any measure of strength, so it is undirected and unweighted. There is either an edge between two nodes or there isn’t.

**Data Format**
There are a lot of files in the zip but we want to focus on relationships between users, and the data for that is a microsoft excel CSV.  Each row includes two user IDs, and it represents a relationship of mutual friendship between the users. It is a pretty large dataset with around 37,000 users and 280,000 relationships between them. We plan on using the entire dataset unless we see it taking too much time or processing power. In the end, our data would be a set of connected components, and in each one the users are all connected through some mutual friendship(s). If there is no connection between them, they would be in different connected components. If we see that the data is taking too much to work with, we might focus on relationships within a single connected component.

**Data Correction**
All of our user IDs are integers, and they range from 0 to 37699. While parsing through the relationships, we can make sure that all of the user IDs we receive are in that range or they’re invalid. We can also ensure that no friendship is accounted for twice, as we don’t want any issues with the edges between our nodes. Finally, we have to ensure that each row actually contains two distinct user IDs. If we come across a row that is missing that (one ID or none), we can disregard it entirely, as it does not represent a meaningful relationship. The same can be said for a friendship between a user and themself.

**Data Storage**
Every user will have a node, and that node will store the user’s ID, and a vector of pointers to all of their mutual friends. We can also store each node in a vector. Whose size is the number of users we have so that we can access the nodes easily for the purpose of adding neighbors. This should be easy to do because the user IDs are consecutive integers starting at 0, so the user ID lines up perfectly with the indices of the vector, and we can access any node by the ID in O(1) time to add neighbors or to access the neighbor vector.  However, this vector is only there for the sake of making sure we don’t lose any nodes that are not connected to the others.  The main graph functionality is implemented through the nodes themselves and the pointers to their neighboring nodes.






**Graph Algorithms:**
Dijkstra's algorithm:
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

Tarjan’s Algorithm:
https://en.wikipedia.org/wiki/Strongly_connected_component#Algorithms

Algorithms that will be beneficial to this project are Dijkstra’s algorithm and Tarjan’s algorithm. The first one is used to calculate the shortest path between two nodes of a graph. The input would be two user ids and the output would be the shortest path between those users. This algorithm is stated to have an O((N+E)log(E)) runtime, where N is the number of nodes and E is the number of edges.
The second algorithm is used to determine strongly connected components. This can help you find friend/creator groups rather than individual creators. We could use this to identify these groups, then store a node in the strongly connected component and use something like Dijkstra’s algorithm to find how relevant that friend/creator/developer group may be to any user given their ID. The input would be a single user id. The output would be the largest strongest connected graph formed from the starting user id.

**Timeline:**

Week 1: Create classes to store data
-Parse through the dataset and store data locally
-Start reading about Dijkstars Algorithm/Tarjan’s Algorithm and write some pseudo code for our project

Week 2: Read data into storage and begin algorithm development
-Begin writing Dijkstars and Tarjan’s Algorithm
-Write test cases for out data to see if our algorithm is working properly
-And that were are not parsing any invalid ID’s or parsing the same ID’s twice for instance 

Week 3: Complete algorithm
-Store all connections of a user in a vector.

Week 4: Add extra parameters and functionality
-Add some features to our algorithm such as find my xth degree connections
-If time permits create a visual graph that personalized to each users connections

