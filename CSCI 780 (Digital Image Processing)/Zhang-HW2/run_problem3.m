clear; clc; close all;

src = imread('Atlas-Mercury.png');
target = imread('techno-trousers.png');

result = my_rgb_hist_match(src, target);

% Visual Result
figure('Name', 'Problem 3: Visual Results', 'Position', [100, 100, 1000, 400]);
subplot(1, 3, 1); imshow(src); title('Source Image (Atlas)');
subplot(1, 3, 2); imshow(target); title('Target Image (Trousers)');
subplot(1, 3, 3); imshow(result); title('Matched Result');

% Scientific Verification
out_R = double(result(:,:,1));
tgt_R = double(target(:,:,1));

h_out = zeros(256, 1); h_tgt = zeros(256, 1);
for i = 0:255
    h_out(i+1) = sum(out_R(:) == i);
    h_tgt(i+1) = sum(tgt_R(:) == i);
end

% Compute the final CDFs
cdf_out = cumsum(h_out) / numel(out_R);
cdf_tgt = cumsum(h_tgt) / numel(tgt_R);

% Plot the CDF curves to prove they match
figure('Name', 'Scientific Verification');
plot(0:255, cdf_tgt, 'b-', 'LineWidth', 3); hold on;
plot(0:255, cdf_out, 'r--', 'LineWidth', 2);
title('Scientific Proof: Red Channel CDF Comparison');
xlabel('Pixel Intensity'); ylabel('Cumulative Probability');
legend('Target CDF', 'Matched Output CDF', 'Location', 'best');
grid on;