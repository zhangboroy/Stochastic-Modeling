#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

///the Alpha function
double Alpha(const int &N, const int &k, const int &t)
{
    //return double(N-k)/double(N)*(800+400*(1+2*exp(-0.3*t/360))*sin(atan(1)*4*t/4320));
    return double(N-k)/double(N)*(15000+14000*sin(atan(1)*4*double(t)/43200));
}

///the Beta function
double Beta(const int &k, const int &t)
{
    //return double(k)*(2+(1+exp(-0.2*t/360))*sin(atan(1)*4*t/4320));
    return double(k)*(3+sin(atan(1)*4*double(t)/43200));
}

int main()
{
    ///Set the capacity
    cout<<"Please Enter the Capacity of the Packing Lot: "<<flush;
    int N=0;
    cin>>N;
    ///Set the initial number of cars
    cout<<"Please Enter the Initial Number of Cars: "<<flush;
    int n0=0;
    cin>>n0;
    int k=n0;

    ///Start constant rate simulation
    ofstream outData;
    outData.open("constantSimulation.txt");
    outData<<"d\tt\tk\n";
    outData<<1<<'\t'<<0<<'\t'<<k<<endl;

    srand(time(0));

    ///day 1 to day 14
    for (int d=1;d<15;++d)
    {
        ///second 1 to second 86400
        for (int t=1;t<86401;++t)
        {
            if (rand()<(1-exp(-double(k)*2/3600))*32768)
            {
                --k;
            }
            if (rand()<(1-exp(-double(N-k)/double(N)*18000/3600))*32768)
            {
                ++k;
            }
            outData<<d<<'\t'<<t<<'\t'<<k<<endl;
        }
    }
    outData.close();

    ///Start periodic rate simulation
    k=n0;
    outData.open("periodicSimulation.txt");
    outData<<"d\tt\tk\n";
    outData<<1<<'\t'<<0<<'\t'<<k<<endl;

    ///day 1 to day 14
    for (int d=1;d<15;++d)
    {
        ///second 1 to second 86400
        for (int t=1;t<86401;++t)
        {
            //cout<<Alpha(N,k,t)<<'\t'<<Beta(k,t)<<'\t'<<exp(-Alpha(N,k,t)/3600)<<'\t'<<exp(-Beta(k,t)/3600)<<endl;
            if (rand()<(1-exp(-Beta(k,t)/3600))*32768)
            {
                --k;
            }
            if (rand()<(1-exp(-Alpha(N,k,t)/3600))*32768)
            {
                ++k;
            }
            outData<<d<<'\t'<<t<<'\t'<<k<<endl;
        }
    }
    outData.close();

    return 0;
}
