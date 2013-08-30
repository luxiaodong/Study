function [P]=bezier(x,y)

%
%bezier(x,y)
%bezier([5,6,10,12],[0 5 -5 -2])

n=length(x); 
t=linspace(0,1); 
xx=0;yy=0; 
for k=0:n-1 
    tmp=nchoosek(n-1,k)*t.^k.*(1-t).^(n-1-k); 
    xx=xx+tmp*x(k+1); 
    yy=yy+tmp*y(k+1); 
end 

P=[xx;yy];

% axis equal;
plot(xx,yy);
% hold on;
plot(x,y,'+r');

end

