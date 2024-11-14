# Thomson SAP to FD disk image converter for Unix/Linux

This little tool allows the conversion of SAP file to FD file.
SAP is hard to use with FlashFloppy due to its track format.
FD on the other side is pure raw image format.

# Requirements

No special requirements are needed but a Unix or Linux box.

# Compilation

```
gcc main.c -o sap2fd
```

# Usage

```
./sap2fd my-image.sap my-image.fd
```

# Bonus point

Here is the FlashFloppy `IMG.CFG` and `FF.CFG` I use.
Be sure to enable DS0 jumper (whereas it is internal or external drive).

`FF.img`:
```
interface = shugart
image-on-startup = last
pin02 = nc
pin34 = nc
index-suppression = no
motor-delay = 0
head-settle-ms = 15
```

`IMG.CFG`:
```
[fd::327680]
cyls = 80
heads = 1
secs = 16
bps = 256
h = auto
rate = 250
```
Be sure to name your fd files like `my-image.fd.img`.

# Todo

No error handling. PR accepted.

