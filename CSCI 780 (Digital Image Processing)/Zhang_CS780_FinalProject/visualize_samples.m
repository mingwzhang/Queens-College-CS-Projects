clear; clc; close all;

load('mnist.mat');

figure;

for i = 1:25
    idx = randi(training.count);

    subplot(5, 5, i);
    imshow(training.images(:,:,idx), []);
    title(sprintf('%d', training.labels(idx)));
end

colormap(gray);
sgtitle('Random MNIST Training Samples');