#!/bin/bash

function usage()
{
	echo " "
	echo "This script calls the espytool python script to flash your CW-01 with"
	echo "a binary file you specify. The script defaults to 115200 baud and the"
	echo "latest XINABOX binary packaged in this release."
	echo " "
	echo "Set your IP01 switches to B and DCE."
	echo " "
	echo "Usage : $0 [-p <port>][-b <baud rate>][-f <binary file>]"
	echo " "
}


# Define default values for the script

ESPTOOLPATH="../esptool/"
BAUDRATE=115200
BINARYFILE=XINABOX_CW01_V1.315.bin
USERBIN=0

while getopts p:f:b:h parm ; do
case $parm in

	p)
		echo "Using port $OPTARG"
		PORT=$OPTARG
		if [ ! -e $PORT ];
			then
				echo "You specified a port that doesn't exist. Try ls -l /dev/tty.* to find the correct port"
				return
		fi
		PORTFLAG=true;
		;;
	b)
		echo "Flashing at $OPTARG baud"
		BAUDRATE=$OPTARG
		;;
	f)
		# Check for binary file before execution and display error message 
		# if missing

		if [ -f $OPTARG ];
			then 
				echo "Using user-specified binary file $OPTARG"
				BINARYFILE=$OPTARG
				USERBIN=true
			else 
				echo "User-specified binary file $BINARYFILE was not found" >&2
				exit 1
		fi
		
		;;
	h)
		usage
		exit 0
		;;
	*)
		usage
		echo "Invalid argument"
esac
done

shift $((OPTIND-1))

# Check to see if valid options have been passed before running the script

if [ ! $PORTFLAG ]
	then
		echo "-p <port> must be specified" >&2
	exit 1
fi

if [ ! "$USERBIN" = true ];
	then
		echo "Using default binary file $BINARYFILE"
fi

# This builds the espytool.py command and requires sudo. 
# Perhaps future versions should require running  this script with sudo?

sudo python "$ESPTOOLPATH"esptool.py --baud $BAUDRATE --port $PORT write_flash -fm dio 0x00000 $BINARYFILE



