cls

$cwd=Split-Path -Path $PSCommandPath 
$cwd=$cwd -replace '\\', '/'

$rundir = Get-Location

$env:Path = "$cwd/external/mingw/bin;$cwd/external/cmake/bin;$env:Path"

$Path = "$cwd/external/raylib"

if (Test-Path "$Path/build") { Remove-Item -Path "$Path/build" -Recurse -Force }
New-Item -ItemType Directory -Path "$Path/build" -Force
New-Item -ItemType Directory -Path "$Path/build/lib" -Force
New-Item -ItemType Directory -Path "$Path/build/include" -Force

Set-Location -Path "$Path/src"

#make DESTDIR="$Path/build/" # if linux
#make install # if linux

make

Copy-Item -Path "$Path/src/libraylib.a" -Destination "$Path/build/lib/libraylib.a"
Copy-Item -Path "$Path/src/raylib.h" -Destination "$Path/build/include/raylib.h"
Copy-Item -Path "$Path/src/raymath.h" -Destination "$Path/build/include/raymath.h"
Copy-Item -Path "$Path/src/rlgl.h" -Destination "$Path/build/include/rlgl.h"

make clean

Set-Location -Path "$rundir"