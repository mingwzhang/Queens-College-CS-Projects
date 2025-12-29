import numpy as np
import pandas as pd
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

# Load the dataset
data = load_breast_cancer()
X = data.data
y = data.target

# EDA
print("=== EXPLORATORY DATA ANALYSIS (EDA) ===")
print("Features:", data.feature_names)
print("X shape:", X.shape)
print("y shape:", y.shape)
print("Class distribution:", np.unique(y, return_counts=True))

# Quick stats
df = pd.DataFrame(X, columns=data.feature_names)
print("\nStatistical Summary (Key Metrics):")
with pd.option_context('display.max_columns', 5):
    print(df.describe().iloc[:, :5])

print(f"\nDataset contains {X.shape[1]} features total")
print(f"Missing values: {df.isnull().sum().sum()}")

# Convert to {-1, 1} for pocket algorithm
y_transformed = np.where(y == 0, -1, 1)

# Data Transformation
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

def pocket_algorithm(X, y, max_iter=1000):
    """
    Proper implementation of Pocket Algorithm
    """
    X_with_bias = np.hstack((np.ones((X.shape[0], 1)), X))
    
    # Initialize with linear regression
    w = np.linalg.pinv(X_with_bias) @ y
    best_w = w.copy()
    best_error = np.sum(np.sign(X_with_bias @ w) != y)
    
    for iteration in range(max_iter):
        # Find all misclassified points
        predictions = np.sign(X_with_bias @ w)
        misclassified = np.where(predictions != y)[0]
        
        if len(misclassified) == 0:
            break
            
        # Pick a random misclassified point
        random_idx = np.random.choice(misclassified)
        
        # PLA update
        w_new = w + y[random_idx] * X_with_bias[random_idx]
        
        # Check if this is better than our best
        current_error = np.sum(np.sign(X_with_bias @ w_new) != y)
        if current_error < best_error:
            best_error = current_error
            best_w = w_new.copy()
        
        w = w_new  # Continue with updated weights
    
    return best_w

def run_experiments(X_data, y_data, data_type="With DT"):
    """
    Run experiments for given dataset
    """
    print(f"\n=== RUNNING EXPERIMENTS {data_type} ===")
    Ein_list, Eout_list, N_values = [], [], []
    sample_sizes = np.linspace(50, 450, 10, dtype=int)
    
    for N in sample_sizes:
        ein_scores = []
        eout_scores = []
        
        # 10 different experiments for this N
        for experiment in range(10):
            X_train, X_test, y_train, y_test = train_test_split(
                X_data, y_data, train_size=N, random_state=experiment
            )
            
            w_pocket = pocket_algorithm(X_train, y_train, max_iter=1000)
            
            # Compute errors
            X_train_bias = np.hstack((np.ones((X_train.shape[0], 1)), X_train))
            X_test_bias = np.hstack((np.ones((X_test.shape[0], 1)), X_test))
            
            ein = np.mean(np.sign(X_train_bias @ w_pocket) != y_train)
            eout = np.mean(np.sign(X_test_bias @ w_pocket) != y_test)
            
            ein_scores.append(ein)
            eout_scores.append(eout)
        
        # Store average results
        avg_ein = np.mean(ein_scores)
        avg_eout = np.mean(eout_scores)
        Ein_list.append(avg_ein)
        Eout_list.append(avg_eout)
        N_values.append(N)
        
        print(f"N={N}: Avg Ein={avg_ein:.3f}, Avg Eout={avg_eout:.3f}")
    
    return N_values, Ein_list, Eout_list

# Run experiments with data transformation (scaled)
N_scaled, Ein_scaled, Eout_scaled = run_experiments(X_scaled, y_transformed, "With Data Transformation")

# Run experiments without data transformation (original)
N_original, Ein_original, Eout_original = run_experiments(X, y_transformed, "Without Data Transformation")

# Plot results comparison
plt.figure(figsize=(12, 8))

# With Data Transformation
plt.subplot(2, 1, 1)
plt.plot(N_scaled, Ein_scaled, 'bo-', label='Ein (training error)', linewidth=2, markersize=6)
plt.plot(N_scaled, Eout_scaled, 'ro-', label='Eout (test error)', linewidth=2, markersize=6)
plt.xlabel('N (Number of training samples)')
plt.ylabel('Error rate')
plt.title('Pocket Algorithm Performance WITH Data Transformation (Standard Scaling)')
plt.legend()
plt.grid(True, alpha=0.3)
plt.ylim(0, 0.2)

# Without Data Transformation
plt.subplot(2, 1, 2)
plt.plot(N_original, Ein_original, 'bo-', label='Ein (training error)', linewidth=2, markersize=6)
plt.plot(N_original, Eout_original, 'ro-', label='Eout (test error)', linewidth=2, markersize=6)
plt.xlabel('N (Number of training samples)')
plt.ylabel('Error rate')
plt.title('Pocket Algorithm Performance WITHOUT Data Transformation')
plt.legend()
plt.grid(True, alpha=0.3)
plt.ylim(0, 0.2)

plt.tight_layout()
plt.show()

# Print summary comparison
print("\n=== PERFORMANCE COMPARISON ===")
print("With Data Transformation (Standard Scaling):")
print(f"Final Eout: {Eout_scaled[-1]:.3f}")
print(f"Average Eout across all N: {np.mean(Eout_scaled):.3f}")

print("\nWithout Data Transformation:")
print(f"Final Eout: {Eout_original[-1]:.3f}")
print(f"Average Eout across all N: {np.mean(Eout_original):.3f}")
