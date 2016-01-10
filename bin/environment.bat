set mpp_root=%~dp0..\..
set mpp_win64_library=%mpp_root%\mpp_install\lib\win64
set mpp_win64_release_library=%mpp_root%\mpp_install\win64\release
set mpp_win32_library=%mpp_root%\mpp_install\lib\win32
set mpp_win32_release_library=%mpp_root%\mpp_install\win32\release
set mpp_library=%mpp_win64_library%;%mpp_win64_release_library%;%mpp_win32_library%;%mpp_win32_release_library% 

for /f "tokens=1,2,*" %%a in ('reg query HKCU\Environment /v Path') do set current_user_path=%%c

reg add HKCU\Environment /v path /t REG_EXPAND_SZ /d "%current_user_path%;%mpp_library%"
