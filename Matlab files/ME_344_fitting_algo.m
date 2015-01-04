%profile on

%% First define the desired path y(t)
%y = @(t) 4*sin(2*pi*t).*((t<2)&(t>=0)) + 1.5*(cos(4*pi*t)-1).*((t>=2)&(t<3))+(exp(t)-1-exp(3)).*(t>3);
y = @(t) 2*t.*((t>=0)&(t<1)) + 2 * (t>=1 & t<2) + 2*(1-sin(pi*t)).*(t>=2 & t<=3.5) + (t>3.5 & t<=5.5).*(square(pi*t, 33) + 2) + (t>5.5).*1;

%% Define the time range (number of total points) and step size (in seconds)
time_range = 1; %seconds to attempt to predict
num_of_parabolas = 40*time_range; %in the time_range seconds of prediction
max_accel = 4000;

%% Define the initial conditions: initial time, initial position, initial first derivative
t0 = 3.5;
y0 = 0;
y0_dot = 0;

tstep = time_range / num_of_parabolas;

lb = ones(num_of_parabolas, 1)*-1*max_accel;
ub = ones(num_of_parabolas, 1)*max_accel;

%% First-order PD estimation accelerations values
%Allocate for speed
accelvals = zeros(num_of_parabolas, 1);
yvals = zeros(num_of_parabolas, 1);
ydotvals = zeros(num_of_parabolas, 1);

%Initialize first values
yvals(1) = y0;
ydotvals(1) = y0_dot;
tcurrent = t0;

%Set gains
Kp = 80; %Must be tuned
Kd = 20;

%First, guess some accelerations with PD (because PD is fast to calc)
for k = 1:num_of_parabolas
    accelvals(k) = Kp * (y(tcurrent) - yvals(k)) - Kd * ydotvals(k);
    tcurrent = tcurrent + tstep;
    yvals(k+1) = yvals(k) + ydotvals(k) * tstep + 0.5 * accelvals(k) * tstep^2;
    ydotvals(k+1) = ydotvals(k) + accelvals(k) * tstep;
end


%% Minimization of sum squared integral errors
options = optimoptions('fmincon','UseParallel',1); 
options = optimoptions(options,'Algorithm', 'interior-point');
%options = optimoptions(options,'Display', 'iter-detailed');
options = optimoptions(options,'MaxIter', 1000);
options = optimoptions(options,'MaxFunEvals', 10000);
%options = optimoptions(options,'PlotFcns', { @optimplotfval });

[best_accels, sse, exitflag] = fmincon(@(accels_dum) sum(calcIntegralErrors(y, t0, tstep, y0, y0_dot, accels_dum, 10).^2), accelvals, [], [], [], [], lb, ub, [], options);
plot_with_accels(y, t0, tstep, num_of_parabolas, best_accels, [y0,y0_dot], 50)
plot_with_accels(y, t0, tstep, num_of_parabolas, accelvals, [y0,y0_dot], 50, 1, 'r-.')

% 
% profile viewer
% profile off