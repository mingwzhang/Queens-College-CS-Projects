% Test script for double exposure

% Read images
img1 = imread('Everest_expedition.jpg');
img2 = imread('Everest_kalapatthar.jpg');

% Call function
result = double_exposure(img1, img2);

% Display images
% figure
% subplot(1,3,1)
% imshow(img1)
% title('Image 1')
% 
% subplot(1,3,2)
% imshow(img2)
% title('Image 2')

figure
imshow(result)
title('Double Exposure Result')


saveas(gcf, 'figure2.png')
