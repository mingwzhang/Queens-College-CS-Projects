function ycbcr_img = my_rgb2ycbcr(rgb_img)
    rgb = double(rgb_img) / 255.0;

    % Extract individual R, G, B channels
    R = rgb(:,:,1);
    G = rgb(:,:,2);
    B = rgb(:,:,3);

    Y  = 16  +  65.481 * R + 128.553 * G +  24.966 * B;
    Cb = 128 -  37.797 * R -  74.203 * G + 112.000 * B;
    Cr = 128 + 112.000 * R -  93.786 * G -  18.214 * B;

    % Combine channels and convert back to uint8 format
    ycbcr_img = cat(3, Y, Cb, Cr);
    ycbcr_img = uint8(round(ycbcr_img));
end