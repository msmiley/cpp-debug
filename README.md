# cpp-debug

Utilities for debugging Node.js C++ Addons

## Installation

```bash
$ npm install cpp-debug
```

## Usage

Add an `include_dirs` section to your project's binding.gyp file so that it resembles the following:

```py
{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "binding.cc" ],
      "include_dirs": [
        "<!(node -e \"require('cpp-debug')\")"
      ]
    }
  ]
}
```

Then include `cpp-debug.h` in your addon:

```cpp
#include "cpp-debug.h"
```

## Debug Functions

cpp-debug provides the following functions for use anywhere in your native addon code:

#### Return a string with a hex dump representation of the provided bytes.

```cpp
std::string hexDump(const unsigned char* data, int len)
```

#### Print a hex dump representation of the given data to stdout.

```cpp
void printHexDump(const unsigned char* data, int len)
```

## License

  [MIT](LICENSE)
