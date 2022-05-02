# !/bin/bash

echo -n "reading markdown file $1"
pandoc $1 | lynx -stdin
