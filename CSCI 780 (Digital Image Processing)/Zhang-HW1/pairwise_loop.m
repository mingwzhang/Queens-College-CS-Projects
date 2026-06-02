function Z = pairwise_loop(X) % Compute pairwise Euclidean distance matrix using two level nested loops

[N, ~] = size(X); % N = number of samples
Z = zeros(N, N); % Preallocate output distance matrix

for i = 1:N
    for j = 1:N
        diff = X(i,:) - X(j,:); % Compute difference between two row vectors (1 x D)
        Z(i,j) = sqrt(diff * diff');  % Euclidean distance: sqrt( (x_i - x_j) * (x_i - x_j)^T )
    end
end

end