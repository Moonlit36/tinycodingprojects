#import Pkg
#Pkg.add(url="https://github.com/heltonmc/Bessels.jl.git")
#Pkg.add("Distributions")
#Pkg.add("ConditionalDists")
#Pkg.add("Plots")

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

    part1 = (x+dist.lambda)/2::Real
    
    part2 = ((dist.k-2)/4) * log(x/dist.lambda)::Real
    
    part3 = log(besseli(dist.k/2 - 1, sqrt(dist.lambda*x)))::Real
     
    result = log(1/2) - part1 + part2 + part3::Real

    return x < zero(x) ? oftype(result, -Inf) : result
end

#x = logpdf(NCQ(4, 3), 1)
#println(exp(x))

#=
Suppose that a random variable J 
has a Poisson distribution 
with mean lambda / 2, 

and the conditional distribution of Z given J = i 
is chi-squared with k + 2i degrees of freedom. 

As in, I need to have a conditional distribution on Chisq(k + 2*J) 


Then the unconditional distribution of Z 
is non-central chi-squared with k degrees of freedom, 
and non-centrality parameter lambda 
=#

using Distributions, ConditionalDists, Random, Statistics

function rand(dist::NCQ) 
    distrib_var = Distributions.rand(Poisson(dist.lambda/2))::Real
    cond_var = Distributions.rand(Chisq(dist.k + 2*distrib_var))::Real
    return cond_var
end




a = zeros(10000)

for i in 1:10000
    z = rand(NCQ(4, 3))
    #println(z)
    global a[i] = z
end


println(Statistics.std(a)^2)
println(Statistics.mean(a))

using Plots

histogram(a, bins=0:0.2:8)

#histogram(a, bins=0:0.2:16)
