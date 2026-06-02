function Z = pairwise_vectorized(X) % Compute pairwise Euclidean distance matrix using vectorization

[N, D] = size(X);

norms = X .* X;  % N x D
norms = norms * ones(D,1);  % N x 1 vector of squared norms

G = X * X';  % N x N

% ||x_i - x_j||^2 = ||x_i||^2 - 2 x_i^T x_j + ||x_j||^2

Z_squared = norms * ones(1,N) ...  % Expand ||x_i||^2
          - 2 * G ...
          + ones(N,1) * norms'; % Expand ||x_j||^2

Z_squared(Z_squared < 0) = 0; % Remove tiny negative values due to floating-point error

Z = sqrt(Z_squared);

end