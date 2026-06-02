clear; clc; close all;

img = imread('LENNA.JPG');

% Convert to grayscale and then to double
if size(img, 3) == 3
    gray = rgb2gray(img);
else
    gray = img;
end
gray = double(gray); % For Laplacian math

avg_filter = fspecial('average', [3 3]);
lap_filter = fspecial('laplacian', 0); 

% Case 1: Averaging then Laplacian
avg_first = imfilter(gray, avg_filter, 'replicate');
result1 = imfilter(avg_first, lap_filter, 'replicate');

% Case 2: Laplacian then Averaging
lap_first = imfilter(gray, lap_filter, 'replicate');
result2 = imfilter(lap_first, avg_filter, 'replicate');

% Scientific Verification
diff_val = max(abs(result1(:) - result2(:)));

figure('Name', 'Problem 4: Filter Order Analysis');

subplot(1,3,1)
imshow(uint8(gray))
title('Original Gray')

subplot(1,3,2)
imshow(result1, []) 
title('Avg -> Laplacian')

subplot(1,3,3)
imshow(result2, []) 
title('Laplacian -> Avg')

fprintf('The maximum difference between the two orders is: %e\n', diff_val);