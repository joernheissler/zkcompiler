Linux
----------------
- Compiling GMP 5.0.1
    - generic C -> ./configure --host=none-unknown-linux
    - with assembler optimizations -> ./configure
    - make
    - make install
- Compiling MPIR 2.1.1
    - generic C -> ./configure --host=none-unknown-linux
    - with assembler optimizations -> ./configure
    - make
    - make install
- Use "cmake ../ -DMPIR=ON" for MPIR library, default is linking to GMP
- Use "make doc" for generating doxygen documentation

Windows
----------------
- Bison
    - Download Bison > 2.4.1 from http://gnuwin32.sourceforge.net/packages/bison.htm
	- Install at c:\gnuwin32 and add to PATH environment variable
	- restart computer
- MPIR 2.1.1 / GMP 5.0.1 are precompiled and stored in ./extern/MPIR and ./extern/GMP
- MPIR is standard
- Use "cmake ../ -DDOXYGEN=ON" for generating doxygen documentation
- Use "cmake .. -G "Visual Studio 9 2008 Win64"" for Windows x64 builds (GMP is not available for windows x64 builds)

Android
----------------
- MPIR is recommended for Android build, because of ARM asm support
- droid-gcc script is used (-> copy from ./extern/Android/droid-gcc to /usr/local/bin)
- Compiling GMP 5.0.1
    - compiled with "android-ndk-r4-crystax"
    - precompiled copy is stored in ./extern/GMP/android/
    - export DROID_TARGET=generic
      export DROID_ROOT=[!!!!PATH TO ANDROID-NDK-R4-CRYSTAX!!!!!]
      export DROID_HOST=linux-x86
      export DROID_TOOLVER=4.4.0
      export CFLAGS="-I$DROID_ROOT/build/platforms/android-5/arch-arm/usr/include -I$DROID_ROOT/build/prebuilt/$DROID_HOST/arm-eabi-$DROID_TOOLVER/lib/gcc/arm-eabi/$DROID_TOOLVER/plugin/include"

    - CC=droid-gcc ./configure --host=arm-eabi (asm optimized, error in configure script -> assembler error)
    - CC=droid-gcc ./configure --host=none (generic C, works!!!)
- Compiling MPIR 2.1.1
    - compiled with "android-ndk-r4-crystax"
    - precompiled copy is stored in ./extern/MPIR/android/
    - export DROID_TARGET=generic
      export DROID_ROOT=[!!!!PATH TO ANDROID-NDK-R4-CRYSTAX!!!!!]
      export DROID_HOST=linux-x86
      export DROID_TOOLVER=4.4.0
      export CFLAGS="-I$DROID_ROOT/build/platforms/android-5/arch-arm/usr/include -I$DROID_ROOT/build/prebuilt/$DROID_HOST/arm-eabi-$DROID_TOOLVER/lib/gcc/arm-eabi/$DROID_TOOLVER/plugin/include"

    - CC=droid-gcc ./configure --host=arm-eabi (asm optimized, works!!!)
 
