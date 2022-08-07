bash```
conan install .. --build=missing
cmake .. -G Ninja -DCMAKE_INSTALL_PREFIX=$HOME/usr/local -DCMAKE_BUILD_TYPE=Release
cmake --build .
ctest
cmake --install .
```
