#!/bin/bash

cbindgen --config cbindgen.toml --crate hello_c --output hello_with_rust.h
