README - Homework 3: Logistic Regression with Regularization
------------------------------------------------------------

Team Member: Mingwei Zhang

1. What did you finish?
   - Implemented logistic regression with L2 regularization.
   - Performed feature space transformations using Polynomial Features (Φ₁, Φ₂, Φ₃).
   - Conducted 5-fold cross validation to evaluate model performance under different λ values.
   - Compared results between polynomial and Legendre polynomial feature transformations (bonus part).
   - Generated plots for 5-fold CV accuracy vs λ for both standard and Legendre transformations.
   - Identified best λ configuration for highest validation accuracy.

2. Python Version:
   - 3.13 

3. Platform:
   - Windows 11

4. Resources:
   - scikit-learn documentation for breast cancer dataset 
	https://scikit-learn.org/stable/modules/generated/sklearn.datasets.load_breast_cancer.html
   - Python library references
	https://scikit-learn.org/stable/modules/linear_model.html
	https://scikit-learn.org/stable/modules/generated/sklearn.preprocessing.PolynomialFeatures.html
	https://numpy.org/doc/stable/reference/generated/numpy.polynomial.legendre.Legendre.html
	https://matplotlib.org/3.5.3/api/_as_gen/matplotlib.pyplot.html
   - Other online sources
	https://www.geeksforgeeks.org/machine-learning/regularization-in-machine-learning/
   - Lecture slides on logistic regression and regularization