@echo off
netsh winsock reset
netsh int ip reset
ipconfig /flushdns
pause