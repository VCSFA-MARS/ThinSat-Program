# Tools for Non-Windows Users

This folder contains scripts and files for Mac and Linux users to flash their CW01 XinaBox chips. The contents are as follows:

## Files in this directory

* flashMyCW01.sh

  This script uses esptool.py, which is included as a git submodule in the ThinSat-Program repository. Use ./flashMyCW01.sh -h for the "help" usage guide.

* XINABOX\_CW01\_VX.XXX.bin

  This folder will always contain the latest release of the XinaBox CW01 firmware for the flashMyCW01.sh script to use. You may still flash older firmwares, which are located in the compiledBinaries folder of the repository.

* radioFlasher.sh

  This script is a work in progress to flash the CR03. It is not functional at this time.
  
## Getting Started

You need to have esptool.py setup in order to flash the CW01. Change to the esptool directory and run the following command:

```
python setup.py install
```

That will setup esptool and any dependencies it has.  You may need to run as sudo.

Once esptool is ready, you can run ./flashMyCW01.sh from the mactools directory.

You will need to specify the port with the -p option

```
./flashMyCW01.sh -p /dev/cu.usbmodem12345 
```

The above command will default to the latest binary and use the default baud rate and attempt to connect to the CW01 over usb serial at /dev/cu.usbmodem12345.

If you have issues, rememebr to set your IP01 switches to B and DCE!
