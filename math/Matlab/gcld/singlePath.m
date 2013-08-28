function [ output_args ] = singlePath(x, y)
%SINGLEPATH Summary of this function goes here
%   Detailed explanation goes here

if length(x) ~= length(y)
    output_args = 0;
end
size = length(x);
rank = size - 1;
if rank > 3
    rank = 3;
end
k = [1:size];
i = (k - 1)./(size - 1);
px = polyfit(i,x,rank);
py = polyfit(i,y,rank);

j = linspace(0,1,100);
xx = polyval(px, j);
yy = polyval(py, j);

plot(xx, yy);
hold on;
plot(x,y,'*');
output_args = [px;py];
end

