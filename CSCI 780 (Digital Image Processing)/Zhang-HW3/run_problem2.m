clc; clear; close all;

fprintf('Running Problem 2 - Watershed Method...\n');
[Lw, avgAreaW, cellAreasW, outW] = problem2_watershed();

fprintf('\nRunning Problem 2 - Region Growing Method...\n');
[Lr, avgAreaR, cellAreasR, outR] = problem2_regiongrowing();

numCellsW = length(cellAreasW);
numCellsR = length(cellAreasR);

% Watershed
figure('Name','Problem 2 - Watershed','Position',[100 100 1400 800]);

subplot(2,4,1);
imshow(outW.I, []);
title('Original Image');

subplot(2,4,2);
imshow(outW.I_smooth, []);
title('Smoothed');

subplot(2,4,3);
imshow(outW.I_noBlobs, []);
title('White Blobs Suppressed');

subplot(2,4,4);
imshow(outW.BW);
title('Clean Cell Mask');

subplot(2,4,5);
imshow(mat2gray(outW.D));
title('Distance Transform');

subplot(2,4,6);
imshow(label2rgb(outW.Lw, 'jet', 'k', 'shuffle'));
title('Watershed Output');

subplot(2,4,7);
imshow(label2rgb(Lw, 'jet', 'k', 'shuffle'));
title('Final Labeled Cells');

subplot(2,4,8);
imshow(outW.I, []);
hold on;
visboundaries(Lw > 0, 'Color', 'r');
title(sprintf('Cells = %d, Avg Area = %.2f', numCellsW, avgAreaW));

% Region-growing 
figure('Name','Problem 2 - Region Growing','Position',[100 100 1400 800]);

subplot(2,4,1);
imshow(outR.I, []);
title('Original Image');

subplot(2,4,2);
imshow(outR.I_noBlobs, []);
title('White Blobs Suppressed');

subplot(2,4,3);
imshow(outR.BWmask);
title('Foreground Mask');

subplot(2,4,4);
imshow(outR.seedMask);
title('Seed Points');

subplot(2,4,5);
imshow(label2rgb(outR.seedLabels, 'jet', 'k', 'shuffle'));
title('Seed Labels');

subplot(2,4,6);
imshow(outR.BW_final);
title('Region Growing Result');

subplot(2,4,7);
imshow(label2rgb(Lr, 'jet', 'k', 'shuffle'));
title('Final Labeled Cells');

subplot(2,4,8);
imshow(outR.I, []);
hold on;
visboundaries(Lr > 0, 'Color', 'g');
title(sprintf('Cells = %d, Avg Area = %.2f', numCellsR, avgAreaR));