#!/usr/bin/env bash

RUSTFLAGS="" cargo build --release --target thumbv7em-none-eabihf;

cbindgen -q --config cbindgen.toml --crate BC26 --output 'BC26.h';

