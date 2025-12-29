import matplotlib.pyplot as plt
import numpy as np

from sklearn.datasets import load_breast_cancer
from sklearn.preprocessing import StandardScaler, PolynomialFeatures
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import cross_val_score, KFold
from numpy.polynomial.legendre import Legendre

# Import the dataset
data = load_breast_cancer()
X = data.data
y = data.target

print("X shape:", X.shape)
print("y shape:", y.shape)
print("Classes:", np.unique(y))


# Standardize features so each has mean 0 and std 1
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Create polynomial features (try degree = 2 first)
poly = PolynomialFeatures(degree=2, include_bias=False)
X_poly2 = poly.fit_transform(X_scaled)

print("Original shape:", X_scaled.shape)
print("Polynomial (2) shape:", X_poly2.shape)

lambdas = [0.01, 0.1, 1, 10, 100]

# 5-fold cross validation setup
kf = KFold(n_splits=5, shuffle=True, random_state=30)

results = []

for lam in lambdas:
    model = LogisticRegression(
        C = 1/lam,
        penalty = 'l2',
        solver = 'lbfgs',
        max_iter = 1000
    )

    # Cross validata and record mean accuracy
    scores = cross_val_score(model, X_poly2, y, cv=kf, scoring = 'accuracy')
    avg_score = np.mean(scores)
    results.append(avg_score)
    print(f"λ = {lam:<6}  →  Accuracy = {avg_score:.4f}")

print("\nBest λ:", lambdas[np.argmax(results)])
print("Best Accuracy:", max(results))

# Different feature transformations
degrees = [1, 2, 3]
lambdas = [0.01, 0.1, 1, 10, 100]

kf = KFold(n_splits=5, shuffle=True, random_state=30)

all_results = {}

for degree in degrees:
    # Generate feature set
    if degree == 1:
        X_transformed = X_scaled
    else:
        poly = PolynomialFeatures(degree=degree, include_bias=False)
        X_transformed = poly.fit_transform(X_scaled)

    print(f"\nΦ{degree}(x): Polynomial degree {degree}")
    results = []

    # Loop over lambdas
    for lam in lambdas:
        model = LogisticRegression(
            C=1/lam,
            penalty='l2',
            solver='lbfgs',
            max_iter=1000
        )
        scores = cross_val_score(model, X_transformed, y, cv=kf, scoring='accuracy')
        avg_score = np.mean(scores)
        results.append(avg_score)
        print(f"λ = {lam:<6} → Accuracy = {avg_score:.4f}")

    all_results[degree] = results

# Plot results
plt.figure(figsize=(8, 6))
for degree in degrees:
    plt.plot(lambdas, all_results[degree], marker='o', label=f'Φ{degree}(x)')

plt.xscale('log')
plt.xlabel('λ (regularization strength)')
plt.ylabel('Accuracy')
plt.title('5-Fold CV Accuracy vs λ for Φ₁(x), Φ₂(x), Φ₃(x)')
plt.legend()
plt.grid(True)
plt.show()



# Legendre Polynomial Transform
def legendre_transform(X, degree):
    
    #Transform features using Legendre polynomial basis up to given degree.
    n_samples, n_features = X.shape
    X_legendre = []
    
    for j in range(n_features):
        
        # Scale feature to [-1, 1]
        xj = X[:, j]
        x_scaled = 2 * (xj - np.min(xj)) / (np.max(xj) - np.min(xj)) - 1
        
        # Apply Legendre basis functions
        for d in range(1, degree + 1):
            P = Legendre.basis(d)
            X_legendre.append(P(x_scaled))
    return np.column_stack(X_legendre)

degrees_legendre = [1, 2, 3]
all_results_legendre = {}

for degree in degrees_legendre:
    X_legendre = legendre_transform(X_scaled, degree)
    print(f"\nLegendre Φ{degree}(x): degree {degree}")
    results = []
    for lam in lambdas:
        model = LogisticRegression(
            C=1/lam,
            penalty='l2',
            solver='lbfgs',
            max_iter=1000
        )
        scores = cross_val_score(model, X_legendre, y, cv=kf, scoring='accuracy')
        avg_score = np.mean(scores)
        results.append(avg_score)
        print(f"λ = {lam:<6} → Accuracy = {avg_score:.4f}")
    all_results_legendre[degree] = results

# Plot Legendre results
plt.figure(figsize=(8, 6))
for degree in degrees_legendre:
    plt.plot(lambdas, all_results_legendre[degree], marker='o', label=f'Legendre Φ{degree}(x)')
plt.xscale('log')
plt.xlabel('λ (regularization strength)')
plt.ylabel('Accuracy')
plt.title('5-Fold CV Accuracy vs λ (Legendre Feature Transform)')
plt.legend()
plt.grid(True)
plt.show()

    
