all: initial-build build-customization initial-build

full: clean dependencies configs initial-build build-customization intial-build

# Delete every file generated by the standard build process.
clean:
	@rm -rf .br-external.mk
	@rm -rf buildroot
	@rm -rf download
	@rm -rf controlCardImage/.br-external.mk
	@rm -rf controlCardImage/.config
	@rm -rf controlCardImage/.config.old
	@rm -rf controlCardImage/build
	@rm -rf controlCardImage/host
	@rm -rf controlCardImage/images
	@rm -rf controlCardImage/staging
	@rm -rf controlCardImage/target
	@rm -rf controlCardImage/Makefile
	@rm -rf sdCardImage/.br-external.mk
	@rm -rf sdCardImage/.config
	@rm -rf sdCardImage/.config.old
	@rm -rf sdCardImage/board/microchip/sama5d2_som/rootfs-overlay/root/part1.img
	@rm -rf sdCardImage/board/microchip/sama5d2_som/rootfs-overlay/root/part2.img
	@rm -rf sdCardImage/board/microchip/sama5d2_som/rootfs-overlay/root/files.md5
	@rm -rf sdCardImage/build
	@rm -rf sdCardImage/host
	@rm -rf sdCardImage/images
	@rm -rf sdCardImage/staging
	@rm -rf sdCardImage/target
	@rm -rf sdCardImage/Makefile

# Fetch and set up any dependencies.
dependencies:
	git clone git://github.com/buildroot/buildroot.git
	cd buildroot && git checkout 2018.02

# Fetch the configs and prepare them for a full build.
configs:
	cd controlCardImage && make O=$(shell pwd)/controlCardImage BR2_EXTERNAL=$(shell pwd)/controlCardImage -C ../buildroot sama5d2_som_minimal_defconfig
	cd sdCardImage && make O=$(shell pwd)/sdCardImage BR2_EXTERNAL=$(shell pwd)/sdCardImage -C ../buildroot sama5d2_som_minimal_defconfig

# Perform the build. The first time it is run on a machine, it may take several
# hours to complete.
initial-build:
	# Build the control card image.
	cd controlCardImage && make OBELISK_OB1_DIR=$(shell pwd)
	# Prepare the control card image for the sd card.
	./controlCardImage/prepareForSDCard.sh
	# Move the control card image to the sd card rootfs.
	mkdir -p sdCardImage/board/microchip/sama5d2_som/rootfs-overlay/root
	cp controlCardImage/images/part1.img sdCardImage/board/microchip/sama5d2_som/rootfs-overlay/root/part1.img
	cp controlCardImage/images/part2.img sdCardImage/board/microchip/sama5d2_som/rootfs-overlay/root/part2.img
	cp controlCardImage/images/files.md5 sdCardImage/board/microchip/sama5d2_som/rootfs-overlay/root/files.md5
	# Build the sd card image.
	cd sdCardImage && make OBELISK_OB1_DIR=$(shell pwd)

# Manually modify some of the built libraries and re-make.
build-customization:
	cp resources/spi_nor_ids.c controlCardImage/build/at91bootstrap3-v3.8.10/driver/spi_flash
	cp resources/spi_nor_ids.c sdCardImage/build/at91bootstrap3-v3.8.10/driver/spi_flash
	cp resources/sama5d27_som1_ek.c sdCardImage/build/at91bootstrap3-v3.8.10/board/sama5d27_som1_ek
	rm controlCardImage/build/at91bootstrap3-v3.8.10/.stamp_built
	rm controlCardImage/build/linux-linux4sam_5.8/.stamp_built
	rm sdCardImage/build/at91bootstrap3-v3.8.10/.stamp_built
	rm sdCardImage/build/linux-linux4sam_5.8/.stamp_built

# Modify the config files for the control card by running 'make menuconfig'.
# After making modifications, the resulting .config file needs to be copied to
# configs/sama5d2_som_minimal_defconfig if the changes are to be persisted.
control-menu:
	cd controlCardImage && make O=$(shell pwd)/controlCardImage BR2_EXTERNAL=$(shell pwd)/controlCardImage -C ../buildroot sama5d2_som_minimal_defconfig && \
		make menuconfig

# Modify the config files for the sd card by running 'make menuconfig'. After
# making modifications, the resulting .config file needs to be copied to
# configs/sama5d2_som_minimal_defconfig if the changes are to be persisted.
sd-menu:
	cd sdCardImage && make O=$(shell pwd)/sdCardImage BR2_EXTERNAL=$(shell pwd)/sdCardImage -C ../buildroot sama5d2_som_minimal_defconfig && \
		make menuconfig

.PHONY: all full clean dependencies configs initial-build build-customization control-name sd-menu
