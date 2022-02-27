#!/bin/bash

pushd .. > /dev/null
COMMIT_HASH=$(git rev-parse --short HEAD)
popd > /dev/null

read -r -d '' VERSION_H << EOM
#pragma once

#define ALT_SDK_VERSION "$COMMIT_HASH"
EOM

if [[ $(< version.h) != "$VERSION_H" ]]; then
  echo $VERSION_H > version.h
fi
