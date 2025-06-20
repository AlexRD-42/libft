# Create a cmlx hook and integrate controls

# Figure out zoom and fitting
Probably involves having the coordinates be set up as a float and interpolating between min/max
Maybe also involves the normalization vector

# Implement colors!
Add a default color if unspecified (could be white or equal to the negative of the average)
Linearly interpolate colors between vtx p0 and vtx p1 in draw lines

# Pre-compute neighbour pairs for better cache prediction and eliminate branching

# Implement anti-aliasing
# Implement motion smoothing
