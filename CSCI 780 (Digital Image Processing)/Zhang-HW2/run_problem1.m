

img1 = imread('Everest_expedition.jpg');
img2 = imread('Everest_kalapatthar.jpg');

% Apply the custom RGB to YCbCr conversion on the first image
my_ycbcr1 = my_rgb2ycbcr(img1);
toolbox_ycbcr1 = rgb2ycbcr(img1);

% Compute maximum difference between implementations
diff_expedition = max(abs(double(my_ycbcr1(:)) - double(toolbox_ycbcr1(:))));
disp(['Max diff for Expedition (RGB->YCbCr): ', num2str(diff_expedition)]);

% Repeat verification for the second image
my_ycbcr2 = my_rgb2ycbcr(img2);
toolbox_ycbcr2 = rgb2ycbcr(img2);

diff_kalapatthar = max(abs(double(my_ycbcr2(:)) - double(toolbox_ycbcr2(:))));
disp(['Max diff for Kalapatthar (RGB->YCbCr): ', num2str(diff_kalapatthar)]);

dark_img = reduce_luminance(img1);

figure;

% Show the original RGB image
subplot(1, 2, 1);
imshow(img1);
title('Original Expedition RGB');

% Show the RGB image after reducing the luminance channel
subplot(1, 2, 2);
imshow(dark_img);
title('Reduced Luminance in RGB');