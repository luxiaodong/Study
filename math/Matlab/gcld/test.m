function [] = test()
%SINGLEPATHTEST Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('data_city.txt');
row = [32 39 1162 483 1211 513 1242 559 1234 601 1214 621 1177 654 1145 686 1130 709 1130 744];
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

end

