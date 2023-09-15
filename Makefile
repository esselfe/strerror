
CFLAGS = -std=c11 -Wall -O2 -g
LDFLAGS = 
LDFLAGS_SHARED = $(LDFLAGS)
LDFLAGS_STATIC = -static $(LDFLAGS)
PROGNAME = strerror
PROGNAME_STATIC = strerror.static

.PHONY: all all-static clean

default: all all-static
	@ls -li --color=auto $(PROGNAME) $(PROGNAME_STATIC)

all: $(PROGNAME)

all-static: $(PROGNAME_STATIC)

$(PROGNAME): strerror.c
	gcc $(CFLAGS) $(LDFLAGS_SHARED) strerror.c -o $(PROGNAME)

$(PROGNAME_STATIC): strerror.c
	gcc $(CFLAGS) $(LDFLAGS_STATIC) strerror.c -o $(PROGNAME_STATIC)

clean:
	@rm -v $(PROGNAME) $(PROGNAME_STATIC) 2>/dev/null || true

