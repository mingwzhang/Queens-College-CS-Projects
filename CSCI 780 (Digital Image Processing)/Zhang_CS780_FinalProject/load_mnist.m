clear; clc; close all;

% Source: https://lucidar.me/en/matlab/load-mnist-database-of-handwritten-digits-in-matlab/

% Load MNIST dataset
load('mnist.mat');

% Check what variables were loaded
whos

% Print dataset information
fprintf('Training images: %d\n', training.count);
fprintf('Training image size: %d x %d\n', training.width, training.height);
fprintf('Test images: %d\n', test.count);
fprintf('Test image size: %d x %d\n', test.width, test.height);

% Check array sizes
disp(size(training.images));
disp(size(training.labels));
disp(size(test.images));
disp(size(test.labels));

% Display one sample digit
idx = 8;
figure;
im = image(rescale(training.images(:,:,idx), 0, 255));
im.CDataMapping = 'scaled';
colormap(gray);
axis square equal;
title(sprintf('Training sample %d, Label: %d', idx, training.labels(idx)));