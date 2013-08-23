function [ output_args ] = city_main( input_args )
%CITY_MAIN Summary of this function goes here
%   Detailed explanation goes here

cityPath = importdata('cityPath.txt');
s = size(cityPath);

% output_args = s(1,2);

for i=1:s(1,1)
    row = cityPath(i,:);
    x=[];
    y=[];
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

    singlePath(x, y);
    hold on;
end

cityPosition = load('cityPosition.txt');
drawCity(cityPosition);
   
end

