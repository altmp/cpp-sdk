#!/bin/bash

pushd .. > /dev/null
COMMIT_HASH=$(git rev-parse --short HEAD)
popd > /dev/null

cat <<EOM >> version.h.tmp
#pragma once

#define ALT_SDK_VERSION "$COMMIT_HASH"
EOM

if cmp -s version.h.tmp version.h; then
  rm version.h.tmp
else
  rm version.h
  mv version.h.tmp version.h
fi
