//Made by https://github.com/HydraLM81

#include <iostream>
#include <windows.h>
#include <unistd.h>
#include "input.cpp"
using namespace std;


int main(){
    cout<<"AntiAFK\n\nEnter minutes to run or input a string/char for infinite runtime: ";
    string runlengthstr;
    cin>>runlengthstr;
    bool fix;
    cout<<"To run /fix every 40 minutes, enter 1, else enter 0: ";
    cin>>fix;
    int runlength;
    try{
        runlength=stoi(runlengthstr);
        cout<<"Will run for "<<runlength<<" minutes.\n\n";
    }
    catch(...){
        runlength=INT_MAX;
        cout<<"Will run until user stops this program.\n\n";
    }
    cout<<"Movement must be bound to WASD, attack to 'J', and command to '/'.\n\n";
    sleep(2);
    cout<<"Running in 10 seconds. Enter 'ctrl + c' to stop.\n";
    sleep(10);
    cout<<"Running...\n";
    int runTime=0;
    int timing[3]={54,3,3};
    int thing=5;
    int* timing2=&thing;
    while(runTime<runlength){
        cout<<"\nRuntime: "<<runTime;
        hold("jsw",0,0,timing2);
        runTime++;
        if(runTime%40==0&&fix)
            hold("/fix\r");
    }
}