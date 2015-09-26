# src directory
CHAPTERS := chapter01

.PHONY: all $(CHAPTERS)

all: $(CHAPTERS)

$(CHAPTERS):
	$(MAKE) -C $@
