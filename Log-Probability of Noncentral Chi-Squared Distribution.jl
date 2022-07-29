#import Pkg
#Pkg.add(url="https://github.com/heltonmc/Bessels.jl.git")


#= 
Essentially what you need to do is 
define a struct called NCQ. 

Then you need to define 
a function logpdf(dist::NCQ, x::Real) 
    that returns the log-probability density for dist evaluated at x
=#

struct NCQ
    k
    lambda
end

using Bessels

function logpdf(dist::NCQ, x::Real)
    a = (x+dist.lambda)/2
    b = ((dist.k-2)/4) * log(x/dist.lambda)
    c = b - a - log(2) + log(besseli(dist.k/2 - 1, sqrt(dist.lambda*x)))
    
    return c
end

x = logpdf(NCQ(4, 3), 1)
println(exp(x))