#!/bin/bash

if [ ! -f "misc/header_cpp.txt" ];
then
	echo "Failed to find header file. Aborting."
	exit
fi

for file in $(find source -name "*.*pp");
do
	sed -i '1,25d' $file
	cat misc/header_cpp.txt $file > $file.new && mv $file.new $file
done

