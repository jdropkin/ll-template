#!/bin/sh

if [ "$#" -ne 1 ]
then
    echo "Usage: ./generate.sh name"
    exit 1
fi

name=$1
nameupper=`echo $name | tr a-z A-Z`
firstchar=`echo $name | cut -c 1`

echo "Creating directory $name..."
mkdir -p $name

echo "Generating files..."

sed "s/UPPERNAME/$nameupper/g" ll-template.c > $name/$name.c
sed "s/UPPERNAME/$nameupper/g" ll-template.h > $name/$name.h

sed -i "s/NAME/$name/g" $name/$name.*

sed -i "s/FIRSTCHAR/$firstchar/g" $name/$name.*

echo "Creating tarball..."
tar cf $name.tar $name/

