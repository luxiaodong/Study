function [ p ] = findPolyByPoints( X , Y )
%FINDPOLYBYPOINTS Summary of this function goes here
%   Detailed explanation goes here

if length(X) ~= length(Y)
    p = 0;
    return ;
end

size = length(X);
rank = size - 1;
if rank > 3
    rank = 3;
end
k = [1:size];
i = (k - 1)./(size - 1);

px = polyfit(i,X,rank);
py = polyfit(i,Y,rank);

p = [px;py];

end

