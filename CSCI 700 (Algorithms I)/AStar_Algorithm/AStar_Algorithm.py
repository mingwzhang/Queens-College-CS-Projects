import heapq
import time
import tracemalloc
import random
import matplotlib.pyplot as plt

def astar_algorithm(graph, start, goal, heuristic_func):
    if start not in graph or goal not in graph:
        return "Failure: Start or goal node not in the graph."

    open_set = []
    heapq.heappush(open_set, (0, start))
    open_set_tracker = {start}

    path_tracker = {}

    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0

    f_score = {node: float('inf') for node in graph}
    f_score[start] = heuristic_func(start, goal)

    while open_set:
        current = heapq.heappop(open_set)[1]
        open_set_tracker.remove(current)

        if current == goal:
            return reconstruct_path(path_tracker, current)

        for neighbor, weight in graph[current]:
            tentative_cost = g_score[current] + weight
            if tentative_cost < g_score[neighbor]:
                path_tracker[neighbor] = current
                g_score[neighbor] = tentative_cost
                f_score[neighbor] = g_score[neighbor] + heuristic_func(neighbor, goal)
                if neighbor not in open_set_tracker:
                    heapq.heappush(open_set, (f_score[neighbor], neighbor))
                    open_set_tracker.add(neighbor)

    return "Failure: No path exists from start to goal"

def reconstruct_path(path_tracker, current):
    reconstructed_path = [current]
    while current in path_tracker:
        current = path_tracker[current]
        reconstructed_path.append(current)
    return reconstructed_path[::-1]

def heuristic_func(node, goal):
    return abs(ord(node) - ord(goal))

def generate_graph(num_nodes, edge_probability=0.3, max_weight=10):
    nodes = [chr(65 + i) for i in range(num_nodes)]
    graph = {node: [] for node in nodes}

    for node in nodes:
        for neighbor in nodes:
            if node != neighbor and random.random() < edge_probability:
                weight = random.randint(1, max_weight)
                graph[node].append((neighbor, weight))

    return graph

def benchmark_astar(graph, start, goal, heuristic_func):
    tracemalloc.start()
    start_time = time.time()

    path = astar_algorithm(graph, start, goal, heuristic_func)

    end_time = time.time()
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    return {
        "runtime": end_time - start_time,
        "peak_memory": peak / 1024 / 1024  # Convert bytes to MB
    }

def run_benchmarks():
    sizes = [10, 50, 100, 200]  # Graph sizes to test
    results = []

    for size in sizes:
        graph = generate_graph(size)
        start, goal = 'A', chr(65 + size - 1)

        metrics = benchmark_astar(graph, start, goal, heuristic_func)
        results.append({"size": size, "runtime": metrics["runtime"], "peak_memory": metrics["peak_memory"]})

    return results

def plot_results(results):
    sizes = [result["size"] for result in results]
    runtimes = [result["runtime"] for result in results]
    memory_usages = [result["peak_memory"] for result in results]

    # Plot runtime
    plt.figure()
    plt.plot(sizes, runtimes, label="Runtime (s)", marker='o')
    plt.xlabel("Graph Size (nodes)")
    plt.ylabel("Runtime (seconds)")
    plt.title("Runtime vs. Graph Size")
    plt.legend()
    plt.grid(True)
    plt.show()

    # Plot memory usage
    plt.figure()
    plt.plot(sizes, memory_usages, label="Memory Usage (MB)", marker='o')
    plt.xlabel("Graph Size (nodes)")
    plt.ylabel("Memory Usage (MB)")
    plt.title("Memory Usage vs. Graph Size")
    plt.legend()
    plt.grid(True)
    plt.show()

# Run benchmarks
benchmark_results = run_benchmarks()

# Display results
for result in benchmark_results:
    print(f"Graph Size: {result['size']} nodes")
    print(f"Runtime: {result['runtime']:.6f} seconds")
    print(f"Peak Memory Usage: {result['peak_memory']:.6f} MB")
    print("-")

# Plot results
plot_results(benchmark_results)
