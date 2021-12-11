include makes/make.rule

.PHONY: build cpheaders pack
build:
	cd ./src/ ; $(MAKE) build 

cpheaders:
	cd ./src/ ; $(MAKE) cpheaders

pack: build cpheaders
	echo "packing..."