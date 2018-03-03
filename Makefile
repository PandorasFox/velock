TOPDIR=$(shell pwd)

INSTALL=install
PREFIX=/usr/local
SYSCONFDIR=/etc
PKG_CONFIG=pkg-config
MANDIR=/usr/share/man

ifeq ($(shell which $(PKG_CONFIG) 2>/dev/null 1>/dev/null || echo 1),1)
$(error "$(PKG_CONFIG) was not found")
endif

CFLAGS += -std=c11
CFLAGS += -pipe
CFLAGS += -Wall
CFLAGS += -O2

#SIMD_CFLAGS += -funroll-loops
#SIMD_CFLAGS += -msse2
#CPPFLAGS += -D_GNU_SOURCE
#CPPFLAGS += -DXKBCOMPOSE=$(shell if test -e /usr/include/xkbcommon/xkbcommon-compose.h ; then echo 1 ; else echo 0 ; fi )
#CFLAGS += $(shell $(PKG_CONFIG) --cflags cairo xcb-composite xcb-xinerama xcb-randr xcb-atom xcb-image xcb-xkb xkbcommon xkbcommon-x11 x11)
#LIBS += $(shell $(PKG_CONFIG) --libs cairo xcb-composite xcb-xinerama xcb-randr xcb-atom xcb-image xcb-xkb xkbcommon xkbcommon-x11 x11)
#LIBS += -lev
#LIBS += -lm

FILES:=$(wildcard src/*.c)
FILES:=$(FILES:.c=.o)

ifeq ($(wildcard .git),)
	# not in git
	VERSION:= $(cat $(TOPDIR)/VERSION)
else
	VERSION:=$(shell git -C $(TOPDIR) describe --abbrev=40 --tags)
endif
CFLAGS += -DVERSION="\"$(VERSION)\""

.PHONY: all clean dist debug

all: velock

debug: CFLAGS += -g
debug: velock

clean:
	rm -f velock $(FILES) velock-$(VERSION).tar.gz

velock: $(FILES)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

dist:
	# echo the version from git into the VERSION file
	$(shell echo $(VERSION) > $(TOPDIR)/VERSION)
