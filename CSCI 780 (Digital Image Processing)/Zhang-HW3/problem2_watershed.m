function [L, avgArea, cellAreas, out] = problem2_watershed()

% Preprocessing, read image and convert to grayscale
I = imread('Fig1118(a).tif');
if size(I,3) == 3
    I = rgb2gray(I);
end
I = im2double(I);

I_smooth = imgaussfilt(I, 1);

% Remove bright blobs inside cells
se = strel('disk', 5);
I_noBlobs = imopen(I_smooth, se);

% Foreground Mask Generation, binary mask using thresholding
T = graythresh(I_noBlobs);
BW = imbinarize(I_noBlobs, T);

% Clean mask
BW = imfill(BW, 'holes');
BW = bwareaopen(BW, 80);
BW = imopen(BW, strel('disk', 2));
BW = imclose(BW, strel('disk', 3));

% Distance Transform
D = bwdist(~BW);

% Watershed Segmentation, watershed transform to separate touching cells
Dmod = -D;
Dmod(~BW) = -Inf;
Dmod = imhmin(Dmod, 1.5);

Lw = watershed(Dmod);

% Final Labeling
BW_final = BW;
BW_final(Lw == 0) = 0;

L = bwlabel(BW_final);

% Area measurement
stats = regionprops(L, 'Area');
cellAreas = [stats.Area];
avgArea = mean(cellAreas);

% Outputs for run_problem2
out.I = I;
out.I_smooth = I_smooth;
out.I_noBlobs = I_noBlobs;
out.BW = BW;
out.D = D;
out.Lw = Lw;
out.BW_final = BW_final;

end