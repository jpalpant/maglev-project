function [ sumerror ] = fSE_with_plot(accels, times, yset, init_conditions)
    num_parabolas = length(accels);
    points_per_parabola = length(times) / num_parabolas
    
    y0 = init_conditions(1);
    y0_dot = init_conditions(2);
    t0 = init_conditions(3);
    
    sumerror = 0;
    
    ally = zeros(length(times), 1);
    alla = zeros(length(times), 1);

    for i=1:num_parabolas
        timerel = times((i-1)*points_per_parabola+1:i*points_per_parabola);
        
        ynew = y0 + y0_dot*(timerel-t0) + 0.5*accels(i)*(timerel-t0).^2;
        
        % Calculate y values and set them in the full arrays
        ally((i-1)*points_per_parabola+1:i*points_per_parabola) = ynew;
        alla((i-1)*points_per_parabola+1:i*points_per_parabola) = ones(points_per_parabola,1)*accels(i);
        
        % Set new initial conditions
        y0 = ynew(end);
        y0_dot = y0_dot + (accels(i) * (timerel(end)-t0));
        t0 = timerel(end);
    end
    
    figure(1); clf;
    subplot(2, 1, 1);
    hold on
    plot(times, yset, 'k-')
    plot(times, ally, 'b-.')
    subplot(2,1,2);
    plot(times, alla, 'k-');
    hold off
    
    %sumerror = sum(abs(yset'-ally));

end

