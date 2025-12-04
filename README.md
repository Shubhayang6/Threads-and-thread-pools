# Very important things to consider.

###### 1. If you are trying to compile and your g++ compiler doesn't support threading then you need to install.
 1. You can check with the following command: 
 > $ g++ -v

2. Remove the existing Win32 thread model by uninstalling the current compiler and remove every binaries related to mingw/mysys2 from environment path.

3. Go with the below link and download the posix compiler thread and paste it inside the C drive and add the bin to path.
> https://winlibs.com/

Restart Terminal and check for the new POSIX thread type.