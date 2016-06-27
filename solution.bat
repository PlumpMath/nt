@echo off
rem Enter the script directory.
pushd %~dp0

rem Initialize the compiler.
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64

rem Set the CMake generator.
set generator="Visual Studio 14 2015 Win64"

rem Set the CMake generator toolset.
set toolset="v140"

rem Determine the project name.
for /f "tokens=2 delims=( " %%i in ('findstr /c:"project(" CMakeLists.txt') do (
  set project=%%i
)

rem Create and enter the build directory.
if not exist build (
  mkdir build
)
pushd build

rem Generate and open the solution.
cmake -G %generator% -T %toolset% -DCMAKE_INSTALL_PREFIX:PATH=.. ..
if %errorlevel% == 0 (
  start %project%.sln
) else (
  pause
)

rem Leave the build directory.
popd

rem Leave the script directory.
popd
