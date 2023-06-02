#!/bin/bash

cd rust-lib && cbindgen --config cbindgen.toml --crate rust-lib --output ../include/rust_lib.h
