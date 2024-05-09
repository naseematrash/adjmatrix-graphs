#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace ariel {
    // Constructor initializes without needing isDirected parameter
    Graph::Graph() : numVertices(0), numEdges(0), isDirected(true) {}

    void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
        int rows = graph.size();
        int cols = graph[0].size();

        if (rows != cols) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        adjacencyMatrix = graph;
        numVertices = rows;
        isDirected = false; // Assume undirected until proven otherwise

        // Check for symmetry and count edges
        numEdges = 0;
        for (unsigned int i = 0; i < numVertices; ++i) {
            for (unsigned int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                    isDirected = true; // If any asymmetric entry is found, it's a directed graph
                }
                if (adjacencyMatrix[i][j] != 0) {
                    ++numEdges;
                }
            }
        }
        if (!isDirected){
            numEdges /= 2; // Divide by 2 for undirected graphs
        }

        // Adjust matrix for undirected graphs by clearing lower triangular matrix
     
    }

    void Graph::printGraph() const {
        std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges";
        if (isDirected) {
            std::cout << " (Directed)" << std::endl;
        } else {
            std::cout << " (Undirected)" << std::endl;
        }
        for (unsigned int i = 0; i < numVertices; ++i) {
            for ( unsigned int j = 0; j < numVertices; ++j) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
                    std::cout << std::endl;

    }

    int Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getNumEdges() const {
        return numEdges;
    }

    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }
}
