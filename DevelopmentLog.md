Monday 9am 04/05/21

Discussed and finished the contract

Tuesday 8pm 04/06/21 

Recap on previous meeting
Discuss and finalize on the selection of dataset: 
Amazon product co-purchasing network metadata
Write up the proposal. Four of us have been going through each question together.
A few questions came up that we need to ask the mentor for clarification.
We plan to attend the office hour at 4pm on Wednesday.

Tuesday 8pm 04/13/21

Went through the entire rubric and splitted the work
Tested readFromFile.cpp and .hpp
Generated a makefile to test a small set of data
Discussed how to write traverals

Tuesday 9pm 04/20/21
We first discussed about how to build the structure of our graphs and we finalized on implementing with Adjacency List and using vector to store nodes instead of doubly linked list from lecture. Based on our research, vector implementation is faster than linked list most of the time although resizing vector can be time-consuming. Thus, we started to write up the code for our Graph.h and Graph.cpp files and we finished the code by 11:50 PM. The meeting wass held on Zoom and Xizheng was in charge of writing up the code while the rest three of us were researching the various possible implementations and offered suggestions. The meeting went pretty productive and we managed to finished the basic implementation of a Graph class. Our next meeting is scheduled on Thursday at 9 PM and we will continue to finish up the traversal implementation. All team members were told to do more research on how to implement the traversal more efficiently.

Thursday 9pm 04/23/21
We started off by updating adjacency list to adjacency matrix, acknowledging that it would be more convenient to find edges and apply our implementation. Then we updated the Makefile, Graph.cpp, Edge.cpp, Node.h. We will continue with the new adjacency matrix algorithm to do traversal next time. The meeting ended at 12:40 AM. 

Monday 8pm 04/28/21
We changed back to Adjacency List implementation and restructured the graph class. Both Graph.cpp and Graph.h were editted. Code has been tested and passed without memory leak.

Thursday 9pm 05/06/21
We discussed and finished traversal and shortest path implemented inside traversal as we don't have weight difference for the edges(all same weight). Then we researched about various ways to implement strongly connected components and decided that although DFS has longer run time, we will first implement Tarjan's algorithm and if run time is not good enough for our particular model, we will use more advanced algorithms introduced by some other researchers such as SCCMulti or SCC-PA.

Saturday 3pm-9pm 05/08/21
We finishied BFS, DFS, traversals algorithm, shortest path algorithm, and strongly connected component algorithm. All tests were passed. A lot of time was used on debugging as we go from the sample data to the actual data. We had to adjust the node, fix many bugs an finally completed strongly connected component after a long debugging in DFS.cpp.

Sunday 3pm-3:30am 05/09/21-05/10/21
We discussed how to write the report, presentation, readme, and the polishing of the code. It was a long process as our test case run into problems due to a large dataset. However, we were able to finally successfully compile the code and got results as we expected. 