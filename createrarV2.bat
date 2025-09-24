chcp 65001
tar.exe acvf coreV2.rar -C "coreV2\CheckHelp\CheckHelp\bin\Release\net8.0\publish\win-x64" CheckHelp.exe
xcopy "D:\gitupload\CheckHelp\coreV2.rar" "D:\yandexdisk\disksync\YandexDisk\work\Другое\OtherUsers\1"
xcopy "D:\gitupload\CheckHelp\coreV2\CheckHelp\CheckHelp\bin\Release\net8.0\publish\win-x64\CheckHelp.exe" "D:\gitupload\CheckHelp"
chcp 866
pause