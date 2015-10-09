#!/bin/bash
#sh ~/arduino/arduino-1.6.5-r5/arduino  $1 --verbose-build

main_dir=$1 
sketch=`ls $main_dir/*.ino`
lib_dir=lib
libs=`ls $lib_dir`
source $main_dir/arduino.conf


#cp libs
for lib in $libs; do
    cp -f $lib_dir/$lib $main_dir
done

~/arduino/arduino-1.6.5-r5/arduino --board $board --port $port  --upload $sketch 


#rm libs
for lib in $libs; do
   rm $main_dir/$lib
done