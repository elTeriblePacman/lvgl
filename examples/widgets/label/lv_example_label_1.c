#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
extern int errno;

#include "../../lv_examples.h"
#if LV_USE_LABEL && LV_BUILD_EXAMPLES

LV_FONT_DECLARE(bauhaus_16_compressed_array)
LV_FONT_DECLARE(bauhaus_16_notcompressed_array)

/**
 * Show line wrap, re-color, line align and text scrolling.
 */
void lv_example_label_1(void)
{

	/* Simple file test 00.*/

	char bfr[50];
	memset(bfr, 0, sizeof(bfr));

	printf("Hello world!\n");
	printf("Simple File Test 00: Opening test file...\n");
	int fd = open("fonts/foo.txt", O_RDONLY);
		
	printf("fd = %d\n", fd);
	if (fd ==-1)
	{
		// print which type of error have in a code
		printf("Error Number % d\n", errno);
		exit(1);
	}
	int sz = read(fd, bfr, 30);
	printf("called read(% d, c, 10). returned that"
					" %d bytes were read.\n", fd, sz);
	printf("bfr: %s\n", bfr);
	// Using close system Call
	if (close(fd) < 0)
	{
			perror("c1");
			exit(1);
	}
	printf("closed the fd.\n");


  /* Simple file test 01.*/

  printf("Simple File Test 01: Opening test file...\n");
  lv_fs_file_t f;
  lv_fs_res_t res;
  // res = lv_fs_open(&f, "S:/tmp/test.txt", LV_FS_MODE_RD);
  res = lv_fs_open(&f, "S:/fonts/foo.txt", LV_FS_MODE_RD);
  if(res == LV_FS_RES_OK){
    printf("\nfile open OK, res: %u\n", (uint8_t)res);
    uint32_t read_num = 0;
    char bfr[20]; memset(bfr, 0, sizeof(bfr));
    res = lv_fs_read(&f, bfr, 10, &read_num);
    // res = lv_fs_read(&f, bfr, 1, &read_num);
    if(res == LV_FS_RES_OK && read_num == 10){
      printf("\nfile read OK.\n");
      printf(" res     : %u\n", (uint8_t)res);
      printf(" read_num: %u\n", read_num);
      printf(" bfr     : %s\n", bfr);
    }
    else {
      printf("\nfile read failed.\n");
      printf(" res     : %u\n", (uint8_t)res);
      printf(" read_num: %lu\n", read_num);
    }
    lv_fs_close(&f);
  }
  else{
    printf("\nfile open failed, res: %u\n", (uint8_t)res);
  }

	lv_obj_t * label_00 = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(label_00, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
	lv_label_set_recolor(label_00, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label_00, "#0000ff Monserrat 16 # \nAa Bb Cc Dd Ee Ff Gg Hi Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789.\n#ff0000 Not Compressed. #");
	lv_obj_set_width(label_00, 200);  /*Set smaller width to make the lines wrap*/
	lv_obj_set_style_text_align(label_00, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label_00, LV_ALIGN_OUT_TOP_LEFT, 0, 0);

  static lv_font_t * my_font_00 = NULL;
  printf("Loading font Not Compressed font from drive...\r\n");
  my_font_00 = lv_font_load("S:/fonts/Montserrat_16_notcompressed.bin");
  if(my_font_00 != NULL){
    printf("font load OK!\r\n");
    lv_obj_set_style_text_font(label_00, my_font_00, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else{
    printf("Loading Not Compressed font from drive failed!\r\n");
  }

	lv_obj_t * label_01 = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(label_01, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
	lv_label_set_recolor(label_01, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label_01, "#0000ff Monserrat 16 # \nAa Bb Cc Dd Ee Ff Gg Hi Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789.\n#ff0000 Compressed. #");
	lv_obj_set_width(label_01, 200);  /*Set smaller width to make the lines wrap*/
	lv_obj_set_style_text_align(label_01, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label_01, LV_ALIGN_OUT_TOP_LEFT, 0, 200);
  static lv_font_t * my_font_01 = NULL;
  printf("Loading font Compressed font from drive...\r\n");
  my_font_01 = lv_font_load("S:/fonts/Montserrat_16_compressed.bin");
  if(my_font_01 != NULL){
    printf("font load OK!\r\n");
    lv_obj_set_style_text_font(label_01, my_font_01, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else{
    printf("Loading Compressed font from drive failed!\r\n");
  }

	lv_obj_t * label_02 = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(label_02, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
	lv_label_set_recolor(label_02, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label_02, "#0000ff Bauhaus 16 # \nAa Bb Cc Dd Ee Ff Gg Hi Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789.\n#ff0000 Not Compressed. #");
	lv_obj_set_width(label_02, 200);  /*Set smaller width to make the lines wrap*/
	lv_obj_set_style_text_align(label_02, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label_02, LV_ALIGN_OUT_TOP_LEFT, 200, 0);

  static lv_font_t * my_font_02 = NULL;
  printf("Loading font Not Compressed font from drive...\r\n");
  my_font_02 = lv_font_load("S:/fonts/bauhaus_16_notcompressed.bin");
  if(my_font_02 != NULL){
    printf("font load OK!\r\n");
    lv_obj_set_style_text_font(label_02, my_font_02, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else{
    printf("Loading Not Compressed font from drive failed!\r\n");
  }

	lv_obj_t * label_03 = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(label_03, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
	lv_label_set_recolor(label_03, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label_03, "#0000ff Bauhaus 16 # \nAa Bb Cc Dd Ee Ff Gg Hi Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789.\n#ff0000 Compressed. #");
	lv_obj_set_width(label_03, 200);  /*Set smaller width to make the lines wrap*/
	lv_obj_set_style_text_align(label_03, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label_03, LV_ALIGN_OUT_TOP_LEFT, 200, 200);

  static lv_font_t * my_font_03 = NULL;
  printf("Loading font Compressed font from drive...\r\n");
  my_font_03 = lv_font_load("S:/fonts/bauhaus_16_compressed.bin");
  if(my_font_03 != NULL){
    printf("font load OK!\r\n");
    lv_obj_set_style_text_font(label_03, my_font_03, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else{
    printf("Loading Compressed font from drive failed!\r\n");
  }

	lv_obj_t * label_04 = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(label_04, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
	lv_label_set_recolor(label_04, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label_04, "#0000ff Ravie 16 # \nAa Bb Cc Dd Ee Ff Gg Hi Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789.\n#ff0000 Not Compressed. #");
	lv_obj_set_width(label_04, 200);  /*Set smaller width to make the lines wrap*/
	lv_obj_set_style_text_align(label_04, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label_04, LV_ALIGN_OUT_TOP_LEFT, 200+200, 0);

  static lv_font_t * my_font_04 = NULL;
  printf("Loading font Not Compressed font from drive...\r\n");
  my_font_04 = lv_font_load("S:/fonts/ravie_16_notcompressed.bin");
  if(my_font_04 != NULL){
    printf("font load OK!\r\n");
    lv_obj_set_style_text_font(label_04, my_font_04, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else{
    printf("Loading Not Compressed font from drive failed!\r\n");
  }

	lv_obj_t * label_05 = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(label_05, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
	lv_label_set_recolor(label_05, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label_05, "#0000ff Ravie 16 # \nAa Bb Cc Dd Ee Ff Gg Hi Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789.\n#ff0000 Compressed. #");
	lv_obj_set_width(label_05, 200);  /*Set smaller width to make the lines wrap*/
	lv_obj_set_style_text_align(label_05, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label_05, LV_ALIGN_OUT_TOP_LEFT, 200+200, 200);

  static lv_font_t * my_font_05 = NULL;
  printf("Loading font Compressed font from drive...\r\n");
  my_font_05 = lv_font_load("S:/fonts/ravie_16_compressed.bin");
  if(my_font_05 != NULL){
    printf("font load OK!\r\n");
    lv_obj_set_style_text_font(label_05, my_font_05, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else{
    printf("Loading Compressed font from drive failed!\r\n");
  }

	lv_obj_t * label_06 = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(label_06, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
	lv_label_set_recolor(label_06, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label_06, "#0000ff Bauhaus 16 C Array# \nAa Bb Cc Dd Ee Ff Gg Hi Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789.\n#ff0000 Not Compressed. #");
	lv_obj_set_width(label_06, 200);  /*Set smaller width to make the lines wrap*/
	lv_obj_set_style_text_align(label_06, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label_06, LV_ALIGN_OUT_TOP_LEFT, 200+200+200, 0);

  static lv_font_t * my_font_06 = &bauhaus_16_notcompressed_array;
  lv_obj_set_style_text_font(label_06, my_font_06, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_t * label_07 = lv_label_create(lv_scr_act());
	lv_label_set_long_mode(label_07, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
	lv_label_set_recolor(label_07, true);                      /*Enable re-coloring by commands in the text*/
  lv_label_set_text(label_07, "#0000ff Bauhaus 16 C Array# \nAa Bb Cc Dd Ee Ff Gg Hi Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789.\n#ff0000 Compressed. #");
	lv_obj_set_width(label_07, 200);  /*Set smaller width to make the lines wrap*/
	lv_obj_set_style_text_align(label_07, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label_07, LV_ALIGN_OUT_TOP_LEFT, 200+200+200, 200);

  static lv_font_t * my_font_07 = &bauhaus_16_compressed_array;
  lv_obj_set_style_text_font(label_07, my_font_07, LV_PART_MAIN | LV_STATE_DEFAULT);

}

#endif
