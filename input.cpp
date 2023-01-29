//Made by https://github.com/HydraLM81

#include <string>
#include <windows.h>
#include <unistd.h>

void hold(std::string in,bool recurse=0,int waitAll=0,int waitIndv[]=0,int current=0){
    for(int a=current;a<in.length();a++){
        INPUT letter[1]={};
        ZeroMemory(letter,sizeof(letter));
        letter[0].type=INPUT_KEYBOARD;
        letter[0].ki.wVk=VkKeyScanEx(in[a],GetKeyboardLayout(0));
        if(in[a]=='\x5B')
            letter[0].ki.wVk=VK_LWIN;
        else if(in[a]=='\x10')
            letter[0].ki.wVk=VK_SHIFT;
        else if(in[a]=='\xA2')
            letter[0].ki.wVk=VK_LCONTROL;
        else if(in[a]=='\x1B')
            letter[0].ki.wVk=VK_ESCAPE;

        UINT sendLetter=SendInput(ARRAYSIZE(letter),letter,sizeof(INPUT));

        if(recurse&&current<in.length())
            hold(in,recurse,waitAll,waitIndv,++current);
        
        sleep(waitAll+waitIndv[a]);
        
        INPUT letterUp[1]={};
        ZeroMemory(letterUp,sizeof(letterUp));
        letterUp[0]=letter[0];
        letterUp[0].ki.dwFlags=KEYEVENTF_KEYUP;
        UINT sendLetterUp=SendInput(ARRAYSIZE(letterUp),letterUp,sizeof(INPUT));

        if(recurse)
            break;
    } 
}