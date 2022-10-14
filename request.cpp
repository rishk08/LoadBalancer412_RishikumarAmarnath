#include <string>
using namespace std;
#define REQUEST_CPP

struct request /*< struct for the request class*/
{
    string start;  /*< source IP*/
    string finish; /*< destination IP*/
    int time;      /*< time to process the request*/
};