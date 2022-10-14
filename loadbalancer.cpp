#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

void loadBalancer::add(request r) /*< add a new request to the load balancer*/
{
    rQueue.push(r);
    time++;
}

request loadBalancer::get() /*<get the request that's at the front of the queue to place in server*/
{
    time++;
    if (!rQueue.empty())
    {
        request r = rQueue.front();
        rQueue.pop();
        return r;
    }
}