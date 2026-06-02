clear; clc; close all;

% Purpose: Generate comparison figures for Raw Pixel + SVM and HOG + SVM.

% Experiment setup:
%   Training images: 60,000
%   Test images: 10,000

% Overall accuracy results manually entered from the outputs of train_svm_rawpixel.m and train_svm_hog.m

methods = categorical({'Raw Pixel + SVM', 'HOG + SVM'});
methods = reordercats(methods, {'Raw Pixel + SVM', 'HOG + SVM'});

overallAccuracy = [94.38, 98.83];

figure;
bar(methods, overallAccuracy);
title('Overall Accuracy Comparison');
ylabel('Accuracy (%)');
ylim([90 100]);
grid on;

for i = 1:length(overallAccuracy)
    text(i, overallAccuracy(i) + 0.2, sprintf('%.2f%%', overallAccuracy(i)), ...
        'HorizontalAlignment', 'center', ...
        'FontWeight', 'bold');
end


% Per-class accuracy results manually entered from the outputs of train_svm_rawpixel.m and train_svm_hog.m

digits = 0:9;

rawPixelAcc = [97.76, 98.59, 93.51, 93.56, 95.72, ...
90.25, 95.62, 93.68, 91.07, 93.16];

hogAcc = [99.69, 99.47, 98.84, 98.71, 98.88, ...
98.99, 98.85, 98.15, 98.46, 98.22]; 

figure;
bar(digits, [rawPixelAcc(:), hogAcc(:)]);
title('Per-Class Accuracy Comparison');
xlabel('Digit');
ylabel('Accuracy (%)');
legend('Raw Pixel + SVM', 'HOG + SVM', ...
       'Location', 'southoutside', 'Orientation', 'horizontal');
xticks(0:9);
ylim([85 100]);
grid on;


% Display numerical table for report notes
perClassTable = table(digits(:), rawPixelAcc(:), hogAcc(:), ...
    'VariableNames', {'Digit', 'RawPixel_SVM_Accuracy', 'HOG_SVM_Accuracy'});

disp('Per-Class Accuracy Comparison:');
disp(perClassTable);