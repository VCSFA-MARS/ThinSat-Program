#!/bin/bash

function usage()
{
	echo "This script uses avrdude to flash the CR-03 radio module."
	echo "The latest XINABOX binary packaged in this release."
	echo " "
	echo "Usage : $0 [-p <port>][-b <baud rate>][-f <binary file>]"
}

UNIXNAME=$(uname)


echo "Found Unix Kernel Name: $UNIXNAME"

case "$UNIXNAME" in

	Darwin)
		echo "You are using Mac OS X"

		# INSTALL AVRDUDE TO FLASH!!!
		
		# brew install avrdude

		;;
	Linux)
		echo "You are using Linux"
		;;
	FreeBSD)
		echo "You are using Linux FreeBSD"
		;;
	GNU)
		# Debian GNU
		echo "You are using Linux Debian"
		;;
	GNU/kFreeBSD)
		# Debiam
		echo "You are using Linux Debian"
		;;
	*)
		echo "Unknown OS Detected"
		;;
esac




	
