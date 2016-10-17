function [] = MA321Project2Problem2(Xnaught, eps,f)
    disp('No adjustment:')
    newton(Xnaught, eps, 50, f);
    disp('With adjustment:')
    newNewton(Xnaught, eps, 50, f);
end

%just finding the first derivative at some x
function[DerivAtX] = calculateDeriv(XToCalc, f)
    syms x
    deriv=diff(f,x);
    DerivAtX = eval(subs(deriv, XToCalc));
end

%just finding the second derivative at some x
function[SecDerivAtX] = CalculateSecondDeriv(XToCalc, f)
    syms x
    deriv=diff(diff(f,x),x);
    SecDerivAtX = eval(subs(deriv, XToCalc));
end

%finding f(x) for some x
function[FAtX] = calculateFAtX(XToCalc, f)
    FAtX = f(XToCalc);
end

%calculating h for some x
function[F_at_x_h_offset] = calculateOffsetFAtX(XToCalc, f)
    %calculate f(x) at current x
    F = calculateFAtX(XToCalc, f);
    %calculate f'(x) at current x
    Fprime = calculateDeriv(XToCalc, f);
    %calculate f''(x) at current x
    FtwoPrime = CalculateSecondDeriv(XToCalc, f);
    %get proper roots of the second order differential
    %f(x)+f'(x)*h+0.5*f''(x)*h^2=0
    %loff of significance avoidance just in case
    if (Fprime > 0)
        h = ((2*F)/(-Fprime-sqrt((Fprime)^2-2*FtwoPrime*F)));
    else
        h = ((2*F)/(-Fprime+sqrt((Fprime)^2-2*FtwoPrime*F)));
    end
    disp(h);
    F_at_x_h_offset = h;
end

%original newton's method
function [] = newton(xapp, eps2, maxIters, f)
    disp('ENTERING INTO NEWTON''S METHOD CALCULATIONS:')
    currIters = 0;
    x = xapp;
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

%modified newton's method
function [] = newNewton(xapp, eps2, maxIters, f)
    disp('ENTERING INTO NEWTON''S METHOD CALCULATIONS:')
    currIters = 0;
    %set starting x
    x = xapp;
    while (currIters < maxIters)
        %calculate f(x)
        Fx = calculateFAtX(x, f);
        %calculate f'(x)
        DerivFx = calculateDeriv(x, f);
        %find current step's h value (used as more accurate error value
        %here)
        h = calculateOffsetFAtX(x, f);
         %present step output
        out = 'The current step is n = %3$+d\nThe current approximation is %1$+.10d\nCurrent error estimate of %2$+.8d\n\n';
        fprintf(out,x,abs(h),currIters);
        %some data extraction for personal reasons
        structNewNewtonsData((currIters+1),1).N=currIters;
        structNewNewtonsData((currIters+1),1).Xn=x;
        structNewNewtonsData((currIters+1),1).Error=abs(h);
        
        %get next x value
        x = x + h;
        %check the current step's error values and break if acceptable
        if (abs(h) < eps2)
            out = 'The current step is n = %2$+d\nThe current approximation is %1$+.10d\nThe previous step met your error threshold!\n';
            fprintf(out,x,currIters+1);
            %some data extraction for personal reasons
            structNewNewtonsData((currIters+2),1).N=currIters+1;
            structNewNewtonsData((currIters+2),1).Xn=x;
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
    T = [struct2table(structNewNewtonsData)]
    size(T)
    writetable(T, 'NewNewtonsData.xlsx')
end