#! /bin/bash

echo "#include\"../lib/basic.h\"" > $1

echo >> $1 

cat << EOF  >> $1
int main()
{
	return 0;
}

EOF

echo $1" is successfully created!"
