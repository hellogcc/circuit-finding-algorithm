# circuit-finding-algorithm

Written by Xing Mingjie (mingjie.xing@gmail.com).

An implementation of the Johnson's circuit finding algorithm [1].

[1] Donald B. Johnson, Finding all the elementary circuits of a directed
    graph, SIAM Journal on Computing, 1975.

## Example

	$ g++ -std=c++11 Example.cpp
	$ ./a.out
	circuit: 1 -> 2 -> 3 -> 5 -> 1
	circuit: 1 -> 2 -> 4 -> 3 -> 5 -> 1
	circuit: 2 -> 2
