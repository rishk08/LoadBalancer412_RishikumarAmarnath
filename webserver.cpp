#ifndef REQUEST_CPP
#include "request.cpp"
#endif

class webServer
{
public:
    request r; /*< requests that will be added to the server*/
    int start; /*< the start time for processing*/
    char name; /*< names of the servers*/

    webServer()
    {
        start = 0;
        name = ' ';
    }

    webServer(char c)
    {
        start = 0;
        name = c;
    }

    void addReq(request req, int now) /*< add request to the server and update starting time*/
    {
        r = req;
        start = now;
    }

    bool requestFinished(int now) /*< check to see if the request is completed based on the time specified*/
    {
        if (now >= (start + r.time))
        {
            return true;
        }
        return false;
    }
};