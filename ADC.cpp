#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<time.h>
#include<windows.h>
using namespace std;
int main()
{
    const int f=15000; // Sampling frequency [Hz]
    const double T=1.0/f; // Sampling period [s]
    const double pi=3.1415926;

    int i,mini,maxi,p1,p2; // Indexes of min, max and period
    double t,min,max,dc,amp,per,freq,phi,run,rms,w;

    cout<<"\n\t\tADC v1\n\n"; // Calculating screen
    cout<<"\n\tCalculating... \t\t";

    ifstream file;
    file.open("values.txt"); // File of values

    vector<double> val;
    while(file>>t)
        val.push_back(t); // Values from file to vector

    file.close();

    //START CALCULATION
    min=val.front(); // These four lines just assign first value to be max and min
    max=min;
    mini=0;
    maxi=mini;
    for(i=1;i<val.size();i++){ // Finding min and max of values
        if(val.at(i)>max){
            max=val.at(i);
            maxi=i;
        }
        if(val.at(i)<min){
            min=val.at(i);
            mini=i;
        }
    }
    amp=1.0*(max-min)/2; // Half of peak to peak
    dc=max-amp; // DC offset

    i=0; // Calculating period by finding same value as first one
    while(val.at(i)==val.at(i+1))
        i++;
    p1=i;
    i=p1+1;
    if(val.at(p1)<val.at(p1+1)) // Also it has to be same derivative
        while(!(val.at(i)<=val.at(p1) && val.at(p1)<=val.at(i+1)))
            i++;
    else
        while(!(val.at(i)>=val.at(p1) && val.at(p1)>=val.at(i+1)))
            i++;
    p2=i;
    per=(p2-p1)*T;
    freq=1.0/per;
    w=2*pi*freq;

    i=0; // Find where signal crosses zero
    while(!((val.at(i)-dc<=0 && val.at(i+1)-dc>=0)||(val.at(i)-dc>=0 && val.at(i+1)-dc<=0)))
        i++;
    phi=pi-T*i*w; // Multiplying sample number with sample period gives time from start to zero crossing

    /*sff=1.0*(val.at(1)-dc)/amp;
    if(sff>ff) // Phasor
        phi=asin(ff);
    else phi=pi-asin(ff);*/

    rms=0;
    for(i=p1;i<p2;i++)
        rms+=pow(abs(val.at(i)-dc),2); // Calculating RMS
    rms=1.0*rms/(p2-p1);
    rms=sqrt(rms); // AC RMS
    rms=sqrt(pow(rms,2)+pow(dc,2)); // If there is DC
    //END OF CALCULATON
    run=1.0*clock()/CLOCKS_PER_SEC; // Calculating time
    system("cls"); // Clearing screen

    cout<<"\n\t\tDAC v1\n\n"; // Printing out everything
    cout<<"\n\tSamples: \t\t"<<val.size();
    cout<<"\n\tSampling time: \t\t"<<val.size()*T<<"s";
    cout<<"\n\tSampling frequency: \t"<<f<<"Hz";
    cout<<"\n\n\tAmplitude: \t\t"<<amp;
    cout<<"\n\tDC offset: \t\t"<<dc;
    cout<<"\n\n\tPeriod: \t\t"<<per<<"s";
    cout<<"\n\tFrequency: \t\t"<<freq<<"Hz";
    cout<<"\n\t\t\t\t"<<w<<"rad/s";
    cout<<"\n\n\tAngle: \t\t\t"<<phi<<"rad";
    cout<<"\n\t\t\t\t"<<1.0*phi*180/pi<<"deg";
    cout<<"\n\n\tRMS: \t\t\t"<<rms;
    cout<<"\n\n\tCalculating time: \t"<<run<<"s";
    cout<<"\n\n\n\t"; // Just offset from bottom
    system("pause");
    return 0;
}
