#include "../Classes.h"

void InfoFunctions::InfoSystem() {
    system("echo off && systeminfo && pause && exit");
}

void InfoFunctions::InfoIp() {
    system("echo off && ipconfig && pause && exit");
}

void InfoFunctions::InfoResources() {
    system("echo off && resmon && pause && exit");
}

void InfoFunctions::InfoLogs() {
    system("echo off && eventvwr.msc && pause && exit");
}

void InfoFunctions::InfoTaskList() {
    system("echo off && tasklist && pause && exit");
}

void InfoFunctions::InfoNet() {
    system("echo off && ping ya.ru && tracert ya.ru && pause && exit");
}