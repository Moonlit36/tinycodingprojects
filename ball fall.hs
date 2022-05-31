program = activityOf(initial, change, picture)
offscreencoefficient = 11
huecyclespeed = 56.2
movespeed = 3.5
returncolorfunction(huevar) = HSL(huecyclespeed*huevar, 1, 0.5)
hue = 0
initcolour = HSL(hue, 1, 0.5)
initial(rs) = (offscreencoefficient, initcolour, hue)
change((y, colour, hue2), TimePassing(dt)) 
  | y < -1*offscreencoefficient = (offscreencoefficient, returncolorfunction(hue2), hue2 + dt)
  | otherwise = (y - movespeed*dt, returncolorfunction(hue2), hue2 + dt)
change(p, other) = p
picture(y, colour, hue2) = translated(colored(solidCircle(1), colour), 0, y) 
                           & translated(colored(solidCircle(1), colour), y, 0)