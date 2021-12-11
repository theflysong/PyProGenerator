include ../makes/make.rule

CPPSRC_LISTS := PPGContext PPGPackages PPGSymbol
CSRC_LISTS :=
OBJ_LISTS := $(addsuffix .cpp.o, $(CPPSRC_LISTS)) $(addsuffix .c.o, $(CSRC_LISTS))
HEADERS := $(wildcard *.h)
OUTPUT := ../build/Lib/ppg.a

.PHONY: build cpheaders
build: $(OBJ_LISTS)
	ar rcs $(OUTPUT) $^

cpheaders: $(HEADERS)
	cp $(HEADERS) ../build/Include