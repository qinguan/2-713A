#! /bin/bash

echo "#include<stdio.h>" > $1
echo "#include<string.h>" >> $1
echo "#include<stdlib.h>" >> $1
echo "#include<assert.h>" >> $1

echo >> $1 

cat << EOF  >> $1
int main()
{
	return 0;
}

EOF

echo $1" is successfully created!"
