function [L, avgArea, cellAreas, out] = problem2_regiongrowing()

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

% Initial cell mask
T = graythresh(I_noBlobs);
BWmask = imbinarize(I_noBlobs, T);
BWmask = imfill(BWmask, 'holes');
BWmask = bwareaopen(BWmask, 80);
BWmask = imopen(BWmask, strel('disk', 2));
BWmask = imclose(BWmask, strel('disk', 3));

% Seed Initialization
D = bwdist(~BWmask);
seedMask = imextendedmax(D, 2);
seedMask = seedMask & BWmask;
seedMask = bwareaopen(seedMask, 3);
seedMask = bwmorph(seedMask, 'shrink', Inf);

[seedLabels, numSeeds] = bwlabel(seedMask);

% Region Growth, parameters
localTol = 0.035;
seedTol = 0.12;
minCellArea = 80;

L = zeros(size(I));
seedValue = zeros(numSeeds, 1);

% Initialize queue
[seedRows, seedCols] = find(seedLabels > 0);
queue = zeros(nnz(BWmask), 3);
head = 1;
tail = 0;

for i = 1:numel(seedRows)
    r = seedRows(i);
    c = seedCols(i);
    lbl = seedLabels(r, c);

    if L(r, c) == 0
        L(r, c) = lbl;
        seedValue(lbl) = I_noBlobs(r, c);

        tail = tail + 1;
        queue(tail, :) = [r, c, lbl];
    end
end

% 8-connected neighbors
neigh = [-1  0;
          1  0;
          0 -1;
          0  1;
         -1 -1;
         -1  1;
          1 -1;
          1  1];

% Grow regions
while head <= tail
    cur = queue(head, :);
    head = head + 1;

    r = cur(1);
    c = cur(2);
    lbl = cur(3);

    currentVal = I_noBlobs(r, c);

    for n = 1:size(neigh, 1)
        nr = r + neigh(n, 1);
        nc = c + neigh(n, 2);

        if nr < 1 || nr > size(I,1) || nc < 1 || nc > size(I,2)
            continue;
        end

        if ~BWmask(nr, nc) || L(nr, nc) ~= 0
            continue;
        end

        candidateVal = I_noBlobs(nr, nc);

        if abs(candidateVal - currentVal) <= localTol && ...
           abs(candidateVal - seedValue(lbl)) <= seedTol

            L(nr, nc) = lbl;

            tail = tail + 1;
            queue(tail, :) = [nr, nc, lbl];
        end
    end
end

% Remaining Pixel Assignment, assign all remaining mask pixels to nearest grown region
remaining = BWmask & (L == 0);
numLabels = max(L(:));

if numLabels > 0 && any(remaining(:))
    distStack = inf([size(L), numLabels]);

    for k = 1:numLabels
        maskK = (L == k);
        if any(maskK(:))
            distStack(:,:,k) = bwdist(maskK);
        end
    end

    [~, nearestLabel] = min(distStack, [], 3);
    L(remaining) = nearestLabel(remaining);
end

% Hole Filling, clean labels and fill holes
labels = unique(L(:));
labels(labels == 0) = [];

L_clean = zeros(size(L));
cellAreas = [];
nextLabel = 0;

for k = 1:numel(labels)
    mask = (L == labels(k));
    mask = mask & BWmask;
    mask = imfill(mask, 'holes');

    areaK = nnz(mask);

    if areaK >= minCellArea
        nextLabel = nextLabel + 1;
        L_clean(mask) = nextLabel;
        cellAreas(end+1) = areaK;
    end
end

L = L_clean;

% Area measurement
if isempty(cellAreas)
    avgArea = 0;
else
    avgArea = mean(cellAreas);
end

% Outputs for run_problem2
out.I = I;
out.I_smooth = I_smooth;
out.I_noBlobs = I_noBlobs;
out.BWmask = BWmask;
out.D = D;
out.seedMask = seedMask;
out.seedLabels = seedLabels;
out.BW_final = L > 0;

end