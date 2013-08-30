function [times] = test()
%SINGLEPATHTEST Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('data_city.txt');
%row = [150 152 3394 2603 3446 2605 3542 2590 3643 2573 3726 2555 3793 2538];
row = [147 152 3573 2362 3584 2400 3619 2448 3672 2482 3719 2504 3782 2505];
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
drawPathByPoly(p(1,:), p(2,:));
drawPoints(x, y);
times = calculatePolyCurveIsometricPoint(p(1,:), p(2,:));
drawPathByPolyAndTimes(p(1,:), p(2,:), times);
set(gca,'DataAspectRatio',[1 1 1])
end

