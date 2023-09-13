PROJECT DESCRIPTION

Our project is meant to give tailored suggestions when people try to buy items online based on the connections between items. We use a dataset downloaded from Amazon networks in Stanford Large Network Dataset Collection and store it as the 'Amazon0302.txt' file in our github. The link to the dataset online is as followed: http://snap.stanford.edu/data/

The dataset is formed by two columns of data and forms a connected graph. All the elements in the dataset are number, which are the item id for all the items. The first column represents the item ids of source items and the second column represents the item ids of destination items. An item pointing to another item represents if customers buy the source item, they have to buy the destination item, for example, if a customer buys a lock, he has to buy a key in order to use the lock. Below is a strip from our dataset. 

0	1
0	2
0	3
0	4
0	5
1	0
1	2
1	4
1	5
1	15
2	0
2	11
2	12

CODE DESCRIPTION

We use a directed graph stored in Graph.cpp and Graph.h as the basic structure for our project. It takes in two source item ids once and uses an addEdge function to build a directed graph stored in an adjacency list structure.

We define three major algorithms for our project; next we are going to describe them.

The first algorithm is the BFS traversal algorithm, which is stored in BFS.cpp and BFS.h files. It will take in a source item id as the input and will output a vector containing a series of item ids that represents the BFS traversal path based on the source item id. 

The second algorithm is the ShortestPath algorithm, which is stored in ShortestPath.cpp and ShortestPath.h files. It takes in two input item ids, where the first one represents the source item id and the second one represents the destination item id. Also, the algorithm contains two functions-getShortestDistance and getShortestPath-that will return different outputs. If we call getShortestDistance, the algorithm will return the shortest distance between the source item and the destination item. If we call the getShortestPath, the algorithm will return a vector containing a series of item ids that represents the shortest path from the source item to the destination item.

The third algorithm is the Strongly Connected Component(SCC) algorithm, which is stored in SCC.cpp and SCC.h files. It has no input. When we call it, it will return a vector that contains all strongly connected components. Also, each strongly connected component is in a vector form containing a list of item ids in the strongly connected component. 

INSTRUCTION ON PROJECT BUILD AND RUN

We have written two test cases for the project and stored them in test1.txt and test2.txt files. You can refer to test1.png and test2.png for the graph representation for these two tests. If you want to build and run our project. First you should type make command in an EWS machine terminal. After our project is built, you can type in the terminal as follows to run our project as you wish.

./finalproj [Amazon0302.txt or test1.txt or test2.txt] [ShortestPath or BFS or SCC] [source item id number] [destination item id number]

Here are the explanations for the content in the square brackets:

[Amazon0302.txt or test1.txt or test2.txt]  You have to type this input and have to choose the input from Amazon0302.txt, test1.txt and test2.txt. These represent which data you want to use to test our project. Amazon0302.txt is the real dataset from the website and test1.txt and test2.txt are two test cases we wrote. Feel free to add or modify the test cases. Notice that our algorithm run base on a 0-index directed graph. So please make sure the node number are integers from 0 to n-1 if you have a graph consist of n nodes.

[ShortestPath or BFS or SCC]  You have to type this input and have to choose the input from ShortestPath, BFS and SCC. These represent which algorithm you want to test-ShortestPath, BFS traversal or Strongly Connected Component.

[source item id number]  You have to type this input if you choose to type ShortestPath or BFS for the [ShortestPath or BFS or SCC] input and you have to type a number that exists in the test file you choose. It represents the source item id for the shortestpath algorithm and for the BFS traversal algorithm.

[destination item id number]   You have to type this input if you choose to type ShortestPath for the [ShortestPath or BFS or SCC] input and you have to type a number that exists in the test file you choose. It represents the destination item id for the shortestpath algorithm.

OUTPUT DESCRIPTION

After you run our project, there three kinds of outputs you may see based on which algorithm you choose to test. Here are their descriptions:

If you choose to test the ShortestPath algorithm, you will see the shortest distance from the source item to the destination item in the first line, and you will see the shortest path from the source item to the destination item in the second line. For example, if you input two inputs to the shortestpath algorithm as 1 4 and the shortest path from item 1 to item 4 is 1->3->4, you will see an output like:
2
1 3 4

If you choose to test the BFS traversal algorithm, you will see a series of item ids that represents the BFS traversal from the source item id. For example, if you input 1 as the source item id and its BFS traversal path is 1->3->4, you will see an output like:  
1 3 4

If you choose to test the Strongly Connected Component(SCC) algorithm, you will see a number that represents the number of strongly connected components in the first line and a vector of item ids in a strongly connected component in a line starting from the second line. Also, starting from the second line, there will be a number at the beginning representing the size of the strongly connected component. For example, if the graph has 3 strongly connected components and they are <1,2,3>, <4,5,7>, <8,10,12>. The output will look like:
3
3 1 2 3
3 4 5 7
3 8 10 12

