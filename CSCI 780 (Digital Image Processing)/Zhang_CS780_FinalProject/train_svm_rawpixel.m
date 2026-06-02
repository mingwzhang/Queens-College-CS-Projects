clear; clc; close all;

load('mnist.mat');

% Use the same final experiment size as the HOG script for fair comparison
numTrain = 60000;
numTest = 10000;

trainImages = training.images(:,:,1:numTrain);
trainLabels = training.labels(1:numTrain);

testImages = test.images(:,:,1:numTest);
testLabels = test.labels(1:numTest);

% Raw pixel feature extraction
% Each 28x28 image becomes one 1x784 vector

featureLength = training.height * training.width;   % 28 * 28 = 784

trainFeatures = zeros(numTrain, featureLength);
testFeatures = zeros(numTest, featureLength);

for i = 1:numTrain
    img = trainImages(:,:,i);
    trainFeatures(i,:) = img(:)';
end

for i = 1:numTest
    img = testImages(:,:,i);
    testFeatures(i,:) = img(:)';
end

% Train multi-class SVM

model = fitcecoc(trainFeatures, trainLabels);

% Predict test labels
predLabels = predict(model, testFeatures);

% Evaluation

accuracy = mean(predLabels == testLabels) * 100;
fprintf('Baseline Raw Pixel + SVM Test Accuracy: %.2f%%\n', accuracy);

% Confusion matrix values
C = confusionmat(testLabels, predLabels);

% Per-class accuracy
perClassAcc = diag(C) ./ sum(C, 2) * 100;

fprintf('\nPer-class accuracy:\n');
for digit = 0:9
    fprintf('Digit %d: %.2f%%\n', digit, perClassAcc(digit + 1));
end

% Display confusion matrix
figure;
confusionchart(testLabels, predLabels);
title('Baseline: Raw Pixel + SVM Confusion Matrix');