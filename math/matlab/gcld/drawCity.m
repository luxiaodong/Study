function [] = drawCity()
%DRAWCITY Summary of this function goes here
%   Detailed explanation goes here

cityPosition = load('data_city.txt');

X = cityPosition(:,2);
Y = cityPosition(:,3);

plot(X, Y, 'r*');
axis([0 6000 0 3600]);
hold on;

end

