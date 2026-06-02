function dark_rgb = reduce_luminance(rgb_img)
    % Convert to YCbCr 
    ycbcr_img = my_rgb2ycbcr(rgb_img);

    % Reduce luminance (Y) by half 
    ycbcr_img(:,:,1) = ycbcr_img(:,:,1) * 0.5;

    % Convert back to RGB 
    dark_rgb = my_ycbcr2rgb(ycbcr_img);
end