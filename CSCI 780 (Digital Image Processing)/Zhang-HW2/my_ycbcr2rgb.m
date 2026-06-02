function rgb_img = my_ycbcr2rgb(ycbcr_img)
    ycbcr = double(ycbcr_img);

    Y  = ycbcr(:,:,1) - 16;
    Cb = ycbcr(:,:,2) - 128;
    Cr = ycbcr(:,:,3) - 128;

    % Define the original transformation matrix 
    T = [ 65.481,  128.553,  24.966;
         -37.797,  -74.203, 112.000;
         112.000,  -93.786, -18.214];

    T_inv = inv(T);

    % Apply the inverse matrix to get R, G, B back
    R = T_inv(1,1)*Y + T_inv(1,2)*Cb + T_inv(1,3)*Cr;
    G = T_inv(2,1)*Y + T_inv(2,2)*Cb + T_inv(2,3)*Cr;
    B = T_inv(3,1)*Y + T_inv(3,2)*Cb + T_inv(3,3)*Cr;

    % Scale back up to [0, 255] and convert to uint8
    rgb_img = cat(3, R, G, B) * 255.0;
    rgb_img = uint8(round(rgb_img));
end