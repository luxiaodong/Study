function [ output_args ] = city_main( input_args )
%CITY_MAIN Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('cityPosition.txt');

cityPath = importdata('cityPath.txt');
s = size(cityPath);

% output_args = s(1,2);

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

    singlePath(x, y);
    hold on;
end

drawCity(cityPosition);
end

