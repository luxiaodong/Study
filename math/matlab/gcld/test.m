function [times] = test()
%SINGLEPATHTEST Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('data_city.txt');
%row = [150 152 3394 2603 3446 2605 3542 2590 3643 2573 3726 2555 3793 2538];
row = [61 102 1990 2030];
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

p = findPolyByPoints(x ,y);

% pSize = size(p);
% if pSize(1,2) < 4
%     XY = bezier(x, y);
%     p = findPolyByPoints(XY(1,:), XY(2,:));
% end

drawPathByPoly(p(1,:), p(2,:));
drawPoints(x, y);
times = calculatePolyCurveIsometricPoint(p(1,:), p(2,:));
drawPathByPolyAndTimes(p(1,:), p(2,:), times);

% times = bezier(x,y);

set(gca,'DataAspectRatio',[1 1 1])
end

