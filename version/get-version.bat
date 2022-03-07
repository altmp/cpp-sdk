@echo off

pushd ..
FOR /F %%I IN ('git rev-parse --short HEAD') DO @SET "COMMIT_HASH=%%I"
popd

(
  echo #pragma once
  echo.
  echo #define ALT_SDK_VERSION "%COMMIT_HASH%"
) > version.h.tmp

if not exist version.h goto rename

fc version.h version.h.tmp > nul
if errorlevel 1 goto remove

rm version.h.tmp
goto end

:remove
rm version.h
:rename
move version.h.tmp version.h

:end
