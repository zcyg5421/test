## Project 1 Implement EDF in ChronOS

#### Prerequisite

Assume ChronOS is installed properly based on instructions.

linux_3.0.24 and ChronOS_3.0 are in local file system.

git is installed.

#### Usage
```
cp proj1_linux.patch /path/to/linux_3.0.24
cd /path/to/linux_3.0.24
git apply proj1_linux.patch 

cp proj1_ChronOS.patch /path/to/ChronOS_3.0
cd /path/to/ChronOS_3.0
git apply proj1_ChronOS.patch 
```

then compile the sched_test_app, and the kernel modules. 

Install the kernel module by using `sudo modprobe edf`

Use sched_test_app to test the EDF.
