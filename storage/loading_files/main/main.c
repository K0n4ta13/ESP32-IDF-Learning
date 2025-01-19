#include <stdio.h>

void app_main(void)
{
    extern const uint8_t indexHtml[] asm("_binary_index_html_start");
    printf("HTML: %s\n", indexHtml);

    extern const uint8_t sample[] asm("_binary_sample_txt_start");
    printf("Sample: %s\n", sample);

    extern const uint8_t imgStart[] asm("_binary_Konata_Chola_jpg_start");
    extern const uint8_t imgEnd[] asm("_binary_Konata_Chola_jpg_end");
    printf("Image size: %d\n", imgEnd - imgStart);
}

