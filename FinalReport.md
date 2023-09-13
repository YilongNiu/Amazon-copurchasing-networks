CS225 Final Project Report

In this report, we will summary our project in three sections: Goals, Development, Results, Discussion, Future Research, and References.


I. Goals 

The purpose of this project is to analyze a dataset from Amazon.com's customers shopping records.

1. We extract the data set from Stanford Large Network Data set Collection. Out of all the graph data, we picked the “Amazon networks” in order to analyze the phenomenon of product co-purchasing. In particular, we imported amazon0302.txt” as our test data set. The file only has two columns. First column represents the first node that an edge is going out and the second column represents the second node that has an incoming edge. That is to say, each row represents an edge, so that we don’t need to convert it into any other format anymore. This data format determined that our code is directed but unweighted. 

2. we are interested in exploring the co-purchase habits of Amazon customers, thus our main goal is to explore the possible relationships between each co-purchased items and provide some insights to the advertising agencies to more accurately delivery related ads to the customers and recommend more useful items that might be bought together whenever the customers are on Amazon.com shopping. In terms of algorithm selection, we implemented BFS, DFS, shortest path, and strongly connected component. 

3. Breadth-First Search (BFS) 

Input is a node which we will start to traverse, and output is a vector consisting of the nodes traversed. 

4. Shortest Path (SP)

We first need to implement the DFS which will be called to find the path. DFS takes a node as input and no output. It is used in strongly connected component to traverse the graph. The shortest path algorithm is demonstrated using two functions. 

Next, we have a “getShortestDistance” function takes two nodes as input and return the shortest distance found corresponding to the shortest path.  The second function is “getShortestPath” that takes two nodes as input and return the actual shortest path as a vector of integers.

5. Strongly Connected Components (SCC)

First we should give the definition of the SCC as it is not an algorithm covered in the class. We found this algorithm during the first meeting, and sticked with it till the actual application. 

We say that a directed graph is strongly connected if every vertex is reachable from every other vertex. 

Then the strongly connected components(SCC) of an arbitrary graph can be divided up into subgraphs that are strongly connected within each subgraph.

The SCC can be found in linear time, which is O(V + E), where V is the number of vertices and E is the number of edges.

The strongly connected component algorithm is demonstrated by the function “findSccs” which takes no input and outputs a vector of vector of integers. Each row represents a strongly connected component.
In order to verify that the methods have worked, we have designed two test cases in the main.cpp file.
The timeline of our work is the same as the order of the list shown above. We started with BFS and ended with Strongly connected component(SCC).


II. Development

1. Monday 9am 04/05/21

This first meeting, we were able to touch base and brain-stormed the topics to discover. Next we discussed and finished the contract.

2. Tuesday 8pm 04/06/21 

Recap on previous meeting
Discuss and finalize on the selection of dataset: 
Amazon product co-purchasing network metadata
Write up the proposal. Four of us have been going through each question together.
A few questions came up that we need to ask the mentor for clarification.
We plan to attend the office hour at 4pm on Wednesday.

3. Tuesday 8pm 04/13/21

Went through the entire rubric and splitted the work.
Tested readFromFile.cpp and .hpp
Generated a makefile to test a small set of data
Discussed how to write traverals

4. Tuesday 9pm 04/20/21
We first discussed about how to build the structure of our graphs and we finalized on implementing with Adjacency List and using vector to store nodes instead of doubly linked list from lecture. Based on our research, vector implementation is faster than linked list most of the time although resizing vector can be time-consuming. Thus, we started to write up the code for our Graph.h and Graph.cpp files and we finished the code by 11:50 PM. The meeting wass held on Zoom and Xizheng was in charge of writing up the code while the rest three of us were researching the various possible implementations and offered suggestions. The meeting went pretty productive and we managed to finished the basic implementation of a Graph class. Our next meeting is scheduled on Thursday at 9 PM and we will continue to finish up the traversal implementation. All team members were told to do more research on how to implement the traversal more efficiently.

5. Thursday 9pm 04/23/21
We started off by updating adjacency list to adjacency matrix, acknowledging that it would be more convenient to find edges and apply our implementation. Then we updated the Makefile, Graph.cpp, Edge.cpp, Node.h. We will continue with the new adjacency matrix algorithm to do traversal next time. The meeting ended at 12:40 AM. 

6. Monday 8pm 04/28/21
We changed back to Adjacency List implementation and restructured the graph class. Both Graph.cpp and Graph.h were editted. Code has been tested and passed without memory leak.

7. Thursday 9pm 05/06/21
We discussed and finished traversal and shortest path implemented inside traversal as we don't have weight difference for the edges(all same weight). Then we researched about various ways to implement strongly connected components and decided that although DFS has longer run time, we will first implement Tarjan's algorithm and if run time is not good enough for our particular model, we will use more advanced algorithms introduced by some other researchers such as SCCMulti or SCC-PA.

8. Saturday 3pm-9pm 05/08/21
We finishied BFS, DFS, traversals algorithm, shortest path algorithm, and strongly connected component algorithm. All tests were passed. A lot of time was used on debugging as we go from the sample data to the actual data. We had to adjust the node, fix many bugs an finally completed strongly connected component after a long debugging in DFS.cpp.

9. Sunday 3pm-12am 05/09/21
We discussed how to write the report, presentation, readme, and the polishing of the code. It was a long process as our test case run into problems due to a large dataset. However, we were able to finally successfully compile the code and got results as we expected. 


III. Results
1. We used two test cases and the graphs are shown in files test1.txt, test1.png test2.txt, and test2.png from the same folder.
test1_result: BFS outputs {1, 0, 3, 2, 4, 5, 6, 7} (refer to BFS_test1Result.png); SP outputs {1, 3, 4, 6} (refer to SP_test1Result.png) with distance being 3; SCC outputs {{0, 1}, {2, 3, 4}, {5, 6, 7}} (refer to SCC_test1Result.png) as three SCC. 

test2_result: BFS outputs {1, 2, 4, 3, 5, 6, 0, 7} (refer to BFS_test2Result.png); SP outputs {1, 4, 6}  (refer to SP_test2Result.png) with distance being 2; SCC outputs {{0, 2, 3}, {1}, {4}, {5}, {6}, {7}} (refer to SCC_test2Result.png).

Both tests verified that our algorithms performed as expected.
realData_result: real data is too big to verify, so we will not demonstrate it here. The results of testing on the actual data can be verified from BFS_realDataTestResult.png, SP_realDataTestResult.png, SCC_realDataTestResult.png.


2. BFS explores all the neighbor of a given node at the present depth before moving on to the node at the next depth. It traverses each node and if there is an edge going from one node to another, it means that the two products represented by these two nodes were bought together. 

3. The first key result from shortest path showed that we can find how many related items were bought together between any two selected items. This is very useful in a sense that given an items a customer must buy, we can find the most related items and send out ads of other products to that customer alongside the already bought item. We may find some hidden relationships between items that were not obvious at all.

4. Similarly, strongly connected components algorithm also demonstrated the relationship among different items co-purchased by customers. By finding the strongest connect products, retailers may bundle the goods and sell it to a customer. What’s more, a customer can look at related goods recommended to them before they checkout. It is also useful for manufactures to investigate and create derivatives, meaning goods that can be produced alongside the main product and sold together as a package. Another sensitive, yet crucial information is that we can track the shopping habits of customers given this dataset or something similar.


IV. Discussion

1. Adjacency Matrix vs. Adjacency List
We tried to implement undirected graph at first as our data don't have weight and we don't really care the direction of the edge. However, since Adjacency Matrix has areAdjacency function only while Adjacency List has the function of clustering all adjacenct nodes. Plus, the run time is faster. Therefore, after the mid-point check, we ended up implementing the Adjacency List again.

2. Tarjan's vs. Kosaraju's Algorithm
Tarjan is better than as it only uses one stack and DFS. We compared the two and picked Tarjan's.


V. Future Reseach 

1. Due to the nature of our dataset, we do not have weight on each edge in our graph. Thus, the problem may be slightly simplified and some inner relationships may not be revealed yet. In the future, researchers can pick a dataset with weighted directed graph(digraph) from other E-commerces.

2. What's more, as we only have time to fully implement the DFS-based linear-time algorithm, Tarjan's strongly connected components algorithm, published by Robert Tarjan in 1972, there are also reachability-based algorithms that we read papers about but did not implement in the end. The advantages of reachability-based algorithms are the possibilites of parallelization. Fleischer et al.[1] in 2000 proposed a divide-and-conquer approach based on reachability queries, and such algorithms are usually called reachability-based SCC algorithms. These algorithms has the run time of Big O of n times log n. 

VI. References
 1. Fleischer, Lisa K.; Hendrickson, Bruce; Pınar, Ali (2000), "On Identifying Strongly Connected Components in Parallel" (PDF), Parallel and Distributed Processing, Lecture Notes in Computer Science, 1800, pp. 505–511, doi:10.1007/3-540-45591-4_68, ISBN 978-3-540-67442-9
