#include <iostream>
#include <sstream>

#include "request.cpp"
#include "webserver.cpp"
#include "loadbalancer.h"

using namespace std;

request createIPRequest() /*< this method generates the IP addresses for the request processing */
{
    stringstream startIP, finishIP;
    request r;
    for (int i = 0; i < 3; i++)
    {
        startIP << (rand() % 256) << ".";
        finishIP << (rand() % 256) << ".";
    }
    startIP << (rand() % 256);
    finishIP << (rand() % 256);

    r.start = startIP.str();
    r.finish = finishIP.str();
    r.time = rand() % 500;

    return r;
}

int main()
{
    loadBalancer theBalancer;
    int serverCount = 0;
    int timeToRun = 0;
    int initialRequests = 0;
    int numTimesofRequests = 0;

    cout << "How many servers do you want to process the load on? ";
    cin >> serverCount;
    cout << "How many cycles do you want to run the balancer? ";
    cin >> timeToRun;
    cout << "How many requests do you want to create initially? ";
    cin >> initialRequests;
    cout << "How many times do you want requests to be generated? ";
    cin >> numTimesofRequests;

    webServer theServers[serverCount];

    for (int i = 0; i < initialRequests; i++) /*< add the random requests to the balancer*/
    {
        theBalancer.add(createIPRequest());
    }

    for (int j = 0; j < serverCount; j++) /*< add the requests to the array of webservers with names*/
    {
        webServer web((char)(j + 65));
        theServers[j] = web;
        theServers[j].addReq(theBalancer.get(), theBalancer.time);
    }

    while (theBalancer.time < timeToRun) /*< within the number of cycles that the user has specified*/
    {
        int whichServer = theBalancer.time % serverCount;
        if (theServers[whichServer].requestFinished(theBalancer.time)) /*< if request is complete, then print out to the system*/
        {
            request req = theServers[whichServer].r;
            cout << "At " << theBalancer.time << theServers[whichServer].name << " processed request from " << req.start << " to " << req.finish << endl;
            theServers[whichServer].addReq(theBalancer.get(), theBalancer.time);
        }

        if (rand() % numTimesofRequests == 0)
        {
            theBalancer.add(createIPRequest());
        }
        theBalancer.time++;
    }
}