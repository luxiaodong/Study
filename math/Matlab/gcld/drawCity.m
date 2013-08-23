function [ output_args ] = drawCity( input_args )
%DRAWCITY Summary of this function goes here
%   Detailed explanation goes here

X = input_args(:,2);
Y = input_args(:,3);

plot(X, Y, 'r*');
axis([0 6000 0 3600]);

end

