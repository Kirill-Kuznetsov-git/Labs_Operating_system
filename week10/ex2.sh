#!/bin/bash

mkdir week01
echo "Hello World" > week01/file.txt
mkdir week10
link week01/file.txt week10/_ex2.txt
find week01/file.txt -inum $(stat -c '%i' _ex2.txt) > ex2.txt
find week01/file.txt -inum $(stat -c '%i' _ex2.txt) -exec rm {} \; >> ex2.txt
cat ex2.txt