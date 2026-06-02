% Problem 1 - Performance Experiment

sizes = [50 100 200 400 800];
time_loop = zeros(size(sizes));
time_vec = zeros(size(sizes));

D = 50;  % Fixed feature dimension

for k = 1:length(sizes)

    N = sizes(k);

    X = rand(N, D);

    % Nested loop timing
    tic
    pairwise_loop(X);
    time_loop(k) = toc;

    % Vectorized timing
    tic
    pairwise_vectorized(X);
    time_vec(k) = toc;

end

% Display numerical table
fprintf('\nPerformance Results:\n');
fprintf('---------------------------------------------\n');
fprintf('N\tLoop Time (s)\tVectorized Time (s)\n');
fprintf('---------------------------------------------\n');

for k = 1:length(sizes)
    fprintf('%d\t%.6f\t\t%.6f\n', sizes(k), time_loop(k), time_vec(k));
end

% Plot results
figure
plot(sizes, time_loop, '-o','LineWidth',1.5)
hold on
plot(sizes, time_vec, '-x','LineWidth',1.5)
legend('Loop', 'Vectorized')
xlabel('Data Size (N)')
ylabel('Execution Time (seconds)')
title('Problem 1: Performance Comparison')
grid on

saveas(gcf, 'figure1.png')
