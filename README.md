# controller01

computercraft turtle botnet for chunk mining, attempt #02.

## building

Uses a relatively new version of CMake.

```bash
mkdir build && cd build
cmake ..

# building server and client version
cmake --build .
```

Clients generate a minified `dist.lua` file in their respective cmake build
directories. This is what should be uploaded to the client. There is also an
unminified version called `dist_large.lua`.

## using

in progress
