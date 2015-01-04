function [accelvals] = findBestAccels(yfun, tstep, num_steps, t0, init_conditions, accelbounds)

lb = accelbounds(1);
ub = accelbounds(2);

Kp = 40; %Must be tuned
Kd = 10;

%Allocate for speed
accelvals = zeros(num_steps, 1);
yvals = zeros(num_steps, 1);
ydotvals = zeros(num_steps, 1);

%Initialize first values
yvals(1) = init_conditions(1);
ydotvals(1) = init_conditions(2);

tcurrent = t0;

%First, guess some accelerations with PD (because PD is fast to calc)
for k = 1:num_steps
    accelvals(k) = Kp * (yfun(tcurrent) - yvals(k)) - Kd * ydotvals(k);
    tcurrent = tcurrent + tstep;
    yvals(k+1) = yvals(k) + ydotvals(k) * tstep + 0.5 * accelvals(k) * tstep^2;
    ydotvals(k+1) = ydotvals(k) + accelvals(k) * tstep;
end
%accelvals = accelvals.*(accelvals > lb & accelvals < ub) + (accelvals > ub).*ub + (accelvals < lb).*lb;

integral_errors = calcIntegralErrors(yfun, t0, tstep, yvals(1), ydotvals(1), accelvals, 10);

cycles = 20;
N = length(accelvals);
k = 1:N;

algo1err = integral_errors;
algo1acc = accelvals;
algo1sumerror = zeros(1, N)
algo1time = 0;

algo2time = 0;
algo2err = integral_errors;
algo2acc = accelvals;
algo2sumerror = zeros(1, N)
linweights = ones(1,N)./k


algo3time = 0;
algo3err = integral_errors;
algo3acc = accelvals;
algo3sumerror = zeros(1, N)
expweights = exp(-k)


algo4time = 0;
algo4err = integral_errors;
algo4acc = accelvals;
algo4sumerror = zeros(1, N)
quadweights = ones(1,N)./(k.^2)


for i = 1:cycles
    fprintf('Starting round %d of accel fitting\n', i)

    for k = 1:N
        tic;
        algo1acc(k) = algo1acc(k) - (Kd/tstep)*algo1err(k);
        algo1time = algo1time + toc;
        
%         tic;
%         algo2acc(k) = algo2acc(k)  - (Kd/tstep)*(1/sum(linweights(1:end-k+1)))*(linweights(1:end-k+1)*algo2err(k:end));
%         algo2time = algo2time + toc;
% 
%         tic;
%         algo3acc(k) = algo3acc(k)  - (Kd/tstep)*(1/sum(expweights(1:end-k+1)))*(expweights(1:end-k+1)*algo3err(k:end));
%         algo3time = algo3time + toc;
% 
% 
%         tic;
%         algo4acc(k) = algo4acc(k)  - (Kd/tstep)*(1/sum(quadweights(1:end-k+1)))*(quadweights(1:end-k+1)*algo4err(k:end));
%         algo4time = algo4time + toc;
%         
    end
    
    fprintf('Finished round %d of accel fitting\n', i)

    algo1err = calcIntegralErrors(yfun, t0, tstep, yvals(1), ydotvals(1), algo1acc, 10);
    %algo2err = calcIntegralErrors(yfun, t0, tstep, yvals(1), ydotvals(1), algo2acc, 10);
    %algo3err = calcIntegralErrors(yfun, t0, tstep, yvals(1), ydotvals(1), algo3acc, 10);
    %algo4err = calcIntegralErrors(yfun, t0, tstep, yvals(1), ydotvals(1), algo4acc, 10);

    algo1sumerror(i) = sum(algo1err);
%     algo2sumerror(i) = sum(algo2err);
%     algo3sumerror(i) = sum(algo3err);
%     algo4sumerror(i) = sum(algo4err);
end


plot_with_accels(yfun, t0, tstep, num_steps, algo1acc, [yvals(1), ydotvals(1)], 20);
plot_with_accels(yfun, t0, tstep, num_steps, accelvals, [yvals(1), ydotvals(1)], 20,1);

%plot_with_accels(yfun, t0, tstep, num_steps, algo2acc, [yvals(1), ydotvals(1)], 20);
%plot_with_accels(yfun, t0, tstep, num_steps, algo3acc, [yvals(1), ydotvals(1)], 20, 1);
%plot_with_accels(yfun, t0, tstep, num_steps, algo4acc, [yvals(1), ydotvals(1)], 20, 1);

figure(2); clf;
i = 1:cycles;
plot(i, algo1sumerror);

algo1time
algo2time
algo3time
algo4time



end