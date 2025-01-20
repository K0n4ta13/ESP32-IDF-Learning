idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS ".")

fatfs_create_spiflash_image(storage ../files FLASH_IN_PROJECT)
# fatfs_create_rawflash_image(storage ../files FLASH_IN_PROJECT)
