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

./sap2fd my-image.sap my-image.fd

# Todo

No error handling. PR accepted.

