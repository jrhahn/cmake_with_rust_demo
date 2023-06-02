#!/bin/bash

cd test-lib && cbindgen --config cbindgen.toml --crate test-lib --output ../include/test_lib.h
