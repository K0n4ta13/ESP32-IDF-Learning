#include <stdio.h>
#include <freertos/FreeRTOS.h>

void print_memory()
{
  printf("stack %d, total ram %d, internal memory %d, external memory %d\n",
     uxTaskGetStackHighWaterMark(NULL), heap_caps_get_free_size(MALLOC_CAP_8BIT),
     heap_caps_get_free_size(MALLOC_CAP_INTERNAL), heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
}

void app_main(void)
{
    printf("xPortGetFreeHeapSize %d = DRAM\n", xPortGetFreeHeapSize());

    unsigned DRam = heap_caps_get_free_size(MALLOC_CAP_8BIT);
    unsigned IRam = heap_caps_get_free_size(MALLOC_CAP_32BIT) - heap_caps_get_free_size(MALLOC_CAP_8BIT);

    printf("DRAM \t\t %d\n", DRam);
    printf("IRam \t\t %d\n", IRam);

    unsigned free = heap_caps_get_largest_free_block(MALLOC_CAP_8BIT);
    printf("free = %d\n", free);

    unsigned stackmem = uxTaskGetStackHighWaterMark(NULL);
    printf("stack space = %d\n", stackmem);

    print_memory();

}

