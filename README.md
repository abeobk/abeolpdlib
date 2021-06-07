# abeolpdlib
Launchpad detector

**Requirements:**
* CMake 3.10 +
* Git
* OpenCV 4.1.1

#1. Clone this repo
```bash
$ git clone https://github.com/abeobk/abeolpdlib.git
```
#2. Install library

```bash
$ cd abeolpdlib
$ sudo dpkg -i abeolpdlib_1.0.0_arm64_opencv4.1.1.deb
```

#3. Build

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

#4. Test

**syntax:**

./test_lpd config_dir sample_dir angle

```bash
# using 32x32 models
./test_lpd ../config32 ../samples 40

# using 48x48 models
./test_lpd ../config48 ../samples -40

# using 64x64 models
./test_lpd ../config64 ../samples 90
```


