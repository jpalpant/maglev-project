clear
y = @(t) 2.*((t>=0)&(t<2)) + 2*(1-sin(pi*t)).*(t>=2 & t<=3.5) + (t>3.5).*(square(pi*t, 33) + 2);

%% Define the initial conditions: initial time, initial position, initial first derivative
t0 = 0;
y0 = 1;
y0_dot = 15;
time_range = 2.5;


maxvectorlength = 100;
maxnumpts = 100;
times = zeros(maxnumpts, maxvectorlength);
parfor k = 1:maxnumpts
    for i = 1:maxvectorlength
        vals = rand(1,i*10);
        tstep = time_range/i;
        tic;
        err = calcIntegralErrors(y, t0, tstep, y0, y0_dot, vals, 10*k);
        times(k,i) = toc;
        fprintf('[%d, %d]\n',k,i)
    end
end

[meshpts, meshvectorlength] = meshgrid(1:maxnumpts, 1:maxvectorlength);

meshc(meshpts, meshvectorlength, times);
xlabel('Number of integral points')
ylabel('Length of vector integrated')
zlabel('Time (s)')