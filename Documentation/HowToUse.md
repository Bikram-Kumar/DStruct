## HOW TO USE

You can [download]() the library files, and use it directly in your project.


If you want to build this library from source, you will need [`cmake`](https://cmake.org/download/).

Clone this repository, and create a `Builds` directory and `cd` to it.

Running
```shell
    cmake path/to/DStruct
    cmake --build .
```
will generate the static library.

To generate `include` files, set the `OUT_INCLUDES` flag to `ON`:
```shell
    cmake -DOUT_INCLUDES=ON path/to/DStruct
    cmake --build .
```

To generate a shared library with include files, set both `BUILD_SHARED_LIBS`
and `OUT_INCLUDES` to `ON`:
```shell
    cmake -DBUILD_SHARED_LIBS=ON -DOUT_INCLUDES=ON path/to/DStruct
    cmake --build .
```