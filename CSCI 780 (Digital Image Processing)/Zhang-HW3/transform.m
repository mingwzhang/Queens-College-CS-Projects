function xformed_image = transform(fixed_pts, moving_pts, moving_image)

fixed_pts = double(fixed_pts);
moving_pts = double(moving_pts);

n = size(fixed_pts, 1);

% Parameter Estimation, Build least-squares system
X = [];
f = [];

for i = 1:n
    x = moving_pts(i,1);
    y = moving_pts(i,2);

    xp = fixed_pts(i,1);
    yp = fixed_pts(i,2);

    % Similarity transform matrix Xi
    Xi = [x  -y  1  0;
          y   x  0  1];

    % Fixed-image target vector fi
    fi = [xp; yp];

    X = [X; Xi];
    f = [f; fi];
end

% Solve for transformation parameters
theta = X \ f;

a = theta(1);
b = theta(2);
tx = theta(3);
ty = theta(4);

% Compute alignment error
total_error = 0;
for i = 1:n
    x = moving_pts(i,1);
    y = moving_pts(i,2);

    xp_est = a*x - b*y + tx;
    yp_est = b*x + a*y + ty;

    xp = fixed_pts(i,1);
    yp = fixed_pts(i,2);

    err = sqrt((xp_est - xp)^2 + (yp_est - yp)^2);
    total_error = total_error + err;
end

mean_error = total_error / n;
disp(['Mean alignment error: ', num2str(mean_error)]);

% Output Initialization
[rows, cols] = size(moving_image);
xformed_image = uint8(ones(rows, cols) * 128);

A = [a -b; b a];
t = [tx; ty];

% Inverse Spatial Mapping, map each output pixel back to source image
for yp = 1:rows
    for xp = 1:cols
        p = [xp; yp] - t;
        original = A \ p;

        % Interpolation, nearest-neighbor sampling
        x = round(original(1));
        y = round(original(2));

        % Boundary Handling, keep gray value for out-of-range pixels
        if x >= 1 && x <= cols && y >= 1 && y <= rows
            xformed_image(yp, xp) = moving_image(y, x);
        end
    end
end

end