ex<-function(x)
{
  exp(-20*x)*(500+900*exp(20*x)-900)
}

x=0:86400
y={}

for (i in 1:86401)
{
  y[i]=ex(x[i]/3600)
}

plot(x,y)
write.csv(y, file = "constantDay1.csv")
a=ex(24)

ex<-function(x)
{
  exp(-20*x)*(a+900*exp(20*x)-900)
}

for (i in 1:86401)
{
  y[i]=ex(x[i]/3600)
}

plot(x,y)
write.csv(y, file = "constantDay2.csv")
a
ex(24)


h<-function(x)
{
  18*x-180/pi*cos(pi*x/12)+180/pi
}

l<-function(u)
{
  (15000+14000*sin(pi*u/12))*exp(h(u))
}

ex<-function(x)
{
  exp(-h(x))*(500+integrate(l,0,x)$value)
}

for (i in 1:86401)
{
  y[i]=ex(x[i]/3600)
}

plot(x,y)
write.csv(y, file = "periodicDay1.csv")
a=ex(24)

ex<-function(x)
{
  exp(-h(x))*(a+integrate(l,0,x)$value)
}

for (i in 1:86401)
{
  y[i]=ex(x[i]/3600)
}

plot(x,y)
write.csv(y, file = "periodicDay2.csv")
a
ex(24)
