img = imread('LENNA.JPG');

% Convert to grayscale only if it is an RGB image
if size(img, 3) == 3
    gray = rgb2gray(img);
else
    gray = img;
end

% Case 1: remove lower 3 bits
low_removed = bitand(gray, 248);

% Case 2: remove higher bits
high_removed = bitand(gray, 7); 

figure

subplot(3,2,1)
imshow(gray)
title('Original Image')

subplot(3,2,2)
imhist(gray)
title('Original Histogram')

subplot(3,2,3)
imshow(low_removed)
title('Lower Bit Planes Removed')

subplot(3,2,4)
imhist(low_removed)
title('Histogram (Lower Bits Removed)')

subplot(3,2,5)

imshow(high_removed, [])
title('Higher Bit Planes Removed')

subplot(3,2,6)
imhist(high_removed)
title('Histogram (Higher Bits Removed)')