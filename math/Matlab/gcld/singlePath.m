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
i = [1:size];
px = polyfit(i,x,rank)
py = polyfit(i,y,rank)

j = linspace(1,size,100);
xx = polyval(px, j);
yy = polyval(py, j);

plot(xx, yy);
hold on;
plot(x,y,'*');

end

