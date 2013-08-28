function [ times ] = pathLength( polyRow )
%PATHLENGTH Summary of this function goes here
%   Detailed explanation goes here

s = 0;
polyX = polyRow(1,:);
polyY = polyRow(2,:);
x0 = polyval(polyX, 0);
y0 = polyval(polyY, 0);
t = 0.001;
while t < 1
    x1 = polyval(polyX, t);
    y1 = polyval(polyY, t);
    s = s + sqrt( (x1 - x0)^2 + (y1 - y0)^2 );
    x0 = x1;
    y0 = y1;
    t = t + 0.001;
end

count = ceil( s/20 );
value = linspace(0,s,count);

times = [];
x0 = polyval(polyX, 0);
y0 = polyval(polyY, 0);
t = 0.001;
s = 0;
valueIndex = 2;
while t < 1
    x1 = polyval(polyX, t);
    y1 = polyval(polyY, t);
    s = s + sqrt( (x1 - x0)^2 + (y1 - y0)^2 );
    
    if s > value(1, valueIndex)
        times = cat(2, times, t);
        valueIndex = valueIndex + 1;
    end
    
    x0 = x1;
    y0 = y1;
    t = t + 0.001;
end


end

