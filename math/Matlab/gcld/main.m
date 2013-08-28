function [ output_args ] = main()
%CITY_MAIN Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('data_city.txt');

cityPath = importdata('data_path.txt');
s = size(cityPath);

output_args = [];

for i=1:s(1,1)
    row = cityPath(i,:);
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
    
    pSize = size(p);
    if pSize(1,2) < 4
        p =  cat(2, zeros(2, 4 - pSize(1,2)), p);
    end
    
    drawPathByPoly(p(1,:), p(2,:));
    drawPoints(x, y);

    p =  cat(2,[citySrc;cityDst], p);
    output_args = cat(1, output_args, p);
    
end

drawCity();
end

