clear; clc; close all;

load('mnist.mat');

% Use the final experiment size
numTrain = 60000;
numTest = 10000;

trainImages = training.images(:,:,1:numTrain);
trainLabels = training.labels(1:numTrain);

testImages = test.images(:,:,1:numTest);
testLabels = test.labels(1:numTest);

% Extract HOG feature size from one image
sampleFeature = extractHOGFeatures(trainImages(:,:,1), 'CellSize', [4 4]);
featureLength = length(sampleFeature);

% Prepare feature matrices
trainFeatures = zeros(numTrain, featureLength);
testFeatures = zeros(numTest, featureLength);

% Extract HOG features for training images
for i = 1:numTrain
    trainFeatures(i,:) = extractHOGFeatures(trainImages(:,:,i), 'CellSize', [4 4]);
end

% Extract HOG features for test images
for i = 1:numTest
    testFeatures(i,:) = extractHOGFeatures(testImages(:,:,i), 'CellSize', [4 4]);
end

% Train multi-class SVM
model = fitcecoc(trainFeatures, trainLabels);

% Predict test labels
predLabels = predict(model, testFeatures);

% Calculate accuracy
accuracy = mean(predLabels == testLabels) * 100;
fprintf('HOG + SVM Test Accuracy: %.2f%%\n', accuracy);

% Confusion matrix
figure;
confusionchart(testLabels, predLabels);
title('HOG + SVM Confusion Matrix');

C = confusionmat(testLabels, predLabels);
perClassAcc = diag(C) ./ sum(C, 2) * 100;

fprintf('\nPer-class accuracy:\n');
for digit = 0:9
    fprintf('Digit %d: %.2f%%\n', digit, perClassAcc(digit + 1));
end