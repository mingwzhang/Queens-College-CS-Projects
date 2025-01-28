# Import the heap queue module to use a min-heap
import heapq  
import time
import tracemalloc

def Dijkstra_Algorithm(graph, source):
    # Print the input graph for better context
    print(f"\n   Input Graph: {graph}")
    
    # Handle the empty graph case
    if not graph:
        print("   The graph is empty.\n")
        return
    
    # Handle the case where the source node does not exist in the graph
    if source not in graph:
        print(f"   Source node '{source}' does not exist in the graph.\n")
        return
    
    # Handle negative weights in the graph
    # Dijkstra's algorithm does not support negative weights, so we stop if any negative weight is found.
    for node, edges in graph.items():
        for _, weight in edges:
            if weight < 0:
                print("   The graph contains negative weight edges, which are not supported by Dijkstra's algorithm.\n")
                return

    # Initialize distance dictionary with infinite distances for all nodes
    distance = {node: float('inf') for node in graph}
    distance[source] = 0 
    # Priority queue to keep track of the nodes to be processed, starting with the source node
    priority_queue = [(0, source)] 

    while priority_queue:
        # Extract the node with the shortest known distance
        current_distance, current_node = heapq.heappop(priority_queue)

        # Iterate over all neighbors of the current node
        for neighbor, weight in graph[current_node]:
            update_distance = current_distance + weight  

            # Condition to update the distance if the new distance is shorter
            if update_distance < distance[neighbor]:
                distance[neighbor] = update_distance
                heapq.heappush(priority_queue, (update_distance, neighbor))
                
    print(f"   Distances from source node {source}: {distance}")

def Dijkstra_Output(graph, source):
    # Start measuring memory
    tracemalloc.start()
    start_time = time.time()
    
    # Run the algorithm
    Dijkstra_Algorithm(graph, source)
    
    # Stop measuring memory and time
    end_time = time.time()
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    print(f"   Time taken: {end_time - start_time:.6f} seconds")
    print(f"   Current memory usage: {current / 1024:.2f} KB")
    print(f"   Peak memory usage: {peak / 1024:.2f} KB\n")

    
# Input Explanation:
# The input graph is represented as a dictionary of nodes, where each node is a key.
# - Each key maps to a list of tuples, representing **edges**.
# - Each tuple in the list contains:
#   1. The **neighbor node** connected by that edge.
#   2. The **weight** of the edge (a positive integer representing distance or cost).
# Example Input:
# {
#     'A': [('B', 3), ('C', 2), ('D', 8)],
#     'B': [('C', 1), ('E', 3)],
#     'C': [('D', 4), ('E', 5)],
#     'D': [('E', 5)],
#     'E': []
# }
# This means:
# - 'A' has edges to 'B' (weight 3), 'C' (weight 2), and 'D' (weight 8).
# - 'B' has edges to 'C' (weight 1) and 'E' (weight 3).
# - And so on.

# Output Explaination:
# The 'distance' dictionary stores the shortest distance from the source node to every other node.
# - Each key in the 'distance' dictionary represents a **node** in the graph.
# - The corresponding value is the **shortest distance** from the source node to that particular node.
# - If a node is not reachable from the source, its value will remain as `infinity` (float('inf')).
# Example output:
#   {'A': 0, 'B': 3, 'C': 2, 'D': 6, 'E': 6}
#   - `'A': 0` means the distance from 'A' to itself is **0**.
#   - `'B': 3` means the shortest distance from 'A' to 'B' is **3**.
#   - `'C': 2` means the shortest distance from 'A' to 'C' is **2**.
#   - If a node is not reachable, its value will be **infinity** (`float('inf')`).


# Test cases (including the new test case)

# 1. Basic Graph Test Case
graph_1 = {
    'A': [('B', 3), ('C', 2), ('D', 8)],
    'B': [('C', 1), ('E', 3)],
    'C': [('D', 4), ('E', 5)],
    'D': [('E', 5)],
    'E': []
}

print("Test Case 1: Basic Graph")
Dijkstra_Output(graph_1, 'A')

# 2. Single Node Graph Test Case
graph_2 = {
    'A': []
}

print("Test Case 2: Single Node Graph")
Dijkstra_Output(graph_2, 'A')


# 3. Disconnected Graph Test Case
graph_3 = {
    'A': [('B', 2)],
    'B': [],
    'C': [('D', 3)],
    'D': []
}

print("Test Case 3: Disconnected Graph")
Dijkstra_Output(graph_3, 'A')


# 4. Negative Weight Graph Test Case
graph_4 = {
    'A': [('B', -3), ('C', 2)],
    'B': [('C', 1)],
    'C': [('D', 4)],
    'D': []
}

print("Test Case 4: Graph with Negative Weights")
Dijkstra_Output(graph_4, 'A')


# 5. Graph with Zero Weights Test Case
graph_5 = {
    'A': [('B', 0), ('C', 2)],
    'B': [('C', 0), ('D', 1)],
    'C': [('D', 4)],
    'D': []
}

print("Test Case 5: Graph with Zero Weights")
Dijkstra_Output(graph_5, 'A')


# 6. Multiple Shortest Paths Test Case
graph_6 = {
    'A': [('B', 1), ('C', 1)],
    'B': [('D', 1)],
    'C': [('D', 1)],
    'D': []
}

print("Test Case 6: Graph with Multiple Shortest Paths")
Dijkstra_Output(graph_6, 'A')


# 7. Empty Graph Test Case
graph_7 = {}

print("Test Case 7: Empty Graph")
Dijkstra_Output(graph_7, 'A')


# 8. Cyclic Graph Test Case
graph_8 = {
    'A': [('B', 1), ('C', 5)],
    'B': [('A', 1), ('C', 2)],
    'C': [('D', 1)],
    'D': [('B', 1)]
}

print("Test Case 8: Cyclic Graph")
Dijkstra_Output(graph_8, 'A')

# 9. Different Source Node Test Case
graph_9 = {
    'A': [('B', 3), ('C', 2), ('D', 8)],
    'B': [('C', 1), ('E', 3)],
    'C': [('D', 4), ('E', 5)],
    'D': [('E', 5)],
    'E': []
}

print("Test Case 9: Different Source Node ('C')")
Dijkstra_Output(graph_9, 'C')

# 10. Source Node Not Found Test Case
graph_10 = {
    'A': [('B', 3), ('C', 2)],
    'B': [('C', 1), ('D', 4)],
    'C': [('D', 5)],
    'D': []
}

print("\nTest Case 10: Source Node Not Found")
Dijkstra_Output(graph_10, 'Z')
















