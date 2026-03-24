#include "../Classes.h"

void FixFunctions::FixSystem() {
    system("echo off && sfc /scannow && pause && exit");
}

void FixFunctions::FixDisk() {
    system("echo off && chkdsk C: /F /R && pause && exit");
}

void FixFunctions::FixOperationalMemory() {
    system("echo off && C:\\Windows\\System32\\mdsched.exe && pause && exit");
}

void FixFunctions::FixDism() {
    system("echo off && DISM /Online /Cleanup-Image /RestoreHealth && pause && exit");
}

void FixFunctions::FixNetSettingsReset() {
    system("echo off && netsh winsock reset && netsh int ip reset && ipconfig /flushdns && pause && exit");
}