function [integral_errors] = calcIntegralErrors(yfun, t0, tstep, y0, ydot0, accelvals, integralN) 
yvals(1) = y0;
ydotvals(1) = ydot0;
for k = 1:length(accelvals)-1
    yvals(k+1) = yvals(k) + ydotvals(k) * tstep + 0.5 * accelvals(k) * tstep^2;
    ydotvals(k+1) = ydotvals(k) + accelvals(k) * tstep;
end


n = length(accelvals);
integral_errors = zeros(n, 1);
trapzintegral_errors = zeros(n, 1);

%Determine weights for nested trapezoidal method for vectorized integration
N = integralN+1;
tblock = linspace(0, tstep, N);
w = 2 * ones(1, N);
w(1) = 1;
w(end) = 1;
w = tstep/(2*integralN) * w;
mytime = 0;
their_time = 0;

parfor k = 1:n
    errors = -yfun(tblock + t0 + tstep*(k-1)) + (yvals(k) + ydotvals(k)*tblock + 0.5*accelvals(k)*tblock.^2)
    tic;
    integral_errors(k) = w * errors';
    mytime = mytime + toc;
    
%     tic;
%     trapzintegral_errors(k) = trapz(errors);
%     their_time = their_time + toc;
    
end

% mytime
% 
% their_time
% 
% ratio = their_time/mytime

end