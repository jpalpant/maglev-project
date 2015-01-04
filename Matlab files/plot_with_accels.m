function [] = plot_with_accels(yfun, t0, tstep, num_steps, accels, initvals, points_per_step, fignum, linestyle)

tplot = linspace(t0, t0 + tstep*num_steps, points_per_step*num_steps);
yplot = yfun(tplot);

if(nargin == 8 || nargin == 9)
    figure(fignum);
else
    figure(1); clf
    plot(tplot, yplot, 'k-')
end
hold on

ystart = initvals(1);
ydotstart = initvals(2);

for k = 1:num_steps
    tblock = linspace(0, tstep, points_per_step);
    yblock = ystart + ydotstart * tblock + 0.5 * accels(k) * tblock.^2;
    
    ystart = ystart + ydotstart*tstep + 0.5 * accels(k) * tstep^2;
    ydotstart = ydotstart + accels(k) * tstep;
    if (nargin == 9)
        plot(t0 + tblock+(k-1)*tstep, yblock, linestyle)
    else
        plot(t0 + tblock+(k-1)*tstep, yblock, 'b-')
    end
    %plot(t0 + (k-1)*tstep, yblock(1), 'ko')
end

%legend('Goal Value', 'Sequential Parabolas', 0)

end
