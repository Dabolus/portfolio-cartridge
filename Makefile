# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
GBDK_HOME = ~/gbdk/
LCC = $(GBDK_HOME)bin/lcc

# Set platforms to build here, spaced separated. (These are in the separate Makefile.targets)
# They can also be built/cleaned individually: "make gg" and "make gg-clean"
# Possible are: gb gbc pocket megaduck sms gg
TARGETS=gb gbc pocket megaduck sms gg

# Configure platform specific LCC flags here:
LCCFLAGS_gb      = -Wl-yt0x1B # Set an MBC for banking (1B-ROM+MBC5+RAM+BATT)
LCCFLAGS_pocket  = -Wl-yt0x1B # Usually the same as required for .gb
LCCFLAGS_duck    = -Wl-yt0x1B # Usually the same as required for .gb
LCCFLAGS_gbc     = -Wl-yt0x1B -Wm-yC # Same as .gb with: -Wm-yc (gb & gbc) or Wm-yC (gbc exclusive)
LCCFLAGS_sms     =
LCCFLAGS_gg      =

LCCFLAGS += $(LCCFLAGS_$(EXT)) # This adds the current platform specific LCC Flags

LCCFLAGS += -Wl-j -Wm-yoA -Wm-ya4 -autobank -Wb-ext=.rel -Wb-v # MBC + Autobanking related flags
LCCFLAGS += -debug -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -Wm-yS # Debugging related flags
LCCFLAGS += -v # Verboseness related flags
LCCFLAGS += -Wl-l$(HUGEDRIVER_LIB) # Additional dependencies related flags

# You can set the name of the ROM file here
PROJECTNAME = portfolio

EXT?=gb
SRCDIR      = src
OBJDIR      = obj/$(EXT)
RESDIR      = res
BINDIR      = build/$(EXT)
EXTERNALDIR = external
# See bottom of Makefile for directory auto-creation
MKDIRS      = $(OBJDIR) $(BINDIR) $(shell find $(SRCDIR)/* $(RESDIR)/* -type d | sed "s/$(subst /,\/,$(SRCDIR))/$(subst /,\/,$(OBJDIR))/" | sed "s/$(subst /,\/,$(RESDIR))/$(subst /,\/,$(OBJDIR))/")

BINS	          = $(OBJDIR)/$(PROJECTNAME).$(EXT)
CSOURCES        = $(shell find $(SRCDIR) $(RESDIR) -name "*.c" | cut -c5-)
ASMSOURCES      = $(shell find $(SRCDIR) $(RESDIR) -name "*.s" | cut -c5-)
OBJS            = $(patsubst %.c,$(OBJDIR)/%.o,$(CSOURCES)) $(patsubst %.s,$(OBJDIR)/%.o,$(ASMSOURCES))
HUGEDRIVER_LIB  = $(EXTERNALDIR)/hUGEDriver/gbdk/hUGEDriver.lib

# Builds all targets sequentially
all: $(TARGETS)

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.s
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# If needed, compile .c files i n"src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -S -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS) $(HUGEDRIVER_TARGET)
	$(LCC) $(LCCFLAGS) $(CFLAGS) -o $(BINDIR)/$(PROJECTNAME).$(EXT) $(OBJS)

clean:
	@echo Cleaning
	@for target in $(TARGETS); do \
		$(MAKE) $$target-clean; \
	done

watch:
	@echo Watching
	@for target in $(TARGETS); do \
		$(MAKE) $$target-watch; \
	done

# Include available build targets
include Makefile.targets


# create necessary directories after Makefile is parsed but before build
# info prevents the command from being pasted into the makefile
ifneq ($(strip $(EXT)),)           # Only make the directories if EXT has been set by a target
$(info $(shell mkdir -p $(MKDIRS)))
endif
