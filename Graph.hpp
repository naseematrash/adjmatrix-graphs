#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>

namespace ariel {
    class Graph {
    public:
        Graph();
       
        void loadGraph(const std::vector<std::vector<int>>& graph);
        void printGraph() const;
        int getNumVertices() const;
        int getNumEdges() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

    private:
        int numVertices;
        
        int numEdges;
        bool isDirected; // New field to indicate whether the graph is directed
        std::vector<std::vector<int>> adjacencyMatrix;
    };
}

#endif
