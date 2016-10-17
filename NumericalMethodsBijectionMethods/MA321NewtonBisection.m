function[] = MA321NewtonBisection(eps1, eps2, a, b, f)
format long g
    FAtA = calculateFAtX(a, f);
    FAtB = calculateFAtX(b, f);
    if ((FAtA > 0 && FAtB > 0) || (FAtA < 0 && FAtB < 0))
        disp('f(a) and f(b) dont have opposite signs')
    else
        xapp = bisection(eps1, a, b, f);
        newton(xapp, eps2, 50, f);
    end
end

%calculating f'(x) for some x
function[DerivAtX] = calculateDeriv(XToCalc, f)
    syms x
    deriv=diff(f,x);
    DerivAtX = eval(subs(deriv, XToCalc));
end

%calculating f''(x) at some x (not necessary for this
    %problem but i did this out of my own satisfaction.
function[SecDerivAtX] = CalculateSecondDeriv(XToCalc, f)
    syms x
    deriv=diff(diff(f,x),x);
    SecDerivAtX = eval(subs(deriv, XToCalc));
end

%calculating f(x) at some x
function[FAtX] = calculateFAtX(XToCalc, f)
    FAtX = f(XToCalc);
end

%bisection method phase 
function[xapp] = bisection(eps1, a, b, f)
    disp('ENTERING INTO BISECTION METHOD CALCULATIONS:')
    Fa = calculateFAtX(a, f);
    Fb = calculateFAtX(b, f);
    n=0;
    while (true)
        %find current step's c and error
        c = (a+b)/2;
        err = (b-a)/2;
        
        out = 'The current step is n = %5$+d\nThe current interval is [%1$+.8d,%2$+.8d]\nCurrent C is %3$+.10d \nCurrent error estimate of %4$+.8d\n\n';
        fprintf(out,a,b,c,err,n);
        %some data extraction for personal reasons
        structBisectionData((n+1),1).N=n;
        structBisectionData((n+1),1).A=a;
        structBisectionData((n+1),1).C=c;
        structBisectionData((n+1),1).B=b;
        structBisectionData((n+1),1).Error=err;
        if ( err < eps1 )
            disp('Your error threshold has been met!')
            break
        end
        
        %calculate f(c)
        Fc = calculateFAtX(c, f);
        
        %check if root was found
        if ( Fc == 0 )
            disp('Your root has been found! f(c) = 0!')
            break
        end
        
        %perform interval end-point swap
        if (sign(Fa) == sign(Fc))
            a = c;
            Fa = Fc;
        end
        if (sign(Fb) == sign(Fc))
            b = c;
            Fb = Fc;
        end
        
        %iterate
        n=n+1;
    end
    %use last c as initial approximation for Newton's Method
    xapp = c;
    %looked at the second derivative just for fun (this isn't necessary nor
    %was it asked of me)
    SecDeriv = CalculateSecondDeriv(xapp, f);
    if (SecDeriv < 0)
        disp('WARNING: It seems that f''''(c) < 0. This means that Newton''s Method MAY not converge.')
    end
    %some data extraction for personal reasons
    T = [struct2table(structBisectionData)]
    size(T)
    writetable(T, 'BisectionData.xlsx')
end

%Newton's method phase
function [] = newton(xapp, eps2, maxIters, f)
    disp('ENTERING INTO NEWTON''S METHOD CALCULATIONS:')
    currIters = 0;
    %set starting x
    x = xapp;
    %loop for 50 iteration as defined by instructions
    while (currIters < maxIters)
        %calculate f(x)
        Fx = calculateFAtX(x, f);
        %calculate f'(x)
        DerivFx = calculateDeriv(x, f);
        %find current step's d value
        d = Fx/DerivFx;
        %present step output
        out = 'The current step is n = %3$+d\nThe current approximation is %1$+.10d\nCurrent error estimate of %2$+.8d\n\n';
        fprintf(out,x,abs(d),currIters);
        %some data extraction for personal reasons
        structNewtonsData((currIters+1),1).N=currIters;
        structNewtonsData((currIters+1),1).Xn=x;
        structNewtonsData((currIters+1),1).Error=abs(d);
        
        %get next x value
        x = x - d;
        %check the current step's error values and break if acceptable
        if (abs(d) < eps2)
            out = 'The current step is n = %2$+d\nThe current approximation is %1$+.10d\nThe previous step met your error threshold!\n';
            fprintf(out,x,currIters+1);
            %some data extraction for personal reasons
            structNewtonsData((currIters+2),1).N=currIters+1;
            structNewtonsData((currIters+2),1).Xn=x;
            break
        end
        %iterate
        currIters = currIters + 1;
    end
    %present message if max iterations were reached
    if (currIters == maxIters)
        out = 'The current step is n = %3$+d\nThe current approximation is %1$+.10d\nCurrent error estimate of %2$+.8d\nCalculations have terminated because the allowed maximum number of iterarions has been met.\n';
        fprintf(out,x,abs(d),currIters);
    end
    %some data extraction for personal reasons
    T = [struct2table(structNewtonsData)]
    size(T)
    writetable(T, 'NewtonsData.xlsx')
end