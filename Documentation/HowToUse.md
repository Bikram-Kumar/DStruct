## HOW TO USE

You can [download](https://github.com/Bikram-Kumar/DStruct/releases) the library files, and [use it directly](#using-independently) in your project.
If you want to use it in your cmake project, [read from here](#add-to-cmake-project).
Or, if you want to build the library from source, [follow these steps](#building-from-source).


### Using independently

If you want to use the library independently, [download the release](https://github.com/Bikram-Kumar/DStruct/releases) and unzip it. 
You will get a `.a` or `.so` or `.lib` or `.dll` file depending on the download, and an `include` directory.
1. Add `include/DStruct/` directory to your include path.
2. Add `DStruct/` to your library path. 
3. Link `DStruct` while compiling your project.



### Add to cmake project

DStruct is a cmake project, so you can link it to your project from your `CMakeLists.txt` file.

To do so, `add_subdirectory()` the cloned repository and link it with your target using `target_link_libraries()`:

```cmake
    add_subdirectory(path/to/DStruct)
    target_link_libraries(a.out DStruct)
```

Note that you don't need to add include paths as these are already exported, and you need to just `#include` the files, like `#include <heap.h>`.

<br>
   
### Building from source
If you want to build this library from source, you will need [`cmake`](https://cmake.org/download/).

Clone this repository, and create a `Builds` directory and `cd` to it.

Running
```shell
    cmake path/to/DStruct
    cmake --build .
```
will generate the static library.


#### Generate include files
To generate `include` files, set the `OUT_INCLUDES` flag to `ON`:
```shell
    cmake -DOUT_INCLUDES=ON path/to/DStruct
    cmake --build .
```

#### Shared library
To generate a shared library with include files, set both `BUILD_SHARED_LIBS`
and `OUT_INCLUDES` to `ON`:
```shell
    cmake -DBUILD_SHARED_LIBS=ON -DOUT_INCLUDES=ON path/to/DStruct
    cmake --build .
```