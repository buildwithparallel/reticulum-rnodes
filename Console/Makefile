# These paths will have to be changed according to where you store these directories on your system
PATH_RETICULUM_WEBSITE=../../sites/reticulum.network
PATH_PACKAGES=../../../rns_build

clean:
	@echo Cleaning...
	@-rm -rf ./build

dirs:
	@mkdir -p ./build
	@mkdir -p ./build/3d
	@mkdir -p ./build/pkg
	@mkdir -p ./build/css
	@mkdir -p ./build/gfx
	@mkdir -p ./build/images

pages:
	python3 ./build.py

pages-debug:
	python3 ./build.py --no-gz --no-remap

sourcepack:
	@echo Packing firmware sources...
	cd .. && zip -r Console/build/pkg/rnode_firmware.zip * -x Builds/\* Console/\* Documentation/images/\* Documentation/RNode_v1_Manual.pdf Documentation/rnfw_1.jpg Graphics/\* Python\ Module/\* Release/\* build/\* partition_hashes
	
data:
	@echo Including assets...
	@cp assets/css/* build/css/
	@cp assets/gfx/* build/gfx/
	@cp assets/images/* build/images/
	@cp assets/stl/* build/3d/
	# @cp assets/pkg/* build/pkg/
	# @cp assets/scripts/* build/scripts/
	# @cp -r ../../Reticulum/docs/manual/* build/reticulum_manual/
	# @cp -r ../../Reticulum/docs/Reticulum\ Manual.pdf build/reticulum_manual/

external:
	make -C $(PATH_RETICULUM_WEBSITE) clean website
	-rm -r $(PATH_PACKAGES)/reticulum.network
	cp -r $(PATH_RETICULUM_WEBSITE)/build $(PATH_PACKAGES)/reticulum.network

site: clean external dirs data sourcepack pages

local: clean external dirs data sourcepack pages-debug

serve:
	python3 -m http.server 7777 --bind 127.0.0.1 --directory ./build
