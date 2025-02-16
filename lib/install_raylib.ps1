cls

$cwd=Split-Path -Path $PSCommandPath 
$cwd=$cwd -replace '\\', '/'

$rundir = Get-Location

$env:Path = "$cwd/external/mingw/bin;$cwd/external/cmake/bin;$env:Path"

$Path = "$cwd/external/raylib"

if (Test-Path "$Path/build") { Remove-Item -Path "$Path/build" -Recurse -Force }
New-Item -ItemType Directory -Path "$Path/build" -Force

Set-Location -Path "$Path/src"

#make DESTDIR="$Path/build/" # if linux
#make install # if linux

make

Copy-Item -Path "$Path/src/libraylib.a" -Destination "$Path/build/libraylib.a"
Copy-Item -Path "$Path/src/raylib.h" -Destination "$Path/build/raylib.h"
Copy-Item -Path "$Path/src/raymath.h" -Destination "$Path/build/raymath.h"
Copy-Item -Path "$Path/src/rlgl.h" -Destination "$Path/build/rlgl.h"

make clean

Set-Location -Path "$rundir"