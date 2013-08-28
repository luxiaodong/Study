function [ output_args ] = singlePathTest()
%SINGLEPATHTEST Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('cityPosition.txt');
row = [130 163 3855 617 3902 619 3951 608 3978 594 4001 563 4013 531 4014 496];
s = size(row);

citySrc = row(1,1);
x= cityPosition(citySrc,2);
y= cityPosition(citySrc,3);
for j=3:s(1,2)
    value = row(1, j);
    if isnan(value)
        break;
    else
        if mod(j,2) == 1
            x = cat(2,x, value);
        else
            y = cat(2,y, 3600 - value);
        end
    end
end

cityDst = row(1,2);

x = cat(2, x, cityPosition(cityDst,2));
y = cat(2, y, cityPosition(cityDst,3));

polyRow = singlePath(x, y);
hold on;
times = pathLength( polyRow );
xx = polyval(polyRow(1,:), times);
yy = polyval(polyRow(2,:), times);

plot(xx,yy,'r*');


end

