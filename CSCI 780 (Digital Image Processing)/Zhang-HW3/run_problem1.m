clc; clear; close all;

% Read fixed and moving images
fixed = imread('BrainProtonDensitySliceBorder20.png');
moving = imread('BrainProtonDensitySliceR10X13Y17.png');

if size(fixed,3) == 3
    fixed = rgb2gray(fixed);
end

if size(moving,3) == 3
    moving = rgb2gray(moving);
end

% Corresponding control points
fixed_pts = [
    86 99;
    136 101;
    96 159;
    125 154;
    48 128;
    177 134;
    169 89;
    161 84;
    144 58;
    60 81
];

moving_pts = [
    106 112;
    153 121;
    104 172;
    134 172;
    62 133;
    188 161;
    187 116;
    180 109;
    169 81;
    82 89
];

% Apply similarity transformation
result = transform(fixed_pts, moving_pts, moving);

% Show registration result
figure('Name','Problem 1 - Registration','Position',[100 100 1200 400]);

subplot(1,3,1);
imshow(fixed, []);
title('Fixed Image');

subplot(1,3,2);
imshow(moving, []);
title('Moving Image');

subplot(1,3,3);
imshow(result, []);
title('Transformed Image');