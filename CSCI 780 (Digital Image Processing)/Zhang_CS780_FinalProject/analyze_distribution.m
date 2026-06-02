clear; clc; close all;

load('mnist.mat');

% Use the same final experiment size
numTrain = 60000;
numTest = 10000;

trainLabels = training.labels(1:numTrain);
testLabels = test.labels(1:numTest);

digits = (0:9)';

trainCounts = zeros(10,1);
testCounts = zeros(10,1);

for digit = 0:9
    trainCounts(digit + 1) = sum(trainLabels == digit);
    testCounts(digit + 1) = sum(testLabels == digit);
end

distributionTable = table(digits, trainCounts, testCounts, ...
    'VariableNames', {'Digit', 'Training_Count', 'Test_Count'});

disp(distributionTable);

% Plot training distribution
figure;
bar(digits, trainCounts);
title('MNIST Training Set Digit Distribution');
xlabel('Digit');
ylabel('Number of Images');
xticks(0:9);

% Plot test distribution
figure;
bar(digits, testCounts);
title('MNIST Test Set Digit Distribution');
xlabel('Digit');
ylabel('Number of Images');
xticks(0:9);