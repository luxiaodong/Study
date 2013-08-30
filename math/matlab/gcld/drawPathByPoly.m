function [] = drawPathByPoly(px, py)
%DRAWPATHBYPOLY Summary of this function goes here
%   Detailed explanation goes here

j = linspace(0,1,100);
xx = polyval(px, j);
yy = polyval(py, j);

plot(xx, yy);
hold on;

end

