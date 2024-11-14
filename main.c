#include <stdio.h>

#define PUK_MAGIC_NUMBER 0xb3
#define TO_CYLENDERS             80
#define TO_SECTORS_PER_CYLENDERS 16
#define TO_SECTOR_SIZE          256
#define PUK_HEADER_SIZE          66 // the header
#define PUK_PRE_SECTOR_SIZE       4 // format, protection, track and sector
#define PUK_POST_SECTOR_SIZE      2 // crc

int main(int argc, char * argv[argc]) {
  FILE * f_sap;
  FILE * f_fd;

  char buffer_sap[512];
  char buffer_fd[512];

  f_sap = fopen(argv[1], "r");
  f_fd = fopen(argv[2], "w");
  fseek(f_sap, PUK_HEADER_SIZE, SEEK_SET); // skip header

  for(int i=0; i<TO_CYLENDERS*TO_SECTORS_PER_CYLENDERS; i++) {
    if (fread(buffer_sap, PUK_PRE_SECTOR_SIZE + TO_SECTOR_SIZE + PUK_POST_SECTOR_SIZE, 1, f_sap)) {
      for(int offset=0; offset < TO_SECTOR_SIZE; offset++) {
        buffer_fd[offset] = buffer_sap[offset + PUK_PRE_SECTOR_SIZE]^PUK_MAGIC_NUMBER;
      }
      fwrite(buffer_fd, TO_SECTOR_SIZE, 1, f_fd);
    }
  }

  fclose(f_sap);
  fclose(f_fd);
}
