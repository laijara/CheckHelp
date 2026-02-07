@echo off
set GOOS=windows
set GOARCH=386
set CGO_ENABLED=0

cd ../../heart

go build -ldflags="-s -w" -o ../compile/dist/ComputerHelperApp.exe

pause