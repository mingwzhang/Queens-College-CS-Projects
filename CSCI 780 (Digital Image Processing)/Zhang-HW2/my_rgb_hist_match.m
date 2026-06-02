function out = my_rgb_hist_match(src, target)

    % Convert images to double for computation
    src = double(src);
    target = double(target);
    out = zeros(size(src));

    % Loop through Red, Green, and Blue channels
    for c = 1:3
        src_c = src(:,:,c);
        tgt_c = target(:,:,c);

        hist_src = zeros(256, 1);
        hist_tar = zeros(256, 1);
        for i = 0:255
            hist_src(i+1) = sum(src_c(:) == i);
            hist_tar(i+1) = sum(tgt_c(:) == i);
        end

        pdf_src = hist_src / numel(src_c);
        pdf_tar = hist_tar / numel(tgt_c);

        cdf_src = cumsum(pdf_src);
        cdf_tar = cumsum(pdf_tar);

        map = zeros(256, 1);
        for i = 1:256

            [~, idx] = min(abs(cdf_src(i) - cdf_tar));
            map(i) = idx - 1; 
        end

        out(:,:,c) = map(src_c + 1);
    end

    % Convert back to standard 8-bit image format
    out = uint8(out);
end