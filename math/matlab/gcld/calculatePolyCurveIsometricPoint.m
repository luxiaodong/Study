function [ times ] = calculatePolyCurveIsometricPoint(px, py)
%POLYCURVELENGTH Summary of this function goes here
%   Detailed explanation goes here

s = 0;
x0 = polyval(px, 0);
y0 = polyval(py, 0);
t = 0.001;
while t < 1
    x1 = polyval(px, t);
    y1 = polyval(py, t);
    s = s + sqrt( (x1 - x0)^2 + (y1 - y0)^2 );
    x0 = x1;
    y0 = y1;
    t = t + 0.001;
end

count = ceil( s/25 );
value = linspace(0,s,count);

times = [];
x0 = polyval(px, 0);
y0 = polyval(py, 0);
t = 0.001;
s = 0;
valueIndex = 2;
while t < 1
    x1 = polyval(px, t);
    y1 = polyval(py, t);
    s = s + sqrt( (x1 - x0)^2 + (y1 - y0)^2 );
    
    if s > value(1, valueIndex)
        times = cat(2, times, t - 0.001);
        valueIndex = valueIndex + 1;
    end
    
    x0 = x1;
    y0 = y1;
    t = t + 0.001;
end

end

