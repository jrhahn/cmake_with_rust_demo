# cmake_with_rust_demo

This is an example project that shows how rust code can be included into a cmake project.

Please install [cbindgen](https://crates.io/crates/cbindgen) that will automatically generate the required
header file by 

```command-line
cargo install cbindgen
```

To build this project, simply run 

```command-line
cmake .
make
```

The executable will be stored in `./bin/`

This project is based on [CMakeRust](https://github.com/Devolutions/CMakeRust).
