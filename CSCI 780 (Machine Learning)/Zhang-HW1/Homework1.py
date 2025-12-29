import numpy as np
import math
import time
from sklearn.datasets import load_iris, load_breast_cancer, load_digits

import matplotlib.pyplot as plt

#--------------------
#Question 1
#--------------------

def compute_distance_loop(X):
    # pairwise distance with nested loops

    N = X.shape[0]
    D = X.shape[1]

    Z = np.zeros((N, N))

    for i in range(N):
        for j in range(N):
            xi = X[i, :]
            xj = X[j, :]
            # Euclidean distance between row i and row j
            Z[i, j] = np.sqrt(np.sum((xi - xj) ** 2))
    return Z

def compute_distance_vector(X):
    # Vectorized distance matrix using broadcasting
    X_norms = np.sum(X**2, axis=1)
    inner_products = X @ X.T
    Z_squared = X_norms[:, None] - 2 * inner_products + X_norms[None, :]

    Z_squared = np.maximum(Z_squared, 0) # avoid negative values due to floating-point errors

    Z = np.sqrt(Z_squared)
    return Z

print('starting running .....')
np.random.seed(100)
params = range(10, 61, 10)  # smaller for speed (cols = 10,20,...,60)
nparams = len(params)

perf_loop = np.zeros([10, nparams])  
perf_vec  = np.zeros([10, nparams])

counter = 0

for ncols in params:
    nrows = ncols * 10
    print("matrix dimensions:", nrows, ncols)

    for i in range(3):  # run multiple trials for averaging
        X = np.random.rand(nrows, ncols)   # random float matrix

        # loop distance timing
        st = time.time()
        dist_loop = compute_distance_loop(X)
        et = time.time()
        perf_loop[i, counter] = et - st

        # Vector distance timing
        st = time.time()
        dist_vec = compute_distance_vector(X)
        et = time.time()
        perf_vec[i, counter] = et - st

        # Check correctness between implementations
        assert np.allclose(dist_loop, dist_vec, atol=1e-6)

    counter += 1

# Average runtimes and standard deviation for plotting
mean_loop = np.mean(perf_loop, axis=0)
mean_vec  = np.mean(perf_vec, axis=0)
std_loop  = np.std(perf_loop, axis=0)
std_vec   = np.std(perf_vec, axis=0)

# Plot runtime comparison for distance matrix
plt.errorbar(params, mean_loop, yerr=std_loop, color='red', label='Loop Distance')
plt.errorbar(params, mean_vec,  yerr=std_vec,  color='blue', label='Vector Distance')
plt.xlabel('Number of Cols of the Matrix')
plt.ylabel('Running Time (Seconds)')
plt.title('Comparing Distance Computation Methods (Random Matrix)')
plt.legend()
plt.savefig('CompareDistanceFig.pdf')
#plt.show()

print("result is written to CompareDistanceFig.pdf")


#--------------------
#Question 2
#--------------------

def compute_correlation_loop(X):
    # loop correlation using explicit loops
    N = X.shape[0]
    D = X.shape[1]

    R = np.zeros((D, D))
    col_mean = np.mean(X, axis=0)

    # Covariance matrix with loops
    S = np.zeros((D, D))
    for i in range(D):
        for j in range(D):
            total = 0.0
            for n in range(N):
                total += (X[n, i] - col_mean[i]) * (X[n, j] - col_mean[j])
            S[i, j] = total / (N - 1)

    vector_sd = np.sqrt(np.diag(S))  # standard deviations

    # Normalize covariance to correlation
    for i in range(D):
        for j in range(D):
            denom = vector_sd[i] * vector_sd[j]
            if denom != 0:
                R[i, j] = S[i, j] / denom
            else:
                R[i, j] = 0.0

    return R

def compute_correlation_vector(X):
    # Vectorized correlation using matrix operations
    N = X.shape[0]
    D = X.shape[1]

    col_mean = np.mean(X, axis=0)

    x_center  = X - col_mean
    S = (x_center .T @ x_center ) / (N - 1) # covariance matrix

    vector_sd = np.sqrt(np.diag(S))

    denom = np.outer(vector_sd, vector_sd)

    R = np.zeros((D, D))
    bool_mask = denom != 0
    R[bool_mask] = S[bool_mask] / denom[bool_mask] # correlation matrix

    return R

print('starting correlation profiling .....')
np.random.seed(100)
params = range(10, 61, 10)   # matrix column sizes
nparams = len(params)

perf_loop = np.zeros([3, nparams])  
perf_vec  = np.zeros([3, nparams])

counter = 0
for ncols in params:
    nrows = ncols * 10
    print("matrix dimensions:", nrows, ncols)

    for i in range(3):   # multiple trials
        X = np.random.rand(nrows, ncols)

        # loop correlation timing
        st = time.time()
        corr_loop = compute_correlation_loop(X)
        et = time.time()
        perf_loop[i, counter] = et - st

        # Vectorized correlation timing
        st = time.time()
        corr_vec = compute_correlation_vector(X)
        et = time.time()
        perf_vec[i, counter] = et - st

        assert np.allclose(corr_loop, corr_vec, atol=1e-6)

    counter += 1

# Average runtimes and std for plotting
mean_loop = np.mean(perf_loop, axis=0)
mean_vec  = np.mean(perf_vec, axis=0)
std_loop  = np.std(perf_loop, axis=0)
std_vec   = np.std(perf_vec, axis=0)

# Plot runtime comparison for correlation matrix
plt.figure() 
plt.errorbar(params, mean_loop, yerr=std_loop, color='red', label='Loop Correlation')
plt.errorbar(params, mean_vec,  yerr=std_vec,  color='blue', label='Vector Correlation')
plt.xlabel('Number of Cols of the Matrix')
plt.ylabel('Running Time (Seconds)')
plt.title('Comparing Correlation Computation Methods (Random Matrix)')
plt.legend()
plt.savefig('CompareCorrelationFig.pdf')
#plt.show()

print("result is written to CompareCorrelationFig.pdf")

#--------------------
#Question 3
#--------------------


datasets = {
    "Iris": load_iris(),
    "Breast Cancer": load_breast_cancer(),
    "Digits": load_digits()
}

# Results storage
distance_times = {}
correlation_times = {}

# Process each dataset
for name, dataset in datasets.items():
    X = dataset.data
    print(f"\nProcessing {name} dataset (N={X.shape[0]}, D={X.shape[1]})")

    # Distance matrix timing
    start_time = time.time()
    dist_loop = compute_distance_loop(X)
    dist_loop_time = time.time() - start_time

    start_time = time.time()
    dist_vector = compute_distance_vector(X)
    dist_vector_time = time.time() - start_time

    # Correlation matrix timing
    start_time = time.time()
    corr_loop = compute_correlation_loop(X)
    corr_loop_time = time.time() - start_time

    start_time = time.time()
    corr_vector = compute_correlation_vector(X)
    corr_vector_time = time.time() - start_time

    # Store results
    distance_times[name] = (dist_loop_time, dist_vector_time)
    correlation_times[name] = (corr_loop_time, corr_vector_time)

    print(f"Distance matrix - loop: {dist_loop_time:.4f}s, vector: {dist_vector_time:.4f}s")
    print(f"Correlation matrix - loop: {corr_loop_time:.4f}s, vector: {corr_vector_time:.4f}s")
    
# Print results in table format
print("\n" + "="*70)
print("PERFORMANCE RESULTS (Time in seconds)")
print("="*70)
print("\nDistance Matrix Computation:")
print(f"{'Dataset':<15} {'loop (s)':<10} {'vector (s)':<10} {'Speedup':<10}")
for name, (loop_time, vector_time) in distance_times.items():
    speedup = loop_time / vector_time
    print(f"{name:<15} {loop_time:<10.4f} {vector_time:<10.4f} {speedup:<10.1f}x")

print("\nCorrelation Matrix Computation:")
print(f"{'Dataset':<15} {'loop (s)':<10} {'vector (s)':<10} {'Speedup':<10}")
for name, (loop_time, vector_time) in correlation_times.items():
    speedup = loop_time / vector_time
    print(f"{name:<15} {loop_time:<10.4f} {vector_time:<10.4f} {speedup:<10.1f}x")
