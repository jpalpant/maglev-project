function y_error = fSE(accels, timestep, yset, init_conditions) 
    num_parabolas = length(accels);
    points_per_parabola = length(yset) / num_parabolas;
    
    y0 = init_conditions(1);
    y0_dot = init_conditions(2);
        
    y_error = 0;
    timerel = linspace(0, timestep, points_per_parabola);

    for i=1:num_parabolas
        % Calculate error for each parabolic section
        y_error = y_error + sum((abs(yset((i-1)*points_per_parabola+1:i*points_per_parabola)-(y0 + y0_dot*(timerel) + 0.5*accels(i)*(timerel).^2))).^2);
        
        % Set new initial conditions for next parabolic section
        y0 = y0 + y0_dot*(timestep) + 0.5*accels(i)*(timestep).^2;
        y0_dot = y0_dot + (accels(i) * (timestep));
    end
    
end
