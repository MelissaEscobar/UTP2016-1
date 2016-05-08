%This simple octave program creates a plot of the normal probability distribution
%where the 0 is the mean and 1 is the variance of the normal probability distribution.
%As I'm replacing my matlab scripts for octave scripts.

x=[-4:0.1:4];
plot(x,normpdf(x,0.1));
print -dpng "-S400, 400" normal.png

