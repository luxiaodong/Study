function [ ] = main()
%CITY_MAIN Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('data_city.txt');

cityPath = importdata('data_path.txt');
s = size(cityPath);

% path_poly = [];
% times = [];

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
         XY = bezier(x, y);
         p = findPolyByPoints(XY(1,:), XY(2,:));
%         p =  cat(2, zeros(2, 4 - pSize(1,2)), p);
    end
    
    t = calculatePolyCurveIsometricPoint( p(1,:), p(2,:) );
    t = cat(2, [citySrc, cityDst], t);
    dlmwrite('timeTable.txt',t,'delimiter','\t','newline','pc','-append');
    
    drawPathByPoly(p(1,:), p(2,:));
    drawPoints(x, y);

    p =  cat(2,[citySrc;cityDst], p);
    dlmwrite('polyTable.txt',p,'delimiter','\t','newline','pc','-append');
end

drawCity();
set(gca,'DataAspectRatio',[1 1 1])

end

