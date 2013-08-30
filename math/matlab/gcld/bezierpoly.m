function B = bezierpoly(n)
    
    for i=0:n
        a=strcat('p',num2str(i)); 
        b=['syms ' a];
        eval(b);
    end

    aa='p0';
    for i=1:n
        a=strcat('p',num2str(i));  
        aa=[aa,',',a];
    end
    eval(['P=[',aa,'];']);
    
    syms t;
    syms f;
    f = 0;
    for i=0:n
        f = f + nchoosek(n,i)*(t^i)*(1-t)^(n-i)*P(i+1);
    end
    
    B = collect(f);
end




