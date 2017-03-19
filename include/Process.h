using namespace std;

#ifndef PROCESS_H
#define PROCESS_H

#include "Utils.h"

class Process
{
    public:
        static bool isElevated(HANDLE process = GetCurrentProcess());

        static bool start(LPPROCESS_INFORMATION pinf, str file, str cmdline = str(), str dir = Utils::getCurrentDir(), HANDLE job = nullptr, bool wait = true);
        static bool startElevated(str file, str cmdline = str(), str dir = Utils::getCurrentDir(), HANDLE job = nullptr, bool wait = true);

        static HANDLE find(str name);
        static HANDLE find(DWORD pid);
        static HANDLE findParent(DWORD pid = GetCurrentProcessId());

        static str name(HANDLE process);
        static str parentName(DWORD pid = GetCurrentProcessId());
};

#endif // PROCESS_H
