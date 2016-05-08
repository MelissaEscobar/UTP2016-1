%Nice Surfing OCTAVE
x = 2:0.2:4; % Define the x- and y- coordinates
 y = 1:0.2:3; % of the grid lines
 [X,Y] = meshgrid(x, y); %Make the grid
 Z=(X-3).^2 - (Y-2).^2;
 surf(X,Y,Z) 
