function [ ] = drawPathByPolyAndTimes( px, py, t )
%DRAWPATHBYPOLYANDTIMES Summary of this function goes here
%   Detailed explanation goes here

xx = polyval(px, t);
yy = polyval(py, t);

plot(xx,yy,'r*');
end

