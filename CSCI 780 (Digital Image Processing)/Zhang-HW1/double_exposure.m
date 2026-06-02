function out = double_exposure(img1, img2)

% Convert to double to avoid overflow during addition
img1 = double(img1);
img2 = double(img2);

[h1, w1, ~] = size(img1);
[h2, w2, ~] = size(img2);

% Output dimensions
H = max(h1, h2);
W = max(w1, w2);

% Initialize output
out = zeros(H, W, 3);

out(1:h1, 1:w1, :) = out(1:h1, 1:w1, :) + img1; % First image
out(1:h2, 1:w2, :) = out(1:h2, 1:w2, :) + img2; % Second image

out = out / 2; % Avoid saturation by averaging

% Convert back to uint8
out = uint8(out);

end
