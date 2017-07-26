#ifndef CIRCUIT_FINDER_H
#define CIRCUIT_FINDER_H

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

typedef std::list<int> NodeList;

template<int N>
class CircuitFinder
{
  std::vector<NodeList> AK;
  std::vector<int> Stack;
  std::vector<bool> Blocked;
  std::vector<NodeList> B;
  int S;

  void unblock(int U);
  bool circuit(int V);
  void output();

 public:
 CircuitFinder(int Array[N][N])
   : AK(N), Blocked(N), B(N) {
    for (int I = 0; I < N; ++I) {
      for (int J = 0; J < N; ++J) {
        if (Array[I][J]) {
          AK[I].push_back(Array[I][J]);
        }
      }
    }
  }

  void run();
};

template<int N>
void CircuitFinder<N>::unblock(int U)
{
  Blocked[U - 1] = false;

  while (!B[U - 1].empty()) {
    int W = B[U - 1].front();
    B[U - 1].pop_front();

    if (Blocked[W - 1]) {
      unblock(W);
    }
  }
}

template<int N>
bool CircuitFinder<N>::circuit(int V)
{
  bool F = false;
  Stack.push_back(V);
  Blocked[V - 1] = true;

  for (int W : AK[V - 1]) {
    if (W == S) {
      output();
      F = true;
    } else if (!Blocked[W - 1]) {
      if(circuit(W))
	F = true;    }
  }

  if (F) {
    unblock(V);
  } else {
    for (int W : AK[V - 1]) {
      auto IT = std::find(B[W - 1].begin(), B[W - 1].end(), V);
      if (IT == B[W - 1].end()) {
        B[W - 1].push_back(V);
      }
    }
  }

  Stack.pop_back();
  return F;
}

template<int N>
void CircuitFinder<N>::output()
{
  std::cout << "circuit: ";
  for (auto I = Stack.begin(), E = Stack.end(); I != E; ++I) {
    std::cout << *I << " -> ";
  }
  std::cout << *Stack.begin() << std::endl;
}

template<int N>
void CircuitFinder<N>::run()
{
  Stack.clear();
  S = 1;

  while (S < N) {
    for (int I = S; I <= N; ++I) {
      Blocked[I - 1] = false;
      B[I - 1].clear();
    }
    circuit(S);

    // remove this vertex from the graph
    for (int I = S+1; I <= N; ++I)
      AK[I-1].remove(S);
    
    ++S;
  }
}

#endif // CIRCUIT_FINDER_H
