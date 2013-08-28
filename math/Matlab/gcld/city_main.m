function [ output_args ] = city_main()
%CITY_MAIN Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('cityPosition.txt');

cityPath = importdata('cityPath.txt');
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
    
    x = cat(2,x, cityPosition(cityDst,2));
    y = cat(2,y, cityPosition(cityDst,3));

    p = singlePath(x, y);
    
    length = pathLength(p);
    
    pSize = size(p);
    if pSize(1,2) < 4
        p =  cat(2, zeros(2, 4 - pSize(1,2)), p);
    end
    
    p =  cat(2,[citySrc;cityDst], p);
    p =  cat(2, p, length);
    
    output_args = cat(1, output_args, p);
    
    hold on;
end

drawCity(cityPosition);
end

