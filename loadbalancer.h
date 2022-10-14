#define LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <queue>

class loadBalancer
{
public:
    int time;              /*< time in the load balancer*/
    queue<request> rQueue; /*< request queue that will be placing the requests in the servers*/

    loadBalancer()
    {
        time = 0;
    }
    void add(request r);
    request get();
};
