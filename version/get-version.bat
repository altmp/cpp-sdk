@echo off

pushd ..
FOR /F %%I IN ('git rev-parse --short HEAD') DO @SET "COMMIT_HASH=%%I"
popd

(
  echo #pragma once
  echo.
  echo #define ALT_SDK_VERSION "%COMMIT_HASH%"
) > version.h.tmp

fc version.h version.h.tmp > nul
if errorlevel 1 goto rename

rm version.h.tmp
goto end

:rename
rm version.h
mv version.h.tmp version.h

:end